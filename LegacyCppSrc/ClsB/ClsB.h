#pragma once

class ClsA;

class ClsB {
 public:
  ClsA Foo(ClsA A);
  int GetValue() { return value_; }
  void SetValue(int value) { value_ = value; }

 private:
  int value_ = 0;
};
