#include <GL/glut.h>

struct Point {
    float x;
    float y;
    float z;

    Point(float x, float y, float z) : x(x), y(y), z(z) {}
};

// Titik-titik awal bidang persegi
Point vertices[] = {
    Point(-1.0, -1.0, -1.0),
    Point(1.0, -1.0, -1.0),
    Point(1.0, 1.0, -1.0),
    Point(-1.0, 1.0, -1.0),
    Point(-1.0, -1.0, 1.0),
    Point(1.0, -1.0, 1.0),
    Point(1.0, 1.0, 1.0),
    Point(-1.0, 1.0, 1.0)
};

// Indices untuk menggambarkan bidang persegi
int indices[][4] = {
    {0, 1, 2, 3},  // Belakang
    {4, 5, 6, 7},  // Depan
    {0, 3, 7, 4},  // Kiri
    {1, 2, 6, 5},  // Kanan
    {3, 2, 6, 7},  // Atas
    {0, 1, 5, 4}   // Bawah
};

// Faktor translasi
float translateX = 2.0;
float translateY = 1.5;
float translateZ = 3.0;

// Faktor skala
float scaleX = 0.5;
float scaleY = 0.5;
float scaleZ = 0.5;

void drawSquare() {
    for (int i = 0; i < 6; i++) {
        glBegin(GL_QUADS);
        for (int j = 0; j < 4; j++) {
            int vertexIndex = indices[i][j];
            glVertex3f(
                vertices[vertexIndex].x * scaleX + translateX,
                vertices[vertexIndex].y * scaleY + translateY,
                vertices[vertexIndex].z * scaleZ + translateZ
            );
        }
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // Warna merah

    // Menampilkan bidang persegi sebelum translasi dan skala
    glPushMatrix();
    drawSquare();
    glPopMatrix();

    // Menampilkan bidang persegi setelah translasi dan skala
    glPushMatrix();
    glTranslatef(translateX, translateY, translateZ);
    glScalef(scaleX, scaleY, scaleZ);
    glColor3f(0.0, 0.0, 1.0); // Warna biru
    drawSquare();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void init() {
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("3D Translation and Scaling using OpenGL");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glClearColor(1.0, 1.0, 1.0, 1.0); // Warna background putih

    glutMainLoop();
    return 0;
}

