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

class Interpreter {

private:

	const std::string file;
	std::stringstream inputstream;
	
	std::ifstream filestream;
	
	unsigned int pointer;
	const unsigned int buffersize;
	
	int *buffer;
	
	void run();
	
public:
	
	Interpreter(std::string file,
				std::string input,
				unsigned int buffersize);
};


#endif //BRAINFUCK_INTERPRETER_CPP_INTERPRETER_HPP
