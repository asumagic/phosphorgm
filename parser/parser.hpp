#ifndef PARSER_HPP
#define PARSER_HPP

#include <functional>
#include <stack>
#include "../ast/ast.hpp"
#include "lexer.hpp"

namespace gmsc
{
	class Parser
	{
		Lexer _lex;

	public:
		Parser(const std::string str); // @TODO string iterators constructor

		std::shared_ptr<ASTNode> parse();
		std::shared_ptr<ASTNode> parse_expression(); // Parse an expression ('a + b', '6 * 7', ...)
		std::shared_ptr<ASTNode> parse_statement_block(); // Parse a statement block ('{}', 'hello(); world();', '{hey(); heyo();}')
		std::shared_ptr<ASTNode> parse_statement(); // Parse a single statement ('a = 7', 'hello();', 'if(i == 0) { ... }'
		std::shared_ptr<ASTNode> parse_call(); // Parse a function call ('hello(arg1, arg2, arg3)')
		std::shared_ptr<ASTNode> parse_assign(); // Parse a variable assignment ('a = 3', 'somenumber = 5')
		std::shared_ptr<ASTNode> parse_instance_assign(); // Parse a global variable assignment ('global.n = 8', 'my_object.value = "hello"')
	};
}

#endif // PARSER_HPP
