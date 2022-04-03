/* Author: Jack Henshaw
 * Created on: 01/04/2022
 * Last edited 01/04/2022
 * Implementation of 2D vector
 */

#include <math.h>
#include <iostream>

#include "TwoVector.h"

TwoVector::TwoVector() : fX(0.0), fY(0.0) {}

TwoVector::TwoVector(double x, double y) : fX(x), fY(y) {}

TwoVector::TwoVector(double *a) : fX(a[0]), fY(a[1]) {}

TwoVector::TwoVector(TwoVector &t) : fX(t.fX), fY(t.fY) {}

TwoVector::~TwoVector() {}

// operators
TwoVector operator + (TwoVector &a,TwoVector &b) {
  return TwoVector(a.X() + b.X(), a.Y() + b.Y());
}

TwoVector operator - (TwoVector &a, TwoVector &b) {
  return TwoVector(a.X() - b.X(), a.Y() - b.Y());
}

TwoVector operator * (TwoVector &a, double f) {
  return TwoVector(f*a.X(), f*a.Y());
}

TwoVector operator * (double f, TwoVector &a) {
  return TwoVector(f*a.X(), f*a.Y());
}

void TwoVector::Print() {
  printf("Vector = (%.3f, %.3f)", fX, fY);
}
