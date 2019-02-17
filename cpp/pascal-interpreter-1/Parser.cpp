#include <string>
#include "Token.h"
#include "Parser.h"
#include "Interpreter.h"

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

AST* Parser::progrm() {
	// program: compound_statement DOT
	AST *node = this->compound_statement();
	this->eat(DOT);
	return node;
}

AST* Parser::compound_statement() {
	// compound_statement: BEGIN statement_list END
	this->eat(BEGIN);
	std::vector<AST *> nodes = this->statement_list();
	this->eat(END);

	Compound *root = new Compound();  
	root->children = nodes;

	return root;
}

std::vector<AST *> Parser::statement_list() {
	/*
	statement_list : statement
                   | statement SEMI statement_list
	*/
	AST *node = this->statement();
	std::vector<AST *> results = {node};

	while(this->current_token.get_type() == SEMI ) {
		this->eat(SEMI);
		results.push_back(this->statement());
	}

	if(this->current_token.get_type() == ID) 
		this->error();
	
	return results;
}

AST* Parser::statement() {
	/*
	statement : compound_statement
              | assignment_statement
              | empty
	*/
	literal type = this->current_token.get_type();
	AST *node = nullptr;

	if(type == BEGIN) 
		node = this->compound_statement();
	else if(type == ID)
		node = this->assignment_statement();
	else 
		node = this->empty();
	
	return node;
}

AST* Parser::assignment_statement() {
	// assignment_statement : variable ASSIGN expr
	AST *left = this->variable();
	Token token = this->current_token;
	
	this->eat(ASSIGN);

	AST *right = this->expr();
	AST *node = new Assign(left, token, right);

	return node;
}
AST* Parser::variable() {
	// variable: ID
	AST *node = new Var(this->current_token);
	this->eat(ID);

	return node;
}

AST* Parser::empty() {
	return new NoOp();
}

AST* Parser::factor() {
	/*
	factor : PLUS  factor
              | MINUS factor
              | INTEGER
              | LPAREN expr RPAREN
              | variable
	*/
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
			node = this->variable();
			break;
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
	AST *node = this->progrm();
	
	if(this->current_token.get_type() != EOFE)
		this->error();
	
	return node;
}
