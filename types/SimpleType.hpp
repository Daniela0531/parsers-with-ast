#pragma once

#include "Type.hpp"

class SimpleType : public Type {
 public:
  explicit SimpleType(const std::string& identifier) {
      this->identifier_ = identifier;
  }

  void Accept(Visitor* visitor) override {
      visitor->Visit(this);
  }


};

