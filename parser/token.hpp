#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <cstddef> // special int types
#include <string>

namespace gmsc
{
	enum class TokenType
	{
		// >0 : unrecognized char

		Undefined = 0,

		End,

		BraceLeft, // '{'
		BraceRight, // '}'

		ParenthesisLeft, // '('
		ParenthesisRight, // ')'

		Comma, // ','
		Dot, // '.'
		Semicolon, // ';'

		Identifier,

		StringLiteral,
		RealLiteral,
		IntegerLiteral,
		ColorLiteral, // Hex literal - $BBGGRR

		AccessorLeftArrayValue, // '['
		AccessorLeftArrayRef, // '[@'
		AccessorLeftDSList, // '[|'
		AccessorLeftDSMap, // '[?'
		AccessorLeftDSGrid, // '[#'
		AccessorRight, // ']'

		If, // 'if'
		Else, // 'else'
		ElseIf, // 'else if'

		For, // 'for'
		While, // 'while'
		Do, // 'do'
		Repeat, // 'repeat'
		With, // 'with'

		Equal, // '='
		DEqual, // '=='
		NotEqual, // '<>' and '!='
		Inferior, // '<'
		InferiorEqual, // '<='
		Superior, // '>'
		SuperiorEqual, // '>='

		Plus, // '+'
		Minus, // '-'
		Multiply, // '*'
		Divide, // '/'

		EuclDivide, // 'div'
		EuclModulo, // 'mod' and '%'

		BitAnd, // '&'
		BitOr, // '|'
		BitXor, // '^'
		BitShiftLeft, // '<<'
		BitShiftRight, // '>>'

		LogicAnd, // '&&'
		LogicOr, // '||'
		LogicXor, // '^^'

		AssignAdd, // '+='
		AssignSubtract, // '-='
		AssignMultiply, // '*='
		AssignDivide, // '/='

		AssignAnd, // '&='
		AssignOr, // '|='
		AssignXor, // '^='
		AssignShiftLeft, // '<<='
		AssignShiftRight, // '>>='

		Increment, // '++'
		Decrement, // '--'

		LineFeed, // '\n'

		LocalVar, // 'var'
	};

	struct Token
    {
		Token() = default;
		Token(const TokenType type, size_t line = 0, size_t col = 0);

		size_t line, col;
		TokenType type;

		bool is_assign() const;
    };
}

#endif // TOKEN_HPP
