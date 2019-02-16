#include <string>
#include "Token.h"
#include "Interpreter.h"

Interpreter::Interpreter(Parser arg): parser(arg){}

int Interpreter::visit(Num &node) {
	return node.token.get_value();
}

int Interpreter::visit(BinOp &node) {
	literal type = node.token.get_type();

	switch(type) {
		case PLUS:
			return 
				node.left->visit(*this) + node.right->visit(*this);

		case MINUS:
			return 
				node.left->visit(*this) - node.right->visit(*this);

		case MUL:
			return 
				node.left->visit(*this) * node.right->visit(*this);

		case DIV:
			return 
				node.left->visit(*this) / node.right->visit(*this);

	}
}

int Interpreter::visit(UnaryOp &node) {
	literal type = node.token.get_type();

	if(type == PLUS) 
		return +node.expr->visit(*this);
	else if(type == MINUS)
		return -node.expr->visit(*this);
}

int Interpreter::interpret() {
	AST* tree = this->parser.parse();
	return tree->visit(*this);
}
