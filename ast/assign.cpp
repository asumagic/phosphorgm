#include "assign.hpp"

namespace gmsc
{
	ASTAssignment::ASTAssignment(std::shared_ptr<ASTVariable> var, std::shared_ptr<ASTExpression> expr) :
		_variable(var), _expression(expr)
	{}

	ASTUnopAssign::ASTUnopAssign(ASTAssignUnopType op, bool return_post_op, std::shared_ptr<ASTVariable> variable) :
		_operator(op), _post(return_post_op), _variable(variable) {}

}
