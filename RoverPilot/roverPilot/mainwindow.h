#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSerialPort* comm;

    enum STEERING{
        FULL_LEFT,
        GRADUAL_LEFT,
        CENTER,
        GRADUAL_RIGHT,
        FULL_RIGHT
    };

private slots:
    void stop();
    void updateSteerLabel();
    void updateThrottleLabel();
    void serialOpenClose();
};

#endif // MAINWINDOW_H
