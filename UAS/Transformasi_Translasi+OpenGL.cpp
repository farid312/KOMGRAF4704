#include <GL/glut.h>

struct Point {
    float x;
    float y;

    Point(float x, float y) : x(x), y(y) {}
};

Point startPoint(1.0, 2.0);
Point endPoint(5.0, 5.0);

float translateX = 2.0;
float translateY = 3.0;

void drawLine(const Point& p1, const Point& p2) {
    glBegin(GL_LINES);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // Warna merah

    // Menampilkan garis sebelum translasi
    glPushMatrix();
    drawLine(startPoint, endPoint);
    glPopMatrix();

    // Menampilkan garis setelah translasi
    glPushMatrix();
    glTranslatef(translateX, translateY, 0.0);
    glColor3f(0.0, 0.0, 1.0); // Warna biru
    drawLine(startPoint, endPoint);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("2D Translation using OpenGL");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(1.0, 1.0, 1.0, 1.0); // Warna background putih

    glutMainLoop();
    return 0;
}

