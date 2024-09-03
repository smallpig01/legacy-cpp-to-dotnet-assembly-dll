#include "MyStdVector.h"

std::vector<int>& MyStdVector::RevertVector(std::vector<int>& vect) {
  std::reverse(vect.begin(), vect.end());
  return vect;
}
