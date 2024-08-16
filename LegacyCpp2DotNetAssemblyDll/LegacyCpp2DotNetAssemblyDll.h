#pragma once

using namespace System;

// inlude legacy class header
#include "../LegacyCppSrc/MyLegacyClass/MyLegacyClass.h"

namespace LegacyCpp2DotNetAssemblyDll {

// Wrapper class for MyLegacyClass
public
ref class MyLegacyClassWrapper {
 public:
  MyLegacyClassWrapper() {
    // create legacy class
    myLegacyClass = new MyLegacyClass();
  }

  ~MyLegacyClassWrapper() { delete myLegacyClass; }  // delete legacy class

  void Set(int a, int b) { myLegacyClass->Set(a, b); }  // recall legacy class

  int Calc() { return myLegacyClass->Calc(); }  // recall legacy class

 private:
  MyLegacyClass* myLegacyClass;  // pointer to legacy class
};

}  // namespace LegacyCpp2DotNetAssemblyDll