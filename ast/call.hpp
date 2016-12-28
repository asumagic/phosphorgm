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
		std::vector<std::shared_ptr<ASTExpression>> _arguments;

	public:
		ASTCallExpression(const std::string function);
		void append_argument(std::shared_ptr<ASTExpression>&& argument);
    };

    class ASTCallStatement : public ASTStatement
    {
		ASTCallExpression _expression;

	public:
		ASTCallStatement(const std::string function);
		ASTCallExpression& get_expression();
    };
}

#endif // CALL_HPP
