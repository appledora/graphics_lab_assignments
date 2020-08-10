#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;
struct Point {
    int dx;
    int dy;
};
struct lineEndPoint {
    int x, y;
};
int ww = 1000, wh = 1000;
Point pointList[100];
int n, xmin, ymin, xmax, ymax;
lineEndPoint pstart, pend, ptempS, ptempE;
int code1, code2;

void myInit() {
    // glViewport(0, 0, ww, wh);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(-500, 500, -500, 500);
    gluOrtho2D(0.0, (GLdouble) ww, 0.0, (GLdouble) wh);
    //gluOrtho2D(-1.0, 1.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawLine(void) {
    glBegin(GL_LINE_STRIP);
    glVertex2f(pstart.x, pstart.y);
    glVertex2f(pstart.x, pend.y);
    glEnd();
    glFlush();
}

void pointClipping(void) {
    for (int i = 0; i < n; i++) {
        if (pointList[i].dx >= xmin && pointList[i].dx <= xmax) {
            if (pointList[i].dy >= ymin && pointList[i].dy <= ymax) {
                glPointSize(4);
                glColor3f(0.0, 1.0, 0.0);
                glBegin(GL_POINTS);
                glVertex2f(pointList[i].dx, pointList[i].dy);
                glEnd();
                glFlush();
            }
        } else {
            glPointSize(4);
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_POINTS);
            glVertex2f(pointList[i].dx, pointList[i].dy);
            glEnd();
            glFlush();
        }
    }

}

void colorLine(void) {
    cout << "ptempS => " << ptempS.x << "\nptempS.y => " << ptempS.y << "\nptempE.x => " << ptempE.x << "\nptempE.y =>"
         << ptempE.y << endl;
    cout << "/////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "pstart.x =>" << pstart.x << "\npstart.y =>" << pstart.y << "\npend.x => " << pend.x
         << "\npend.y => " << pend.y << endl;
    glClear(GL_COLOR_BUFFER_BIT);
    cout << "started DRAWING\n";

    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();
    glFlush();

    cout << "finished DRAWING\n";

    glColor3f(1.0, 0.0, 0.0);
    cout << "drawing red 1 with : " << "ptempS => " << ptempS.x << "\nptempS.y => " << ptempS.y << " and "
         << "pstart.x =>" << pstart.x << "\npstart.y =>" << pstart.y << endl;
    glBegin(GL_LINE_STRIP);
    glVertex2f(ptempS.x, ptempS.y);
    glVertex2f(pstart.x, pstart.y);
    glEnd();
    glFlush();
    glColor3f(0.0, 1.0, 0.0);
    cout << "drawing GREEN with : " << "pend.x => " << pend.x
         << "\npend.y => " << pend.y << " and " << "pstart.x =>" << pstart.x << "\npstart.y =>" << pstart.y << endl;
    glBegin(GL_LINE_STRIP);
    glVertex2f(pstart.x, pstart.y);
    glVertex2f(pend.x, pend.y);
    glEnd();
    glFlush();

    glColor3f(1.0, 0.0, 0.0);
    cout << "drawing RED 2 with : " << "pend.x => " << pend.x
         << "\npend.y => " << pend.y << " and " << "ptempE.x => " << ptempE.x << "\nptempE.y =>"
         << ptempE.y << endl;
    glBegin(GL_LINES);
    glVertex2i(pend.x, pend.y);
    glVertex2i(ptempE.x, ptempE.y);
    glEnd();
    glFlush();

}

int calculateCode(lineEndPoint point) {
    lineEndPoint line;
    int code = 0;
    line.x = point.x;
    line.y = point.y;
    if (point.y > ymax) {
        code |= (1 << 3); //1000
    } else if (point.y < ymin) {
        code |= (1 << 2); //0100
    }

    if (point.x > xmax) {
        code |= (1 << 1); //0010
    } else if (point.x < xmin) {
        code |= (1 << 0); //0001
    }
    return code;
}

void CohenSutherland(void) {
    for (int i = 0; i < n; i++) {
        cin >> pstart.x >> pstart.y >> pend.x >> pend.y;
        ptempS.x = pstart.x;
        ptempS.y = pstart.y;
        ptempE.x = pend.x;
        ptempE.y = pend.y;

        code1 = calculateCode(pstart);
        code2 = calculateCode(pend);
        if (code1 == 0 && code2 == 0) {
            cout << "Line inside the window" << endl;
            drawLine();
        }
        while ((code1 | code2) > 0) {
            cout << "code1 => " << code1 << "\ncode2 => " << code2 << endl;
            cout << "AND => " << (code1 & code2) << endl;
            if ((code1 & code2) != 0) {
                cout << "breaking LOOP" << endl;
                exit(0);
            } else {
                float newx, newy;
                int code;
                if (code1 != 0) {
                    code = code1;

                } else {
                    code = code2;

                }
                cout << "new code => " << code << "\n";
                if ((code & (1 << 0)) != 0) { // 0001 or 2
                    /* Endpoint is to the left of clip window */
                    newx = xmin;
                    newy = pstart.y + (pend.y - pstart.y) * (xmin - pstart.x) / (pend.x - pstart.x);
                    cout << "newx => " << newx << " \nnewy => " << newy << "\n condition 1" << endl;

                } else if ((code & (1 << 1)) != 0) { //0010 or 4
                    /* Endpoint is to the right of clip window */
                    newx = xmax;
                    newy = pstart.y + (pend.y - pstart.y) * (xmax - pstart.x) / (pend.x - pstart.x);
                    cout << "newx => " << newx << " \nnewy => " << newy << "\n condition 2" << endl;
                } else if ((code & (1 << 3)) != 0) { //1000 o4 16
                    /* Endpoint is above the clip window */
                    newy = ymax;
                    newx = pstart.x + (pend.x - pstart.x) * (ymax - pstart.y) / (pend.y - pstart.y);
                    cout << "newx => " << newx << " \nnewy => " << newy << "\n condition 3" << endl;

                } else if ((code & (1 << 2)) != 0) { // 0100 or 8
                    /* Endpoint is below the clip window */
                    newy = ymin;
                    newx = pstart.x + (pend.x - pstart.x) * (ymin - pstart.y) / (pend.y - pstart.y);
                    cout << "newx => " << newx << " \nnewy => " << newy << "\n condition 4" << endl;

                }
                cout << "pstart.x =>" << pstart.x << "\npstart.y =>" << pstart.y << "\npend.x => " << pend.x
                     << "\npend.y => " << pend.y << endl;

                if (code == code1) {
                    cout << "code == code1 \n";
                    ptempS.x = pstart.x;
                    pstart.x = newx;
                    ptempS.y = pstart.y;
                    pstart.y = newy;
                    code1 = calculateCode(pstart);
                }

                if (code == code2) {
                    cout << "code == code2 \n";
                    ptempE.x = pend.x;
                    pend.x = newx;
                    ptempE.y = pend.y;
                    pend.y = newy;
                    code2 = calculateCode(pend);
                }
            }
            cout << "code1 => " << code1 << "\ncode2 => " << code2 << endl;
            cout << "OR => " << (code1 | code2) << endl;
            colorLine();
        }

    }
}

void drawWindow(void) {
    /*Draw the polygon*/
    cout << "started DRAWING\n";


    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();
    glFlush();

    cout << "finished DRAWING\n";
    pointClipping();
}

int main(int argc, char **argv) {
    cout << "Enter window corner points: \n";
    cin >> xmin >> ymin >> xmax >> ymax;
    cout << "Choose 1 for point clipping and 2 for Cohen-sutherland Line Clipping" << endl;
    int flag;
    cin >> flag;
    if (flag == 1) {
        cout << "Enter number of random points\n";
        cin >> n;
        cout << "Enter point coords: \n";
        for (int i = 0; i < n; i++) {
            cin >> pointList[i].dx >> pointList[i].dy;
        }
    } else {
        cout << "Enter number of random lines\n";
        cin >> n;
    }


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(ww, wh);
    glutCreateWindow("Clipping");
    glColor3f(0.7, 0.0, 1.0);
    if (flag == 1) {
        glutDisplayFunc(drawWindow);
    } else {
        glutDisplayFunc(CohenSutherland);
    }
    myInit();
    glutMainLoop();

    return 0;
}

/*100 100 400 400
 * 5
120 250
600 390
300 300
400 400
500 800

 100 10 800 600

 *
 * */