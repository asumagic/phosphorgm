#include "call.hpp"

namespace gmsc
{
	ASTCallExpression::ASTCallExpression(const std::string function) : _call_name(function) {}

	void ASTCallExpression::append_argument(std::shared_ptr<ASTExpression>&& argument)
	{
		_arguments.emplace_back(argument);
	}

	ASTCallStatement::ASTCallStatement(const std::string function) :
		_expression(function) {}

	ASTCallExpression& ASTCallStatement::get_expression()
	{
		return _expression;
	}

}
