// Symbol
// Joseph Petric

#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <stdlib.h>
#include <unordered_map>

struct Symbol {
	Symbol(std::string, int);
	std::string const str;
	int kind;
};

class Symbol_Table {
	private:
		std::unordered_map<std::string, Symbol*> map;

	public:
		void put(std::string const, Symbol*);
		Symbol const * get(std::string const);
};

#endif