#pragma once

#include "statement/StatementList.hpp"
#include "TreeNode.hpp"

#include <string>
#include <memory>

class MainClass : public TreeNode {
 public:
  MainClass(std::string name, StatementList* statements) : main_name(std::move(name)), main_statements(statements) {}

  void accept(Visitor* v) {
      v->visit(this);
  }

  std::string getName() {
      return main_name;
  }

  StatementList* getStatements() {
      return main_statements;
  }

 private:
  std::string main_name;
  StatementList* main_statements;
};
