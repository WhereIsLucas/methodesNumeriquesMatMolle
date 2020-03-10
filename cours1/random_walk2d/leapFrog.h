//
// Created by lucas on 09/03/2020.
//


#ifndef RANDOM_WALK_LEAPFROG_H
#define RANDOM_WALK_LEAPFROG_H
/*
 * this function executes leapfrog method
 * */
void leapfrog(double *x, double *v, double d_t, double acceleration(double position, double velocity));

#endif //RANDOM_WALK_LEAPFROG_H
