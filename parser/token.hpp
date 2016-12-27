#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <cstddef> // special int types

namespace gmsc
{
	enum class TokenType
	{
		// >0 : unrecognized char

		Undefined = 0,

		End = -1,

		BraceLeft = -2, // '{'
		BraceRight = -3, // '}'

		ParenthesisLeft = -4, // '('
		ParenthesisRight = -5, // ')'

		Comma = -6, // ','
		Dot = -7, // '.'
		Semicolon = -8, // ';'

		Identifier = -9,

		StringLiteral = -10,
		RealLiteral = -11,
		IntegerLiteral = -12,
		ColorLiteral = -13, // Hex literal - $BBGGRR

		AccessorLeftArrayValue = -14, // '['
		AccessorLeftArrayRef = -15, // '[@'
		AccessorLeftDSList = -16, // '[|'
		AccessorLeftDSMap = -17, // '[?'
		AccessorLeftDSGrid = -18, // '[#'
		AccessorRight = -19, // ']'

		If = -20, // 'if'
		Else = -21, // 'else'
		ElseIf = -22, // 'else if'

		For = -23, // 'for'
		While = -24, // 'while'
		Do = -25, // 'do'
		Repeat = -26, // 'repeat'
		With = -27, // 'with'

		Equal = -28, // '='
		DEqual = -29, // '=='
		NotEqual = -30, // '<>' and '!='
		Inferior = -31, // '<'
		InferiorEqual = -32, // '<='
		Superior = -33, // '>'
		SuperiorEqual = -34, // '>='

		Plus = -35, // '+'
		Minus = -36, // '-'
		Multiply = -37, // '*'
		Divide = -38, // '/'

		EuclDivide = -39, // 'div'
		EuclModulo = -40, // 'mod' and '%'

		BitAnd = -41, // '&'
		BitOr = -42, // '|'
		BitXor = -43, // '^'
		BitShiftLeft = -44, // '<<'
		BitShiftRight = -45, // '>>'

		LogicAnd = -46, // '&&'
		LogicOr = -47, // '||'
		LogicXor = -48, // '^^'

		AssignAdd = -49, // '+='
		AssignSubtract = -50, // '-='
		AssignMultiply = -51, // '*='
		AssignDivide = -52, // '/='

		AssignAnd = -53, // '&='
		AssignOr = -54, // '|='
		AssignXor = -55, // '^='
		AssignShiftLeft = -56, // '<<='
		AssignShiftRight = -57, // '>>='

		Increment = -58, // '++'
		Decrement = -59, // '--'

		LineFeed = -60, // '\n'

		LocalVar = -61, // 'var'
	};

    class Token
    {
		size_t _line, _col;
		TokenType _type;

	public:
		Token(const TokenType type = TokenType::Undefined, size_t line = 0, size_t col = 0);

		bool is_assign() const;

		TokenType type() const;
		size_t line() const;
		size_t column() const;
    };
}

#endif // TOKEN_HPP
