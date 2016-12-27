#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "ast.hpp"

namespace gmsc
{
    enum class ValueType
    {
		Unknown,
		String,
        Real,
        Int32,
        Int64,
		Array,
        Pointer,
        Enum,
		Undefined
    };

    class ASTExpression : public ASTNode
    {
		ValueType _known_type;
    };
}

#endif // EXPRESSION_HPP
