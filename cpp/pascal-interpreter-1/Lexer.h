#ifndef __LEXER_H__
#define __LEXER_H__

#include "Token.h"

class Lexer{
	std::string text;
 	long unsigned int pos;
 	char current_char;

 public:
	Lexer(std::string text);

 	void error();

 	void advance();
	void skip_whitespace();
	int get_integer();
	char peek();
	
	Token get_next_token();
};

#endif