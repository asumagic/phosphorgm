#include "token.hpp"

namespace gmsc
{
Token::Token(const TokenType type, size_t line, size_t col) : _line(line), _col(col), _type(type) {}

	bool Token::is_assign() const
	{
		return (_type == TokenType::Equal) ||
			   ((static_cast<int>(_type) >= static_cast<int>(TokenType::AssignAdd)) &&
				(static_cast<int>(_type) <= static_cast<int>(TokenType::AssignShiftRight)));
	}

	TokenType Token::type() const
	{
		return _type;
	}

	size_t Token::line() const
	{
		return _line;
	}

	size_t Token::column() const
	{
		return _col;
	}
}
