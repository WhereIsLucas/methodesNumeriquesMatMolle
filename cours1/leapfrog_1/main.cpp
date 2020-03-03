#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double acc(double position, double velocity)
{
    double force;
    double chargeElectron = 1.6*pow(10,-19);
    force = 9*pow(10,9)*chargeElectron*chargeElectron/pow(position-0,2);
    double m =9*pow(10,-31);
    return force/m;
}


int main() {
    cout << "Fixed electron approched by mmoving electron" << endl;

    ofstream myfile;
    myfile.open("data.txt");

    double d_t = .001;
    double MAX_TIME = 2;

    double t = 0;
    double v  = 1;
    double x = 10;
    do{
        x = x + v*d_t;
        v = v + acc(x,v)*d_t;
        t+= d_t;
        myfile << t << " " << x << " " << v << endl;
    }while(t<MAX_TIME);

    myfile.close();

    return 0;
}