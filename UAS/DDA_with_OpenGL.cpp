#include <GL/glut.h>

// Fungsi DDA untuk menggambar garis
void drawLineDDA(float x1, float y1, float x2, float y2) {
    // Menghitung perbedaan antara titik akhir dan awal
    float dx = x2 - x1;
    float dy = y2 - y1;

    // Menentukan jumlah langkah yang dibutuhkan
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Menghitung perubahan nilai pada setiap langkah
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    // Menggambar titik awal
    glBegin(GL_POINTS);
    glVertex2f(x1, y1);
    glEnd();

    // Menjalankan algoritma DDA
    float x = x1, y = y1;
    for (int i = 0; i < steps; i++) {
        x += xIncrement;
        y += yIncrement;

        // Menggambar setiap titik pada layar
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

    // Panggil fungsi DDA untuk menggambar garis dari (0, 0) ke (300, 200)
    drawLineDDA(0, 0, 300, 200);

    glFlush();
}

// Fungsi inisialisasi OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

