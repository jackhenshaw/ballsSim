/* Author: Jack Henshaw
 * Created on: 01/04/2022
 * Last edited 03/04/2022
 * Main source file to control the simulation
 */

#include "ControlWindow.h"
#include "DisplayWindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  // Create a simulation
  Simulation sim;

  // Create display window
  DisplayWindow dw(0, &sim);
  dw.show();
  dw.move(dw.pos().x() - 200, dw.pos().y());

  // Create control window
  ControlWindow cw(0, &sim);
  cw.show();
  cw.move(dw.pos().x() + dw.width() + 100, dw.rect().center().y() - cw.height()/2);

  return app.exec();
}
