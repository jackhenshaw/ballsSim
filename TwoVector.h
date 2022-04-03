/* Author: Jack Henshaw
 * Created on:  01/04/2022
 * Last Edited: 03/04/2022
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
  inline void SetXY(TwoVector &a);

  // Getters:
  inline double X() const;
  inline double Y() const;

  // Vector Specific Operations
  inline double Mag() const;
  inline double Dot(const TwoVector &p) const;
  inline double Length(TwoVector a);
  inline double Angle(TwoVector a);

  // Operators:
  inline TwoVector & operator  = (const TwoVector &);
  inline TwoVector & operator += (const TwoVector &);
  inline TwoVector & operator -= (const TwoVector &);
  inline TwoVector & operator *= (double);

  // Print data members to console
  void Print() const;

private:
  double fX, fY; // Components
};

// Operators without invoking instance
TwoVector operator + (const TwoVector &, const TwoVector &);
TwoVector operator - (const TwoVector &, const TwoVector &);
TwoVector operator * (const TwoVector &, double a);
TwoVector operator * (double a, const TwoVector);

// Setters:
inline void TwoVector::SetX(double x) { fX = x; }
inline void TwoVector::SetY(double y) { fY = y; }
inline void TwoVector::SetXY(double x, double y) {
  fX = x;
  fY = y;
}

// Getters:
inline double TwoVector::X() const { return fX; }
inline double TwoVector::Y() const { return fY; }

// Vector Specific Operations
inline double TwoVector::Mag() const { return sqrt(pow(fX,2) + pow(fY,2)); }
inline double TwoVector::Dot(const TwoVector &p) const { return fX*p.X() + fY*p.Y(); }
double TwoVector::Length(TwoVector a) { return sqrt(pow(fX - a.X(),2) + pow(fY - a.Y(), 2)); }
double TwoVector::Angle(TwoVector a) {
  // calculates the inverse tangent of the opposite and adjacent sides of a triangle
  double dy = fY - a.Y();
  double dx = fX - a.X();

  double angle;
  if (dx == 0) {
    if (dy > 0) angle = 2 * qAtan(1);
    else angle = 6 * qAtan(1);
  }
  if (dy == 0) {
    if (dx > 0) angle = 0;
    else if (dx < 0) angle = 4 * qAtan(1);
  }
  if (dx > 0) angle = qAtan(dy/dx);
  if (dx < 0) angle = 2 * qAtan(1) + qAtan(dy/dx);
  return angle;
}

// Operators:
inline TwoVector & TwoVector::operator = (const TwoVector &p) {
  fX = p.fX;
  fY = p.fY;
  return *this;
}

inline TwoVector & TwoVector::operator += (const TwoVector &p) {
  fX += p.fX;
  fY += p.fY;
  return *this;
}

inline TwoVector & TwoVector::operator -= (const TwoVector &p) {
  fX -= p.fX;
  fY -= p.fY;
  return *this;
}

inline TwoVector & TwoVector::operator *= (double a) {
  fX *= a;
  fY *= a;
  return *this;
}

#endif /* TWOVECTOR_H_ */






