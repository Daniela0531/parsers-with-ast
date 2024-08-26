#pragma once

class BoolValue : public Value {
 public:
  explicit BoolValue(bool v = false) : main_value(v) {}
  BoolValue(BoolValue& other) = default;
  BoolValue& operator=(BoolValue& other) = default;

  int toInt();

  bool toBool();

  std::string getTypeIdentifier();

 private:
  bool main_value = false;
};
