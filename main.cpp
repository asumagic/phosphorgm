#include "ast/ast.hpp"
#include "parser/parser.hpp"

#include <iostream>
#include <iomanip>

int main()
{
	using namespace gmsc;

	std::string source = "global.thing = a";
	Lexer lex{source};

	Token t;
	do { // quick and very dirty test
		t = lex.readtok();
		if (t.type() == TokenType::End || t.type() == TokenType::Undefined)
			break;

		std::cout << "Token(" << t.line() << ";" << t.column() << ") "
					 "ID #" << std::abs(static_cast<int>(t.type()));

		const std::string val = lex.last_value();
		if (!val.empty())
			std::cout << ", value '" << lex.last_value() << '\'';

		std::cout << std::endl
				  << source << std::endl
				  << std::setw(static_cast<int>(t.column())) << '^' << std::endl;
	} while(t.type() != TokenType::End && t.type() != TokenType::Undefined);
}
