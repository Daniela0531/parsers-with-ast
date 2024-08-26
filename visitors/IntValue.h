#pragma once

#include <memory>

class IntValue : public Value {
 public:
  explicit IntValue(int v = 0) : main_value(v) {}
  IntValue(const IntValue& other) = default;
  IntValue& operator=(const IntValue& other) = default;

  int toInt() {
    return main_value;
  }

  bool toBool() {
      return main_value == 0;
  }

  std::string getTypeIdentifier() {
      return "int";
  }

 private:
  int main_value = 0;
};
