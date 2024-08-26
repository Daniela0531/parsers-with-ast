#pragma once

#include "Type.hpp"

class ArrayType : public Type {
 public:
  explicit ArrayType(const std::string& identifier) {
      this->identifier_ = identifier;
  }

  void Accept(Visitor* visitor) override {
      visitor->Visit(this);
  }
};
