#pragma once

#include "Expression.hpp"

class DivExpression : public Expression {
public:
    DivExpression(Expression *l, Expression *r) : main_left(l), main_right(r) {}

    void accept(Visitor *v) {
        v->visit(this);
    }

    Expression *getLeft() const {
        return main_left;
    }

    void setRight(Expression *r) {
        main_right = r;
    }

    void setLeft(Expression *l) {
        main_left = l;
    }

    Expression *getRight() const {
        return main_right;
    }

private:
    Expression *main_left;
    Expression *main_right;
};
