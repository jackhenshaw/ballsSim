/* Author: Jack Henshaw
 * Created on: 03/04/2022
 * Last edited: 03/04/2022
 * Implementation of a StandardBall
 */

#include "StandardBall.h"

StandardBall::StandardBall() : GenericBall() {}

StandardBall::StandardBall(TwoVector pos, TwoVector vel) : GenericBall(pos, vel) {}

StandardBall::~StandardBall() {};

void StandardBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                         QWidget *widget) {
  Q_UNUSED(option);
  Q_UNUSED(widget);
  painter->fillPath(shape(), QBrush(Qt::red));   // fill
  painter->strokePath(shape(), QPen(Qt::black)); // outline
}

void StandardBall::advance(int phase) {
  /* advance works in two stages, first it notifies all items that the scene is
   * about to change (phase=0), then all items are notified that they can move
   * (phase 1).
   */
  if (!phase) return;

  // update position
  fPosition.SetXY(fPosition.X() + timeStep*fVelocity.X(),
                  fPosition.Y() + timeStep*fVelocity.Y());
  setRect(fPosition.X(), fPosition.Y(), fBallSize, fBallSize);
  ContainBall();
  CollidingBalls();
}
