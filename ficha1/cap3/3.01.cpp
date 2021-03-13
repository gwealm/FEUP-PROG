#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double area(double x1, double y1, double x2, double y2, double x3, double y3);
double distance(double x1, double y1, double x2, double y2);

int main() {
    
    double x1, y1, x2, y2, x3, y3;

    cout << "Input the coordenates of the first vertice: ";
    cin >> x1 >> y1 ;

    cout << "Input the coordenates of the second vertice: ";
    cin >> x2 >> y2 ;

    cout << "Input the coordenates of the third vertice: ";
    cin >> x3 >> y3;

    cout << fixed << setprecision(3) << "The area of the triangle is " << area(x1, y1, x2, y2, x3, y3) << " U.A" << endl;

    return 0;
}


double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double s, a, b, c;
    a = distance(x1, y1, x2, y2);
    b = distance(x1, y1, x3, y2);
    c = distance(x2, y2, x3, y3);
    s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) *  (s- c));
}


double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}