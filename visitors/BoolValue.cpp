#pragma once
#include "BoolValue.h"

int BoolValue::toInt() {
  return static_cast<int>(value_);
}

bool BoolValue::toBool() {
  return value_;
}

std::string BoolValue::GetTypeIdentifier() {
  return "boolean";
}
