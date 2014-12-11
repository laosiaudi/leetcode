// C/C++ File
// AUTHOR:   laosi
// FILE:     solution.cpp
// ROLE:     TODO (some explanation)
// CREATED:  2014-12-11 21:28:22
// MODIFIED: 2014-12-11 22:24:16
#include <iostream>
#include <math.h>
using namespace std;

const double epsilon = 0.0000001;
#define PI 3.14159265

void solve(double a, double b, double c, double d, double e) { //a, b, c, d, e 为五个系数
   double p = -(3*b*b - 8*a*c);
   double q = 3*b*b*b*b + 16*a*a*c*c - 16*a*b*b*c + 16*a*a*b*d - 64*a*a*a*e;
   double r = -(b*b*b - 4*a*b*c + a*a*d)*(b*b*b - 4*a*b*c + a*a*d);

   double A = p*p - 3*q;
   double B = p*q - 9*r;
   double C = q*q - 3*p*r;

   if (A - B < epsilon && A - 0 < epsilon) {
     double y1, y2, y3;
     y1 = y2 = y3 = -p/3;
     double x1 = 0.25*a*(-b + sqrt(y1) + sqrt(y2) + sqrt(y3));
     double x2 = 0.25*a*(-b - sqrt(y1) + sqrt(y2) - sqrt(y3));
     double x3 = 0.25*a*(-b + sqrt(y1) - sqrt(y2) - sqrt(y3));
     double x4 = 0.25*a*(-b - sqrt(y1) - sqrt(y2) + sqrt(y3));
     cout << "x1,x2,x3,x4为\n";
     cout << "x1 = " << x1 << " x2 = " << x2 << " x3 = " << x3
         << " x4 = " << x4 << endl;
   } else if (B*B - 4*A*C - 0 < epsilon) {
     double k = B/A;
     double y1 = -p + k;
     double y3;
     double y2 = y3 = -k/2;

     double x1 = 0.25*a*(-b + sqrt(y1) + sqrt(y2) + sqrt(y3));
     double x2 = 0.25*a*(-b - sqrt(y1) + sqrt(y2) - sqrt(y3));
     double x3 = 0.25*a*(-b + sqrt(y1) - sqrt(y2) - sqrt(y3));
     double x4 = 0.25*a*(-b - sqrt(y1) - sqrt(y2) + sqrt(y3));
     cout << "x1,x2,x3,x4为\n";
     cout << "x1 = " << x1 << " x2 = " << x2 << " x3 = " << x3
         << " x4 = " << x4 << endl;
   } else if (B*B - 4*A*C < 0) {
     double T = (2*A*p - 3*B)/(2*pow(A, 1.5));
     double y1 = -1.0/3*(p + 2*A*cos(1.0/3*acos(T)));
     double y2 = -1.0/3*(p + 2*A*cos(1.0/3*acos(T) + 2*PI/3));
     double y3 = -1.0/3*(p + 2*A*cos(1.0/3*acos(T) - 2*PI/3));

     double x1 = 0.25*a*(-b + sqrt(y1) + sqrt(y2) + sqrt(y3));
     double x2 = 0.25*a*(-b - sqrt(y1) + sqrt(y2) - sqrt(y3));
     double x3 = 0.25*a*(-b + sqrt(y1) - sqrt(y2) - sqrt(y3));
     double x4 = 0.25*a*(-b - sqrt(y1) - sqrt(y2) + sqrt(y3));
     cout << "x1,x2,x3,x4为\n";
     cout << "x1 = " << x1 << " x2 = " << x2 << " x3 = " << x3
         << " x4 = " << x4 << endl;
   } else if (B*B - 4*A*C > 0) {
     double delta1 = c*c - 3*b*d + 12*a*e;
     double delta2 = 2*c*c*c - 9*b*c*d + 27*a*d*d + 27*b*b*e - 72*a*c*e;

     double temp = sqrt(-4*pow(delta1, 3) + pow(delta2, 2));
     double delta = delta1*pow(2, 1.0/3)/(3*a*pow(delta2 + temp,1.0/3)) +
         (3*a*pow(delta2 + temp,1.0/3))/3*a*pow(2, 1.0/3);

     double temp2 = sqrt(b*b/4*a*a - 2*c/3*a + delta);
     double x1 = -b/4*a - 0.5*temp2 - 0.5*sqrt(b*b/2*a*a - 4*c/3*a - delta -
             (-b*b*b/a*a*a + 4*b*c/a*a - 8*d/a)/4*temp2);
     double x2 = -b/4*a - 0.5*temp2 + 0.5*sqrt(b*b/2*a*a - 4*c/3*a - delta -
             (-b*b*b/a*a*a + 4*b*c/a*a - 8*d/a)/4*temp2);
     double x3 = -b/4*a + 0.5*temp2 - 0.5*sqrt(b*b/2*a*a - 4*c/3*a - delta +
             (-b*b*b/a*a*a + 4*b*c/a*a - 8*d/a)/4*temp2);
     double x4 = -b/4*a + 0.5*temp2 + 0.5*sqrt(b*b/2*a*a - 4*c/3*a - delta +
             (-b*b*b/a*a*a + 4*b*c/a*a - 8*d/a)/4*temp2);
     cout << "x1,x2,x3,x4为\n";
     cout << "x1 = " << x1 << " x2 = " << x2 << " x3 = " << x3
         << " x4 = " << x4 << endl;
   }
}

int main() {
    double a,b,c,d,e;
    cout << "依次输入a,b,c,d,e,空格隔开";
    cin >> a >> b >> c >> d >> e;
    solve(a, b, c, d, e);
    return 0;
}
