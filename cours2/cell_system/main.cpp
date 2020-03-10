#include <iostream>
#include <random>
#include "classes/Particle.h"
#include "classes/Cell.h"

using namespace std;

int main() {

    //RANDOM C++ 11
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, .0);

    //Set the variables
    double Lx=3, Ly=3;
    int Nx = 3, Ny = 3;
    int N = 80;
    int Ncells = Nx*Ny;
    //width of the cells
    double w_x = (double) Lx/Nx;
    double w_y = (double) Ly/Ny;

    Cell cells[Ncells];
    for (int i = 0; i < Ncells; ++i) {
        Cell cell{};
        cell.index = i;
        cell.hol = -9;
        cell.x = i%Nx * w_x;
        cell.y = int (i/Ny) * w_y;
        cells[i] = cell;
    }

    Particle particles[N];
    for (int i = 0; i < N; ++i) {
        Particle particle{};
        particle.x = Lx* dist(mt);
        particle.y = Ly* dist(mt);

        particle.setCellIndex(particle,w_x,w_y,Ny);
        particles[i] = particle;
    }

    for (int i = 0; i < N; ++i) {
        particles[i].linkedParticle = cells[particles[i].cell_index].hol;
        cells[particles[i].cell_index].hol = i;
    }

    for (int i = 0; i < N; ++i) {
        cout << particles[i].linkedParticle << endl;
    }

    return 0;
}

