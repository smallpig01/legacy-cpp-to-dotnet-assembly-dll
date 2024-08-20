#include "ClsB.h"

#include "../ClsA/ClsA.h"

ClsA ClsB::Foo(ClsA A) {
  A.SetValue(value_);
  return A;
}
