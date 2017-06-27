#include <cstdlib>
#include <climits>
#include <iostream>
#include "Interpreter.hpp"

void displayUsage(){
	std::cout << "Usage: bf -FILE [OPTIONS]" << std::endl;
	std::cout << "OPTIONS:" << std::endl;
	std::cout << "-i, --input: Program input" << std::endl;
	std::cout << "-b, --buffersize: size of the buffer" << std::endl;
	
}

int main(int argc, char* argv[]) {
	
	if(argc < 2){
		//display usage
		displayUsage();
		return 1;
	}
	
	std::string file(argv[1]); // must be given
	
	std::string input = "";
	unsigned int buffersize = 0xFFFF; //65535
	
	for(int i = 2; i < argc; i++){
		if(argv[i] == "-i" || argv[i] == "--input"){
			input = argv[++i];
		}else if(argv[i] == "-b" || argv[i] == "--buffersize"){
			try{
				buffersize = std::stoi(argv[++i]);
			} catch (std::invalid_argument& ive ){
				std::cerr << ive.what();
				std::cerr << "buffersize must be a "
						  << "positive integer in range [1,"
						  << INT_MAX << "]" << std::endl;
				return 2;
			} catch (std::out_of_range& oor){
				std::cerr << oor.what();
				std::cerr << "buffersize must be a "
						  << "positive integer in range [1,"
						  << INT_MAX << "]" << std::endl;
				return 3;
			}
		}else{
			std::cerr << "invalid parameter " << argv[i] << std::endl;
			displayUsage();
			return 4;
		}
	}
	
	Interpreter interpreter(file,input, buffersize);
	
	return EXIT_SUCCESS;
}