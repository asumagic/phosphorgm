#include "parser.hpp"
#include "errors.hpp"

#include "../ast/statement.hpp"
#include "../ast/assign.hpp"
#include "../ast/call.hpp"

#include <iostream>

namespace gmsc
{
	Parser::Parser(const std::string str) : _lex(str) {}

	std::shared_ptr<ASTNode> Parser::parse()
	{
		_lex.readtok();
		return parse_statement_block();
	}

	std::shared_ptr<ASTNode> Parser::parse_expression()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		if (_lex.last_token().type == TokenType::Increment)
		{
			if (_lex.readtok().type != TokenType::Identifier)
				throw ParserException{TokenType::Identifier, *this};
			_lex.readtok(); // skip one character

			return std::make_shared<ASTUnopAssign>(ASTAssignUnopType::Increment, false, std::make_shared<ASTVariable>(_lex.last_value()));
		}
		else if (_lex.last_token().type == TokenType::Decrement)
		{
			if (_lex.readtok().type != TokenType::Identifier)
				throw ParserException{TokenType::Identifier, *this};
			_lex.readtok();

			return std::make_shared<ASTUnopAssign>(ASTAssignUnopType::Decrement, false, std::make_shared<ASTVariable>(_lex.last_value()));
		}
		else if (_lex.last_token().type == TokenType::Identifier)
		{
			_lex.readtok();
			if (_lex.last_token().type == TokenType::Increment)
			{
				_lex.readtok();
				return std::make_shared<ASTUnopAssign>(ASTAssignUnopType::Increment, true, std::make_shared<ASTVariable>(_lex.last_value()));
			}
			else if (_lex.last_token().type == TokenType::Decrement)
			{
				_lex.readtok();
				return std::make_shared<ASTUnopAssign>(ASTAssignUnopType::Decrement, true, std::make_shared<ASTVariable>(_lex.last_value()));
			}
			else
			{
				// crash
			}
		}

		// crash.
	}

	std::shared_ptr<ASTNode> Parser::parse_statement_block()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		std::shared_ptr<ASTStatementBlock> block = std::make_shared<ASTStatementBlock>();
		while (true)
		{
			auto statement = std::dynamic_pointer_cast<ASTStatement>(parse_statement());
			if (statement)
				block->append(statement);
			else
				break;
		}

		return block;
	}

	std::shared_ptr<ASTNode> Parser::parse_statement()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		if (_lex.last_token().type == TokenType::Identifier)
		{
			_lex.readtok();

			if (_lex.last_token().type == TokenType::ParenthesisLeft) // function call
				return parse_call();
			else if (_lex.last_token().is_assign()) // Assignment - @TODO handle +=, -= etc, ++, --
				return parse_assign();
			else if (_lex.last_token().type == TokenType::Dot) // object property access
			{
				/*_lex.readtok();
				if (top_context().tok.type == TokenType::Identifier)
				{
					push_context();
					if (top_context().tok.is_assign())
						parse_instance_assign();
				}
				else
				{
					throw ParserException{TokenType::Identifier, *this};
				}*/
			}
			else
			{
				throw ParserException{TokenType::Undefined, *this}; // @TODO define
			}
		}
		else if (_lex.last_token().type == TokenType::ParenthesisLeft) // parse expression
		{

		}

		return std::shared_ptr<ASTNode>{};
	}

	std::shared_ptr<ASTNode> Parser::parse_call()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		const std::string function_name = _lex.last_value();
		std::shared_ptr<ASTNode> call = std::make_shared<ASTCallStatement>(function_name);

		while (true) // parse all arguments
		{
			_lex.readtok(); // skip '(' too
			parse_expression();
			if (_lex.last_token().type != TokenType::Comma)
				break;
		}

		if (_lex.last_token().type != TokenType::ParenthesisRight)
			throw ParserException{TokenType::ParenthesisRight, *this};

		return call;
	}

	std::shared_ptr<ASTNode> Parser::parse_assign()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	std::shared_ptr<ASTNode> Parser::parse_instance_assign()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
}
