#pragma once

#include "Expression.hpp"

#include <string>

class IdentExpression : public Expression {
public:
    explicit IdentExpression(std::string ident) : main_ident(std::move(ident)) {}

    void accept(Visitor *v) {
        v->visit(this);
    }

    const std::string &getIdentifier() const {
        return main_ident;
    }

private:
    std::string main_ident;
};
