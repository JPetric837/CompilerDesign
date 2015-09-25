// Parser
// Joseph Petric

#ifndef PARSER_HPP
#define PARSER_HPP

#include "ast.hpp"
#include <string>
#include <stdlib.h>

class Parser {

public:
	// Look ahead that traverses through input string
	unsigned int la;
	// User's expression
	std::string input;

	Parser(std::string);

	// Increments the look ahead
	void next();

	Expr * E();  // Parses expression
	Expr * F();  // Parses factor
	Expr * T();  // Parses term


};


#endif
