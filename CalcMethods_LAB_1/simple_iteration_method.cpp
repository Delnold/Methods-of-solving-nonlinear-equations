#include "simple_iteration_method.h"

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double func_SI(double x) {
    return sqrt(-x + 4 + 4/x)
;
    
}
double func_point_SI(double x) {
    return pow(x,3) + pow(x,2) - 4 * x - 4;
}

int max_iterations_SI(double &eps)
{
    return int(log(abs(S_SI - 1.7 ) / ((1 - Q_SI)*eps)) / log(1/Q_SI)) + 1;
}

void simple_iteration_method(double epsilon)
{
    double x0 = 1.7;
    int count = 0;
    double x_previous = x0;
    double x_next = func_SI(x_previous);
    cout << endl;
    cout << "Simple_iteration method: :" << endl;
    cout << "Epsilon: " << epsilon << endl;
    cout << "Estimated iteration: " << max_iterations_SI(epsilon) << endl;
    cout << "Count "<< count << "\t" << "x=" << x_previous << "\t" << "f(x)=" << func_point_SI(x_previous) << endl;

    while(abs(x_next - x_previous) > epsilon)
    {
        count++;
        cout << "Count "<< count << "\t" << "x=" << fixed <<setprecision(15) << x_next << "\t" << "f(x)=" << func_point_SI(x_next) << endl;
        x_previous = x_next;
        x_next = func_SI(x_next);
    }
    cout << "Done in " << count << " steps";
}