#include "biome.h"

Biome::Biome(QString _name, QColor _color): name(_name), color(_color)
{

}

QString Biome::getName()
{
    return name;
}

QColor Biome::getColor()
{
    return color;
}
