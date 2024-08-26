#pragma once

#include "Expression.hpp"


class AddExpression : public Expression {
public:
    AddExpression(Expression *l, Expression *r) : main_left(l), main_right(r) {}

    void accept(visitor *v) {
        v->visit(this);
    }

    Expression *getLeft() const {
        return main_left;
    }

    Expression *getRight() const {
        return main_right;
    }

    void setLeft(Expression *l) {
        main_left = l;
    }

    void setRight(Expression *r) {
        main_right = r;
    }

private:
    Expression *main_left;
    Expression *main_right;
};
