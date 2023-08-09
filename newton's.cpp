//
//  main.cpp
//  newton's
//
//  Created by Vika Granadzer on 20.02.2023.
//
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double f(double x) {
    return (x+1)*sinh(0.1*x+1)-x-15;
}

double f1(double x) {
    return -1 + 0.1*(1 + x)*cosh(1 + 0.1*x) + sinh(1 + 0.1*x);
}

double f2(double x) {
    return 0.01*(1 + x)*sinh(1 + 0.1*x) + 0.2*cosh(1 + 0.1*x);
}

int main() {
    double eps = 0.0001; //точність обчислення - може змінюватись
    double x0; //початкове наближення - може змінюватись, наразі обирається автоматично з кордонів проміжку

    int n = 0;
    double delta;
    double a = -12.5, b = -12;
    int n0;

    double q = 0.024334921516;
    n0 = int(log2(log((abs(a-b))/eps)/log(1/q)) + 1) + 1;
    cout << "Апріорна оцінка кількості ітерацій = " << n0 << endl << endl;

    if (f(a) * f2(a)>0) //обираємо перше наближення
        x0 = a;
    else
        x0 = b;
    
    if (f(x0)* f2(x0) < 0){
        cout << "x0 - початкове наближення - обрано неправильно" << endl;
        return 0;
    }
    double xn = x0;

    for (int i = 0; i <n0; i++){
        xn = x0 - f(x0)/f1(x0);
        delta = fabs(x0-xn);
        x0 = xn;
        n++;
        cout << "Ітерація: " << setw(2) << setprecision(2) << n << " | " << "x(k): " << setw(18) << setprecision(13) << xn << " | x(k)-x(k-1): " << setw(20) << setprecision(13) << delta <<" | f(x): " << setw(14) <<  setprecision(13) << f(xn) << endl;
    }
    
    cout << endl << "Корінь xn = " << xn << " | f(xn) = "<< f(x0) << endl;
    cout << "Кількість ітерацій = " << n << "\n";
    return 0;
}
