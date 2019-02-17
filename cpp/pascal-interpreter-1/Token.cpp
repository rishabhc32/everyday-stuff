#include "Token.h"

Token::Token(literal type, std::string value) {
	this->type = type;
	this->value = value;
}

literal Token::get_type() {
 	return this->type;
}

std::string Token::get_value() {
	return this->value;
}
