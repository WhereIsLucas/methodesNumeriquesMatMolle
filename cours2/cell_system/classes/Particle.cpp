//
// Created by lucas on 10/03/2020.
//

#include "Particle.h"

void Particle::setCellIndex(Particle particle, double w_x, double w_y, int Ny) {
    double index_x = (int) particle.x/w_x;
    double index_y = (int) particle.y/w_y;
    Particle::cell_index = (int) (index_x + index_y * Ny);
}
