#include <iostream>
#include <cmath>

// fungsi untuk pembulatan
int round(float n) {
    if (n - (int)n < 0.5)
        return (int)n;
    return (int)(n + 0.5); 
}

// Fungsi untuk membuat garis
void GarisDDA(int x0, int y0, int x1, int y1) {

    // Step 1
    // Menghitung delta_x dan delta_y
    int d_x = x1 - x0;
    int d_y = y1 - y0;
    float m = (float)d_y / d_x;

    // Step 2
    // Menghitung step pada perulangan
    int step;
    if (std::abs(d_x) > std::abs(d_y)) {
        step = std::abs(d_x);
    }
    else {
        step = std::abs(d_y);
    }

    // Menghitung x-inc dan y-inc untuk setiap step
    float x_inc = (float)d_x / step;
    float y_inc = (float)d_y / step;

    float x = x0;
    float y = y0;

    for (int i = 0; i < step; i++) {
        std::cout << round(x) << " " << round(y) << "\n";
        x += x_inc;
        y += y_inc;
    }
}

int main() {
    int x0, y0, x1, y1;
    
    char repeat;
    do {
        int x0, y0, x1, y1;

        std::cout << "Masukkan nilai x0: ";
        std::cin >> x0;

        std::cout << "Masukkan nilai y0: ";
        std::cin >> y0;

        std::cout << "Masukkan nilai x1: ";
        std::cin >> x1;

        std::cout << "Masukkan nilai y1: ";
        std::cin >> y1;

        GarisDDA(x0, y0, x1, y1);

        std::cout << "Ingin memasukkan garis lain? (y/n): ";
        std::cin >> repeat;
    } 
	
	while (repeat == 'y' || repeat == 'Y');

    GarisDDA(x0, y0, x1, y1);

    return 0;
}

