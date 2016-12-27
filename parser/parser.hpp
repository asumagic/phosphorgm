#ifndef PARSER_HPP
#define PARSER_HPP

#include <functional>
#include "../ast/ast.hpp"
#include "lexer.hpp"

namespace gmsc
{
	class Parser
	{
		Lexer _lex;

	public:
		Parser(const std::string str); // @TODO string iterators constructor

		std::unique_ptr<ASTNode> parse();
		std::unique_ptr<ASTNode> parse_statement_block();
		std::unique_ptr<ASTNode> parse_statement();
		std::unique_ptr<ASTNode> parse_call();
		std::unique_ptr<ASTNode> parse_assign();
	};
}

#endif // PARSER_HPP
