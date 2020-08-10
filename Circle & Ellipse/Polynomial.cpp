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


void plot4Pixels(float x, float y){
    setPixel(x+h,y+k);
    cout<< "1: "<<x+h <<" "<<y+k<<endl;
   setPixel(x+h,-(y+k));
    cout<< "2: "<<x+h <<" "<<-(y+k)<<endl;
    setPixel(-x+h,y+k);
    cout<< "3: "<<-x+h <<" "<<y+k<<endl;
    setPixel(-x+h,-y+k);
    cout<< "4: "<<-x+h <<" "<<-y+k<<endl;
}

void PolynomialEllipse(void){
    int xe = 0;
    int ye = b;
    plot4Pixels(xe, ye);
    while(xe <= abs(h-a)){
        float par = (xe)*(xe);
        float maj = a*a;
        float diff = 1 - (par/maj)  ;
        if(diff<0){
            diff = diff*(-1);
            cout<<"neg diff: "<< diff<<endl;
        }
        float ye = b*(sqrt(diff)) ;
        plot4Pixels(xe, ye);
        xe++;
    }

}

int main(int argc, char **argv) {
 cout << "enter the center and major-minor axes of the circle : "<<endl;
    cin >> h >> k >> a>> b;
    if(a>=h){
        swap(a,h);
    }
    if(b>=k){
        swap(b,k);
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(ww, wh);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Polynomial Ellipse");
    glutDisplayFunc(PolynomialEllipse);
    myinit();
    glutMainLoop();
    return 0;
}
