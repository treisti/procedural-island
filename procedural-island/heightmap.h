#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include <vector>

class Heightmap
{
public:
    Heightmap(int _xSize, int _ySize);
    void clear(); // Clear the heightmap
private:
    std::vector<std::vector<double> *> * map;
    int xSize, ySize;
};

#endif // HEIGHTMAP_H
