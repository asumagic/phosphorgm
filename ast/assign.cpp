#include "assign.hpp"


gmsc::ASTAssignment::ASTAssignment(std::unique_ptr<gmsc::ASTVariable>&& var, std::unique_ptr<gmsc::ASTExpression>&& expr) :
	_variable(std::move(var)), _expression(std::move(expr))
{}
