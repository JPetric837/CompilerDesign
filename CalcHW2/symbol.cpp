// Symbol
// Joseph Petric

#include "symbol.hpp"

Symbol::Symbol(std::string s, int k) : str(s), kind(k) {}

void Symbol_Table::put(std::string const str, Symbol * sym) {
	std::pair<std::string,Symbol*> newSym (str, sym);
	map.insert(newSym);
}

Symbol const * Symbol_Table::get(std::string const str) {
	auto iter = map.find(str);
  	if (iter != map.end())
    	return iter->second;
  	else
    	return nullptr;
}
