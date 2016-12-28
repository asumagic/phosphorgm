#include "errors.hpp"

#include <sstream>

namespace gmsc
{
	LexerException::LexerException(const std::string detail, const size_t line, const size_t col)
	{
		std::ostringstream ss;
		ss << "Lexer error (" << line << "," << col << ") : " << detail;
		_detail = ss.str();
	}

	const char* LexerException::what() const noexcept
	{
		return _detail.c_str();
	}

	ParserException::ParserException(TokenType expected, Parser& parser)
	{
		std::ostringstream ss;
		//ss << "Parser error (" << ctx.tok.line << "," << ctx.tok.col << ") : Expected \"" << static_cast<size_t>(expected) << "\", got \"" << static_cast<size_t>(ctx.tok.type) << "\"";
		_detail = ss.str();
	}

	const char* ParserException::what() const noexcept
	{
		return _detail.c_str();
	}
}
