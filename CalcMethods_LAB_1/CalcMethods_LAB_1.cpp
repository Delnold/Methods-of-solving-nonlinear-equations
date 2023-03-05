#include "simple_iteration_method.h"
#include "relaxation_method.h"
#include "NewTon_method.h"
#include <iostream>
using namespace std;


int main() {
    double epsilon;
    cout << "Enter epsilon: ";
    cin >> epsilon;

    simple_iteration_method(epsilon);
    cout << endl;
    newton_method(epsilon);
    cout << endl;
    relaxation_method(epsilon);

    system("pause");
    return 0;
}
