#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void drawLineDDA(int x1, int y1, int x2, int y2) {
    // Hitung perubahan dalam x dan y
    float dx = x2 - x1;
    float dy = y2 - y1;

    // Tentukan langkah iterasi
    float steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    // Hitung inkremen untuk x dan y
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    // Inisialisasi koordinat awal
    float x = x1;
    float y = y1;

    // Gambar setiap pixel dalam garis
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

int main(int argc, char** argv) {
	int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1, x2, y2;

    // Masukkan koordinat titik awal dan akhir
    cout << "Masukkan koordinat titik awal (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Masukkan koordinat titik akhir (x2 y2): ";
    cin >> x2 >> y2;

    // Gambar garis menggunakan algoritma DDA
    drawLineDDA(x1, y1, x2, y2);

    getch();
    closegraph();
	return 0;
}
