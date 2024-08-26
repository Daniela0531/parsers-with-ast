#include "IntValue.h"

int IntValue::toInt() {
    return main_value;
}

bool IntValue::toBool() {
  return main_value == 0;
}

std::string IntValue::getTypeIdentifier() {
  return "int";
}
