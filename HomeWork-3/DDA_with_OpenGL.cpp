#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <algorithm> // Include the <algorithm> header

int x0, y0, x1, y1;

// Function to draw a line using DDA algorithm
void drawLineDDA() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

    glBegin(GL_POINTS);

    float dx = x1 - x0;
    float dy = y1 - y0;
    float steps = std::max(std::abs(dx), std::abs(dy)); // Use std::max

    float x_inc = dx / steps;
    float y_inc = dy / steps;

    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; i++) {
        glVertex2i(round(x), round(y));
        x += x_inc;
        y += y_inc;
    }

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("DDA Line Drawing");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400, 0.0, 400);

    // Input coordinates
    std::cout << "Enter x0: ";
    std::cin >> x0;
    std::cout << "Enter y0: ";
    std::cin >> y0;
    std::cout << "Enter x1: ";
    std::cin >> x1;
    std::cout << "Enter y1: ";
    std::cin >> y1;

    glutDisplayFunc(drawLineDDA);
    glutMainLoop();

    return 0;
}

