// PostExpr
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

			PostExpr pe;

			Expr * root = p->E();

			// Evaluates PostExpr with visitor
			root->accept(pe);
			cout << endl;

			delete p;
		}
	}

	return 0;

}
