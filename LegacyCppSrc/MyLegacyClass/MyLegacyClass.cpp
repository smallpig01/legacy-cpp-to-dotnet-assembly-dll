#include "MyLegacyClass.h"

void MyLegacyClass::Set(int a, int b) {
  a_ = a;
  b_ = b;
}

MyLegacyClass MyLegacyClass::Set(MyLegacyClass& myLegacyClass) {
  *this = myLegacyClass;
  return *this;
}

MyLegacyClass MyLegacyClass::Get(MyLegacyClass& myLegacyClass) {
  myLegacyClass = *this;
  return myLegacyClass;
}

float CArrayTools::Max(float arr[], int size) {
  if (size <= 0) return -999999.0f;
  float max = arr[0];
  for (int i = 1; i < size; i++)
    if (arr[i] > max) max = arr[i];
  return max;
}
