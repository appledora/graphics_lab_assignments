#include <GL/glut.h>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;
int ww = 800, wh = 800;
int r, h, k;
int m1, n1, m2, n2;
int cx, cy;
int kase;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool vis[10000][10000];

void setPixel(float x, float y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

void BFS(void) {
    glColor3f(1, 0, 0);
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(h);
    q.push(k);
    vis[h + ww][k + wh] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        glBegin(GL_POINTS);
        glVertex2d(x, y);
        glEnd();

        for (int i = 0; i < 4; i++) {
            int fx = x + dx[i];
            int fy = y + dy[i];
            if (sqrt((fx - h) * (fx - h) + (fy - k) * (fy - k)) < r && !vis[fx + ww][fy + wh]) {
                q.push(fx);
                q.push(fy);
                vis[fx + ww][fy + wh] = 1;
            }
        }
    }

    glFlush();

}

void BFSr() {
    cout << "DFS" << endl;
    glColor3f(1, 0, 0);
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(cx);
    q.push(cy);
    vis[cx + ww][cy + wh] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        glBegin(GL_POINTS);
        glVertex2d(x, y);
        glEnd();

        for (int i = 0; i < 4; i++) {
            int fx = x + dx[i];
            int fy = y + dy[i];
            if (fx > m1 && fx < m2 && fy > n1 && fy < n2 && !vis[fx + ww][fy + wh]) {
                q.push(fx);
                q.push(fy);
                vis[fx + ww][fy + wh] = 1;
            }
        }
    }

    glFlush();
}

void drawCircle(void) {
    cout << "draw circle" << endl;
    int xe = 0;
    int ye = r;
    int d = 3 - 2 * r;
    cout << "#pos0: " << d << endl;
    while (xe <= ye) {
        setPixel(h + xe, k + ye);
        setPixel(h + ye, k + xe);
        setPixel(h - xe, k + ye);
        setPixel(h - xe, k - ye);
        setPixel(h - ye, k + xe);
        setPixel(h - ye, k - xe);
        setPixel(h + ye, k - xe);
        setPixel(h + xe, k - ye);

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

    BFS();
}

void drawRect(void) {
    memset(vis, 0, sizeof vis);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glVertex2i(m1, n1);
    glVertex2i(m2, n1);
    glVertex2i(m2, n2);
    glVertex2i(m1, n2);
    glEnd();
    glFlush();
    cx = ((m1 + m2) / 2);
    cy = ((n1 + n2) / 2);
    BFSr();
}

int main(int argc, char **argv) {
    cout << " Enter 0 for CIRCLE & 1 for RECTANGLE: \n";
    cin >> kase;
    if (kase == 0) {
        cout << "enter the center and radius of the circle : " << endl;
        cin >> h >> k >> r;
    } else {
        cout << "Enter the diagonal points of the rectangle : " << endl;
        cin >> m1 >> n1 >> m2 >> n2;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(ww, wh);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Trigonometry Circle");
    gluOrtho2D(-ww, (GLdouble) ww, -wh, (GLdouble) wh);
    if (kase == 0) {
        glutDisplayFunc(drawCircle);
    } else {
        glutDisplayFunc(drawRect);
    }
    glutMainLoop();
    return 0;
}
