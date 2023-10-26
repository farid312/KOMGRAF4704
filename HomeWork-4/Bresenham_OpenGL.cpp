#include <GL/freeglut.h>
#include <iostream>
using namespace std;

int x1, y1, x2, y2; // Global variables to store coordinates

void drawLine_Bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);

    int x, y;

    if (x1 > x2) {
        x = x2;
        y = y2;
        x2 = x1;
        y2 = y1;
    } else {
        x = x1;
        y = y1;
    }

    glBegin(GL_POINTS);

    while (x < x2) {
        x++;

        if (p < 0) {
            p += twoDy;
        } else {
            y++;
            p += twoDyMinusDx;
        }

        glVertex2i(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set the line color to white
    drawLine_Bresenham(x1, y1, x2, y2);
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    cout << "Masukkan nilai x1: ";
    cin >> x1;

    cout << "Masukkan nilai y1: ";
    cin >> y1;

    cout << "Masukkan nilai x2: ";
    cin >> x2;

    cout << "Masukkan nilai y2: ";
    cin >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Line Drawing");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}

