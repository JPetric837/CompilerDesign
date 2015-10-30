// Token
// Joseph Petric

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "symbol.hpp"
#include <iostream>

enum Token_kind
{
	t_integer,
	t_plus,
	t_minus,
	t_mult,
	t_div,
	t_mod,
	t_bool,
	t_lparen,
	t_rparen,
	t_less,
	t_lesseq,
	t_great,
	t_greateq,
	t_equal,
	t_unequal,
	t_and,
	t_or,
	t_not
};

struct Token {
	Token(int k, Symbol const* s) : kind(k), sym(s) {}
	int kind;
	Symbol const* sym;
};

struct Node {
	Node * next;
	Token * tok;
};

struct TokenStream {
	Node * head;

	TokenStream() {head = nullptr;}

	void insert(Token * t) {
		if(head == nullptr) {
			head = new Node();
			head->next = nullptr;
			head->tok = t;
		}
		else {
			Node * temp = new Node();
			temp = head;
			while(temp->next != nullptr) {
				temp = temp->next;
			}
			Node * newnode = new Node();
			newnode->next = nullptr;
			newnode->tok = t;
			temp->next = newnode;
		}
	}

	void print() {
		Node * temp = new Node();
		temp = head;
		while(temp != nullptr) {
			std::cout << temp->tok->kind << "\n";
			temp = temp->next;
		}
	}
};


#endif
