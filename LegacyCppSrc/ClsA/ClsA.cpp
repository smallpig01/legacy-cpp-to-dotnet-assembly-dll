#include "ClsA.h"

#include "../ClsB/ClsB.h"

ClsB ClsA::Foo(ClsB B) {
  B.SetValue(value_);
  return B;
}
