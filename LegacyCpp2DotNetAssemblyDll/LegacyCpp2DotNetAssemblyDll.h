#pragma once

// include C++/CLI header
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace msclr::interop;

// inlude legacy class header
#include "../LegacyCppSrc/ClsA/ClsA.h"
#include "../LegacyCppSrc/ClsB/ClsB.h"
#include "../LegacyCppSrc/EnumList/EnumList.h"
#include "../LegacyCppSrc/MyLegacyClass/MyLegacyClass.h"
#include "../LegacyCppSrc/MyStdVector/MyStdVector.h"
#include "../LegacyCppSrc/MyStringChar/MyStringChar.h"

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
// global enum from legecy c++ enum (out of class)
enum class MyEnum {
  A = EnumList::A,
  B = EnumList::B,
  C = EnumList::C,
  D = EnumList::D
};
// in class enum from legecy c++ enum (in class)
public
ref class InClassMyEnum {
 public:
  enum class MyEnum {
    A = EnumList::A,
    B = EnumList::B,
    C = EnumList::C,
    D = EnumList::D
  };
};
}  // namespace LegacyCpp2DotNetAssemblyDll

// Wrapper class for MyStringChar
namespace LegacyCpp2DotNetAssemblyDll {
public
ref class MyStringCharWrapper {
 public:
  MyStringCharWrapper();
  MyStringCharWrapper(MyStringChar* my_string_char);
  ~MyStringCharWrapper();
  void SetDataString(String ^ str);
  void SetDataChar(String ^ str);
  String ^ GetDataString();
  String ^ GetDataChar();

 private:
  MyStringChar* my_string_char_;
};
}  // namespace LegacyCpp2DotNetAssemblyDll

// Wrapper class for MyStdVector
namespace LegacyCpp2DotNetAssemblyDll {
public
ref class MyStdVectorWrapper {
 public:
  static array<int> ^ RevertVector(array<int> ^ cs_arr);
};
}  // namespace LegacyCpp2DotNetAssemblyDll