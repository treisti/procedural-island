#include "heightmap.h"

Heightmap::Heightmap(int _xSize, int _ySize): xSize(_xSize), ySize(_ySize)
{
    clear();
}

void Heightmap::clear()
{
    map = new std::vector<std::vector<double> *>();

    for(int i=0; i<xSize; i++)
    {
        map->push_back(new std::vector<double>());

        for(int j=0; j<ySize; j++)
        {
            map[i][j]->push_back(0.0);
        }
    }
}
