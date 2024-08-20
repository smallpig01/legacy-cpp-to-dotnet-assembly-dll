#pragma once

class ClsB;

class ClsA {
 public:
  ClsB Foo(ClsB B);
  int GetValue() { return value_; }
  void SetValue(int value) { value_ = value; };

 private:
  int value_ = 0;
};
