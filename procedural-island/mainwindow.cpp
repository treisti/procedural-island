#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generate()
{
    Preview2D * preview = new Preview2D();
    Heightmap map = Heightmap(width, height);
    map.diamondSquare(smoothness);
    map.normalize(0.0, 255.0);

    preview->show();
    preview->showHeightmap(map);
}

void MainWindow::updateSmoothness(double value)
{
    smoothness = value;
}

void MainWindow::updateWidth(int value)
{
    width = value;
}

void MainWindow::updateHeight(int value)
{
    height = value;
}
