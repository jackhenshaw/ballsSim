/* Author: Jack Henshaw
 * Created on:  03/04/2022
 * Last edited: 03/04/2022
 * Header file for the display window
 */

#ifndef DISPLAYWINDOW_H_
#define DISPLAYWINDOW_H_

#include "Simulation.h"

#include <QWidget>

namespace Ui {
  class DisplayWindow;
}

class DisplayWindow : public QWidget {
  Q_OBJECT // allows display window to handle signals and slots

public:
  explicit DisplayWindow(QWidget *parent=0, Simulation *sim=0);
  ~DisplayWindow();

private:
  Ui::DisplayWindow *ui;
};

#endif /* DISPLAYWINDOW_H_ */
