#include "parser.hpp"

namespace gmsc
{
	Parser::Parser(const std::string str) : _lex(str) {}

	std::unique_ptr<ASTNode> Parser::parse()
	{
		_lex.readtok();
		return parse_statement();
	}

	std::unique_ptr<ASTNode> Parser::parse_statement_block()
	{
		// @TODO
	}

	std::unique_ptr<ASTNode> Parser::parse_statement()
	{
		if (_lex.last_token().type() == TokenType::Identifier)
		{
			const std::string id = _lex.last_value();
			TokenType ntype = _lex.readtok().type();

			if (ntype == TokenType::ParenthesisLeft) // function call
				return parse_call();
			else if (_lex.last_token().is_assign()) // Assignment - @TODO handle +=, -= etc
				return parse_assign();
			else if (ntype == TokenType::Dot) // object property access
			{
				Token accessed = _lex.readtok();
				if (accessed.type() == TokenType::Identifier)
				{

				}
				else
				{
					// compile error
				}
			}
			else
			{
				// crash
			}
		}
	}

	std::unique_ptr<ASTNode> Parser::parse_call()
	{

	}

	std::unique_ptr<ASTNode> Parser::parse_assign()
	{

	}
}
