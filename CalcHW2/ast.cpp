// Abstract Syntax Tree
// Joseph Petric

#include "ast.hpp"



/*********************************  Type Checking  ***********************************/


int Check_BinaryArithmetic(int type1, int type2) {
	if(type1 == t_integer) {
		if(type2 == t_integer)
			return t_integer;
	}
	
	throw std::runtime_error("Binary arithmetics can only be performed on two integers");
}

int Check_Unary(int type1) {
	if(type1 == t_integer)
		return t_integer;

	throw std::runtime_error("Unary operators can only be applied to integers");
}

int Check_Ordering(int type1, int type2) {
	if(type1 == t_integer) {
		if(type2 == t_integer)
			return t_bool;
	}

	throw std::runtime_error("Ordering expressions can only be performed on two integers");
}

int Check_Equality(int type1, int type2) {
	if(type1 == t_integer) {
		if(type2 == t_integer)
			return t_bool;
	}
	if(type1 == t_bool) {
		if(type2 == t_bool)
			return t_bool;
	}

	throw std::runtime_error("Equality operands must be of the same type");
}

int Check_Logical(int type1, int type2) {
	if(type1 == t_bool) {
		if(type2 == t_bool)
			return t_bool;
	}

	throw std::runtime_error("Logical expressions can only be performed on two booleans");
}

int Check_LogicalNot(int type1) {
	if(type1 == t_bool)
		return t_bool;

	throw std::runtime_error("Logical not expression can only be performed a boolean");
}



// Structure to hold values during evaluation
// Uses type variable to read the value as integer or boolean
Value::Value(int x, int t) : integer(x), type(t) {}

Value::Value(bool b, int t) : boolean(b), type(t) {}


/******************************  Evaluation  ***********************************/

Value * eval_add(Value * left, Value * right) {
	return new Value(left->integer + right->integer, t_integer);
}

Value * eval_sub(Value * left, Value * right) {
	return new Value(left->integer - right->integer, t_integer);
}

Value * eval_mult(Value * left, Value * right) {
	return new Value(left->integer * right->integer, t_integer);
}

Value * eval_div(Value * left, Value * right) {
	if(right != 0)
		return new Value(left->integer / right->integer, t_integer);
	else
		throw std::runtime_error("Cannot divide by zero");
}

Value * eval_mod(Value * left, Value * right) {
	return new Value(left->integer % right->integer, t_integer);
}

Value * eval_positive(Value * num) {
	return new Value(num->integer, t_integer);
}

Value * eval_negative(Value * num) {
	return new Value(num->integer * -1, t_integer);
}

Value * eval_less(Value * left, Value * right) {
	return new Value(left->integer < right->integer, t_bool);
}

Value * eval_lessEq(Value * left, Value * right) {
	return new Value(left->integer <= right->integer, t_bool);
}

Value * eval_greater(Value * left, Value * right) {
	return new Value(left->integer > right->integer, t_bool);
}

Value * eval_greaterEq(Value * left, Value * right) {
	return new Value(left->integer >= right->integer, t_bool);
}

Value * eval_equal(Value * left, Value * right) {
	if(left->type == t_integer)
		return new Value(left->integer == right->integer, t_integer);
	if(left->type == t_bool)
		return new Value(left->boolean == right->boolean, t_bool);
}

Value * eval_unequal(Value * left, Value * right) {
	if(left->type == t_integer)
		return new Value(left->integer != right->integer, t_integer);
	if(left->type == t_bool)
		return new Value(left->boolean != right->boolean, t_bool);
}

Value * eval_and(Value * left, Value * right) {
	return new Value(left->boolean && right->boolean, t_bool);
}

Value * eval_or(Value * left, Value * right) {
	return new Value(left->boolean || right->boolean, t_bool);
}

Value * eval_not(Value * b) {
	return new Value(!b->boolean, t_bool);
}
