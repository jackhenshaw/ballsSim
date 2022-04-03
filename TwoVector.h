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
  TwoVector(double *);
  TwoVector(TwoVector &);
  virtual ~TwoVector();

  // Setters:
  inline void SetX(double x);
  inline void SetY(double y);
  inline void SetXY(double x, double y);
  inline void SetXY(TwoVector &a);

  // Getters:
  inline double X();
  inline double Y();

  // vector specific operations
  inline double Mag();
  inline double Dot(TwoVector &a);
  inline double Length(TwoVector a);
  inline double Angle(TwoVector a);

  // operators
  inline TwoVector & operator =  (TwoVector &);
  inline TwoVector & operator += (TwoVector &);
  inline TwoVector & operator -= (TwoVector &);
  inline TwoVector & operator *= (double);

  void Print();

private:
  double fX, fY;
};

//operators without invoking instance
TwoVector operator + (TwoVector &, TwoVector &);
TwoVector operator - (TwoVector &, TwoVector &);
TwoVector operator * (TwoVector &, double a);
TwoVector operator * (double a, TwoVector);


// setters
inline void TwoVector::SetX(double x) { fX = x; }
inline void TwoVector::SetY(double y) { fY = y; }
inline void TwoVector::SetXY(double x, double y) {
  fX = x;
  fY = y;
}
inline void TwoVector::SetXY(TwoVector &a) {
  fX = a.X();
  fY = a.Y();
}

// getters
inline double TwoVector::X() { return fX; };
inline double TwoVector::Y() { return fY; };

// vector specific operations
inline double TwoVector::Mag() { return sqrt(pow(fX,2) + pow(fY,2)); }
inline double TwoVector::Dot(TwoVector &a) { return fX*a.X() + fY*a.Y(); }
inline double TwoVector::Length(TwoVector a) { return sqrt(pow(fX - a.X(),2) + pow(fY - a.Y(), 2)); }
inline double TwoVector::Angle(TwoVector a) {
  //calculates the inverse tangent of the opposite and adjacent sides of a triangle.
  double dy = fY - a.Y();
  double dx = fX - a.X();

  double angle;
  if (dx == 0) {
      if (dy > 0) angle = 2 * qAtan(1); //return pi/2
      else angle = 6 * qAtan(1); //return 3pi/2
  }
  if (dy == 0) {
      if (dx > 0) angle = 0;
      else if(dx < 0) angle = 4*qAtan(1); //return pi
  }
  if (dx > 0) angle = qAtan(dy/dx);
  if (dx < 0) angle = 2*qAtan(1) + qAtan(dy/dx); //180 degrees plus angle
  return angle;
}

// operators
inline TwoVector & TwoVector::operator = (TwoVector &p) {
  fX = p.fX;
  fY = p.fY;
  return *this;
}
inline TwoVector& TwoVector::operator += (TwoVector &p){
  fX += p.fX;
  fY += p.fY;
  return *this;
}

inline TwoVector& TwoVector::operator -= (TwoVector &p){
  fX -= p.fX;
  fY -= p.fY;
  return *this;
}

inline TwoVector& TwoVector::operator *= (double a){
  fX *= a;
  fY *= a;
  return *this;
}


#endif /* TWOVECTOR_H_ */

