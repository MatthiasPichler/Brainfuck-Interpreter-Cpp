//
// Created by matze on 6/27/17.
//


#include "Interpreter.hpp"

Interpreter::Interpreter(std::string file,
						 std::string input,
						 unsigned int buffersize) :
		file(file),
		buffersize(buffersize),
		buffer(new int[buffersize]),
		pointer(0) {
	
	
	filestream.open(file, std::ifstream::in);
	
	if(!filestream.is_open()) {
		std::cerr << "Failed to open file " << file << std::endl;
		exit(5);
	}
	
	inputstream.str(input);
	
	try{
		run();
	} catch(std::underflow_error &ufe){
		std::cerr << ufe.what();
	}
	
	
}

void Interpreter::run() {
	
	char c;
	
	while(filestream.get(c)){
		
		switch(c){
			case '<':
				if(pointer == 0) {
					pointer = buffersize - 1;
				} else {
					pointer--;
				}
				break;
			
			case '>':
				if(pointer == buffersize - 1) {
					pointer = 0;
				} else {
					pointer++;
				}
				break;
			
			case '+':
				buffer[pointer]++;
				break;
			
			case '-':
				buffer[pointer]--;
				break;
			
			case '.':
				std::cout << (char) buffer[pointer];
				break;
			
			case ',':{
				char tmp;
				if(inputstream.get(tmp)) {
					buffer[pointer] = tmp;
				} else {
					throw std::underflow_error("to little input");
				}
				
			}
				break;
			
			case '[':
				//TODO
				break;
			
			case ']':
				//TODO
				break;
		}
		
	}
	
}