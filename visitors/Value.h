#pragma once

class Value {
 public:
  virtual int toInt() const = 0;
  virtual bool toBool() const = 0;

  virtual std::string getTypeIdentifier() const = 0;
};
