#include "MyStringChar.h"

const char* MyStringChar::GetDataChar() { return str_.c_str(); }

std::string MyStringChar::GetDataString() { return str_; }

void MyStringChar::SetDataChar(const char* str) { str_ = str; }

void MyStringChar::SetDataString(const std::string& str) { str_ = str; }