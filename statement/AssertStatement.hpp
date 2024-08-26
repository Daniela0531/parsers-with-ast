#pragma once

#include <Visitors/Visitor.hpp>
#include "Statement.hpp"
#include "expressions/Expression.hpp"

class AssertStatement : public Statement {
 public:
  explicit AssertStatement(Expression* ex) : main_expression(ex) {}

  void accept(Visitor* v) {
      v->visit(this);
  }

  void setExpression(Expression* ex) {
      main_expression = ex;
  }

  Expression* getExpression() {
      return main_expression;
  }

 private:
  Expression* main_expression;
};
