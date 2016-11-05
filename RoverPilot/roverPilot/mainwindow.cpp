#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stopButton->setStyleSheet("background-color: red"); //make stop button red
    connect(ui->stopButton,SIGNAL(clicked()),this,SLOT(stop()));
    connect(ui->steerPosition,SIGNAL(valueChanged(int)),this,SLOT(updateSteerLabel()));
    connect(ui->speedLevel,SIGNAL(valueChanged(int)),this,SLOT(updateThrottleLabel()));
    comm = new QSerialPort(this);
    comm->setPortName("/dev/ttyAMA0");
    comm->setBaudRate(QSerialPort::Baud9600);
            comm->setDataBits(QSerialPort::Data8);
            comm->setParity(QSerialPort::NoParity);
            comm->setFlowControl(QSerialPort::NoFlowControl);
      comm->setStopBits(QSerialPort::OneStop);
    connect(ui->portClt,SIGNAL(clicked()),this,SLOT(serialOpenClose()));

}

MainWindow::~MainWindow()
{
    delete ui;
    comm->close();
}


void MainWindow::stop()
{
    qDebug() << "Stopping Rover" << endl;
    //set throttle to 'stop' level
    comm->write("0");
    ui->speedLevel->setSliderPosition(0);
    ui->steerPosition->setSliderPosition(CENTER);
}

void MainWindow::updateSteerLabel()
{
    if (ui->steerPosition->value() == FULL_LEFT)
    {
        ui->steerLabel->setText("Full Left");
    }

    if (ui->steerPosition->value() == GRADUAL_LEFT)
     {
        ui->steerLabel->setText("Gradual Left");

     }

    if (ui->steerPosition->value() == CENTER)
        {
        ui->steerLabel->setText("Center");

        }

    if (ui->steerPosition->value() == GRADUAL_RIGHT)
        {
        ui->steerLabel->setText("Gradual Right");

        }

    if (ui->steerPosition->value() == FULL_RIGHT)
        {
        ui->steerLabel->setText("Full Right");

        }



    return;

}

void MainWindow::updateThrottleLabel()
{
    ui->speedLabel->setNum(ui->speedLevel->value());

    comm->write(ui->speedLabel->text().toStdString().c_str());
}

void MainWindow::serialOpenClose()
    {
    if (comm->isOpen()){
        comm->close();
        ui->portClt->setText("Open Port");
    }

    else{
        if(comm->open(QIODevice::ReadWrite))
        {
            ui->portClt->setText("Close Port");
            qDebug() << "could not open serial port\n";
        }

        else
        {
        qDebug() << "could not open serial port\n";
        ui->portClt->setText("Open Port");
        }
    }
}
