#ifndef UNOP_HPP
#define UNOP_HPP

#include "ast.hpp"

namespace gmsc
{
    enum class UnaryOperator
    {
        Not, // '!'
        Negate, // '-'
        Positive, // '+'
        BitNot // '~'
    };

    class ASTUnaryOperator : public ASTExpression
    {
        ASTExpression* _operand;
        UnaryOperator _op;
    };
}

#endif // UNOP_HPP
