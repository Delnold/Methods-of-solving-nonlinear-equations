#include "relaxation_method.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func_R(double x) {
    return x - 0.048 * func_point_R(x);
    
}
double func_point_R(double x) {
    return pow(x, 3) - 6 * pow(x, 2) + 5 * x + 12;
}

int max_iterations_R(double &eps)
{
    return int(log(1/eps)/log(1/0.433)) + 1;
}

void relaxation_method(double epsilon) {
    double x0 = -0.5;
    int count = 0;
    double x_previous = x0;
    double x_next = func_R(x_previous);
    cout << endl;
    cout << "Relaxation_method:" << endl;
    cout << "Epsilon: " << epsilon << endl;
    cout << "Estimated iteration: " << max_iterations_R(epsilon) << endl;
    cout << "Count "<< count << "\t" << "x=" << x_previous << "\t" << "f(x)=" << func_point_R(x_previous) << endl;

    while(abs(x_next - x_previous) > epsilon)
    {
        count++;
        cout << "Count "<< count << "\t" << "x=" << fixed <<setprecision(15) << x_next << "\t" << "f(x)=" << func_point_R(x_next) << endl;
        x_previous = x_next;
        x_next = func_R(x_next);
    }
    cout << "Done in " << count << " steps";
}