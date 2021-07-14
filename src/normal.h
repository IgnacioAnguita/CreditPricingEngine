#ifndef NORMAL_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define NORMAL_H

#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

const double OneOverRootTwoPi = 0.398942280401433;

double NormalDensity(double x);

double InverseCumulativeNormal(double u);

double CumulativeNormal(double x);

#endif
