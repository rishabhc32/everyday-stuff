#ifndef __PARSER_H__
#define __PARSER_H__

#include <vector>
#include "Lexer.h"
#include "AST.h"

class AST;

class Parser {
	Lexer lexer;
	Token current_token;
public:
	Parser(Lexer arg);

	void error();
	void eat(literal type);

	AST * progrm();
	AST * compound_statement();
	std::vector<AST *> statement_list();
	AST * statement();
	AST * assignment_statement();
	AST * variable();
	AST * empty();
	AST * factor();
	AST * term();
	AST * expr();

	AST *parse();
};

#endif
