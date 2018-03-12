#include "preview2d.h"
#include "ui_preview2d.h"

Preview2D::Preview2D(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Preview2D)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

Preview2D::~Preview2D()
{
    delete ui;
}

void Preview2D::showHeightmap(Heightmap heightmap)
{
    for(int i = 0; i < heightmap.getXSize(); i++)
    {
        for(int j = 0; j < heightmap.getYSize(); j++)
        {
            QColor color = QColor(heightmap.get(i, j), heightmap.get(i, j), heightmap.get(i, j));
            scene->addRect(i*4, j*4, 4, 4, QPen(color), QBrush(color));
            qDebug() << heightmap.get(i, j);
        }
    }
}
