#pragma once

#include "Statement.hpp"
#include "Expression.hpp"

class PrintStatement : public Statement {
 public:
  explicit PrintStatement(Expression* expression) : expression_(expression ) {}

  void Accept(Visitor* visitor) override {
      visitor->Visit(this);
  }

  Expression* GetExpression() const {
      return expression_;
  }

  void SetExpression(Expression* expression) {
      expression_ = expression;
  }

 private:
  Expression* expression_;
};
