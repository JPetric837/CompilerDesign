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



/******************************  Evaluation  ***********************************/

int eval_add(int left, int right) {
	return (left + right);
}

int eval_sub(int left, int right) {
	return (left - right);
}

int eval_mult(int left, int right) {
	return (left * right);
}

int eval_div(int left, int right) {
	if(right != 0)
		return (left / right);
	else
		throw std::runtime_error("Cannot divide by zero");
}

int eval_mod(int left, int right) {
	return (left % right);
}

int eval_positive(int num) {
	return num;
}

int eval_negative(int num) {
	return (num * -1);
}

bool eval_less(int left, int right) {
	return (left < right);
}

bool eval_lessEq(int left, int right) {
	return (left <= right);
}

bool eval_greater(int left, int right) {
	return (left > right);
}

bool eval_greaterEq(int left, int right) {
	return (left >= right);
}

template<class T>
bool eval_equal(T left, T right) {
	return (left == right);
}

template<class T>
bool eval_unequal(T left, T right) {
	return (left != right);
}

bool eval_and(bool left, bool right) {
	return (left && right);
}

bool eval_or(bool left, bool right) {
	return (left || right);
}

bool eval_not(bool b) {
	return (!b);
}
