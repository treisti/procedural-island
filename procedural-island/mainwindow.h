#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <string>
#include "preview2d.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void generate(); // Generate map
    void updateSmoothness(double value);
    void updateWidth(int value);
    void updateHeight(int value);

private:
    Ui::MainWindow *ui;

    double smoothness = 1.0;
    int width = 256;
    int height = 256;
};

#endif // MAINWINDOW_H
