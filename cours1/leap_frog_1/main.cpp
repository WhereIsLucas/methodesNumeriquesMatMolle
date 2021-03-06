#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double acc(double position, double velocity)
{
    double force;
    double chargeElectron = 1.6*pow(10,-19);
    double m =9*pow(10,-31);
    force = -(9*pow(10,9)*chargeElectron*chargeElectron)/pow(position-1,2);
    return force/m;
}
void leapfrog(double *x, double *v, double d_t) {
    *x += .5 * (*v) * d_t;
    *v += acc(*x, *v) * d_t;
    *x += 1. / 2. * (*v) * d_t;
}


int main() {
    cout << "Fixed electron approched by mmoving electron" << endl;

    ofstream dataFile;
    dataFile.open("data.txt");

    double d_t = .0001;
    double MAX_TIME = .05;

    double t = 0;
    double v  = 100.;
    double x = 0.;
    do{
        leapfrog(&x,&v,d_t);
        t+= d_t;
        dataFile << t << " " << x << " " << v << endl;
    }while(t<MAX_TIME);

    dataFile.close();

    return 0;
}