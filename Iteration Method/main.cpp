//Iteration Method
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func(double x){
    return 1 / sqrt(x + 1);
}

int main(){
    int n = 0;
    double x0 = 1.0;
    double x_n = func(x0);
    float tolerance = 0.0001;
    int max_ite = 100;


    cout << "Iteration     x_n       g(x_n)       |x_{n+1} - x_n|" << endl;
    cout << "--------------------------------------------" << endl;

    while (fabs(x_n - x0) >= tolerance && n < max_ite) {

        cout << setw(5) << n + 1 << "   " << fixed << setprecision(6) << x0
             << "   " << x_n << "   " << fabs(x_n - x0) << endl;

        x0 = x_n;
        x_n = func(x0);
        n++;
    }


    if (fabs(x_n - x0) < tolerance) {
        cout << "------------------------------------------------" << endl;
        cout << "The approximate root is: " << x_n << endl;
    } else {
        cout << "------------------------------------------------" << endl;
        cout << "Did not converge within " << max_ite << " iterations." << endl;
    }

    return 0;
}
