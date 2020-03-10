//
// Created by lucas on 10/03/2020.
//

#ifndef CELL_SYSTEM_PARTICLE_H
#define CELL_SYSTEM_PARTICLE_H

class Particle {
public:
    double x;
    double y;
    int cell_index;
    int linkedParticle;

    void setCellIndex(Particle particle, double d, double d1, int i);
};


#endif //CELL_SYSTEM_PARTICLE_H
