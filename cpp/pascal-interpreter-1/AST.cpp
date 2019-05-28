#include "AST.h"
#include "Interpreter.h"

/* -------------Compound Class-----------------------*/
Compound::visit

/* -------------Assign Class-----------------------*/
Assign::Assign(AST *left, Token arg_token, AST *right)
	: token(arg_token) {
	this->left = left;
	this->right = right;	
}

/* -------------Var Class-----------------------*/
Var::Var(Token arg_token): token(arg_token) {}

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
