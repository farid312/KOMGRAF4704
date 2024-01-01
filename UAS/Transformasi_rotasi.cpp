#include <iostream>
#include <cmath>

struct Point {
    float x, y;

    // Konstruktor untuk inisialisasi koordinat titik
    Point(float x, float y) : x(x), y(y) {}
};

// Fungsi untuk merotasi titik (x, y) sebesar angle derajat
Point rotatePoint(const Point& point, float angle) {
    float radians = angle * M_PI / 180.0;
    float x = point.x * cos(radians) - point.y * sin(radians);
    float y = point.x * sin(radians) + point.y * cos(radians);
    return {x, y};
}

int main() {
    // Titik awal sebelum rotasi
    Point originalPoint(1.0, 10.0);

    // Sudut rotasi (misalnya, 45 derajat)
    float rotationAngle = 90.0;

    // Panggil fungsi rotasi untuk mengubah titik
    Point rotatedPoint = rotatePoint(originalPoint, rotationAngle);

    // Tampilkan hasil rotasi
    std::cout << "Titik awal: (" << originalPoint.x << ", " << originalPoint.y << ")\n";
    std::cout << "Sudut Rotasi: " << rotationAngle << " derajat\n";
    std::cout << "Titik setelah rotasi: (" << rotatedPoint.x << ", " << rotatedPoint.y << ")\n";

    return 0;
}

