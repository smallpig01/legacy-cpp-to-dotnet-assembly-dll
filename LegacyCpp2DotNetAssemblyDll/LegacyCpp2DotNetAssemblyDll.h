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
// global enum from legecy c++ define (out of class)
public
enum class MyDefine {
  A = DEF_BIN_A,
  B = DEF_BIN_B,
  C = DEF_BIN_C,
  D = DEF_BIN_D
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

// Wrapper struct for global and in-class struct
namespace LegacyCpp2DotNetAssemblyDll {

// use ref keyword to create a global reference type struct
public
ref struct MyGlobalRefStruct {
  int i = 1;
  float f = 1.1f;
  System::String ^ s = "MyGlobalRefStruct";
};

// use value keyword to create a global value type (
public
value struct MyGlobalValueStruct {
  int i /*=2*/;       // cant init value here due to value struct type
  float f /*=2.2f*/;  // cant init value here due to value struct type
  // cant init value here due to value struct type
  System::String ^ s /* = "MyGlobalValueStruct"*/;
};

public
ref class MyStructClass {
  // use ref keyword to create a in class reference type struct
 public:
  ref struct MyInClassRefStruct {
    int i = 3;
    float f = 3.3f;
    System::String ^ s = "MyInClassRefStruct";
  };
  // use value keyword to create a in class value type struct
  value struct MyInClassVlaueStruct {
   public:
    int i /* = 4*/;       // cant init value here due to value struct type
    float f /* = 4.4f*/;  // cant init value here due to value struct type
    // cant init value here due to value struct type
    System::String ^ s /* = "MyInClassVlaueStruct"*/;
  };
};
}  // namespace LegacyCpp2DotNetAssemblyDll
