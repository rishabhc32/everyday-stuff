#include "Token.h"

Token::Token(literal type, int value) {
 	this->type = type;
 	this->value = value;
}

literal Token::get_type() {
 	return this->type;
}

int Token::get_value() {
	return this->value;
} 	
