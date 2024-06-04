#include <GL/glut.h>
#include <cmath>

float scale = 1.0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; i++) {
        float angle = 2 * M_PI * i / 6;
        glVertex2f(scale * cos(angle), scale * sin(angle));
    }
    glEnd();

    glutSwapBuffers();
}

void timer(int value) {
    scale -= 0.01;
    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Shrinking Hexagon");

    glClearColor(0.0, 0.0, 1.0, 1.0);

    glutDisplayFunc(display);
    glutTimerFunc(100, timer, 0);

    glutMainLoop();

    return 0;
}