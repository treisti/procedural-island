#ifndef BIOME_H
#define BIOME_H

#include <QColor>

class Biome
{
public:
    Biome(QString _name, QColor _color);

    QString getName();
    QColor getColor();

private:
    QString name;
    QColor color;
};

#endif // BIOME_H
