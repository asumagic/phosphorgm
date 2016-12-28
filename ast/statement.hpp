#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include "ast.hpp"

namespace gmsc
{
    class ASTStatement : public ASTNode
    {

    };

    class ASTStatementBlock : public ASTStatement
    {
		std::vector<std::shared_ptr<ASTStatement>> _block;

	public:
		void append(std::shared_ptr<ASTStatement> statement);
    };
}

#endif // STATEMENT_HPP
