// Parser
// Joseph Petric

#include "Parser.hpp"


void Parser::next() {

	if(index->next)
		index = index->next;

}

bool Parser::match(int testkind) {
	return (index->tok->kind == testkind);
}


Expr * Parser::parse(TokenStream * ts) {
	index = ts->head;

	if(index) {
		return expression();
	}
}

Expr * Parser::expression() {
	return logical_or();
}

Expr * Parser::logical_or() {
	Expr * e1 = logical_and();
	while(true) {
		if(match(t_or)) {
			next();
			Expr * e2 = logical_and();
			return new Or(e1, e2);
		}
		else {
			break;
		}
	}
	return e1;
}

Expr * Parser::logical_and() {
	Expr * e1 = equality();
	while(true) {
		if(match(t_and)) {
			next();
			Expr * e2 = equality();
			return new And(e1, e2);
		}
		else {
			break;
		}
	}
	return e1;
}

Expr * Parser::equality() {
	Expr * e1 = ordering();
	while(true) {
		if(match(t_equal)) {
			next();
			Expr * e2 = ordering();
			return new Equal(e1, e2);
		}
		else if(match(t_unequal)) {
			next();
			Expr * e2 = ordering();
			return new Unequal(e1, e2);
		}
		else {
			break;
		}
	}
	return e1;
}

Expr * Parser::ordering() {
	Expr * e1 = additive();
	while(true) {
		if(match(t_less)) {
			next();
			Expr * e2 = additive();
			return new Less(e1, e2);
		}
		else if(match(t_great)) {
			next();
			Expr * e2 = additive();
			return new Greater(e1, e2);
		}
		else if(match(t_lesseq)) {
			next();
			Expr * e2 = additive();
			return new LessEqual(e1, e2);
		}
		else if(match(t_greateq)) {
			next();
			Expr * e2 = additive();
			return new GreaterEqual(e1, e2);
		}
		else {
			break;
		}
	}
	return e1;
}

Expr * Parser::additive() {
	Expr * e1 = multiplicative();
	while(true) {
		if(match(t_plus)) {
			next();
			Expr * e2 = multiplicative();
			return new Add(e1, e2);
		}
		else if(match(t_minus)) {
			next();
			Expr * e2 = multiplicative();
			return new Sub(e1, e2);
		}
		else {
			break;
		}
	}
	return e1;
}

Expr * Parser::multiplicative() {
	Expr * e1 = unary();
	while(true) {
		if(match(t_mult)) {
			next();
			Expr * e2 = unary();
			return new Mult(e1, e2);
		}
		else if(match(t_div)) {
			next();
			Expr * e2 = unary();
			return new Div(e1, e2);
		}
		else if(match(t_mod)) {
			next();
			Expr * e2 = unary();
			return new Mod(e1, e2);
		}
		else {
			break;
		}
	}
	return e1;
}

Expr * Parser::unary() {
	if(match(t_plus)) {
		next();
		Expr * e = unary();
		return new Positive(e);
	}
	else if(match(t_minus)) {
		next();
		Expr * e = unary();
		return new Negative(e);
	}
	else if(match(t_not)) {
		next();
		Expr * e = unary();
		return new Not(e);
	}
	else {
		return primary();
	}
}

Expr * Parser::primary() {
	if(match(t_bool)) {
		if(index->tok->sym->str == "true") {
			next();
			return new BoolLiteral(true);
		}
		else {
			next();
			return new BoolLiteral(false);
		}
	}
	else if(match(t_integer)) {
		int x = stringToInt(index->tok->sym->str);
		next();
		return new IntLiteral(x);
	}
	else if(match(t_lparen)) {
		next();
		Expr * e = expression();
		if(!match(t_rparen))
			throw std::runtime_error("Closing parenthese missing");
		next();
		return e;
	}
	else
		throw std::runtime_error("Expected a literal");

}


int stringToInt(std::string s) {
	int literal = 0;
	int multiplier = 1;
	for(int i=s.length()-1; i >= 0; i--) {
		literal += (s.at(i) - 48) * multiplier;
		multiplier *= 10;
	}

	return literal;
}
