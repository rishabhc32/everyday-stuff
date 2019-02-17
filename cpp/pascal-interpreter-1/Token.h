#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <unordered_map>

enum class literal {INTEGER, PLUS, MINUS, MUL, DIV, LPAREN, RPAREN, ID, ASSIGN, BEGIN, END, SEMI, DOT, EOFE};

class Token{
	literal type;
	std::string value;

public:
	Token(literal, std::string);

 	literal get_type();
	std::string get_value();
};

#endif
