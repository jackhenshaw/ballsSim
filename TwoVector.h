/* Author: Jack Henshaw
 * Created on: 01/04/2022
 * Last edited 01/04/2022
 * Header file for defining a 2D vector and how this interacts
 */

#ifndef TWOVECTOR_H_
#define TWOVECTOR_H_

#include <QtMath>

class TwoVector {
public:
  TwoVector();
  TwoVector(double x, double y);
  TwoVector(const double *);
  TwoVector(const TwoVector &);
  virtual ~TwoVector();

  // Setters:
  inline void SetX(double);
  inline void SetY(double);
  inline void SetXY(double x, double y);

  // Getters:
  inline double X() const { return fX; };
  inline double Y() const { return fY; };

private:
  double fX, fY;
};
#endif /* TWOVECTOR_H_ */

