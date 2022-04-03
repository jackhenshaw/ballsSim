/* Author: Jack Henshaw
 * Created on:  03/04/2022
 * Last edited: 03/04/2022
 * Header file for the control window
 */

#ifndef CONTROLWINDOW_H_
#define CONTROLWINDOW_H_

#include "Simulation.h"

#include <QMainWindow>

namespace Ui {
  class ControlWindow;
}

class ControlWindow : public QMainWindow {
  Q_OBJECT // allows control window to handle signals and slots

public:
  explicit ControlWindow(QWidget *parent=0, Simulation *sim=0);
  ~ControlWindow();

  // Update text with number of balls
  void UpdateStandardNum();

  // styling of buttons
  void WhiteAddBoxes();
  void GreyAddBoxes();

private slots:
  void on_startButton_clicked();

  // adding/removing balls
  void on_addStandardBall_clicked();
  void on_deleteStandardBall_clicked();

private:
  Ui::ControlWindow *ui;
  Simulation *fSim;

  enum {
    kIdle,
    kRun
  };
  int fStatus;

  double fTotalBalls;
};

#endif /* CONTROLWINDOW_H_ */
