#include <cstdlib>
#include <climits>
#include <iostream>
#include "Interpreter.hpp"

void displayUsage() {
	std::cout << "Usage: bf -f FILE [OPTIONS]" << std::endl;
	std::cout << "-f, --file: Program source code" << std::endl;
	std::cout << "OPTIONS:" << std::endl;
	std::cout << "-i, --input: Program input" << std::endl;
	std::cout << "-b, --buffersize: size of the buffer" << std::endl;
	
}

int main(int argc, char *argv[]) {
	
	if(argc < 2) {
		//display usage
		displayUsage();
		return 1;
	}
	
	//std::string file(argv[1]); // must be given
	
	std::string file = "";
	std::string input = "";
	unsigned int buffersize = 0xFFFF; //65535
	
	for(int i = 1; i < argc - 1; i++){
		
		std::string param(argv[i]);
		
		if(param == "-i" ||
		   param == "--input") {
			
			std::string(argv[++i]);
			
		} else if(param == "-b" ||
				  param == "--buffersize") {
			
			try{
				buffersize = std::stoi(argv[++i]);
				
			} catch(std::invalid_argument &ive){
				std::cerr << ive.what();
				std::cerr << "buffersize must be a "
						  << "positive integer in range [1,"
						  << INT_MAX << "]" << std::endl;
				return 2;
				
			} catch(std::out_of_range &oor){
				std::cerr << oor.what();
				std::cerr << "buffersize must be a "
						  << "positive integer in range [1,"
						  << INT_MAX << "]" << std::endl;
				return 3;
			}
			
		} else if(param == "-f" ||
				  param == "--file") {
			
			file = std::string(argv[++i]);
			
		} else {
			std::cerr << "invalid parameter " << argv[i] << std::endl;
			displayUsage();
			return 4;
		}
	}
	
	Interpreter interpreter(file, input, buffersize);
	
	try{
		interpreter.setup();
		interpreter.run();
	} catch(std::underflow_error &ufe){
		std::cerr << ufe.what();
	} catch(std::out_of_range &oor){
		std::cerr << oor.what();
	}
	
	return EXIT_SUCCESS;
}