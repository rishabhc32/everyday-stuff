#ifndef __AST_H__
#define __AST_H__

#include "Token.h"
#include <vector>

class Interpreter;

class AST {
public:
	virtual int visit(Interpreter &) = 0;
};

class Compound: public AST {
public:
	std::vector<AST *> children;

	int visit(Interpreter &) override;

};

class Assign: public AST {
public:
	AST *left;
	Token token;
	AST *right;

	int visit(Interpreter &) override;
};

class Var: public AST {
public:
	Token token;

};

class NoOp: public AST {

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

#endif
