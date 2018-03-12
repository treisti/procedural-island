#include "heightmap.h"

Heightmap::Heightmap(int _xSize, int _ySize): xSize(_xSize), ySize(_ySize)
{
    clear();
}

void Heightmap::clear()
{
    map = std::vector<std::vector<double> >();

    for(int i=0; i<xSize; i++)
    {
        map.push_back(std::vector<double>());

        for(int j=0; j<ySize; j++)
        {
            map[i].push_back(0.0);
        }
    }
}

void Heightmap::diamondSquare(double smoothness)
{
    // Diamond Square generation must have a map size of (2^n)+1
    int n = 0;
    while(pow(2, n)+1 < (xSize < ySize)?ySize:xSize)
    {
        n++;
    }
    int size = pow(2, n)+1;

    // Generation map initialisation
    std::vector<std::vector<double> > gen;
    for(int i=0; i<size; i++) {
        gen.push_back(std::vector<double>());
        for(int j=0; j<size; j++) {
            gen[i].push_back(0.0);
        }
    }

    gen[0][0]=Random::between(0.0, 1.0);
    gen[0][size-1]=Random::between(0.0, 1.0);
    gen[size-1][0]=Random::between(0.0, 1.0);
    gen[size-1][size-1]=Random::between(0.0, 1.0);

    // Generation
    int step = size-1;
    while(step > 1)
    {
        // Square
        for(int i = step/2; i<size; i+=step)
        {
            for(int j = step/2; j<size; j+=step)
            {
                gen[i][j] = square(i, j, step, gen);
                gen[i][j] += Random::between(0.0, 1.0) * (smoothness * (double)step) * 2 - (smoothness * (double)step);
            }
        }

        // Diamond
        for(int i = step/2; i<size; i+=step/2)
        {
            for(int j = ((i/(step/2))%2==0)?step/2:0; j<size; j+=step)
            {
                gen[i][j] = diamond(i, j, step, gen, size);
                gen[i][j] += Random::between(0.0, 1.0) * (smoothness * (double)step) * 2 - (smoothness * (double)step);
            }
        }

        step /= 2;
    }
}

double Heightmap::square(int x, int y, int step, std::vector<std::vector<double> > map)
{
    double cornerA, cornerB, cornerC, cornerD;

    cornerA = map[x + (step/2)][y - (step/2)];
    cornerB = map[x - (step/2)][y + (step/2)];
    cornerC = map[x + (step/2)][y + (step/2)];
    cornerD = map[x - (step/2)][y - (step/2)];

    return (cornerA + cornerB + cornerC + cornerD) / 4.0;
}

double Heightmap::diamond(int x, int y, int step, std::vector<std::vector<double> > map, int size)
{
    double cornerA, cornerB, cornerC, cornerD;
    double n = 0.0;

    if(x + (step/2) < size)
    {
        cornerA = map[x + (step/2)][y];
        n++;
    } else
    {
        cornerA = 0.0;
    }

    if(x - (step/2) >= 0)
    {
        cornerB = map[x - (step/2)][y];
        n++;
    } else
    {
        cornerB = 0.0;
    }

    if(y + (step/2) < size)
    {
        cornerC = map[x][y + (step/2)];
        n++;
    } else
    {
        cornerC = 0.0;
    }

    if(y - (step/2) >= 0.0)
    {
        cornerD = map[x][y - (step/2)];
        n++;
    } else
    {
        cornerD = 0.0;
    }

    return (cornerA + cornerB + cornerC + cornerD) / n;
}
