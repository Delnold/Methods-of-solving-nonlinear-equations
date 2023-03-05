#include "NewTon_method.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func_NT(double x) {
    return x - func_point_NT(x) / (3 * pow(x,2) +  6*  x - 1)  ;
    
}
double func_point_NT(double x) {
        return pow(x, 3) + 3 * pow(x, 2) - x -3;
}

int max_iterations_NT(double &eps)
{
    double x = 6;
    double y = 13;
    double z = x / y;
    return int(log2((log(0.4/eps)/log(1/z))+1)) + 1;
}

void newton_method(double epsilon) {
    double x0 = 1.2;
    int count = 0;
    double x_previous = x0;
    double x_next = func_NT(x_previous);
    cout << endl;
    cout << "NewTon method:" << endl;
    cout << "Epsilon: " << epsilon << endl;
    cout << "Estimated iteration: " << max_iterations_NT(epsilon) << endl;
    cout << "Count "<< count << "\t" << "x=" << x_previous << "\t" << "f(x)=" << func_point_NT(x_previous) << endl;

    while(abs(x_next - x_previous) >= epsilon)
    {
        count++;
        cout << "Count "<< count << "\t" << "x=" << fixed <<setprecision(15) << x_next << "\t" << "f(x)=" << func_point_NT(x_next) << endl;
        x_previous = x_next;
        x_next = func_NT(x_next);
    }
    cout << "Done in " << count << " steps";
}