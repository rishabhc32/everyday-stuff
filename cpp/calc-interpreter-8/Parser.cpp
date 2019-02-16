#include <string>
#include "Token.h"
#include "Parser.h"
#include "Interpreter.h"

/* -------------Num Class-----------------------*/
Num::Num(Token arg_token)
	: token(arg_token) {}

int Num::visit(Interpreter &interpreter) {
	return interpreter.visit(*this);
}

/* -------------BinOp Class-----------------------*/
BinOp::BinOp(AST *left, Token arg_token, AST *right)
	: token(arg_token) {
	this->token = arg_token;
	this->left = left;
	this->right = right;
}

int BinOp::visit(Interpreter &interpreter) {
	return interpreter.visit(*this);
}

/* -------------UnaryOp Class-----------------------*/
UnaryOp::UnaryOp(Token arg_token, AST *expr)
	: token(arg_token) {
	this->token = arg_token;
	this->expr = expr;
}

int UnaryOp::visit(Interpreter &interpreter) {
	return interpreter.visit(*this);
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

AST* Parser::factor() {
	// factor : (PLUS | MINUS) factor | INTEGER | LPAREN expr RPAREN"
	Token token = this->current_token;

	AST *node = nullptr;

	switch(token.get_type()) {
		case PLUS:
			this->eat(PLUS);
			node = new UnaryOp(token, this->factor());
			break;
		
		case MINUS:
			this->eat(MINUS);
			node = new UnaryOp(token, this->factor());
			break;

		case INTEGER:
			this->eat(INTEGER);
			node = new Num(token);
			break;
		
		case LPAREN:
			this->eat(LPAREN);
			node = this->expr();
			this->eat(RPAREN);
			break;

		default: 
			this->error();
	}

	return node;
}

AST* Parser::term() {
	// term: factor ((MUL | DIV) factor)*
	AST *node = this->factor();

	while(current_token.get_type() == MUL || current_token.get_type() == DIV) {
		Token token = this->current_token;
		if(token.get_type() == MUL)
			this->eat(MUL);
		else if(token.get_type() == DIV)
			this->eat(DIV);

		node = new BinOp(node, token, this->factor());
	}

	return node;
}

AST* Parser::expr() {
	/*
	expr   : term ((PLUS | MINUS) term)*
    term   : factor ((MUL | DIV) factor)*
    factor : INTEGER | LPAREN expr RPAREN
    */
	AST *node = this->term();

    while(current_token.get_type() == PLUS || current_token.get_type() == MINUS) {
       	Token token = this->current_token;
       	
		if(token.get_type() == PLUS)
       		this->eat(PLUS);
       	else if(token.get_type() == MINUS)
       		this->eat(MINUS);

       	node = new BinOp(node, token, this->term());
    }

    return node;
}

AST* Parser::parse() {
	AST *node = this->expr();
	
	if(this->current_token.get_type() != EOFE)
		this->error();
	
	return node;
}
