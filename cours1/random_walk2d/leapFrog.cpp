//
// Created by lucas on 09/03/2020.
//

#include "leapFrog.h"

void leapfrog(double *x, double *v, double d_t, double (*acceleration)(double, double)) {
    *x += .5 * (*v) * d_t;
    *v += acceleration(*x, *v) * d_t;
    *x += 1. / 2. * (*v) * d_t;
}
