#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "ast.hpp"

namespace gmsc
{
    class ASTCase : public ASTStatement
    {
        ASTExpression* _expression;
        ASTStatementBlock* _body;
        ASTCase* _next;
    };

    class ASTDefaultCase : public ASTStatement
    {
        ASTStatementBlock* _body;
    };

    class ASTSwitch : public ASTStatement
    {
        ASTExpression* _expression;
        std::vector<ASTCase> _master_cases;
        ASTDefaultCase* _default = nullptr;
    };
}

#endif // SWITCH_HPP
