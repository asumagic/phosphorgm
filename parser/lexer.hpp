#ifndef LEXER_HPP
#define LEXER_HPP

#include "../ast/ast.hpp"
#include "token.hpp"

namespace gmsc
{
    class Lexer
    {
		static const std::vector<std::pair<std::string, TokenType>> basic_matches;
		const std::string& _source;

		std::string _last_value;
		char _last_char = ' ';
		Token _last_token;

		size_t _line = 0, _col = 0;
		typedef std::string::const_iterator sit_t;
		sit_t _it;

		bool _current_parsed = false;

		bool is_whitespace(const char c); // '\t' or ' '
		bool is_line_end(const char c); // '\n' or EOF

		bool is_digit(const char c); // 0-9
		bool is_alpha(const char c); // a-z and A-Z

		bool is_numeral(const char c); // 0-9 and '.'
		bool is_alphanum(const char c); // 0-9 and a-z and A-Z

		bool is_identifier_begin(const char c); // a-z and A-Z and '_'
		bool is_identifier(const char c); // 0-9 and a-z and A-Z and '_'

		bool eof(); // returns whether _last_char == eof
public:
		char readchar(); // gets one character
		Token readtok();

	public:
		Lexer(const std::string& source);

		char last_char() const;
		Token last_token() const;
		std::string last_value() const; // includes literals as well

		size_t line() const;
		size_t column() const;
    };
}

#endif // LEXER_HPP
