#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include "ast.hpp"

namespace gmsc
{
    enum class VariableAccessibility
    {
        Local,
        Global,
        Instance,
        Builtin,
        BuiltinConstant
    };

    class ASTVariable : public ASTExpression
    {
        std::string _name;

	public:
		ASTVariable(const std::string name);
    };

    class ASTLocalDeclare : public ASTStatement
    {
        std::vector<ASTVariable*> _locals;
    };
}

#endif // VARIABLE_HPP
