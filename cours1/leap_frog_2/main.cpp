#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double acc(double position, double velocity)
{
    double force = 0;
    double r = .01;
    double volume = (4./3.)*3.14*pow(r,3);

    double p_ball = 2000;
    double p_fluid = 1000;
    double eta_fluid = 10*pow(10,-3);

    force+= -9.81*p_ball*volume;
    force+= 9.81*p_fluid*volume;
    force+= -6*3.14*eta_fluid*r*velocity;

    return force/(p_ball*volume);
}


int main() {
    cout << "Ball falling into a viscous fluid" << endl;

    ofstream dataFile;
    dataFile.open("data.txt");

    double d_t = .0001;
    double MAX_TIME = 2;

    double t = 0;
    double v  = 0;
    double x = 10.;
    do{
        x += 1./2.*v*d_t;
        v += acc(x,v)*d_t;
        x += 1./2.*v*d_t;
        t+= d_t;
        dataFile << t << " " << x << " " << v << endl;
    }while(t<MAX_TIME);

    dataFile.close();

    return 0;
}