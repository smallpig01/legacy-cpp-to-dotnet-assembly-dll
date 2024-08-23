#include "LegacyCpp2DotNetAssemblyDll.h"

#include "pch.h"

LegacyCpp2DotNetAssemblyDll::MyLegacyClassWrapper::MyLegacyClassWrapper() {
  myLegacyClass_ = new MyLegacyClass();
}

LegacyCpp2DotNetAssemblyDll::MyLegacyClassWrapper::MyLegacyClassWrapper(
    MyLegacyClass* myLegacyClass) {
  myLegacyClass_ = new MyLegacyClass(*myLegacyClass);
}

LegacyCpp2DotNetAssemblyDll::MyLegacyClassWrapper::~MyLegacyClassWrapper() {
  delete myLegacyClass_;
}

LegacyCpp2DotNetAssemblyDll::MyLegacyClassWrapper::MyLegacyClassWrapper(int a,
                                                                        int b) {
  myLegacyClass_ = new MyLegacyClass(a, b);
}

LegacyCpp2DotNetAssemblyDll::MyLegacyClassWrapper ^
    LegacyCpp2DotNetAssemblyDll::MyLegacyClassWrapper::Set(
        MyLegacyClassWrapper ^ myLegacyClass) {
  // clang-format off
  // the correct process of wrapper invoking legacy class
  // create a c-class object to recieve the legacy class method return object
  MyLegacyClass tempClass = myLegacyClass_->Set( *(myLegacyClass->myLegacyClass_) );
  // create a new wrapper object by passing the c-class object
  MyLegacyClassWrapper ^ tempWrapper = gcnew MyLegacyClassWrapper( &tempClass );
  // return the wrapper object
  return tempWrapper;

  // or use one-line style to retun MyLegacyClassWrapper ^ object
  // return gcnew MyLegacyClassWrapper(&(myLegacyClass_->Set(*(myLegacyClass->myLegacyClass_))));
  // clang-format on
}

LegacyCpp2DotNetAssemblyDll::MyLegacyClassWrapper ^
    LegacyCpp2DotNetAssemblyDll::MyLegacyClassWrapper::Get(
        MyLegacyClassWrapper ^ myLegacyClass) {
  // use one-line style to retun MyLegacyClassWrapper ^ object
  return gcnew MyLegacyClassWrapper(
      &(myLegacyClass_->Get(*(myLegacyClass->myLegacyClass_))));
}

void LegacyCpp2DotNetAssemblyDll::MyLegacyClassWrapper::Set(int a, int b) {
  myLegacyClass_->Set(a, b);
}

int LegacyCpp2DotNetAssemblyDll::MyLegacyClassWrapper::Calc() {
  return myLegacyClass_->Calc();
}

LegacyCpp2DotNetAssemblyDll::ClsAWrapper::ClsAWrapper() { clsA_ = new ClsA(); }

LegacyCpp2DotNetAssemblyDll::ClsAWrapper::ClsAWrapper(ClsA* clsA) {
  clsA_ = new ClsA(*clsA);
}

LegacyCpp2DotNetAssemblyDll::ClsAWrapper::~ClsAWrapper() { delete clsA_; }

LegacyCpp2DotNetAssemblyDll::ClsBWrapper ^
    LegacyCpp2DotNetAssemblyDll::ClsAWrapper::Foo(ClsBWrapper ^ b) {
  // clang-format off
  // the correct process of wrapper invoking legacy class
  // create a c-class object to recieve the return object of legacy class method
  ClsB tmepClass = clsA_->Foo( *(b->GetCppObject()) );
  // create a new wrapper object by passing the c-class object
  ClsBWrapper ^ tempWrapper = gcnew ClsBWrapper( &tmepClass );
  // return the wrapper object
  return tempWrapper;  

  // use the one-line call method to avoid the object life cycle issues
  // return gcnew ClsBWrapper(&(clsA_->Foo(*(b->GetCppObject()))));
  // clang-format on
}

int LegacyCpp2DotNetAssemblyDll::ClsAWrapper::GetValue() {
  return clsA_->GetValue();
}

void LegacyCpp2DotNetAssemblyDll::ClsAWrapper::SetValue(int value) {
  clsA_->SetValue(value);
}

LegacyCpp2DotNetAssemblyDll::ClsBWrapper::ClsBWrapper() { clsB_ = new ClsB(); }

LegacyCpp2DotNetAssemblyDll::ClsBWrapper::ClsBWrapper(ClsB* clsB) {
  clsB_ = new ClsB(*clsB);
}

LegacyCpp2DotNetAssemblyDll::ClsBWrapper::~ClsBWrapper() { delete clsB_; }

LegacyCpp2DotNetAssemblyDll::ClsAWrapper ^
    LegacyCpp2DotNetAssemblyDll::ClsBWrapper::Foo(ClsAWrapper ^ a) {
  // use the one-line call method to avoid the object life cycle issues
  return gcnew ClsAWrapper(&(clsB_->Foo(*(a->clsA_))));
}

int LegacyCpp2DotNetAssemblyDll::ClsBWrapper::GetValue() {
  return clsB_->GetValue();
}

void LegacyCpp2DotNetAssemblyDll::ClsBWrapper::SetValue(int value) {
  clsB_->SetValue(value);
}

ClsB* LegacyCpp2DotNetAssemblyDll::ClsBWrapper::GetCppObject() { return clsB_; }
