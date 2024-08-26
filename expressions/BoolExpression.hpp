#pragma once

#include "Expression.hpp"

class BoolExpression : public Expression {
public:
    explicit BoolExpression(const bool &val) : main_value(val) {}

    void accept(Visitor *v) {
        v->visit(this);
    }

    int getValue() const {
        return static_cast<int>(main_value);
    }

private:
    bool main_value = 0;
};
