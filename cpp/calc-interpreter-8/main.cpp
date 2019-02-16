#include <iostream>
#include "Interpreter.h"

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
		else if(input == "")
			continue;

		try {
			Lexer lexer(input);
			Parser parser(lexer);
			Interpreter interpreter(parser);
			
			result = interpreter.interpret();
			std::cout<<result<<std::endl;
		}
		catch(char const *mssg) {
			std::cout<<"Invalid Syntax\n";
		}
	}

	return 0;
}
