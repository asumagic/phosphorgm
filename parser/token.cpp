#include "token.hpp"

namespace gmsc
{
	Token::Token(const TokenType type, size_t line, size_t col) : line(line), col(col), type(type) {}

	bool Token::is_assign() const
	{
		return (type == TokenType::Equal) ||
			   ((static_cast<int>(type) >= static_cast<int>(TokenType::AssignAdd)) &&
				(static_cast<int>(type) <= static_cast<int>(TokenType::AssignShiftRight)));
	}
}
