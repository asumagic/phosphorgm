#include "lexer.hpp"

#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

namespace gmsc
{
	const std::vector<std::pair<std::string, TokenType>> Lexer::basic_matches // lower index = higher priority
	{
		{"\n", TokenType::LineFeed},

		{"!=", TokenType::NotEqual},
		{"<>", TokenType::NotEqual},
		{"<", TokenType::Inferior},
		{"<=", TokenType::InferiorEqual},
		{">", TokenType::Superior},
		{">=", TokenType::SuperiorEqual},

		{"{", TokenType::BraceLeft},
		{"}", TokenType::BraceRight},
		{"(", TokenType::ParenthesisLeft},
		{")", TokenType::ParenthesisRight},

		{".", TokenType::Dot},
		{",", TokenType::Comma},
		{";", TokenType::Semicolon},

		{"&&", TokenType::LogicAnd},
		{"||", TokenType::LogicOr},
		{"^^", TokenType::LogicXor},

		{"[@", TokenType::AccessorLeftArrayRef},
		{"[|", TokenType::AccessorLeftDSList},
		{"[?", TokenType::AccessorLeftDSMap},
		{"[#", TokenType::AccessorLeftDSGrid},
		{"[", TokenType::AccessorLeftArrayValue},
		{"]", TokenType::AccessorRight},

		{"++", TokenType::Increment},
		{"--", TokenType::Decrement},

		{"+=", TokenType::AssignAdd},
		{"-=", TokenType::AssignSubtract},
		{"*=", TokenType::AssignMultiply},
		{"/=", TokenType::AssignDivide},
		{"&=", TokenType::AssignAnd},
		{"|=", TokenType::AssignOr},
		{"^=", TokenType::AssignXor},

		{"<<=", TokenType::AssignShiftLeft},
		{">>=", TokenType::AssignShiftRight},

		{"==", TokenType::DEqual},
		{"=", TokenType::Equal},

		{"+", TokenType::Plus},
		{"-", TokenType::Minus},
		{"*", TokenType::Multiply},
		{"/", TokenType::Divide},

		{"div", TokenType::EuclDivide},
		{"mod", TokenType::EuclModulo},
		{"%", TokenType::EuclModulo},

		{"&", TokenType::BitAnd},
		{"|", TokenType::BitOr},
		{"^", TokenType::BitXor},

		{"if", TokenType::If},
		{"else if", TokenType::ElseIf},
		{"else", TokenType::Else},

		{"for", TokenType::For},
		{"while", TokenType::While},
		{"do", TokenType::Do},
		{"repeat", TokenType::Repeat},
		{"with", TokenType::With},

		{"var", TokenType::LocalVar}
	};

	Lexer::Lexer(const std::string& source) : _source(source),
		_it(begin(source)) {}

	bool Lexer::is_whitespace(const char c)
	{
		return (c == ' ') || (c == '\t');
	}

	bool Lexer::is_line_end(const char c)
	{
		return (c == '\n') || (c == '\0');
	}

	bool Lexer::is_digit(const char c)
	{
		return (c >= '0') && (c <= '9');
	}

	bool Lexer::is_alpha(const char c)
	{
		return ((c >= 'a') && (c <= 'z')) ||
			   ((c >= 'A') && (c <= 'Z'));
	}

	bool Lexer::is_numeral(const char c)
	{
		return is_digit(c) || (c == '.');
	}

	bool Lexer::is_alphanum(const char c)
	{
		return is_digit(c) || is_alpha(c);
	}

	bool Lexer::is_identifier_begin(const char c)
	{
		return is_alpha(c) || (c == '_');
	}

	bool Lexer::is_identifier(const char c)
	{
		return is_alphanum(c) || (c == '_');
	}

	bool Lexer::eof()
	{
		return _last_char == '\0';
	}

	char Lexer::readchar()
	{
		if (eof())
			throw std::runtime_error("Lexer crash : EOF was not handled (l" + std::to_string(_line) + ")"); // @TODO: cleaner error management

		_last_char = *_it;
		if (_it == end(_source))
			return '\0';

		++_it;

		if (_last_char == '\n')
		{
			++_line;
			_col = 0;
		}
		else
		{
			++_col;
		}


		return _last_char;
	}

	Token Lexer::readtok()
	{
		if (eof())
			return Token{TokenType::End, _line, _col};

		if (_current_parsed)
		{
			readchar();
			if (eof())
				return Token{TokenType::End, _line, _col}; // @TODO less eof checks?
		}
		else
			_current_parsed = true;

		// @TODO return better line&col (for string etc)
		while(is_whitespace(_last_char)) // consume skippable spaces and tabs
		{
			readchar();
			if (eof())
				return Token{TokenType::End, _line, _col};
		}

		size_t tline = _line, tcol = _col;

		if (_last_char == '/') // check for comments
		{
			readchar(); // read the second character
			if (_last_char == '/') // single line comment
			{
				while(!is_line_end(readchar()));
				if (eof())
					return Token{TokenType::End, tline, tcol};
			}
			else if (_last_char == '*') // multi-line comment
			{
				do {
					while (readchar() != '*')
					{
						if (eof())
							return Token{TokenType::End, tline, tcol}; // @todo : warning : multiline comment reachs eof
					}
				} while (readchar() != '/');
				return readtok();
			}
			else
				_current_parsed = false;
		}

		if (_last_char == '\"' || _last_char == '\'') // parse string literals
		{
			char delim = _last_char; // GML supports both "abc" and 'abc' - handle both
			_last_value.clear();

			while (readchar() != delim) // nb : strings can be multiline, don't handle '\n' separately
			{
				if (_last_char == '\\') // '\'
				{
					readchar();
					if (eof())
						return Token{TokenType::End, tline, tcol};
					else if (_last_char == delim)
						_last_value += delim;
					else if (_last_char == 'n')
						_last_value += '\n';
					else if (_last_char == '#')
						_last_value += '#';
					else // not an escape sequence, append the two chars
					{
						_last_value += '\\';
						_last_value += _last_char;
					}
				}
				else if (_last_char == '#') // line feed
					_last_value += '\n';
				else // regular character
					_last_value += _last_char;

			}

			return Token{TokenType::StringLiteral, tline, tcol};
		}

		if (_last_char == '$')
		{
			std::runtime_error("Lexer stub : ColorLiteral");
		}

		std::string peekstr = _source.substr(static_cast<size_t>(_it - begin(_source) - 1), 4);
		for (size_t i = 0; i < basic_matches.size(); ++i)
		{
			if (peekstr.substr(0, basic_matches[i].first.size()) == basic_matches[i].first)
			{
				for (size_t j = 1; j < basic_matches[i].first.size(); ++j)
					readchar();

				return Token{basic_matches[i].second, tline, tcol};
			}
		}

		if (is_numeral(_last_char)) // parse reals
		{
			_last_value.clear();

			do {
				_last_value += _last_char;
			} while (is_numeral(readchar()));
			_current_parsed = false;

			return Token{TokenType::RealLiteral, tline, tcol};
		}

		if (is_identifier_begin(_last_char)) // parse identifiers
		{
			_last_value.clear();

			do {
				_last_value += _last_char;
			} while (is_identifier(readchar()));
			_current_parsed = false;

			return Token{TokenType::Identifier, tline, tcol};
		}

		return Token{TokenType::Undefined, tline, tcol};
	}

	char Lexer::last_char() const
	{
		return _last_char;
	}

	Token Lexer::last_token() const
	{
		return _last_token;
	}

	std::string Lexer::last_value() const
	{
		return _last_value;
	}

	size_t Lexer::line() const
	{
		return _line;
	}

	size_t Lexer::column() const
	{
		return _col;
	}
}
