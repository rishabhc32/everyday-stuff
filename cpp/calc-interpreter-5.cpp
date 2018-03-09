#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

class Token{
	std::string type;
 	int value;

public:
	Token(){
		this->type = "";
	}

 	Token(std::string type, int value){
 		this->type = type;
 		this->value = value;
 	}

 	std::string get_type(){
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

class Interpreter{
	Token current_token;
	Lexer lexer;

public:
	Interpreter(Lexer arg): lexer(arg){
		this->current_token = this->lexer.get_next_token();
	}

	void error(){
		throw std::invalid_argument("Error parsing input");
	}

	void eat(std::string type){
		if( this->current_token.get_type() == type )
			this->current_token = this->lexer.get_next_token();
		else
			this->error();
	}
	
	int factor(){
		Token token = this->current_token;
		this->eat("INTEGER");
		return token.get_value();
	}

	long term();
	long expr();
};

int main(){
	std:: string input;
	int result;
	while(1){
		std::cout<<"RCalc> ";
		getline(std::cin, input, '\n');

		if(input == "exit" || input=="quit")
			return 0;	

		try{
			Lexer lexer(input);
			Interpreter interpreter(lexer);
			result = interpreter.expr();
		}
		catch(const std::invalid_argument& ia){
			std::cerr<<"Abort: "<<ia.what()<<std::endl;
			return -1;
		}

		std::cout<<result<<std::endl;
	}

	return 0;
}

Token Lexer::get_next_token(){
	while(this->current_char != '\0'){
		if( isspace(this->current_char) ){
			this->skip_whitespace();
			continue;
		}

		if( isdigit(this->current_char) )
			return Token("INTEGER", this->get_integer());

		if( this->current_char == '+' ){
			this->advance();
			return Token("PLUS", (int)'+');
		}

		if( this->current_char == '-' ){
			this->advance();
			return Token("MINUS", (int)'-');
		}

		if( this->current_char == '*' ){
			this->advance();
			return Token("MUL", (int)'*');
		}

		if (this->current_char == '/' ){
			this->advance();
			return Token("DIV", (int)'/');
		}

		this->error();
	}
	return Token("EOF", (int)'\0');
}

long Interpreter::term(){
	long result = this->factor();

	while(this->current_token.get_type()=="MUL" || this->current_token.get_type()=="DIV"){
		Token token = this->current_token;
		if(token.get_type() == "MUL"){
			this->eat("MUL");
			result = result * this->factor();
		}
		else if(token.get_type() == "DIV"){
			this->eat("DIV");
			result = result / this->factor();
		}
	}
	return result;
}

long Interpreter::expr(){
	long result = this->term();

	while(this->current_token.get_type()=="PLUS" || this->current_token.get_type()=="MINUS"){
		Token token = this->current_token;
		if(token.get_type() == "PLUS"){
			this->eat("PLUS");
			result = result + this->term();
		}
		else if(token.get_type() == "MINUS"){
			this->eat("MINUS");
			result = result - this->term();
		}
	}
	return result;
}
