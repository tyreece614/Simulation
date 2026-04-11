#include "Utilities.h"

double Distance(double x1, double x2, double y1, double y2)
{
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

