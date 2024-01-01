#include <iostream>
#include <cmath>

// Kode klipping
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Koordinat batas window
const double X_MIN = -50.0;
const double X_MAX = 50.0;
const double Y_MIN = -50.0;
const double Y_MAX = 50.0;

// Fungsi untuk menentukan kode klipping
int computeCode(double x, double y) {
    int code = INSIDE;

    if (x < X_MIN)
        code |= LEFT;
    else if (x > X_MAX)
        code |= RIGHT;

    if (y < Y_MIN)
        code |= BOTTOM;
    else if (y > Y_MAX)
        code |= TOP;

    return code;
}

// Fungsi untuk meng-clip garis
void cohenSutherlandClip(double x1, double y1, double x2, double y2) {
    // Kode klipping untuk kedua ujung garis
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    // Flag untuk menentukan apakah garis perlu di-clip atau tidak
    bool accept = false;

    while (true) {
        // Kondisi di luar while untuk mengatasi kasus garis seluruhnya di dalam window
        if (!(code1 | code2)) {
            accept = true;
            break;
        } else if (code1 & code2) {
            // Garis sepenuhnya di luar window, tidak perlu di-clip
            break;
        } else {
            // Garis perlu di-clip
            int codeOut;
            double x, y;

            // Pilih titik yang berada di luar window
            if (code1 != 0)
                codeOut = code1;
            else
                codeOut = code2;

            // Hitung titik potong (interseksi)
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            // Ganti titik yang berada di luar window dengan titik potong
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
        std::cout << "Luar Window: (" << x1 << ", " << y1 << ") dan (" << x2 << ", " << y2 << ")\n";
    } else {
        std::cout << "Garis sepenuhnya di luar window dan tidak perlu di-clip.\n";
    }
}

int main() {
    // Contoh garis sebelum di-clip
    double x1 = -60.0, y1 = 70.0, x2 = 80.0, y2 = -40.0;

    std::cout << "Garis sebelum di-clip: (" << x1 << ", " << y1 << ") dan (" << x2 << ", " << y2 << ")\n";

    // Melakukan clipping
    cohenSutherlandClip(x1, y1, x2, y2);

    return 0;
}

