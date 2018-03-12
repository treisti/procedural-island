#include "preview2d.h"
#include "ui_preview2d.h"

Preview2D::Preview2D(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Preview2D)
{
    ui->setupUi(this);
}

Preview2D::~Preview2D()
{
    delete ui;
}
