#include <bits/stdc++.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;
struct edge
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
};

struct vektor
{
    int vx, vy;
};
int ww = 1000, wh = 1000;
edge ed;
vektor vec;
int theta;
int flag = 0;

void myInit()
{
    // glViewport(0, 0, ww, wh);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
    // gluOrtho2D(0.0, (GLdouble) ww, 0.0, (GLdouble) wh);
    //gluOrtho2D(-1.0, 1.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void translate(void)
{
    cout << "STARTED TRANSLATE \n";
    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_LINE_LOOP);
    glVertex2f(ed.x1 + vec.vx, ed.y1 + vec.vy);
    glVertex2f(ed.x2 + vec.vx, ed.y2 + vec.vy);
    glVertex2f(ed.x3 + vec.vx, ed.y3 + vec.vy);
    glVertex2f(ed.x4 + vec.vx, ed.y4 + vec.vy);
    glEnd();
    glFlush();

    cout << "FINISHED TRANSLATE \n";
}

void scale(void)
{
    cout << "STARTED SCALING \n";
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(ed.x1 / vec.vx, ed.y1 / vec.vy);
    glVertex2f(ed.x2 / vec.vx, ed.y2 / vec.vy);
    glVertex2f(ed.x3 / vec.vx, ed.y3 / vec.vy);
    glVertex2f(ed.x4 / vec.vx, ed.y4 / vec.vy);
    glEnd();
    glFlush();

    cout << "FINISHED SCALING \n";
}
void mirror(void)
{
    cout << "STARTED MIRRORING \n";
    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_LINE_LOOP);
    glVertex2f(ed.x1 * -1, ed.y1);
    glVertex2f(ed.x2 * -1, ed.y2);
    glVertex2f(ed.x3 * -1, ed.y3);
    glVertex2f(ed.x4 * -1, ed.y4);
    glEnd();
    glFlush();

    cout << "FINISHED MIRRORING \n";
}

void rotate(void)
{
    cout << "STARTED ROTATING \n";
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(ed.x1 * cos(theta) - ed.y1 * sin(theta), ed.x1 * sin(theta) + ed.y1 * cos(theta));
    glVertex2f(ed.x2 * cos(theta) - ed.y2 * sin(theta), ed.x2 * sin(theta) + ed.y2 * cos(theta));
    glVertex2f(ed.x3 * cos(theta) - ed.y3 * sin(theta), ed.x3 * sin(theta) + ed.y3 * cos(theta));
    glVertex2f(ed.x4 * cos(theta) - ed.y4 * sin(theta), ed.x4 * sin(theta) + ed.y4 * cos(theta));
    glEnd();
    glFlush();

    cout << "FINISHED ROTATING \n";
}

void drawPolygon(void)
{
    /*Draw the polygon*/
    cout << "started DRAWING\n";

    glBegin(GL_LINE);
    glVertex2i(-400, 0);
    glVertex2i(400, 0);
    glEnd();
    glFlush();

    glBegin(GL_LINE_LOOP);
    glVertex2f(ed.x1, ed.y1);
    glVertex2f(ed.x2, ed.y2);
    glVertex2f(ed.x3, ed.y3);
    glVertex2f(ed.x4, ed.y4);
    glEnd();
    glFlush();

    cout << "finished DRAWING\n";
    cout << "FLAG => " << flag << endl;
    if (flag == 1)
    {
        translate();
    }

    else if (flag == 2)
    {
        scale();
    }

    else if (flag == 3)
    {
        rotate();
    }

    else
    {
        mirror();
    }
}

int main(int argc, char **argv)
{

    cout << "Enter the vertices\n";
    cin >> ed.x1 >> ed.y1 >> ed.x2 >> ed.y2 >> ed.x3 >> ed.y3 >> ed.x4 >> ed.x4;
    cout << "Enter \n => 1 to TRANSLATE \n => 2 to SCALE \n => 3 to ROTATE \n => 4 to MIRROR\n";
    cin >> flag;
    cout << "FLAG => " << flag << endl;

    if (flag == 1)
    {
        cout << "Enter transformation vector \n";
        cin >> vec.vx >> vec.vy;
    }
    else if (flag == 2)
    {
        cout << "Enter scaling factor \n";
        cin >> vec.vx >> vec.vy;
    }
    else if (flag == 3)
    {
        cout << "Enter angle of rotation \n";
        cin >> theta;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(ww, wh);
    glutCreateWindow("2D transformation");
    glColor3f(0.7, 0.0, 1.0);
    glutDisplayFunc(drawPolygon);
    myInit();
    glutMainLoop();

    return 0;
}
