#include <iostream>
#include <cmath>

using namespace std;

double area(double radius);
double area(double x1, double y1, double x2, double y2, double x3, double y3);
double area(double x1, double y1, double x2, double y2);
double distance(double x1, double y1, double x2, double y2);

int main() {

    double radius, x1, y1, x2, y2, x3, y3;          // User input

    cout << "Insert the radius: " << endl;
    cin >> radius;
    cout << "Insert the 1st vertice: " << endl;
    cin >> x1 >> y1;
    cout << "Insert the 2nd vertice: " << endl;
    cin >> x2 >> y2;
    cout << "Insert the 3rd vertice: " << endl;
    cin >> x3 >> y3;

    cout << "Area of the circle: " << area(radius) << endl;
    cout << "Area of the triangle: " << area(x1, y1, x2, y2, x3, y3) << endl;
    cout << "Area of the rectangle: " << area(x1, y1, x2, y2) << endl;

    return 0;
}

/**
 * @brief       - Returns the area of a circle, given its radius
 * 
 * @param       - radius (double) 
 * @return      - area (double) 
 */
double area(double radius) {
    return M_PI * pow(radius, 2);
}

/**
 * @brief       - Returns the area of a triangle given 3 vertices
 * 
 * @param       - x1 (double)
 * @param       - y1 (double)
 * @param       - x2 (double)
 * @param       - y2 (double)
 * @param       - x3 (double)
 * @param       - y3 (double)
 * @return      - area (double) 
 */
double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = distance(x1, y1, x2, y2);            // Length of the 1st side
    double b = distance(x1, y1, x3, y3);            // Length of the 2nd side
    double c = distance(x2, y2, x3, y3);            // Length of the 3rd side
    double s = (a + b + c) / 2.0;                   // Semi-perimeter

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

/**
 * @brief       - Returns the area of a rectangle. given 2 opposite vertices
 * 
 * @param       - x1 (double) 
 * @param       - y1 (double) 
 * @param       - x2 (double) 
 * @param       - y2 (double) 
 * @return      - area (double) 
 */
double area(double x1, double y1, double x2, double y2) {
    double width = abs(x2 - x1);
    double height = abs(y2 - y1);

    return width * height;
}

/**
 * @brief       - Returns the distance between 2 points
 * 
 * @param       - x1 (double)
 * @param       - y1 (double)
 * @param       - x2 (double)
 * @param       - y2 (double) 
 * @return      - distance (double) 
 */
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
}