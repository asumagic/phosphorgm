#include "ast/ast.hpp"
#include "parser/parser.hpp"

#include <iostream>
#include <iomanip>

int main()
{
	using namespace gmsc;

	std::string source = "hello(--a);";
	/*Lexer lex{source};

	Token t;
	do { // quick and very dirty test
		t = lex.readtok();
		if (t.type == TokenType::End || t.type == TokenType::Undefined)
			break;

		std::cout << "Token(" << t.line << ";" << t.col << ") "
					 "ID #" << std::abs(static_cast<int>(t.type));

		if (!t.value.empty())
			std::cout << ", value '" << t.value << '\'';

		std::cout << std::endl
				  << source << std::endl
				  << std::setw(static_cast<int>(t.col)) << '^' << std::endl;
	} while(t.type != TokenType::End && t.type != TokenType::Undefined);*/

	Parser parser{source};
	parser.parse();
}
