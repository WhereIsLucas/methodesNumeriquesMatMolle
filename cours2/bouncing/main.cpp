#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double g = 9.81;
const double m = 1;
const double R = .10;
const double dissip = .9;

double acc(double position, double velocity) {
    double force = 0;
    double d = position - R;
    if (d < 0) {
        double k_n = 2 * m * g * position / pow(R / 100, 2);
        force += -k_n * d;
    }
    force += -m * g;
    return force / m;
}

void leapfrog(double *x, double *v, double d_t) {
    *x += .5 * (*v) * d_t;
    *v += acc(*x, *v) * d_t;
    *x += 1. / 2. * (*v) * d_t;
}


int main() {
    cout << "Bouncing ball" << endl;

    ofstream dataFile;
    dataFile.open("data.txt");

    double d_t = .0001;
    double MAX_TIME = 10;

    double t = 0;
    double v = 0.;
    double x = 1.;
    do {
        leapfrog(&x, &v, d_t);
        t += d_t;
        dataFile << t << " " << x << " " << v << endl;
    } while (t < MAX_TIME);

    dataFile.close();

    return 0;
}