// Abstract Syntax Tree
// Joseph Petric

#ifndef AST_HPP
#define AST_HPP

#include <iostream>

struct Expr;
struct Digit;
struct Add;
struct Sub;
struct Mult;
struct Div;
struct Mod;
struct Visitor;
struct Eval;
struct SExpr;
struct PostExpr;

// Visitor that calls the correct operation for each node in the AST
/*struct Visitor{
	virtual void visit(Digit const * e) = 0;
	virtual void visit(Add const * e) = 0;
	virtual void visit(Sub const * e) = 0;
	virtual void visit(Mult const * e) = 0;
	virtual void visit(Div const * e) = 0;
	virtual void visit(Mod const * e) = 0;
};*/


// Expression is a base class of which all syntax is derived from
struct Expr {
	virtual ~Expr() {}
	//virtual void accept(Visitor &v) const = 0;
};


// Digit represents single digit numbers from 0 - 9
struct IntLiteral : Expr {
	IntLiteral(int n) : val(n) {}
	int val;
	//void accept(Visitor &v) const {v.visit(this);};
};


struct Positive : Expr {
	Positive(Expr * e1) : num(e1) {}
	Expr * num;
};

struct Negative : Expr {
	Negative(Expr * e1) : num(e1) {}
	Expr * num;
};


// Add represents addition of two expressions
struct Add : Expr {
	Add(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	//void accept(Visitor &v) const {v.visit(this);};
};


// Sub represents subtraction of two expressions
struct Sub : Expr {
	Sub(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	//void accept(Visitor &v) const {v.visit(this);};
};


// Mult represents multiplication of two expressions
struct Mult : Expr {
	Mult(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	//void accept(Visitor &v) const {v.visit(this);};
};


// Div represents division of two expressions
struct Div : Expr {
	Div(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	//void accept(Visitor &v) const {v.visit(this);};
};


// Mod represents modulus of two expressions
struct Mod : Expr {
	Mod(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	//void accept(Visitor &v) const {v.visit(this);};
};


struct BoolLiteral : Expr {
	BoolLiteral(bool n) : val(n) {}
	const bool val;
};


struct Greater : Expr {
	Greater(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
};


struct Less : Expr {
	Less(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
};


struct GreaterEqual : Expr {
	GreaterEqual(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
};


struct LessEqual : Expr {
	LessEqual(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
};


struct Equal : Expr {
	Equal(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
};


struct Unequal : Expr {
	Unequal(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
};


struct And : Expr {
	And(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
};


struct Or : Expr {
	Or(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
};


struct Not : Expr {
	Not(Expr * e1) : val(e1) {}
	Expr * val;
};


// Evaluates the AST
/*struct Eval : Visitor {
	int result;

	void visit(Digit const * e) { result = e->val; }
	void visit(Add const * e)   { e->left->accept(*this); int t1 = result; e->right->accept(*this); result = t1 + result; }
	void visit(Sub const * e)   { e->left->accept(*this); int t1 = result; e->right->accept(*this); result = t1 - result; }
	void visit(Mult const * e)  { e->left->accept(*this); int t1 = result; e->right->accept(*this); result = t1 * result; }
	void visit(Div const * e)   { e->left->accept(*this); int t1 = result; e->right->accept(*this); result = t1 / result; }
	void visit(Mod const * e)   { e->left->accept(*this); int t1 = result; e->right->accept(*this); result = t1 % result; }
};*/


#endif
