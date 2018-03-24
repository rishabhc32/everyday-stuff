#include <iostream>
#include <cctype>

enum  literal {INTEGER, MUL, PLUS, MINUS, DIV, LPAREN, RPAREN, EOFE};

class Token{
	literal type;
 	int value;

public:
 	Token(literal type, int value){
 		this->type = type;
 		this->value = value;
 	}

 	literal get_type(){
 		return this->type;
 	}

	int get_value(){
		return this->value;
	} 	
 };

class Lexer{
	std::string text;
 	int pos;
 	char current_char;
 public:
	Lexer(std::string text){
 		this->text = text;
 		this->pos = 0;
 		this->current_char = this->text.at(this->pos);
 	}

 	void error(){
		throw std::invalid_argument("Error parsing input");
	}
 	
 	void advance(){
		this->pos++;
		if(this->pos > this->text.length()-1)
			this->current_char = '\0';
		else
			this->current_char = this->text.at(this->pos);
	}

	void skip_whitespace(){
		while(this->current_char!='\0' && this->current_char==' ')
			this->advance();
	}

	int get_integer(){
		std::string result = "";
		while(this->current_char!='\0' && isdigit(this->current_char)){
			result += this->current_char;
			this->advance();
		}
		return stoi(result);
	}

	Token get_next_token();
};


class Tree {
public:
	Token token;
	Tree *left, *right;
	Tree(Token arg): token(arg) {
		this->left = nullptr;
		this->right = nullptr;
	}

	Tree(Tree *left, Token arg, Tree *right): token(arg) {
		this->left = left;
		this->right = right;
	}
};

class Parser {
	Lexer lexer;
	Token current_token;
public:
	Parser(Lexer arg)
		: lexer(arg), current_token(this->lexer.get_next_token()) {}

	void error(){
		throw "Invalid Syntax";
	}

	void eat(literal type) {
		if( this->current_token.get_type() == type )
			this->current_token = lexer.get_next_token();
		else
			this->error();
	}

	Tree *factor() {
		// factor: INTEGER | LPAREN EXPR RPAREN
		Token token = this->current_token;
		if( token.get_type() == INTEGER ) {
			this->eat(INTEGER);
			Tree *t = new Tree(token);
			return t;
		}
		else if(token.get_type() == LPAREN) {
			this->eat(LPAREN);
			Tree *t = this->expr();
			this->eat(RPAREN);
			return t;
		}
	}

	Tree *term() {
		// term: factor ((MUL | DIV) factor)*
		Tree *t = this->factor();

		while(current_token.get_type() == MUL || current_token.get_type() == DIV) {
			Token token = this->current_token;
			if(token.get_type() == MUL)
				this->eat(MUL);
			else if(token.get_type() == DIV)
				this->eat(DIV);

			t = new Tree(t, token, this->factor());
		}

		return t;
	}

	Tree *expr() {
		/*
		expr   : term ((PLUS | MINUS) term)*
        term   : factor ((MUL | DIV) factor)*
        factor : INTEGER | LPAREN expr RPAREN
        */
        Tree *t = this->term();

        while(current_token.get_type() == PLUS || current_token.get_type() == MINUS) {
        	Token token = this->current_token;
        	if(token.get_type() == PLUS)
        		this->eat(PLUS);
        	else if(token.get_type() == MINUS)
        		this->eat(MINUS);

        	t = new Tree(t, token, this->term());
        }

        return t;
	}

	Tree *parse() {
		return this->expr();
	}
};

class Interpreter {
	Parser parser;
public:
	Interpreter(Parser arg): parser(arg){}

	int visit(Tree *t) {
		if(t->token.get_type() == INTEGER)
			return visit_Num(t);
		else 
			return visit_BinOp(t, t->token.get_type());
	}

	int visit_BinOp(Tree *t, literal type) {
		if( type == PLUS )
			return this->visit(t->left) + this->visit(t->right);
		else if( type == MINUS )
			return this->visit(t->left) - this->visit(t->right);
		else if( type == MUL )
			return this->visit(t->left) * this->visit(t->right);
		else if( type == DIV )
			return this->visit(t->left) / this->visit(t->right);
	}

	int visit_Num(Tree *t) {
		return t->token.get_value();
	}

	int interpret() {
		Tree *t = this->parser.parse();
		return this->visit(t);
	}
};


 int main(){
	std:: string input;
	int result;
	while(1){
		std::cout<<"RCalc> ";
		getline(std::cin, input, '\n');

		if(input == "exit" || input=="quit") {
			std::cout<<"Bye!\n";
			return 0;
		}

		Lexer lexer(input);
		Parser parser(lexer);
		Interpreter interpreter(parser);
		int result = interpreter.interpret();

		std::cout<<result<<std::endl;
	}

	return 0;
}

Token Lexer::get_next_token() {
	while(this->current_char != '\0'){
		if( isspace(this->current_char) ){
			this->skip_whitespace();
			continue;
		}

		if( isdigit(this->current_char) )
			return Token(INTEGER, this->get_integer());

		if( this->current_char == '+' ){
			this->advance();
			return Token(PLUS, (int)'+');
		}

		if( this->current_char == '-' ){
			this->advance();
			return Token(MINUS, (int)'-');
		}

		if( this->current_char == '*' ){
			this->advance();
			return Token(MUL, (int)'*');
		}

		if (this->current_char == '/' ){
			this->advance();
			return Token(DIV, (int)'/');
		}

		if(this->current_char == '('){
			this->advance();
			return Token(LPAREN, (int)'(');
		}

		if(this->current_char == ')'){
			this->advance();
			return Token(RPAREN, (int)')');
		}

		this->error();
	}
	return Token(EOFE, (int)'\0');
}
