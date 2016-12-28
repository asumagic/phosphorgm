#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <stdexcept>
#include <string>
#include "token.hpp"
#include "parser.hpp"

namespace gmsc
{
	class LexerException : public std::exception
	{
		std::string _detail;

	public:
		LexerException(const std::string detail, const size_t line, const size_t col);
		virtual char const* what() const noexcept override;
	};

	class ParserException : public std::exception
	{
		std::string _detail;

	public:
		ParserException(TokenType expected, Parser& parser);
		virtual char const* what() const noexcept override;
	};
}

#endif // ERRORS_HPP
