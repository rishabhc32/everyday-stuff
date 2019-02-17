#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

#include "Parser.h"

class NodeVisitor {
public:
	virtual void visit(Compound &) = 0;
	virtual int visit(Num &) = 0;
	virtual int visit(BinOp &) = 0;
	virtual int visit(UnaryOp &) = 0;
};

class Interpreter: public NodeVisitor {
	Parser parser;

public:
	Interpreter(Parser arg);
	int interpret();

	void visit(Compound &) override;
	int visit(Num &) override;
	int visit(BinOp &) override;
	int visit(UnaryOp &) override;
};

#endif
