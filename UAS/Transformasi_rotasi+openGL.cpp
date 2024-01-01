#include <GL/glut.h>

// Titik-titik objek
float points[][2] = {{-50, -50}, {50, -50}, {50, 50}, {-50, 50}};

// Sudut rotasi
float angle = 45.0;

void drawSquare() {
    glBegin(GL_QUADS);
    for (int i = 0; i < 4; i++) {
        glVertex2fv(points[i]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    // Melakukan translasi ke pusat objek
    glTranslatef(0.0, 0.0, 0.0);

    // Melakukan rotasi objek
    glRotatef(angle, 0.0, 0.0, 1.0);

    // Menggambar objek setelah rotasi
    glColor3f(1.0, 0.0, 0.0); // Warna merah
    drawSquare();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("2D Rotation using OpenGL");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(1.0, 1.0, 1.0, 1.0); // Warna background putih

    glutMainLoop();
    return 0;
}

