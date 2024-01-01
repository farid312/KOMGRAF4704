#include <iostream>
#include <GL/glut.h>

float x1, y1, x2, y2;

// Fungsi DDA untuk menggambar garis
void drawLineDDA() {
    // Menghitung perbedaan antara titik akhir dan awal
    float dx = x2 - x1;
    float dy = y2 - y1;

    // Menentukan jumlah langkah yang dibutuhkan
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Menghitung perubahan nilai pada setiap langkah
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    // Menjalankan algoritma DDA
    float x = x1, y = y1;

    // Menggambar titik awal
    glBegin(GL_POINTS);
    glVertex2f(x1, y1);
    glEnd();

    // Menggambar setiap titik pada layar
    for (int i = 0; i < steps; i++) {
        x += xIncrement;
        y += yIncrement;

        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
    }

    // Tampilkan buffer layar
    glFlush();
}

// Fungsi untuk menggambar
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Panggil fungsi DDA untuk menggambar garis
    drawLineDDA();

    glFlush();
}

// Fungsi inisialisasi OpenGL
void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

// Fungsi untuk menangani input keyboard
void keyboardHandler(unsigned char key, int x, int y) {
    if (key == 27) // ASCII untuk tombol Escape
        exit(0);
    else if (key == 13) // ASCII untuk tombol Enter
        glutPostRedisplay();
}

int main(int argc, char** argv) {
    std::cout << "Masukkan nilai x1, y1, x2, y2 (contoh: 100 100 400 300): ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line Algorithm");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardHandler);
    glutMainLoop();

    return 0;
}

