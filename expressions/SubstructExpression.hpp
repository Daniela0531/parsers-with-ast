#pragma once

#include "Expression.hpp"

class SubExpression : public Expression {
public:
    SubExpression(Expression *l, Expression *r) : main_left(l), main_right(r) {}

    void accept(Visitor *v) {
        v->visit(this);
    }

    Expression *getLeftExpression() const {
        return main_left;
    }

    Expression *getRightExpression() const {
        return main_right;
    }

    void setLeftExpression(Expression *l) {
        main_left = l;
    }

    void setRightExpression(Expression *r) {
        main_right = r;
    }

private:
    Expression *main_left;
    Expression *main_right;
};
