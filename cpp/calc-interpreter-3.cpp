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

class Interpreter{
	std::string text;
	Token current_token;
	char current_char;
	int pos;

public:
	Interpreter(std::string text){
		this->text = text;
		this->pos = 0;
		this->current_char = this->text.at(this->pos);
	}

	void error(){
		throw std::invalid_argument("Error parsing input");
	}

	void eat(std::string type){
		if( this->current_token.get_type() == type )
			this->current_token = this->get_next_token();
		else
			this->error();
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
	int term();
	int expr();
};

Token Interpreter::get_next_token(){
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

		if (this->current_char == '-' ){
			this->advance();
			return Token("MINUS", (int)'-');
		}
	}
}

int Interpreter::term(){
	Token token = this->current_token;
	this->eat("INTEGER");
	return token.get_value();
}

int Interpreter::expr(){
	this->current_token = this->get_next_token();

	int result = this->term();
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

int main(){
	std:: string input;
	int result;
	while(1){
		std::cout<<"RCalc> ";
		getline(std::cin, input, '\n');

		Interpreter interpreter(input);
		result = interpreter.expr();

		std::cout<<result<<std::endl;
	}

	return 0;
}