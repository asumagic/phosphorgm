#include "literal.hpp"

namespace gmsc
{
	ASTStringLiteral::ASTStringLiteral(const std::string str) : _string(str) {}

	ASTIntegerLiteral::ASTIntegerLiteral(const std::string str) : _number(std::stoll(str)) {}
	ASTIntegerLiteral::ASTIntegerLiteral(const long long integer) : _number(integer) {}

	ASTRealLiteral::ASTRealLiteral(const std::string str) : _number(std::stod(str)) {}
	ASTRealLiteral::ASTRealLiteral(const double real) : _number(real) {}
}
