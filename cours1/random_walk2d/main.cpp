#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include "leapFrog.h"

using namespace std;

double acc(double position, double velocity) {
    double m = 1;
    double width = 1;
    double random = ((rand() % 2000) - 1000) / 1000.;
    double acc = random * width;
    return acc / m;
}


int main() {
    //Init the random seed
    srand(time(NULL));

    cout << "Random Walk 2D" << endl;

    ofstream dataFile;
    dataFile.open("data.txt");

    double d_t = .01;
    double MAX_TIME = 100;

    double t = 0;
    double v_y = 0;
    double v_x = 0;
    double y = 0;
    double x = 0;
    while (t < MAX_TIME) {
        //LeapFrog for x and y
        leapfrog(&x, &v_x, d_t, acc);
        leapfrog(&y, &v_y, d_t, acc);
        t += d_t;
        dataFile << t << " " << x << " " << y << endl;
        /* to plot this on the 2d plan use gnuplot with
         * p "data.txt" using 2:3 */
    }
    dataFile.close();

    return 0;
}