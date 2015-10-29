// Lexer
// Joseph Petric


#include "lexer.hpp"

Lexer::Lexer() {

	symtab.put("+", new Symbol("+", t_plus));
	symtab.put("-", new Symbol("-", t_minus));
	symtab.put("*", new Symbol("*", t_mult));
	symtab.put("/", new Symbol("/", t_div));
	symtab.put("%", new Symbol("%", t_mod));
	symtab.put("true", new Symbol("true", t_true));
	symtab.put("false", new Symbol("false", t_false));
	symtab.put("(", new Symbol("(", t_lparen));
	symtab.put(")", new Symbol(")", t_rparen));
	symtab.put("<", new Symbol("<", t_less));
	symtab.put("<=", new Symbol("<=", t_lesseq));
	symtab.put(">", new Symbol(">", t_great));
	symtab.put(">=", new Symbol(">=", t_greateq));
	symtab.put("==", new Symbol("==", t_equal));
	symtab.put("!=", new Symbol("!=", t_unequal));
	symtab.put("&&", new Symbol("&&", t_and));
	symtab.put("||", new Symbol("||", t_or));
	symtab.put("!", new Symbol("!", t_not));

}

// Function used to supply index in error messages
std::string intToString(int);

// Returns character from the input from a specified position ahead of the index
char Lexer::peek(int i) {
	if(index + i < input.length())
		return input.at(index + i);
	else
		throw std::runtime_error("Invalid keyword at char (" + intToString(index) + ")");
}

TokenStream * Lexer::scan(std::string line) {

	// Add termination character to end of the line
	line += "\0";
	input = line;
	ts = new TokenStream();
	index = 0;
	bool exitloop = false;

	while(index < input.length()) {

		switch(input.at(index)) {
			case ' ': index++; break;
			case '+': ts->insert(plus_tok()); break;
			case '-': ts->insert(minus_tok()); break;
			case '*': ts->insert(mult_tok()); break;
			case '/': ts->insert(div_tok()); break;
			case '%': ts->insert(mod_tok()); break;
			case 't': ts->insert(true_tok()); break;
			case 'f': ts->insert(false_tok()); break;
			case '(': ts->insert(lparen_tok()); break;
			case ')': ts->insert(rparen_tok()); break;
			case '<': ts->insert(less_tok()); break;
			case '>': ts->insert(great_tok()); break;
			case '=': ts->insert(equal_tok()); break;
			case '&': ts->insert(and_tok()); break;
			case '|': ts->insert(or_tok()); break;
			case '!': ts->insert(not_tok()); break;

			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				ts->insert(integer_tok()); break;

			case '\0': exitloop = true; break;

			default: throw std::runtime_error("Unrecognized token at char (" + intToString(index) + ")");
		}

		if(exitloop == true)
			break;

	}

	return ts;
	
}


Token * Lexer::plus_tok() {
	Token * tok = new Token(t_plus, symtab.get("+"));
	index++;
	return tok;
}

Token * Lexer::minus_tok() {
	Token * tok = new Token(t_minus, symtab.get("-"));
	index++;
	return tok;
}

Token * Lexer::mult_tok() {
	Token * tok = new Token(t_mult, symtab.get("*"));
	index++;
	return tok;
}

Token * Lexer::div_tok() {
	Token * tok = new Token(t_div, symtab.get("/"));
	index++;
	return tok;
}

Token * Lexer::mod_tok() {
	Token * tok = new Token(t_mod, symtab.get("%"));
	index++;
	return tok;
}

Token * Lexer::lparen_tok() {
	Token * tok = new Token(t_lparen, symtab.get("("));
	index++;
	return tok;
}

Token * Lexer::rparen_tok() {
	Token * tok = new Token(t_rparen, symtab.get(")"));
	index++;
	return tok;
}

Token * Lexer::true_tok() {
	if(peek(1) == 'r' && peek(2) == 'u' && peek(3) == 'e') {
		Token * tok = new Token(t_true, symtab.get("true"));
		index += 4;
		return tok;
	}
	else
		throw std::runtime_error("Invalid keyword at char (" + intToString(index) + ")");
}

Token * Lexer::false_tok() {
	if(peek(1) == 'a' && peek(2) == 'l' && peek(3) == 's' && peek(4) == 'e') {
		Token * tok = new Token(t_false, symtab.get("false"));
		index += 5;
		return tok;
	}
	else
		throw std::runtime_error("Invalid keyword at char (" + intToString(index) + ")");
}

Token * Lexer::less_tok() {
	if(peek(1) == '=') {
		Token * tok = new Token(t_lesseq, symtab.get("<="));
		index += 2;
		return tok;
	}
	else {
		Token * tok = new Token(t_less, symtab.get("<"));
		index++;
		return tok;
	}
}

Token * Lexer::great_tok() {
	if(peek(1) == '=') {
		Token * tok = new Token(t_greateq, symtab.get(">="));
		index += 2;
		return tok;
	}
	else {
		Token * tok = new Token(t_great, symtab.get(">"));
		index++;
		return tok;
	}
}

Token * Lexer::equal_tok() {
	if(peek(1) == '=') {
		Token * tok = new Token(t_equal, symtab.get("=="));
		index += 2;
		return tok;
	}
	else
		throw std::runtime_error("Invalid operation at char (" + intToString(index) + ")");
}

Token * Lexer::and_tok() {
	if(peek(1) == '&') {
		Token * tok = new Token(t_and, symtab.get("&&"));
		index += 2;
		return tok;
	}
	else 
		throw std::runtime_error("Invalid operation at char (" + intToString(index) + ")");
}

Token * Lexer::or_tok() {
	if(peek(1) == '|') {
		Token * tok = new Token(t_or, symtab.get("||"));
		index += 2;
		return tok;
	}
	else 
		throw std::runtime_error("Invalid operation at char (" + intToString(index) + ")");
}

Token * Lexer::not_tok() {
	if(peek(1) == '=') {
		Token * tok = new Token(t_unequal, symtab.get("!="));
		index += 2;
		return tok;
	}
	else {
		Token * tok = new Token(t_not, symtab.get("!"));
		index++;
		return tok;
	}
}

Token * Lexer::integer_tok() {
	std::string number = "" + input.at(index);

	while(isdigit(peek(1))) {
		index++;
		number += input.at(index);
	}

	if(symtab.get(number) == nullptr)
		symtab.put(number, new Symbol(number, t_integer));

	Token * tok = new Token(t_integer, symtab.get(number));
	index++;
	return tok;
}

std::string intToString(int i) {
	std::string result;
	std::ostringstream convert;
	convert << i;
	result = convert.str();
	return result;
}
