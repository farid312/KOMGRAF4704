#include <iostream>
#include <vector>

struct Point {
    float x;
    float y;

    Point(float x, float y) : x(x), y(y) {}
};

void drawLine(const Point& p1, const Point& p2) {
    // Fungsi untuk menggambar garis antara dua titik
    // (Implementasi sederhana, Anda dapat mengganti atau menyesuaikan sesuai kebutuhan)
    std::cout << "Drawing line from (" << p1.x << ", " << p1.y << ") to (" << p2.x << ", " << p2.y << ")\n";
}

void scaleLine(Point& p1, Point& p2, float scaleX, float scaleY) {
    // Melakukan scaling pada dua titik
    p1.x *= scaleX;
    p1.y *= scaleY;

    p2.x *= scaleX;
    p2.y *= scaleY;
}

int main() {
    // Titik-titik awal
    Point startPoint(1.0, 2.0);
    Point endPoint(5.0, 5.0);

    // Menampilkan titik-titik awal
    std::cout << "Initial Points:\n";
    std::cout << "Start Point: (" << startPoint.x << ", " << startPoint.y << ")\n";
    std::cout << "End Point:   (" << endPoint.x << ", " << endPoint.y << ")\n";

    // Faktor scaling
    float scaleX = 2.0;
    float scaleY = 3.0;

    // Melakukan scaling pada garis
    scaleLine(startPoint, endPoint, scaleX, scaleY);

    // Menampilkan hasil scaling
    std::cout << "\nAfter Scaling:\n";
    std::cout << "Start Point: (" << startPoint.x << ", " << startPoint.y << ")\n";
    std::cout << "End Point:   (" << endPoint.x << ", " << endPoint.y << ")\n";

    // Menggambar garis setelah scaling
    drawLine(startPoint, endPoint);

    return 0;
}

