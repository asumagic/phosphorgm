#ifndef WITH_HPP
#define WITH_HPP

#include "ast.hpp"

namespace gmsc
{
    class ASTWith : public ASTStatementBlock
    {
        ASTExpression* _object;
        ASTStatementBlock* _body;
    };
}

#endif // WITH_HPP
