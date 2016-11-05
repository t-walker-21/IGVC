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
        comm->write("1000");
    }

    if (ui->steerPosition->value() == GRADUAL_LEFT)
     {
        ui->steerLabel->setText("Gradual Left");
        comm->write("2000");
     }

    if (ui->steerPosition->value() == CENTER)
        {
        ui->steerLabel->setText("Center");
        comm->write("3000");
        }

    if (ui->steerPosition->value() == GRADUAL_RIGHT)
        {
        ui->steerLabel->setText("Gradual Right");
        comm->write("4000");
        }

    if (ui->steerPosition->value() == FULL_RIGHT)
        {
        ui->steerLabel->setText("Full Right");
        comm->write("5000");
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
        qDebug() << "Closing serial port\n\n";
    }

    else{
        if (ui->comPortName->text() == "default")
        {
            comm->setPortName("/dev/ttyAMA0");
        }

        else
        {
            comm->setPortName(ui->comPortName->text());
        }

        if(comm->open(QIODevice::ReadWrite)) //attempt to open port
        {
            ui->portClt->setText("Close Port");
            qDebug() << "Successfully opened serial port\n";
        }

        else
        {
        qDebug() << "could not open serial port\n";
        ui->portClt->setText("Open Port");
        }
    }
}


bool MainWindow::event(QEvent *event)
{
    if (!event || event->type() != QEvent::KeyPress)
            return QMainWindow::event(event);

        QKeyEvent* ke = static_cast<QKeyEvent*>(event);

        switch(ke->key())
        {
        case Qt::Key_S:
            stop();
            break;

        case Qt::Key_1:
            ui->speedLevel->setSliderPosition(1);
            comm->write("1");
            break;

        case Qt::Key_2:
                    ui->speedLevel->setSliderPosition(2);
                    comm->write("1");
                    break;

        case Qt::Key_3:
                    ui->speedLevel->setSliderPosition(3);
                    comm->write("3");
                    break;

        case Qt::Key_4:
                    ui->speedLevel->setSliderPosition(4);
                    comm->write("4");
                    break;

        case Qt::Key_M:
            ui->speedLevel->setSliderPosition(ui->speedLevel->value() - 1);
            comm->write(ui->speedLabel->text().toStdString().c_str());
            updateThrottleLabel();
            break;


        case Qt::Key_A:
            ui->steerPosition->setSliderPosition(ui->steerPosition->value() - 1);
            updateSteerLabel();
            break;

        case Qt::Key_F:
            ui->steerPosition->setSliderPosition(ui->steerPosition->value() + 1);
            updateSteerLabel();
            break;


        }

        return true;
}
