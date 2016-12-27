#ifndef CALL_HPP
#define CALL_HPP

#include "ast.hpp"

namespace gmsc
{
    enum class CallType
    {
        external_call,
        script_call
    };

    class ASTCallExpression : public ASTExpression
    {
        CallType _type;
        std::string _call_name;
        std::vector<ASTExpression*> _arguments;
    };

    class ASTCallStatement : public ASTStatement
    {
        ASTCallExpression* _expression;
    };
}

#endif // CALL_HPP
