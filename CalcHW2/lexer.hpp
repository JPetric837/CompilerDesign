// Lexer
// Joseph Petric

#ifndef LEXER_HPP
#define LEXER_HPP

#include "token.hpp"
#include <sstream>

class Lexer {

	private:
		std::string input;
		Symbol_Table symtab;
		TokenStream * ts;
		int index;
		char peek(int);
		Token * integer_tok();
		Token * plus_tok();
		Token * minus_tok();
		Token * mult_tok();
		Token * div_tok();
		Token * mod_tok();
		Token * true_tok();
		Token * false_tok();
		Token * lparen_tok();
		Token * rparen_tok();
		Token * less_tok();
		Token * great_tok();
		Token * equal_tok();
		Token * and_tok();
		Token * or_tok();
		Token * not_tok();

	public:
		Lexer();
		TokenStream * scan(std::string);
};


#endif
