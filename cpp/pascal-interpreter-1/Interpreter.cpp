#include <string>
#include "Token.h"
#include "Interpreter.h"

Interpreter::Interpreter(Parser arg): parser(arg){}

int Interpreter::visit(Num &node) {
	return node.token.get_value();
}

void Interpreter::visit(Compound &node) {
	for(AST *child : node.children) {
		child->visit(*this);
	}
}

int Interpreter::visit(BinOp &node) {
	literal type = node.token.get_type();

	switch(type) {
		case literal::PLUS:
			return 
				node.left->visit(*this) + node.right->visit(*this);

		case literal::MINUS:
			return 
				node.left->visit(*this) - node.right->visit(*this);

		case literal::MUL:
			return 
				node.left->visit(*this) * node.right->visit(*this);

		case literal::DIV:
			return 
				node.left->visit(*this) / node.right->visit(*this);

	}
}

int Interpreter::visit(UnaryOp &node) {
	literal type = node.token.get_type();

	if(type == literal::PLUS) 
		return +node.expr->visit(*this);
	else if(type == literal::MINUS)
		return -node.expr->visit(*this);
}

int Interpreter::interpret() {
	AST* tree = this->parser.parse();
	return tree->visit(*this);
}
