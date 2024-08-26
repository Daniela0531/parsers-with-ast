#pragma once

#include "Expression.hpp"
#include "Statement.hpp"
#include "NamedEntity.hpp"

class AssignmentStatement : public Statement {
 public:
  AssignmentStatement(NamedEntity* named_entity, Expression* expression)
      : main_named_entity(named_entity), main_expression(expression) {}

  void accept(Visitor* visitor) override {
      visitor->visit(this);
  }

  NamedEntity* getNamedEntity() const {
      return main_named_entity;
  }

  void setNamedEntity(NamedEntity* named_entity) {
      main_named_entity = named_entity;
  }

  Expression* getExpression() const {
      return main_expression;
  }

  void setExpression(Expression* expression) {
      main_expression = expression;
  }

 private:
    NamedEntity* main_named_entity;
    Expression* main_expression;
};
