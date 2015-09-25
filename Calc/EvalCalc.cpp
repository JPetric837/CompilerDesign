// EvalCalc
// Joseph Petric

#include <iostream>
#include "Parser.hpp"

using namespace std;

int main() {

	string input;

	while(true) {
		cout << "Evaluate >> ";
		getline(cin, input);

		if(input == "exit") break;
		else {
			Parser * p = new Parser(input);
			Eval eval;
			
			// Assigned to the root of the AST
			Expr * root = p->E();

			// Evaluates tree with visitor
			root->accept(eval);
			cout << eval.result << endl;

			delete p;
		}
	}

	return 0;

}
