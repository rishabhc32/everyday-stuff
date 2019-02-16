#ifndef __PARSER_H__
#define __PARSER_H__
#include "Lexer.h"

class Interpreter;

class AST {
public:
	virtual int visit(Interpreter &) = 0;
};

class Num: public AST {
public:
	Token token;

	Num(Token);
	int visit(Interpreter &) override;
};

class BinOp: public AST {
public:
	AST *left, *right;
	Token token;

	BinOp(AST*, Token, AST*);
	int visit(Interpreter &) override;
};

class UnaryOp: public AST {
public:
	AST* expr;
	Token token;

	UnaryOp(Token, AST*);
	int visit(Interpreter &) override;
};

class Parser {
	Lexer lexer;
	Token current_token;
public:
	Parser(Lexer arg);

	void error();
	void eat(literal type);

	AST *factor();
	AST *term();
	AST *expr();

	AST *parse();
};

#endif
