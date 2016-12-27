#ifndef ENUM_HPP
#define ENUM_HPP

#include "ast.hpp"

namespace gmsc
{
    class ASTEnumEntry : public ASTStatement
    {
        std::string _entry;
        ASTExpression* _value;
    };

    class ASTEnum : public ASTStatement
    {
        std::string _name;
        std::vector<ASTEnumEntry*> _entries;
    };

    class ASTEnumAccess : public ASTStatement
    {
        ASTEnum* _enum;
        ASTEnumEntry* _entry;
    };
}

#endif // ENUM_HPP
