#ifndef BINOP_HPP
#define BINOP_HPP

#include "ast.hpp"

namespace gmsc
{
    enum class BinaryOperator
    {
        // Arithmetic
		Add, // '+'
		Subtract, // '-' is an unary operator too
        Multiply, // '*'
        Divide, // '/'

        // Euclidian division
		EuclDivide, // 'div'
		EuclModulo, // 'mod' and '%'

        // Comparison
        Equal, // '=' (which is the assignment operator too) and '=='
        NotEqual, // '<>' and '!='
        Inferior, // '<'
        InferiorEqual, // '<='
        Superior, // '>'
        SuperiorEqual, // '>='

		// Logic boolean operators
		LogicAnd, // '&&'
		LogicOr, // '||'
		LogicXor, // '^^'

        // Bitwise operators
        BitAnd, // '&'
        BitOr, // '|'
        BitXor, // '^'
        BitShiftLeft, // '<<'
        BitShiftRight, // '>>'
    };

    class ASTBinaryOperator : public ASTExpression
    {
        ASTExpression *_loperand, *_roperand;
        BinaryOperator _op;
    };
}

#endif // BINOP_HPP
