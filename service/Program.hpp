#pragma once

#include "TreeNode.hpp"
#include "MainClass.hpp"

class Program : public TreeNode {
 public:
  explicit Program(MainClass* main_class) : main_class_(main_class) {}

  void accept(Visitor* v) {
      v->visit(this);
  }

  MainClass* getMainClass() {
      return main_class_;
  }

  void setMainClass(MainClass* main_class) {
      main_class_ = main_class;
  }

 private:
  MainClass* main_class_;
};
