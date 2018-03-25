#include <string>
#include "Token.h"
#include "Parser.h"

/* -------------Tree Class-----------------------*/
Tree::Tree(Token arg): token(arg) {
	this->left = nullptr;
	this->right = nullptr;
}

Tree::Tree(Tree *left, Token arg, Tree *right): token(arg) {
	this->left = left;
	this->right = right;
}

/* -------------Parser Class-----------------------*/
Parser::Parser(Lexer arg)
	: lexer(arg), current_token(this->lexer.get_next_token()) {}

void Parser::error(){
	throw "Invalid Syntax";
}

void Parser::eat(literal type) {
	if( this->current_token.get_type() == type )
		this->current_token = lexer.get_next_token();
	else
		this->error();
}

Tree* Parser::factor() {
	// factor: INTEGER | LPAREN EXPR RPAREN
	Token token = this->current_token;
	if( token.get_type() == INTEGER ) {
		this->eat(INTEGER);
		Tree *t = new Tree(token);
		return t;
	}
	else if(token.get_type() == LPAREN) {
		this->eat(LPAREN);
		Tree *t = this->expr();
		this->eat(RPAREN);
		return t;
	}
}

Tree* Parser::term() {
	// term: factor ((MUL | DIV) factor)*
	Tree *t = this->factor();

	while(current_token.get_type() == MUL || current_token.get_type() == DIV) {
		Token token = this->current_token;
		if(token.get_type() == MUL)
			this->eat(MUL);
		else if(token.get_type() == DIV)
			this->eat(DIV);

		t = new Tree(t, token, this->factor());
	}

	return t;
}

Tree* Parser::expr() {
	/*
	expr   : term ((PLUS | MINUS) term)*
    term   : factor ((MUL | DIV) factor)*
    factor : INTEGER | LPAREN expr RPAREN
    */
	Tree *t = this->term();

    while(current_token.get_type() == PLUS || current_token.get_type() == MINUS) {
       	Token token = this->current_token;
       	if(token.get_type() == PLUS)
       		this->eat(PLUS);
       	else if(token.get_type() == MINUS)
       		this->eat(MINUS);

       	t = new Tree(t, token, this->term());
    }

    return t;
}

Tree* Parser::parse() {
	return this->expr();
}
