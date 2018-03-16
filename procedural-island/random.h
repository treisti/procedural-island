#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>
#include <time.h>

// Random handle

class Random
{
public:
    static void randomize(); // Initialize random
    static double between(double a, double b); // Random between two double
};

#endif // RANDOM_H
