//Newton-Raphson Method
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return pow(x, 3) - 2 * x - 5;
}

double f_prime(double x) {
    return 3 * pow(x, 2) - 2;
}

int main() {
    int n = 0;
    double x0 = 2.0;
    double tolerance = 0.0001;
    int max_iterations = 100;

    cout << "Iteration     x_n       f(x_n)      |x_{n+1} - x_n|" << endl;
    cout << "----------------------------------------------------------------" << endl;

    while (n < max_iterations) {
        double fx = f(x0);
        double fpx = f_prime(x0);

        if (fabs(fpx) < 0.0001) {
            cout << "Derivative near zero. Newton-Raphson method fails." << endl;
            break;
        }


        double x1 = x0 - fx / fpx;
        double diff = fabs(x1 - x0);

        cout << setw(5) << n + 1 << "   " << fixed << setprecision(6) << x0
             << "   " << fx << "   " << diff << endl;


        if (diff < tolerance) {
            cout << "----------------------------------------------------------------" << endl;
            cout << "The approximate root is: " << fixed << setprecision(4) << x1 << endl;
            break;
        }

        x0 = x1;
        n++;
    }

    if (n >= max_iterations) {
        cout << "----------------------------------------------------------------" << endl;
        cout << "Did not converge within " << max_iterations << " iterations." << endl;
    }

    return 0;
}
