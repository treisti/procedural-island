#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include <math.h>
#include <vector>
#include "random.h"
#include <QDebug>

class Heightmap
{
public:
    Heightmap(int _xSize, int _ySize);
    void clear(); // Clear the heightmap
    void diamondSquare(double smoothness); // Heightmap generation using diamond-square algorithm
    double getXSize();
    double getYSize();
    double get(int x, int y);
    void normalize(double a, double b);
private:
    std::vector<std::vector<double> > map;
    int xSize, ySize;

    // Diamond-square algorith fonctions
    double square(int x, int y, int step, std::vector<std::vector<double> > map);
    double diamond(int x, int y, int step, std::vector<std::vector<double> > map, int size);
};

#endif // HEIGHTMAP_H
