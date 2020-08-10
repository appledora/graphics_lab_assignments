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

void myinit(){
    glViewport(0,0,ww,wh);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)ww,50.0,(GLdouble)wh);
    glMatrixMode(GL_MODELVIEW);
}


void TrigCircle(void){
    float pi = 3.14159/180;
    float x,y;
    for(int i = 0;i<=360;i++){
        x = a*cos(i*pi);
        cout<<"x: "<<x<<endl;
        y = b*sin(i*pi);
        cout<<"y: "<< y<< endl;
        plot4Pixels(x,y);
    }
}

int main(int argc, char **argv) {
 cout << "enter the center and radius of the circle : "<<endl;
    cin >> h >> k >> r;
    a = r;
    b = r;
    if(h<a){
        swap(h,a);
    }
    if(k<b){
        swap(k,b);
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(ww, wh);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Trigonometry Circle");
    glutDisplayFunc(TrigCircle);
    myinit();
    glutMainLoop();
    return 0;
}
