// Parser
// Joseph Petric

#include "Parser.hpp"


Parser::Parser(std::string line) {
	la = 0;
	input = line;
}


void Parser::next() {

	do {
		if(la == input.size() - 1) break;
		la++;  // Increment look ahead
	}
	// Look past the white space
	while(isspace(input.at(la)));

}


// Parses expressions to create an addition or subtraction node
Expr * Parser::E() {
	Expr * e1 = F();
	while(true) {
		if(input.at(la) == '+') {
			next();
			Expr * e2 = F();
			e1 = new Add(e1, e2);
		}
		else if(input.at(la) == '-') {
			next();
			Expr * e2 = F();
			e1 = new Sub(e1, e2);
		}
		else break;
	}
	return e1;
}


// Parses factors to create a multiplication, division, or modulus node
Expr * Parser::F() {
	Expr * e1 = T();
	while(true) {
		if(input.at(la) == '*') {
			next();
			Expr * e2 = T();
			e1 = new Mult(e1, e2);
		}
		else if(input.at(la) == '/') {
			next();
			Expr * e2 = T();
			e1 = new Div(e1, e2);
		}
		else if(input.at(la) == '%') {
			next();
			Expr * e2 = T();
			e1 = new Mod(e1, e2);
		}
		else break;
	}
	return e1;
}


// Parses terms to check for a digit or a parentheses
Expr * Parser::T() {
	if     ( input.at(la) == '0' ) { next(); return new Digit(0); }
	else if( input.at(la) == '1' ) { next(); return new Digit(1); }
	else if( input.at(la) == '2' ) { next(); return new Digit(2); }
	else if( input.at(la) == '3' ) { next(); return new Digit(3); }
	else if( input.at(la) == '4' ) { next(); return new Digit(4); }
	else if( input.at(la) == '5' ) { next(); return new Digit(5); }
	else if( input.at(la) == '6' ) { next(); return new Digit(6); }
	else if( input.at(la) == '7' ) { next(); return new Digit(7); }
	else if( input.at(la) == '8' ) { next(); return new Digit(8); }
	else if( input.at(la) == '9' ) { next(); return new Digit(9); }

	// Parentheses trigger a recursive call back to E()
	else if( input.at(la) == '(' ) {
		next();
		Expr * e1 = E();

		if(input.at(la) == ')')
			next();
		else {
			std::cout << "Syntax Error | Needs closing parenth | Exiting...\n";
			exit(1);
		}

		return e1;
	}
	
	// A valid symbol has not been found
	else {
		std::cout << "Syntax Error | Exiting...\n";
		exit(1);
	}
}
