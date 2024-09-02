#pragma once

#include <stdlib.h>

#include <string>

class MyStringChar {
 public:
  const char* GetDataChar();
  std::string GetDataString();
  void SetDataChar(const char* str);
  void SetDataString(const std::string& str);

 private:
  std::string str_;
};
