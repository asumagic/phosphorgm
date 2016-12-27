#ifndef LITERAL_HPP
#define LITERAL_HPP

#include "ast.hpp"

namespace gmsc
{
    class ASTStringLiteral : public ASTExpression
    {
        std::string _string;
    };

    class ASTIntegerLiteral : public ASTExpression
    {
        long long _number;
    };

    class ASTRealLiteral : public ASTExpression
    {
        double _number;
    };
}

#endif // LITERAL_HPP
