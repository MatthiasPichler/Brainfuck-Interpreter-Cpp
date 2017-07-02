//
// Created by matze on 6/27/17.
//

#ifndef BRAINFUCK_INTERPRETER_CPP_INTERPRETER_HPP
#define BRAINFUCK_INTERPRETER_CPP_INTERPRETER_HPP

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <array>
#include <sstream>
#include <stack>

class Interpreter {

private:

	const char tokens[8] = {'<','>','+','-','.',',','[',']'};
	
	const std::string file;
	std::stringstream inputstream;
	
	std::ifstream filestream;
	std::string code;
	
	unsigned int pointer;
	const unsigned int buffersize;
	
	int *buffer;
	
	std::stack<int> stack;
	
	
	
public:
	
	Interpreter(std::string file,
				std::string input,
				unsigned int buffersize);
	
	void setup();
	
	void run();
};


#endif //BRAINFUCK_INTERPRETER_CPP_INTERPRETER_HPP
