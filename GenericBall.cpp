/* Author: Jack Henshaw
 * Created on: 03/04/2022
 * Last edited: 03/04/2022
 * Implementation of a GenericBall - The parent ball if you will
 */

#include "GenericBall.h"

GenericBall::GenericBall() {
  // seed random number generator
  srand(QDateTime::currentMSecsSinceEpoch());

  // generate random position (between +-200) and velocity
  double rand1 = (rand() % 400) - 200;
  double rand2 = (rand() % 400) - 200;
  fPosition = TwoVector(rand1, rand2);
  fVelocity = TwoVector(2*qCos(rand1), 2*qSin(rand2));

  // draw ball on screen
  setRect(rand1, rand2, fBallSize, fBallSize);
}

GenericBall::GenericBall(TwoVector pos, TwoVector vel) {
  fPosition = pos;
  fVelocity = vel;
  setRect(pos.X(), pos.Y(), fBallSize, fBallSize);
}

GenericBall::~GenericBall() {}

void GenericBall::ContainBall() {
  // check side walls
  if (qFabs(fPosition.X()) + boundingRect().width() >= 250)
    fVelocity.SetX(-fVelocity.X()); // reverse x component
  else if (qFabs(fPosition.Y()) + boundingRect().height() >= 250)
    fVelocity.SetY(-fVelocity.Y());
}

void GenericBall::CollidingBalls() {
  // make list of all balls colliding with the calling ball
  QList<QGraphicsItem *> collidingBalls = collidingItems(Qt::IntersectsItemShape);

  for (int i=0; i<collidingBalls.size(); i++) {
    GenericBall *ball = dynamic_cast<GenericBall *>(collidingBalls[i]);
    if (this->fVelocity.Y() * ball->GetVelocity().Y() > 0) {
      this->fVelocity.SetX(-fVelocity.X());
      ball->SetVelocity(TwoVector(-ball->GetVelocity().X(), ball->GetVelocity().Y()));
    }
    else if (this->fVelocity.Y() * ball->GetVelocity().Y() < 0) {
      this->fVelocity.SetXY(-fVelocity.X(), -fVelocity.Y());
      ball->SetVelocity(TwoVector(-ball->GetVelocity().X(), -ball->GetVelocity().Y()));
    }
  }
}
