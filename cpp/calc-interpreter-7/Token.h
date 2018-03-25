#ifndef __TOKEN_H__
#define __TOKEN_H__

enum  literal {INTEGER, MUL, PLUS, MINUS, DIV, LPAREN, RPAREN, EOFE};

class Token{
	literal type;
 	int value;

public:
 	Token(literal type, int value);

 	literal get_type();
 	int get_value();
};

#endif
