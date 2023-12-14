#include <iostream>

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

const int xMin = 1;
const int xMax = 4;
const int yMin = 1;
const int yMax = 5;

int computeCode(double x, double y) {
    int code = INSIDE;

    if (x < xMin) {
        code |= LEFT;
    } else if (x > xMax) {
        code |= RIGHT;
    }

    if (y < yMin) {
        code |= BOTTOM;
    } else if (y > yMax) {
        code |= TOP;
    }

    return code;
}

void cohenSutherlandClip(double x1, double y1, double x2, double y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int codeOut = code1 ? code1 : code2;
            double x, y;

            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        std::cout << "Segmen garis setelah clipping: (" << x1 << ", " << y1 << ") dan (" << x2 << ", " << y2 << ")\n";
    } else {
        std::cout << "Segmen garis sepenuhnya di luar area klip\n";
    }
}

int main() {
    double x1, y1, x2, y2;

    std::cout << "Masukkan koordinat titik awal (x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Masukkan koordinat titik akhir (x2, y2): ";
    std::cin >> x2 >> y2;

    std::cout << "Segmen garis sebelum clipping: (" << x1 << ", " << y1 << ") dan (" << x2 << ", " << y2 << ")\n";

    cohenSutherlandClip(x1, y1, x2, y2);

    return 0;
}

