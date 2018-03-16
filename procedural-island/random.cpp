#include "random.h"

void Random::randomize()
{
    srand(time(NULL));
}

double Random::between(double a, double b)
{
    if(a>b)
    {
        double temp = b;
        b = a;
        a = temp;
    }

    return (rand() / (double)RAND_MAX) * (b-a) + a;
}
