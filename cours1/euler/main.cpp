#include <iostream>
#include <fstream>

using namespace std;

double acc(double position, double velocity) {
    return -9.81;
}

void euler(double *x, double *v, double d_t) {
    *x += *v * d_t;
    v += acc(*x, *v) * d_t;
}

int main() {
    cout << "Freefall with Euler method" << endl;

    ofstream dataFile;
    dataFile.open("data.txt");

    double d_t = .001;
    double x = 10.;
    double v, t = 0;
    do {
        t += d_t;
        euler(&x,&v,d_t);
        dataFile << t << " " << x << " " << v << endl;
    } while (x > 0);

    dataFile.close();

    return 0;
}

