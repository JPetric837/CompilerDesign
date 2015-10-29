// Main
// Joseph Petric

#include "lexer.hpp"
#include "parser.hpp"

int main(int argc, char **argv) {
	Lexer * l = new Lexer();
	TokenStream * ts = new TokenStream();
	Parser * p = new Parser();
	Expr * e = new Expr();

	std::string line;
	std::cout << "Evaluate >>";
	std::getline(std::cin, line);

	try {
		ts = l->scan(line);
		e = p->parse(ts);
	}

	catch(std::runtime_error e) {
		std::cout << "Exception Occurred: " << e.what() << '\n';
	}

	delete l;
	delete ts;
	delete p;

	return 0;
}