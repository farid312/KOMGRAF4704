#include <iostream>
#include <cmath>

void GarisDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Menentukan jumlah langkah yang dibutuhkan
    int steps = std::max(std::abs(dx), std::abs(dy));

    // Menghitung perubahan nilai x dan y pada setiap langkah
    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;

    // Inisialisasi nilai awal
    float x = x1;
    float y = y1;

    // Menggambar titik awal
    std::cout << "(" << round(x) << ", " << round(y) << ")" << std::endl;

    // Menggambar garis menggunakan algoritma DDA
    for (int i = 0; i < steps; ++i) {
        x += xIncrement;
        y += yIncrement;
        std::cout << "(" << round(x) << ", " << round(y) << ")" << std::endl;
    }
}

int main() {
    int x1, y1, x2, y2;

    // Input koordinat titik awal dan akhir dari pengguna
    std::cout << "Masukkan koordinat titik awal (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Masukkan koordinat titik akhir (x2 y2): ";
    std::cin >> x2 >> y2;

    // Memanggil fungsi untuk menggambar garis dengan algoritma DDA
    GarisDDA(x1, y1, x2, y2);

    return 0;
}
