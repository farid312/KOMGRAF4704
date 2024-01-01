#include <iostream>
#include <cmath>

struct Point3D {
    float x, y, z;

    Point3D(float x, float y, float z) : x(x), y(y), z(z) {}
};

void rotateX(Point3D& point, float angle) {
    float radianAngle = angle * M_PI / 180.0;
    float newY = point.y * cos(radianAngle) - point.z * sin(radianAngle);
    float newZ = point.y * sin(radianAngle) + point.z * cos(radianAngle);
    point.y = newY;
    point.z = newZ;
}

void rotateY(Point3D& point, float angle) {
    float radianAngle = angle * M_PI / 180.0;
    float newX = point.x * cos(radianAngle) + point.z * sin(radianAngle);
    float newZ = -point.x * sin(radianAngle) + point.z * cos(radianAngle);
    point.x = newX;
    point.z = newZ;
}

void rotateZ(Point3D& point, float angle) {
    float radianAngle = angle * M_PI / 180.0;
    float newX = point.x * cos(radianAngle) - point.y * sin(radianAngle);
    float newY = point.x * sin(radianAngle) + point.y * cos(radianAngle);
    point.x = newX;
    point.y = newY;
}

int main() {
    // Membuat titik pada kubus
    Point3D pointA(1.0, 1.0, 1.0);

    // Menampilkan koordinat titik sebelum rotasi
    std::cout << "Before Rotation: (" << pointA.x << ", " << pointA.y << ", " << pointA.z << ")\n";

    // Rotasi pada sumbu X dengan sudut 45 derajat
    rotateX(pointA, 45.0);

    // Rotasi pada sumbu Y dengan sudut 30 derajat
    // rotateY(pointA, 30.0);

    // Rotasi pada sumbu Z dengan sudut 60 derajat
    // rotateZ(pointA, 60.0);

    // Menampilkan koordinat titik setelah rotasi
    std::cout << "After Rotation: (" << pointA.x << ", " << pointA.y << ", " << pointA.z << ")\n";

    return 0;
}

