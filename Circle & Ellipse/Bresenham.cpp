using namespace std;
int xe, ye;
int ww=400,wh=400;

void setPixel(int x, int y){
    glColor3f(0.7, 0.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}
void BresenhamCircle(void) {
    int xe = 0;
    int ye = r;
    int d = 3 - 2 * r;
    cout << "#pos0: " << d << endl;
    while (xe <= ye) {
        setPixel(250+xe,250+ye);
        setPixel(250+ye,250+xe);
        setPixel(250-xe,250+ye);
        setPixel(250-xe,250-ye);
        setPixel(250-ye,250+xe);
        setPixel(250-ye,250-xe);
        setPixel(250+ye,250-xe);
        setPixel(250+xe,250-ye);

        if (d < 0) {
            d = d + (4 * xe) + 6;
            cout << "#pos: " << d << endl;
        } else {
            d = d + 4 * (xe - ye) + 10;
            cout << "#pos: " << d << endl;
            ye--;
        }
        xe++;
    }
}

void myinit(){
    glViewport(0,0,ww,wh);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    cout << "Enter the radius of the circle: " << endl;
    cin >> r;    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(ww, wh);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("BRESENHAMCIRCLE");
    glutDisplayFunc(BresenhamCircle);
    myinit();
    glutMainLoop();

    return 0;
}