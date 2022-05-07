#include "zxc.h"

Equilateral_Triangle::Equilateral_Triangle() {
    v1.x = 0;
    v1.y = 0;
    v2.x = 0;
    v2.y = 0;
    v3.x = 0;
    v3.y = 0;
    mass_in = 0;
}

void Equilateral_Triangle::initFromDialog() {
    cout << "Enter coordinates of corner points: " << endl;
    cin >> v1.x >> v1.y >> v2.x >> v2.y >> v3.x >> v3.y;
    cout << "Enter mass of the object: " << endl;
    cin >> mass_in;
}

double Equilateral_Triangle::square() {
    return (((pow((v2.x - v1.x), 2) + pow((v2.y - v1.y), 2)) * sqrt(3)) / 4);
}

double Equilateral_Triangle::perimeter() {
    return (3 * sqrt(pow((v2.x - v1.x), 2) + pow((v2.y - v1.y), 2)));
}

double Equilateral_Triangle::mass() {
    return mass_in;
}

Vector2D Equilateral_Triangle::position() {
    Vector2D centre;
    centre.x = (v1.x + v2.x + v3.x) / 3;
    centre.y = (v1.y + v2.y + v3.y) / 3;
    return centre;
}

void Equilateral_Triangle::draw() {
    cout << "Coordinates: (" << v1.x << ", " << v1.y << ") (" << v2.x << ", " << v2.y << ") (" << v3.x << ", "
         << v3.y << ")" << endl;;
    cout << "Mass: " << mass_in << endl;
}

const char *Equilateral_Triangle::classname() {
    return "Equilateral Triangle!";
}

int Equilateral_Triangle::size() {
    return sizeof(*this);
}

Ellipse::Ellipse() {
    xCenter = 0;
    yCenter = 0;
    a = 0;
    b = 0;
    mass_in = 0;
}

void Ellipse::initFromDialog() {
    cout << "Enter coordinates of a center of the ellipse :" << endl;
    cin >> xCenter >> yCenter;
    cout << "Enter a and b : " << endl;
    cin >> a >> b;
    cout << "Enter mass : " << endl;
    cin >> mass_in;
}

double Ellipse::square() {
    return M_PI * a * b;
}

double Ellipse::perimeter() {
    return 4 * (M_PI * a * b + a - b) / (a + b);
}

double Ellipse::mass() {
    return mass_in;
}

Vector2D Ellipse::position() {
    Vector2D centre;
    centre.x = xCenter;
    centre.y = yCenter;
    return centre;
}

void Ellipse::draw() {
    cout << "Coordinates of a center: (" << xCenter << ", " << yCenter << ")" << endl;
    cout << "a = : " << a << " b = " << b << endl;
    cout << "Mass: " << mass_in << endl;
}

const char *Ellipse::classname() {
    return "Ellipse!";
}

int Ellipse::size() {
    return sizeof(*this);
}