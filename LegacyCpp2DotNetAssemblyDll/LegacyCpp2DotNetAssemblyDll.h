#pragma once

using namespace System;

// inlude legacy class header
#include "../LegacyCppSrc/ClsA/ClsA.h"
#include "../LegacyCppSrc/ClsB/ClsB.h"
#include "../LegacyCppSrc/EnumList/EnumList.h"
#include "../LegacyCppSrc/MyLegacyClass/MyLegacyClass.h"

// forward declare
namespace LegacyCpp2DotNetAssemblyDll {
ref class ClsAWrapper;  // forward declare due to circular dependency
ref class ClsBWrapper;  // forward declare due to circular dependency
}  // namespace LegacyCpp2DotNetAssemblyDll

// Wrapper class for MyLegacyClass
namespace LegacyCpp2DotNetAssemblyDll {
public
ref class MyLegacyClassWrapper {
 public:
  MyLegacyClassWrapper();
  MyLegacyClassWrapper(MyLegacyClass* myLegacyClass);
  ~MyLegacyClassWrapper();
  MyLegacyClassWrapper(int a, int b);
  MyLegacyClassWrapper ^ Set(MyLegacyClassWrapper ^ myLegacyClass);
  MyLegacyClassWrapper ^ Get(MyLegacyClassWrapper ^ myLegacyClass);
  void Set(int a, int b);
  int Calc();

 private:
  MyLegacyClass* myLegacyClass_;  // pointer to legacy class
};
}  // namespace LegacyCpp2DotNetAssemblyDll

// Wrapper class for ClsA
namespace LegacyCpp2DotNetAssemblyDll {
public
ref class ClsAWrapper {
 public:
  ClsA* clsA_;  // pointer to legacy class
  ClsAWrapper();
  ClsAWrapper(ClsA* clsA);
  ~ClsAWrapper();
  ClsBWrapper ^ Foo(ClsBWrapper ^ b);
  int GetValue();
  void SetValue(int value);
};
}  // namespace LegacyCpp2DotNetAssemblyDll

// Wrapper class for ClsB
namespace LegacyCpp2DotNetAssemblyDll {
public
ref class ClsBWrapper {
 public:
  ClsBWrapper();
  ClsBWrapper(ClsB* clsB);
  ~ClsBWrapper();
  ClsAWrapper ^ Foo(ClsAWrapper ^ a);
  int GetValue();
  void SetValue(int value);
  ClsB* GetCppObject();

 private:
  ClsB* clsB_;
};
}  // namespace LegacyCpp2DotNetAssemblyDll

// Wrapper class for CArrayTools
namespace LegacyCpp2DotNetAssemblyDll {
public
ref class CArrayToolsWrapper {
 public:
  // static method to find the maximum value in an array
  static float Max(array<float> ^ arr);
};
}  // namespace LegacyCpp2DotNetAssemblyDll

// Wrapper class for EnumList
namespace LegacyCpp2DotNetAssemblyDll {
public
enum class MyEnum {
  A = EnumList::A,
  B = EnumList::B,
  C = EnumList::C,
  D = EnumList::D
};
}  // namespace LegacyCpp2DotNetAssemblyDll