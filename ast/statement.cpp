#include "statement.hpp"

namespace gmsc
{
	void ASTStatementBlock::append(std::shared_ptr<ASTStatement> statement)
	{
		_block.emplace_back(statement);
	}
}
