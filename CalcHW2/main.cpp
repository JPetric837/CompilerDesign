// Main
// Joseph Petric

#include "lexer.hpp"
#include "parser.hpp"

int main(int argc, char **argv) {

	while(1) {
	Lexer * l = new Lexer();
	TokenStream * ts = new TokenStream();
	Parser * p = new Parser();
	Expr * e = nullptr;
	TypeCheck tc;
	Eval eval;
	Value * v = nullptr;

	std::string line;
	std::cout << "Evaluate >>";
	std::getline(std::cin, line);
	if(line == "exit")
		break;

	try {
		// Scan line to create token stream
		ts = l->scan(line);
		// Parse token stream to produce ast
		e = p->parse(ts);
		// Run ast through type check
		e->accept(tc);
		// Run ast through evaluation to produce value
		v = e->accept(eval);

		std::cout << "Answer: ";

		// If final result is integer
		if(v->type == t_integer)
			std::cout << v->integer << "\n\n";
		// If final result is bool
		else if(v->type == t_bool) {
			std::cout << std::boolalpha;
			std::cout << v->boolean << "\n\n";
		}

	}

	catch(std::runtime_error e) {
		std::cout << "Exception Occurred: " << e.what() << '\n';
	}

	delete l;
	delete ts;
	delete p;
	delete e;
	delete v;
	}

	return 0;
}