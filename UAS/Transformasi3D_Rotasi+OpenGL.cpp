#include <GL/glut.h>

float angleX = 45.0;
float angleY = 45.0;

void drawCube() {
    glutWireCube(2.0); // Menggunakan glutWireCube untuk menggambar kubus dengan tepi terhubung
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0); // Translasi ke dalam bidang layar

    glRotatef(angleX, 1.0, 0.0, 0.0); // Rotasi sumbu X
    glRotatef(angleY, 0.0, 1.0, 0.0); // Rotasi sumbu Y

    glColor3f(0.0, 0.0, 1.0); // Warna biru

    drawCube(); // Menggambar kubus setelah transformasi

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 10.0); // Proyeksi perspektif
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'd':
        angleX += 5.0; // Putar ke atas sumbu X
        break;
    case 'a':
        angleX -= 5.0; // Putar ke bawah sumbu X
        break;
    case 'w':
        angleY += 5.0; // Putar ke atas sumbu Y
        break;
    case 's':
        angleY -= 5.0; // Putar ke bawah sumbu Y
        break;
    case 27: // ASCII untuk tombol Esc
        exit(0);
        break;
    }

    glutPostRedisplay(); // Meminta redisplay
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("3D Transformation using OpenGL");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glEnable(GL_DEPTH_TEST); // Aktifkan depth testing

    glClearColor(1.0, 1.0, 1.0, 1.0); // Warna background putih

    glutMainLoop();
    return 0;
}

