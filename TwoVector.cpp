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

TwoVector::TwoVector(const double *a) : fX(a[0]), fY(a[1]) {}

TwoVector::TwoVector(const TwoVector &t) : fX(t.fX), fY(t.fY) {}

TwoVector::~TwoVector() {}

