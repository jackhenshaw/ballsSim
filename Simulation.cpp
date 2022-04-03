/* Author: Jack Henshaw
 * Created on: 03/04/2022
 * Last edited 03/04/2022
 * Implementation file for the class controlling the simulation
 */

#include "Simulation.h"

#include <QDebug>

Simulation::Simulation() {
  // set scene
  fScene = new QGraphicsScene();
  fScene->setSceneRect(-250, 250, 500, 500);
  // prepare timer
  fSimTimer = new QTimer(this);
  connect( fSimTimer, SIGNAL(timeout()), this, SLOT(MoveBall()) );
  fSimTimer->setInterval(10);
}

Simulation::~Simulation() {
  delete fSimTimer;
  delete fScene;
}

void Simulation::StartSim() {
  fSimTimer->start();
}

void Simulation::StopSim() {
  fSimTimer->stop();
}

void Simulation::AddStandard() {
  StandardBall *ball = new StandardBall();
  fScene->addItem(ball);
  fListStandard.append(ball);
  fListTotal.append(ball);
}

void Simulation::RemoveStandard() {
  if (fListStandard.size() == 0) return;
  StandardBall *ball = fListStandard.last();
  fScene->removeItem(ball);
  fListStandard.removeLast();
  fListTotal.removeLast();
  delete ball;
}

void Simulation::MoveBall() {
  fScene->advance();
}
