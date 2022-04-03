/* Author: Jack Henshaw
 * Created on:  01/04/2022
 * Last Edited: 03/04/2022
 * Implementation file of 2D vector
 */

#include <math.h>
#include <iostream>

#include "TwoVector.h"

// Constructors and Destructor
TwoVector::TwoVector() : fX(0.0), fY(0.0) {}
TwoVector::TwoVector(double x, double y) : fX(x), fY(y) {}
TwoVector::TwoVector(const double *a) : fX(a[0]), fY(a[1]) {}
TwoVector::TwoVector(const TwoVector &p) : fX(p.fX), fY(p.fY) {}
TwoVector::~TwoVector() {}

// Operators
TwoVector operator + (const TwoVector &a, const TwoVector &b) {
  return TwoVector(a.X() + b.X(), a.Y() + b.Y());
}

TwoVector operator - (const TwoVector &a, const TwoVector &b) {
  return TwoVector(a.X() - b.X(), a.Y() - b.Y());
}

TwoVector operator * (const TwoVector &p, double a) {
  return TwoVector(a*p.X(), a*p.Y());
}

TwoVector operator * (double a, const TwoVector &p) {
  return TwoVector(a*p.X(), a*p.Y());
}

void TwoVector::Print() const {
  printf("Vector = (%.3f, %.3f)", fX, fY);
}
