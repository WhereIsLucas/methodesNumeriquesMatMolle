#include <iostream>
#include <fstream>

using namespace std;

double acc(double position, double velocity)
{
    return -9.81;
}


int main() {
    cout << "Freefall with Euler method" << endl;

    ofstream myfile;
    myfile.open("data.txt");

    double d_t = .001;
    double x = 10.;
    double v,t = 0;
    do{
        x = x + v*d_t;
        v = v + acc(x,v)*d_t;
        t+= d_t;
        myfile << t << " " << x << " " << v << endl;
    }while(x>0);

    myfile.close();

    return 0;
}

