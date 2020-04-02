#include <iostream>
#include <fstream>
#include <cmath>
#include <random>

using namespace std;

const double g = 9.81;
const double m = 1;
const double R = .10;
const double e = .8;


double acc_y(double position, double velocity, double d_t) {
    double force = 0;
    double d = position - R;
    if (d < 0) {
        double k_n = 2 * m * g * position / pow(R / 100, 2);
        force += -k_n * d;
        double eta = -2 *log(e)*sqrt((m*k_n)/(pow(log(e),2)+pow(M_PI,2)));
        force += -eta * d/d_t;
    }
    force += -m * g;

    return force / m;
}

void leapfrog(double *position, double *velocity, double d_t, double acc(double position, double velocity, double d_t)) {
    *position += .5 * (*velocity) * d_t;
    *velocity += acc(*position, *velocity, d_t) * d_t;
    *position += 1. / 2. * (*velocity) * d_t;
}


int main() {

    srand(time(NULL));
    // Choose a random mean between 1 and 6

    cout << "Bouncing ball" << endl;

    ofstream dataFile;
    dataFile.open("data.txt");

    double d_t = .0001;
    double MAX_TIME = 10;

    double t = 0;
    double v_y = 0.;
    double y = 1.;
    do {
        leapfrog(&y, &v_y, d_t, acc_y);
        t += d_t;
        dataFile << t << " " << " " << y << endl;
    } while (t < MAX_TIME);

    dataFile.close();

    return 0;
}