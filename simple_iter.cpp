//
//  main.cpp
//  simp iter
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

double fi(double x) {
    return (x+0.3*((x+1)*sinh(0.1*x+1)-x-15));
}

double fif(double x) {
    return (x+0.3*((x+1)*sinh(0.1*x+1)-x-15));
}

#include <iostream>

int main(int argc, const char * argv[]) {
    double eps = 0.0001; //точність обчислення - може змінюватись
    double x0 = -12.5; //початкове наближення - може змінюватись
    
    int n = 0, n0;
    double xn,  delta;
    double q=0.303, dif = fabs(fi(x0)-x0);
    
    string aposterior_txt = "";
    bool aposterior_shown = true;
    
    n0 = int(log(dif/((1-q)*eps))/log(1/q))+1;
    cout << "Апріорна оцінка кількості ітерацій = " << n0 << endl << endl;
    
    for (int i = 0; i < n0; i++){
        xn = fi(x0);
        delta = fabs(xn-x0);
        x0 = xn;
        n++;
        
        cout << "Ітерація: " << setw(2) << setprecision(2) << n << " | " << "x(k): " << setw(18) << setprecision(13) << xn << " | x(k)-x(k-1): " << setw(20) << setprecision(13) << delta <<" | f(x): " << setw(14) <<  setprecision(13) << f(xn) << endl;
        
        if ((delta<=(1-q)/q*eps) && aposterior_shown){
            aposterior_txt = "Виконуються умови збіжності, які випливають з апостеріорної оцінки. Ітерація номер: ";
            cout << aposterior_txt << n << endl;
            aposterior_shown = false;
        }
    }
    

    cout << endl << "Корінь xn = " << x0 << " | f(xn) = "<< f(x0) << endl;
    cout << "Кількість ітерацій = " << n << "\n";
}
