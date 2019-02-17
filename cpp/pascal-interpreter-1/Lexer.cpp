#include <stdexcept>
#include <string>
#include <cctype>
#include "Token.h"
#include "Lexer.h"

Lexer::Lexer(std::string text) {
 	this->text = text;
 	this->pos = 0;
 	this->current_char = this->text.at(this->pos);
}

void Lexer::error() {
	throw "Error parsing input";
}
 	
void Lexer::advance() {
	this->pos++;
	if(this->pos > this->text.length()-1)
		this->current_char = '\0';
	else
		this->current_char = this->text.at(this->pos);
}

void Lexer::skip_whitespace() {
	while(this->current_char!='\0' && this->current_char==' ')
		this->advance();
}

std::string Lexer::get_integer() {
	std::string result = "";
	while(this->current_char!='\0' && isdigit(this->current_char)){
		result += this->current_char;
		this->advance();
	}

	return result;
}

char Lexer::peek() {
	long unsigned peek_pos = this->pos + 1;

	if( peek_pos > this->text.length()-1 )
		return '\0';
	
	return this->text.at(peek_pos);
}

Token Lexer::get_next_token() {
	while(this->current_char != '\0') {
		if( isspace(this->current_char) ) {
			this->skip_whitespace();
			continue;
		}

		if(isalpha(this->current_char)) {
			return this->_id();
		}

		if( isdigit(this->current_char) ) {
			return Token(literal::INTEGER, this->get_integer());
		}
		
		if(this->current_char == ':' && this->peek() == '=') {
			this->advance();
			this->advance();
			return Token(literal::ASSIGN, ":=");
		}

		if(this->current_char == ';') {
			this->advance();
			return Token(literal::SEMI, ";");
		}

		if( this->current_char == '+' ) {
			this->advance();
			return Token(literal::PLUS, "+");
		}

		if( this->current_char == '-' ) {
			this->advance();
			return Token(literal::MINUS, "-");
		}

		if( this->current_char == '*' ) {
			this->advance();
			return Token(literal::MUL, "*");
		}

		if (this->current_char == '/' ) {
			this->advance();
			return Token(literal::DIV, "/");
		}

		if(this->current_char == '(') {
			this->advance();
			return Token(literal::LPAREN, "(");
		}

		if(this->current_char == ')') {
			this->advance();
			return Token(literal::RPAREN, ")");
		}

		if(this->current_char == '.') {
			this->advance();
			return Token(literal::DOT, ".");
		}

		this->error();
	}

	return Token(literal::EOFE, "\0");
}

Token Lexer::_id() {
	std::string result = "";

	while( this->current_char != '\0' && isalnum(this->current_char ) ) {
		result += this->current_char;
		this->advance();
	}

	if(result == "BEGIN") {
		return Token(literal::BEGIN, "BEGIN");
	} 
	
	if(result == "END") {
		return Token(literal::END, "BEGIN");
	}

	return Token(literal::ID, result);
}
