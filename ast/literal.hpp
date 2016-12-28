#ifndef LITERAL_HPP
#define LITERAL_HPP

#include "ast.hpp"

namespace gmsc
{
    class ASTStringLiteral : public ASTExpression
    {
		std::string _string;

	public:
		ASTStringLiteral(const std::string str);
	};

    class ASTIntegerLiteral : public ASTExpression
    {
        long long _number;

	public:
		ASTIntegerLiteral(const std::string str);
		ASTIntegerLiteral(const long long integer);
    };

    class ASTRealLiteral : public ASTExpression
    {
        double _number;

	public:
		ASTRealLiteral(const std::string str);
		ASTRealLiteral(const double real);
    };
}

#endif // LITERAL_HPP
