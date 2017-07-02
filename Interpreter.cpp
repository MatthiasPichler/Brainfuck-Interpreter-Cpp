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
	
	
	
	
}

void Interpreter::setup(){
	char c;
	
	while(filestream.get(c)){
		for(int i = 0; i < 8; i++){
			if(c == tokens[i]){
				code.push_back(c);
			}
		}
	}
}

void Interpreter::run() {
	
	char c;
	
	for(int i = 0; i < code.length(); i++){
		c = code[i];
		
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
				//don't process loop
				if(buffer[pointer] == 0){
					int loop = 1;
					while(loop > 0){
						i++;
						if(code[i] == '['){
							loop++;
						} else if (code[i] == ']'){
							loop--;
						}
					}
				} else {
					stack.push(i);
				}
				
				break;
			
			case ']':
				if(buffer[pointer] != 0){
					i = stack.top();
				} else {
					stack.pop();
				}
				break;
		}
		
	}
	
}