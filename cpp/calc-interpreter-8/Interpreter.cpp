#include <string>
#include "Token.h"
#include "Interpreter.h"

Interpreter::Interpreter(Parser arg): parser(arg){}

int Interpreter::visit(AST *t) {
	if(t->token.get_type() == INTEGER)
		return visit_Num(t);
	else 
		return visit_BinOp(t, t->token.get_type());
}

int Interpreter::visit_BinOp(AST *t, literal type) {
	if( type == PLUS )
		return this->visit(t->left) + this->visit(t->right);
	else if( type == MINUS )
		return this->visit(t->left) - this->visit(t->right);
	else if( type == MUL )
		return this->visit(t->left) * this->visit(t->right);
	else if( type == DIV )
		return this->visit(t->left) / this->visit(t->right);
}

int Interpreter::visit_Num(AST *t) {
	return t->token.get_value();
}

int Interpreter::interpret() {
	AST *t = this->parser.parse();
	return this->visit(t);
}
