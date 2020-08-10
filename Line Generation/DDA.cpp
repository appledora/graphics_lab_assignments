#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

int xs ,ys,xe,ye;


void DDA(void){
    cout<< xs << ys << xe << ye << endl;
    float dx = xe -xs;
    float dy = ye - ys;
    int steps;

    if (abs(dx) > abs(dy)){
        steps = dx;
    }
    else steps = dy;

    float xinc = dx/ steps;
    float yinc = dy/steps;
    cerr <<"increment\n" << xinc << " " <<yinc <<endl;

   float x = xs ;
   float y = ys;

    glColor3f(0.7,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for(int i = xs; i< steps; i++){
        x+= xinc ;
        y+= yinc;
        cerr<< x << " " << y <<endl;
        glVertex2f(x/200, y/200);

    }
    glEnd();
    glFlush();


}

int main(int argc, char** argv) {
    cout << "Enter x1 x2 m c: \n";
    std:: cin>>xs >>ys >> xe >> ye;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DDA");
    glutDisplayFunc(DDA);
    glutMainLoop();
    return 0;
}
