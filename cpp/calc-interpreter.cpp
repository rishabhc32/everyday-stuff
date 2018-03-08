#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

 class Token{
 	std::string type;
 	char value;

public:
	Token(){
		this->type = "";
	}

 	Token(std::string type, char value){
 		this->type = type;
 		this->value = value;
 	}

 	std::string get_type(){
 		return this->type;
 	}

	char get_value(){
		return this->value;
	} 	
 };

class Interpreter{
	std::string text;
	Token current_token;
	int pos;

public:
	Interpreter(std::string text){
		this->text = text;
		this->pos = 0;
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

	Token get_next_token();
	int expr();
};

Token Interpreter::get_next_token(){
	std::string text = this->text;

	if(this->pos > this->text.length()-1)
		return Token("EOF", '\0');

	char current_char = text.at(this->pos);

	if( isdigit(current_char) ){
		Token token("INTEGER", current_char);
		this->pos++;
		return token;
	}

	if( current_char == '+' ){
		Token token("PLUS", '+');
		this->pos++;
		return token;
	}

	this->error();
}


int Interpreter::expr(){
	this->current_token = this->get_next_token();

	Token left = this->current_token;
	this->eat("INTEGER");

	this->eat("PLUS");

	Token right = this->current_token;
	this->eat("INTEGER");

	return (left.get_value()-'0') + (right.get_value()-'0');
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