#ifndef FLOWBREAK_HPP
#define FLOWBREAK_HPP

#include "ast.hpp"

namespace gmsc
{
    class ASTLoopBreak : public ASTStatement
    {

    };

    class ASTLoopContinue : public ASTStatement
    {

    };

    class ASTModuleExit : public ASTStatement
    {

    };

    class ASTScriptReturn : public ASTStatement
    {
        ASTExpression* _value;
    };
}

#endif // FLOWBREAK_HPP
