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
  this->!MyLegacyClassWrapper();
  GC::SuppressFinalize(this);
}

LegacyCpp2DotNetAssemblyDll::MyLegacyClassWrapper::!MyLegacyClassWrapper() {
  if (myLegacyClass_ == nullptr) return;
  delete myLegacyClass_;
  myLegacyClass_ = nullptr;
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

LegacyCpp2DotNetAssemblyDll::ClsAWrapper::~ClsAWrapper() {
  this->!ClsAWrapper();
  GC::SuppressFinalize(this);
}

LegacyCpp2DotNetAssemblyDll::ClsAWrapper::!ClsAWrapper() {
  if (clsA_ == nullptr) return;
  delete clsA_;
  clsA_ = nullptr;
}

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

LegacyCpp2DotNetAssemblyDll::ClsBWrapper::~ClsBWrapper() {
  this->!ClsBWrapper();
  GC::SuppressFinalize(this);
}

LegacyCpp2DotNetAssemblyDll::ClsBWrapper::!ClsBWrapper() {
  if (clsB_ == nullptr) return;
  delete clsB_;
  clsB_ = nullptr;
}

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

float LegacyCpp2DotNetAssemblyDll::CArrayToolsWrapper::Max(array<float> ^ arr) {
  // convert managed array to unmanaged array
  pin_ptr<float> p = &arr[0];
  // the other option is Marshal::Copy(...)
  // use umanaged array pointer, to call the legacy class method
  return CArrayTools::Max(p, arr->Length);
}

LegacyCpp2DotNetAssemblyDll::MyStringCharWrapper::MyStringCharWrapper() {
  my_string_char_ = new MyStringChar();
}

LegacyCpp2DotNetAssemblyDll::MyStringCharWrapper::MyStringCharWrapper(
    MyStringChar* my_string_char) {
  my_string_char_ = new MyStringChar(*my_string_char);
}

LegacyCpp2DotNetAssemblyDll::MyStringCharWrapper::~MyStringCharWrapper() {
  this->!MyStringCharWrapper();
  GC::SuppressFinalize(this);
}

LegacyCpp2DotNetAssemblyDll::MyStringCharWrapper::!MyStringCharWrapper() {
  if (my_string_char_ == nullptr) return;
  delete my_string_char_;
  my_string_char_ = nullptr;
}

void LegacyCpp2DotNetAssemblyDll::MyStringCharWrapper::SetDataString(String ^
                                                                     str) {
  // convert System::String to std::string
  marshal_context context;
  std::string std_string = context.marshal_as<std::string>(str);
  // call the legacy class method
  my_string_char_->SetDataString(std_string);
}

void LegacyCpp2DotNetAssemblyDll::MyStringCharWrapper::SetDataChar(String ^
                                                                   str) {
  // convert System::String to unmanaged char array
  marshal_context context;
  const char* char_arr = context.marshal_as<const char*>(str);
  // call the legacy class method
  my_string_char_->SetDataChar(char_arr);
}

String ^ LegacyCpp2DotNetAssemblyDll::MyStringCharWrapper::GetDataString() {
  // call the legacy class method
  std::string std_string = my_string_char_->GetDataString();
  // convert std::string to System::String
  marshal_context context;
  System::String ^ system_string =
      context.marshal_as<System::String ^>(std_string);
  return system_string;
}

String ^ LegacyCpp2DotNetAssemblyDll::MyStringCharWrapper::GetDataChar() {
  // call the legacy class method
  const char* char_arr = my_string_char_->GetDataChar();
  // convert char* to System::String
  marshal_context context;
  System::String ^ system_string =
      context.marshal_as<System::String ^>(char_arr);
  return system_string;
}

array<int> ^
    LegacyCpp2DotNetAssemblyDll::MyStdVectorWrapper::RevertVector(array<int> ^
                                                                  cs_arr) {
  // use Marshal::Copy to implemtent C++ std::vector and cs array conversion
  // convert managed cs array to unmanaged std::vector
  pin_ptr<int> src_arr_ptr = &cs_arr[0];
  std::vector<int> src_std_vect(cs_arr->Length);
  Marshal::Copy(cs_arr, 0, (IntPtr)src_std_vect.data(), cs_arr->Length);

  // call the legacy class method
  std::vector<int> reversed_vect = MyStdVector::RevertVector(src_std_vect);

  // convert unmanaged std::vector to managed cs array
  // copy convert src_std_vect back to sec_cs_array
  int src_std_vect_length = static_cast<int>(src_std_vect.size());
  Marshal::Copy((IntPtr)src_std_vect.data(), cs_arr, 0, src_std_vect_length);

  // create a managed array result and copy convert reversed_vect into it
  int reversed_vect_length = static_cast<int>(reversed_vect.size());
  array<int> ^ result = gcnew array<int>(reversed_vect_length);
  Marshal::Copy((IntPtr)reversed_vect.data(), result, 0, reversed_vect_length);

  return result;
}
