#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double acc(double position, double velocity)
{
    double force;
    double chargeElectron = 1.6*pow(10,-19);
    force = -(9*pow(10,9)*chargeElectron*chargeElectron)/pow(position-1,2);
    double m =9*pow(10,-31);
    return force/m;
}


int main() {
    cout << "Fixed electron approched by mmoving electron" << endl;

    ofstream myfile;
    myfile.open("data.txt");

    double d_t = .0001;
    double MAX_TIME = .05;

    double t = 0;
    double v  = 100.;
    double x = 0.;
    do{
        x += 1./2.*v*d_t;
        v += acc(x,v)*d_t;
        x += 1./2.*v*d_t;
        t+= d_t;
        myfile << t << " " << x << " " << v << endl;
    }while(t<MAX_TIME);

    myfile.close();

    return 0;
}