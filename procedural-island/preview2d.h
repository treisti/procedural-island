#ifndef PREVIEW2D_H
#define PREVIEW2D_H

#include <QWidget>

namespace Ui {
class Preview2D;
}

class Preview2D : public QWidget
{
    Q_OBJECT

public:
    explicit Preview2D(QWidget *parent = 0);
    ~Preview2D();

private:
    Ui::Preview2D *ui;
};

#endif // PREVIEW2D_H
