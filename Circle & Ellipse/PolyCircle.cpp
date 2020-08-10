#include <GL/glut.h>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;
int r;

int ww=600,wh=600;
int h, k, a,b;

void setPixel(float x, float y){
    glColor3f(0.7, 0.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}
void myinit(){
    glViewport(0,0,ww,wh);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)ww,50.0,(GLdouble)wh);
    glMatrixMode(GL_MODELVIEW);
}

void plot8Pixels(int xe,int ye){
    setPixel(h+xe,k+ye);
    setPixel(h+ye,k+xe);
    setPixel(h-xe,k+ye);
    setPixel(h-xe,k-ye);
    setPixel(h-ye,k+xe);
    setPixel(h-ye,k-xe);
    setPixel(h+ye,k-xe);
    setPixel(h+xe,k-ye);
}

void PolynomialCircle(void){
    int xe = 0;
    int ye = r;
    int d = r/sqrt(2);

    plot8Pixels(xe,ye);

    while(xe <= d){
        ye = sqrt(r*r  - xe*xe);
        plot8Pixels(xe,ye);
        xe++;
    }


}

int main(int argc, char **argv) {
 cout << "enter the center and radius of the circle : "<<endl;
    cin >> h >> k >> r;
    if(h<r){
        swap(h,r);
    }
    if(k<r){
        swap(k,r);
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(ww, wh);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Polynomial Circle");
    glutDisplayFunc(PolynomialCircle);
    myinit();
    glutMainLoop();
    return 0;
}
