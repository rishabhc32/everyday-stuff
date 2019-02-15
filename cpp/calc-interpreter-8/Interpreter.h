#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__
#include "Parser.h"

class NodeVisitor {
public:
	virtual void visit(const Num &) = 0;
	virtual void visit(const BinOp &) = 0;
	virtual void visit(const UnaryOp &) = 0;
};

class Interpreter {
	Parser parser;
public:
	Interpreter(Parser arg);

	int visit(AST *);
	
	int visit_BinOp(AST *, literal);
	int visit_Num(AST *);
	
	int interpret();
};

#endif
