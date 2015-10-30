// Abstract Syntax Tree
// Joseph Petric

#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include "token.hpp"

struct Expr;
struct Positive;
struct Negative;
struct IntLiteral;
struct Add;
struct Sub;
struct Mult;
struct Div;
struct Mod;
struct BoolLiteral;
struct Less;
struct LessEqual;
struct Greater;
struct GreaterEqual;
struct Equal;
struct Unequal;
struct And;
struct Or;
struct Not;
struct Visitor;
struct TypeVisitor;
struct TypeCheck;

int Check_BinaryArithmetic(int, int);
int Check_Ordering(int, int);
int Check_Unary(int);
int Check_Equality(int, int);
int Check_Logical(int, int);
int Check_LogicalNot(int);


struct TypeVisitor{
	virtual int visit(IntLiteral const * e) = 0;
	virtual int visit(BoolLiteral const * e) = 0;
	virtual int visit(Add const * e) = 0;
	virtual int visit(Sub const * e) = 0;
	virtual int visit(Mult const * e) = 0;
	virtual int visit(Div const * e) = 0;
	virtual int visit(Mod const * e) = 0;
	virtual int visit(Positive const * e) = 0;
	virtual int visit(Negative const * e) = 0;
	virtual int visit(Equal const * e) = 0;
	virtual int visit(Unequal const * e) = 0;
	virtual int visit(Less const * e) = 0;
	virtual int visit(LessEqual const * e) = 0;
	virtual int visit(Greater const * e) = 0;
	virtual int visit(GreaterEqual const * e) = 0;
	virtual int visit(And const * e) = 0;
	virtual int visit(Or const * e) = 0;
	virtual int visit(Not const * e) = 0;
};


struct Visitor{
	virtual int  visit(IntLiteral const * e) = 0;
	virtual bool visit(BoolLiteral const * e) = 0;
	virtual int  visit(Add const * e) = 0;
	virtual int  visit(Sub const * e) = 0;
	virtual int  visit(Mult const * e) = 0;
	virtual int  visit(Div const * e) = 0;
	virtual int  visit(Mod const * e) = 0;
	virtual int  visit(Positive const * e) = 0;
	virtual int  visit(Negative const * e) = 0;
	virtual bool visit(Equal const * e) = 0;
	virtual bool visit(Unequal const * e) = 0;
	virtual bool visit(Less const * e) = 0;
	virtual bool visit(LessEqual const * e) = 0;
	virtual bool visit(Greater const * e) = 0;
	virtual bool visit(GreaterEqual const * e) = 0;
	virtual bool visit(And const * e) = 0;
	virtual bool visit(Or const * e) = 0;
	virtual bool visit(Not const * e) = 0;
};


// Expression is a base class of which all syntax is derived from
struct Expr {
	virtual ~Expr() {}
	virtual int  accept(Visitor &v) const = 0;
	virtual bool accept(Visitor &v) const = 0;
	virtual int accept(TypeVisitor &v) const = 0;
};


// Digit represents single digit numbers from 0 - 9
struct IntLiteral : Expr {
	IntLiteral(int n) : val(n) {}
	int val;
	int accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


struct Positive : Expr {
	Positive(Expr * e1) : num(e1) {}
	Expr * num;
	int accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};

struct Negative : Expr {
	Negative(Expr * e1) : num(e1) {}
	Expr * num;
	int accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


// Add represents addition of two expressions
struct Add : Expr {
	Add(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	int accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


// Sub represents subtraction of two expressions
struct Sub : Expr {
	Sub(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	int accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


// Mult represents multiplication of two expressions
struct Mult : Expr {
	Mult(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	int accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


// Div represents division of two expressions
struct Div : Expr {
	Div(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	int accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


// Mod represents modulus of two expressions
struct Mod : Expr {
	Mod(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	int accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


struct BoolLiteral : Expr {
	BoolLiteral(bool n) : val(n) {}
	const bool val;
	bool accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


struct Greater : Expr {
	Greater(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	bool accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


struct Less : Expr {
	Less(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	bool accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


struct GreaterEqual : Expr {
	GreaterEqual(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	bool accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


struct LessEqual : Expr {
	LessEqual(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	bool accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


struct Equal : Expr {
	Equal(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	bool accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


struct Unequal : Expr {
	Unequal(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	bool accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


struct And : Expr {
	And(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	bool accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


struct Or : Expr {
	Or(Expr * e1, Expr * e2) : left(e1), right(e2) {}
	Expr * left;
	Expr * right;
	bool accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};


struct Not : Expr {
	Not(Expr * e1) : val(e1) {}
	Expr * val;
	bool accept(Visitor &v) const {return v.visit(this);}
	int accept(TypeVisitor &v) const {return v.visit(this);}
};




// ***********************************
// **        Type Checking          **
// ***********************************


struct TypeCheck : TypeVisitor {

	int visit(IntLiteral const * e) 	{ return t_integer; }
	int visit(BoolLiteral const * e)   	{ return t_bool; }
	int visit(Add const * e)   			{ return Check_BinaryArithmetic(e->left->accept(*this), e->right->accept(*this)); }
	int visit(Sub const * e)   			{ return Check_BinaryArithmetic(e->left->accept(*this), e->right->accept(*this)); }
	int visit(Mult const * e)  			{ return Check_BinaryArithmetic(e->left->accept(*this), e->right->accept(*this)); }
	int visit(Div const * e)   			{ return Check_BinaryArithmetic(e->left->accept(*this), e->right->accept(*this)); }
	int visit(Mod const * e)   			{ return Check_BinaryArithmetic(e->left->accept(*this), e->right->accept(*this)); }
	int visit(Positive const * e) 		{ return Check_Unary(e->num->accept(*this)); }
	int visit(Negative const * e) 		{ return Check_Unary(e->num->accept(*this)); }
	int visit(Less const * e) 			{ return Check_Ordering(e->left->accept(*this), e->right->accept(*this)); }
	int visit(LessEqual const * e) 		{ return Check_Ordering(e->left->accept(*this), e->right->accept(*this)); }
	int visit(Greater const * e) 		{ return Check_Ordering(e->left->accept(*this), e->right->accept(*this)); }
	int visit(GreaterEqual const * e) 	{ return Check_Ordering(e->left->accept(*this), e->right->accept(*this)); }
	int visit(Equal const * e) 			{ return Check_Equality(e->left->accept(*this), e->right->accept(*this)); }
	int visit(Unequal const * e) 		{ return Check_Equality(e->left->accept(*this), e->right->accept(*this)); }
	int visit(And const * e) 			{ return Check_Logical(e->left->accept(*this), e->right->accept(*this)); }
	int visit(Or const * e) 			{ return Check_Logical(e->left->accept(*this), e->right->accept(*this)); }
	int visit(Not const * e) 			{ return Check_LogicalNot(e->val->accept(*this)); }
};


// ***********************************
// **          Evaluating           **
// ***********************************

struct Eval : Visitor {

	int  visit(IntLiteral const * e) 	{ return e->val; }
	bool visit(BoolLiteral const * e)   { return e->val; }
	int  visit(Add const * e)   		{ return eval_add(e->left->accept(*this), e->right->accept(*this)); }
	int  visit(Sub const * e)   		{ return eval_sub(e->left->accept(*this), e->right->accept(*this)); }
	int  visit(Mult const * e)  		{ return eval_mult(e->left->accept(*this), e->right->accept(*this)); }
	int  visit(Div const * e)   		{ return eval_div(e->left->accept(*this), e->right->accept(*this)); }
	int  visit(Mod const * e)   		{ return eval_mod(e->left->accept(*this), e->right->accept(*this)); }
	int  visit(Positive const * e) 		{ return eval_positive(e->num->accept(*this)); }
	int  visit(Negative const * e) 		{ return eval_negative(e->num->accept(*this)); }
	bool visit(Less const * e) 			{ return eval_less(e->left->accept(*this), e->right->accept(*this)); }
	bool visit(LessEqual const * e) 	{ return eval_lessEq(e->left->accept(*this), e->right->accept(*this)); }
	bool visit(Greater const * e) 		{ return eval_greater(e->left->accept(*this), e->right->accept(*this)); }
	bool visit(GreaterEqual const * e) 	{ return eval_greaterEq(e->left->accept(*this), e->right->accept(*this)); }
	bool visit(Equal const * e) 		{ return eval_equal(e->left->accept(*this), e->right->accept(*this)); }
	bool visit(Unequal const * e) 		{ return eval_unequal(e->left->accept(*this), e->right->accept(*this)); }
	bool visit(And const * e) 			{ return eval_and(e->left->accept(*this), e->right->accept(*this)); }
	bool visit(Or const * e) 			{ return eval_or(e->left->accept(*this), e->right->accept(*this)); }
	bool visit(Not const * e) 			{ return eval_not(e->val->accept(*this)); }
};


#endif
