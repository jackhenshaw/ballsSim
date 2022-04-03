/* Author: Jack Henshaw
 * Created on: 03/04/2022
 * Last edited 03/04/2022
 * Header file for the parent class of all balls
 */

#ifndef GENERICBALL_H_
#define GENERICBALL_H_

#include <QGraphicsEllipseItem>
#include <QTime>
#include <QtMath>
#include "TwoVector.h"

// needed for all daughter classes so include here so only included once.
#include <QBrush>
#include <QPainter>

class GenericBall: public QObject, public QGraphicsEllipseItem {
  Q_OBJECT // allows balls to handle signals and slots

public:
  GenericBall();
  GenericBall(TwoVector position, TwoVector Velocity);
  virtual ~GenericBall();

  // Getters and Setters
  inline TwoVector GetPosition() const { return fPosition; }
  inline void SetPosition(TwoVector position) { fPosition = position; }
  inline TwoVector GetVelocity() const { return fVelocity; }
  inline void SetVelocity(TwoVector velocity) { fVelocity = velocity; }

  // Functions relating to movement of balls
  void ContainBall(); // keep ball inside container
  void CollidingBalls(); // checks for collisions and changes velocity accordingly

  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) = 0;

protected: // protected as wish to be inherited in daughter classes
  virtual void advance(int phase) = 0; // how the ball will move

  TwoVector fPosition;
  TwoVector fVelocity;
  double fBallSize = 20; // size of ball on screen
  double timeStep = 0.5; // time between each evaluation of the balls position
};

#endif /* GENERICBALL_H_ */
