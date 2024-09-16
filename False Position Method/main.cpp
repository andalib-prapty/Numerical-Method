//False position Method
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double func(double x){
    return pow(x, 3) -2*x - 5;
}

int main(){
    double a = 2, b = 3;
    float tolerance = 0.0001;

    if(func(a) * func(b) >= 0){
        cout << "Invalid Initial Guess" << endl;
    }
    else{
        cout << "Iteration     a       b       m        f(m)" << endl;
        cout << "--------------------------------------------" << endl;
        cout << setprecision(4) << fixed;

        double m;
        int set_ite = 1;
        while(abs((b - a)) >= tolerance){
            m = (a*func(b)-b*func(a))/(func(b)-func(a));

            if(fabs(func(m)) < tolerance){
                break;
            }
            else if(func(m) * func(a) < 0){
                b = m;
            }
            else{
                a = m;
            }

            cout << set_ite << "     " << a << "     " << b << "     " << m << "     " << func(m) << endl;
            set_ite++;
        }
        cout << "--------------------------------------------" << endl;
        cout << "The Root is: " << m << endl;
    }

    return 0;
}

