#ifndef ASSIGN_HPP
#define ASSIGN_HPP

#include "ast.hpp"
#include "variable.hpp"

namespace gmsc
{
    class ASTAssignment : public ASTStatement
    {
		std::unique_ptr<ASTVariable> _variable;
		std::unique_ptr<ASTExpression> _expression;

	public:
		ASTAssignment(std::unique_ptr<ASTVariable>&& var, std::unique_ptr<ASTExpression>&& expr);
    };
}

#endif // ASSIGN_HPP
