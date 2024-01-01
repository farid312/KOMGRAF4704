#include <GL/glut.h>
#include <iostream>

GLfloat x1 = -50.0, y1 = -50.0, x2 = 50.0, y2 = 50.0;
GLfloat clipBoundary = 0.0;

void myInit() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);
}

void drawRectangle() {
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void drawClippedLine() {
    glColor3f(0.0, 0.0, 0.0);  // Warna hitam untuk garis yang di-clip
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawClippingBoundary() {
    glColor3f(1.0, 0.0, 0.0);  // Warna merah untuk batas pemotongan
    glBegin(GL_LINE_LOOP);
    glVertex2f(-clipBoundary, -clipBoundary);
    glVertex2f(clipBoundary, -clipBoundary);
    glVertex2f(clipBoundary, clipBoundary);
    glVertex2f(-clipBoundary, clipBoundary);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);  // Warna hitam untuk garis sebelum pemotongan
    drawRectangle();

    drawClippingBoundary();

    glEnable(GL_CLIP_PLANE0);  // Mengaktifkan plane pemotongan
    GLdouble eq[4] = {1.0, -1.0, 0.0, clipBoundary};  // Persamaan plane pemotongan (x - y = clipBoundary)
    glClipPlane(GL_CLIP_PLANE0, eq);

    glDisable(GL_CLIP_PLANE0);  // Menonaktifkan plane pemotongan
    drawClippedLine();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Clipping using OpenGL");
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

