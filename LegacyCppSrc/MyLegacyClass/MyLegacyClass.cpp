#include "MyLegacyClass.h"

void MyLegacyClass::Set(int a, int b) {
  a_ = a;
  b_ = b;
}

MyLegacyClass MyLegacyClass::Set(MyLegacyClass& myLegacyClass) {
  *this = myLegacyClass;
  return *this;
}
