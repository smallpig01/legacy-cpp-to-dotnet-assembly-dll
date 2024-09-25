#pragma once
class MyDynamicPointer {
 public:
  MyDynamicPointer() {
    // new 1MB data
    data_ = new char[1000000];
  }
  ~MyDynamicPointer() {
    if (data_ == nullptr) return;
    delete[] data_;
    data_ = nullptr;
  }

 private:
  char *data_;
};
