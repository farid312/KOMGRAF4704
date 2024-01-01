#include <iostream>

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

void translateLine(Point& p1, Point& p2, float translateX, float translateY) {
    // Melakukan translasi pada dua titik
    p1.x += translateX;
    p1.y += translateY;

    p2.x += translateX;
    p2.y += translateY;
}

int main() {
    // Titik-titik awal
    Point startPoint(1.0, 2.0);
    Point endPoint(5.0, 5.0);

    // Menampilkan titik-titik awal
    std::cout << "Initial Points:\n";
    std::cout << "Start Point: (" << startPoint.x << ", " << startPoint.y << ")\n";
    std::cout << "End Point:   (" << endPoint.x << ", " << endPoint.y << ")\n";

    // Faktor translasi
    float translateX = 2.0;
    float translateY = 3.0;

    // Melakukan translasi pada garis
    translateLine(startPoint, endPoint, translateX, translateY);

    // Menampilkan hasil translasi
    std::cout << "\nAfter Translation:\n";
    std::cout << "Start Point: (" << startPoint.x << ", " << startPoint.y << ")\n";
    std::cout << "End Point:   (" << endPoint.x << ", " << endPoint.y << ")\n";

    // Menggambar garis setelah translasi
    drawLine(startPoint, endPoint);

    return 0;
}

