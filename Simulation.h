/* Author: Jack Henshaw
 * Created on: 03/04/2022
 * Last edited 03/04/2022
 * Header file for the class controlling the simulation
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

#include "StandardBall.h"

class Simulation: public QObject {
  Q_OBJECT

public:
  Simulation();
  ~Simulation();

  QGraphicsScene *GetScene() { return fScene; }

  // controlling the simulation
  void StartSim();
  void StopSim();

  // add/remove balls
  void AddStandard();
  void RemoveStandard();

  // access functions to number of balls in simulation
  int StandardListSize() { return fListStandard.size(); }

private slots:
  void MoveBall();

private:
  QTimer *fSimTimer;
  QGraphicsScene *fScene;
  QList<StandardBall *> fListStandard;

};

#endif /* SIMULATION_H_ */
