/* Author: Jack Henshaw
 * Created on:  03/04/2022
 * Last edited: 03/04/2022
 * Implementation file for the control window
 */

#include "ControlWindow.h"
#include "ui_ControlWindow.h"

ControlWindow::ControlWindow(QWidget *parent, Simulation *sim) : QMainWindow(parent), ui(new Ui::ControlWindow) {
  fSim = sim;

  // Set-up window
  ui->setupUi(this);
  setWindowTitle("Control Window");

  // Start simulation in an idle state
  ui->startButton->setStyleSheet("background-color:green");
  fStatus = kIdle;

  // Start with 0 balls on the screen
  fTotalBalls = 0;
  ui->totalBallCount->setText(QString::number(fTotalBalls));

  // Format the colour and border of the add ball buttons
  WhiteAddBoxes();

  // Format colour of delete ball buttons
  ui->deleteStandardBall->setStyleSheet("background-color:#3C3B3A");
}

ControlWindow::~ControlWindow() { delete ui; }

void ControlWindow::UpdateStandardNum() {
  ui->standardBallNum->setText(QString::number(fSim->StandardListSize()));
  ui->totalBallCount->setText(QString::number(fSim->TotalBallNum()));
}

void ControlWindow::WhiteAddBoxes() {
  ui->addStandardBall->setStyleSheet("background-color:white");
  ui->addStandardBall->setStyleSheet("border:2px solid #000000");
}

void ControlWindow::GreyAddBoxes() {
  ui->addStandardBall->setStyleSheet("background-color:#3C3B3A");
}

void ControlWindow::on_startButton_clicked() {
  if (fStatus == kIdle) {
    ui->startButton->setStyleSheet("background-color:red");
    ui->startButton->setText("Stop");
    fSim->StartSim();
    fStatus = kRun;
  }
  else {
    ui->startButton->setStyleSheet("background-color:green");
    ui->startButton->setText("Start");
    fSim->StopSim();
    fStatus = kIdle;
  }
}

void ControlWindow::on_addStandardBall_clicked() {
  // Limit the number of balls allowed (for CPU performance)
  if (fSim->TotalBallNum() < 20) {
    ui->deleteStandardBall->setStyleSheet("background-color:white");
    ui->deleteStandardBall->setStyleSheet("border:2px solid #000000");

    fSim->AddStandard();
    UpdateStandardNum();

    if (fSim->TotalBallNum() == 20) GreyAddBoxes();
  }
}

void ControlWindow::on_deleteStandardBall_clicked() {
  fSim->RemoveStandard();
  UpdateStandardNum();

  if (fSim->TotalBallNum() < 20) WhiteAddBoxes();
  if (fSim->StandardListSize() == 0)
    ui->deleteStandardBall->setStyleSheet("background-color:#3C3B3A");
}
