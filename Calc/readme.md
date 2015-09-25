Calculator Readme
---------------------

Build Instructions

Run cmake on Calc folder then run make.
The AST and parser are used to create a library.
3 executable files will be made and linked to the library.
These executables are evalCalc, sExpr, and postExpr.
---------------------

Execution Instructions

Input expressions are limited to single digit numbers,
addition, subtraction, multiplication, division, modulus,
and parentheses.  Using numbers of multiple digits will
result in false evaluations.

evalCalc will evaluate and answer expressions.
sExpr will convert expressions to s-expressions.
postExpr will convert expressions to postfix expressions.

To exit any of the 3 programs, simply type "exit".
---------------------

Testing Instructions

There is no provided test suite.
