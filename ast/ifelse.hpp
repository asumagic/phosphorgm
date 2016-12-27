#ifndef IFELSE_HPP
#define IFELSE_HPP

#include "ast.hpp"

namespace gmsc
{
    class ASTIfBlock : public ASTStatement
    {
        ASTExpression* _condition;
        ASTStatementBlock* _then;
    };

    class ASTIfElseBlock : public ASTIfBlock
    {
        ASTStatementBlock* _else;
    };
}

#endif // IFELSE_HPP
