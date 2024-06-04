#include <iostream>
#include <GL/glut.h>

using namespace std;

const int WIDTH = 500;
const int HEIGHT = 500;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the square
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.5, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.5, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.5, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.5, 0.5);
    glEnd();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) {
        gluOrtho2D(-1.0, 1.0, -1.0 * (GLfloat) h / (GLfloat) w, 1.0 * (GLfloat) h / (GLfloat) w);
    } else {
        gluOrtho2D(-1.0 * (GLfloat) w / (GLfloat) h, 1.0 * (GLfloat) w / (GLfloat) h, -1.0, 1.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Square with Orthographic Projection");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}