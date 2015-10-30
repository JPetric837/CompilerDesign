// Parser
// Joseph Petric

#ifndef PARSER_HPP
#define PARSER_HPP

#include "ast.hpp"
#include "token.hpp"
#include <stdlib.h>

int stringToInt(std::string);

class Parser {

private:

	void next();
	bool match(int);

	Node * index;

	Expr * expression();
	Expr * logical_or();
	Expr * logical_and();
	Expr * equality();
	Expr * ordering();
	Expr * additive();
	Expr * multiplicative();
	Expr * unary();
	Expr * primary();

public:

	Expr * parse(TokenStream*);

};


#endif
