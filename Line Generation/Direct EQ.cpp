#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
int x1,x2, m,c;


void directEQ(void){
//    cout <<x1<<x2<<m<<c;
    glColor3f(0.7,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for(int i=x1; i<=x2; i++){
        //cout <<"got here\n";
        float y = m*i + c;
        cerr << i << " " << y << endl;
        glVertex2f(i/200,y/200);
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    cout << "Enter x y m c: \n";
    std::cin>>x1>>x2>>m>>c;
    if(x1 > x2)
        swap(x1,x2);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Direct EQ");
    glutDisplayFunc(directEQ);
    glutMainLoop();
    return 0;
}
