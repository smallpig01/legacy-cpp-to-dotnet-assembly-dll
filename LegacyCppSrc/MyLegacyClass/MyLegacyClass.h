#pragma once

class MyLegacyClass {
 public:
  int Calc() const { return a_ + b_; }
  void Set(int a, int b) {
    a_ = a;
    b_ = b;
  }

 private:
  int a_ = 0;
  int b_ = 0;
};