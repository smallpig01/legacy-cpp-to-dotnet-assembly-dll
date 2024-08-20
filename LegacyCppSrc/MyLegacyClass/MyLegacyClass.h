#pragma once

class MyLegacyClass {
 public:
  MyLegacyClass() = default;
  MyLegacyClass(int a, int b) : a_(a), b_(b) {}
  int Calc() const { return a_ + b_; }
  void Set(int a, int b);
  MyLegacyClass Set(MyLegacyClass& myLegacyClass);

 private:
  int a_ = 0;
  int b_ = 0;
};