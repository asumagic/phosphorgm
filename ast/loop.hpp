#ifndef LOOP_HPP
#define LOOP_HPP

#include "ast.hpp"

namespace gmsc
{
    class ASTLoop : public ASTStatement
    {
        ASTStatementBlock* _body;
    };

    class ASTLoopWhile : public ASTLoop
    {
        ASTExpression* _condition;
    };

    class ASTLoopDoWhile : public ASTLoop
    {
        ASTExpression* _condition;
    };

    class ASTForLoop : public ASTLoop
    {
        ASTExpression* _condition;
        ASTStatement *_initialize, *_increment;
    };

    class ASTRepeatLoop : public ASTLoop
    {
        ASTExpression* _times;
    };
}

#endif // LOOP_HPP
