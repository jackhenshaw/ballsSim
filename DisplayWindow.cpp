/* Author: Jack Henshaw
 * Created on:  03/04/2022
 * Last edited: 03/04/2022
 * Implementation file for the display window
 */

#include "DisplayWindow.h"
#include "ui_DisplayWindow.h"

DisplayWindow::DisplayWindow(QWidget *parent, Simulation *sim) : QWidget(parent), ui(new Ui::DisplayWindow) {
  // Set-up display window
  ui->setupUi(this);
  setWindowTitle("Simulation Window");

  // Set the scene in the graphics view and format how this display appears.
  ui->graphicsView->setScene(sim->GetScene());
  ui->graphicsView->setRenderHint(QPainter::Antialiasing);
  ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

DisplayWindow::~DisplayWindow() { delete ui; }
