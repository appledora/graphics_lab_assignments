#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
int xs ,ys,xe,ye;

void Bresenham (void){
    cout <<xs <<" "<<ys<<" "<<xe<<" "<<ye<<endl;
    float dx = xe -xs;
    float dy = ye - ys;
    float param = (2*dx) - dy;
   cout <<"param: " <<param<<endl;

    float x = xs;
    float y = ys;

    glColor3f(0.7,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for(int i=xs; i<=xe;i++){
        cout<<x<<" "<<y<<endl;
        glVertex2f(x/200, y/200);
        if(param < 0){
            param = param + (2*dx);
            x++;
        }
        else {
            param = param + (2*dy) - (2*dx);
            y++;
        }
        cout <<"new param: "<< param<<endl;
    }
    glEnd();
    glFlush();


}

int main(int argc, char** argv) {
    cout << "Enter xs ys xe ye: \n";
    std:: cin>>xs >>ys >> xe >> ye;
       glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(100,100);
    glutCreateWindow("BRESENHAM");
    glutDisplayFunc(Bresenham);
    glutMainLoop();
    return 0;
}
