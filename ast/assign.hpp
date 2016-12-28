#ifndef ASSIGN_HPP
#define ASSIGN_HPP

#include "ast.hpp"
#include "variable.hpp"

namespace gmsc
{
    class ASTAssignment : public ASTStatement
    {
		std::shared_ptr<ASTVariable> _variable;
		std::shared_ptr<ASTExpression> _expression;

	public:
		ASTAssignment(std::shared_ptr<ASTVariable> var, std::shared_ptr<ASTExpression> expr);
    };

	enum class ASTAssignUnopType
	{
		Increment,
		Decrement
	};

	class ASTUnopAssign : public ASTStatement // ++ --
	{
		ASTAssignUnopType _operator;
		bool _post;
		std::shared_ptr<ASTVariable> _variable;

	public:
		ASTUnopAssign(ASTAssignUnopType op, bool return_post_op, std::shared_ptr<ASTVariable> variable);
	};
}

#endif // ASSIGN_HPP
