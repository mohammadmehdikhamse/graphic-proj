#include <iostream>
#include <cstdlib>
#include <GL/glut.h>

using namespace std;

const int WIDTH = 500;
const int HEIGHT = 500;
const int SQUARE_SIZE = 10;
const int NUM_SQUARES = WIDTH / SQUARE_SIZE;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

void drawSquare(int x, int y, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + SQUARE_SIZE, y);
    glVertex2i(x + SQUARE_SIZE, y + SQUARE_SIZE);
    glVertex2i(x, y + SQUARE_SIZE);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < NUM_SQUARES; i++) {
        for (int j = 0; j < NUM_SQUARES; j++) {
            float r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            float g = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            float b = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            drawSquare(i * SQUARE_SIZE, j * SQUARE_SIZE, r, g, b);
        }
    }

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Checkerboard with Random Colors");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}