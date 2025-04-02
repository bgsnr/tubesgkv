#include <GL/glut.h>
#include <math.h>

float balloonY = 0.0f;
float rotationAngle = 0.0f;
bool isRising = true;

//kubus 
void drawCube(float x, float y, float z, float sizeX, float sizeY, float sizeZ) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(sizeX, sizeY, sizeZ);
    glutSolidCube(1.0);
    glPopMatrix();
}

// wajah steve 
void drawFace() {
    glColor3f(1.0f, 0.8f, 0.6f);
    drawCube(0.0f, 1.0f, 0.21f, 0.38f, 0.38f, 0.02f);
    //mata kiri
    glColor3f(0.0f, 0.0f, 1.0f);
    drawCube(-0.08f, 1.05f, 0.22f, 0.05f, 0.05f, 0.01f);
    
    //mata kanan 
    drawCube(0.08f, 1.05f, 0.22f, 0.05f, 0.05f, 0.01f);
}

//steve
void drawSteve(float x, float y, float z, float scale) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(scale, scale, scale);
    
    //kepala 
    glColor3f(0.4f, 0.2f, 0.1f);
    drawCube(0.0f, 1.0f, 0.0f, 0.4f, 0.4f, 0.4f);
    drawFace();
    //badan 
    glColor3f(0.0f, 1.0f, 1.0f);
    drawCube(0.0f, 0.5f, 0.0f, 0.5f, 0.6f, 0.3f);
    //lengan kiri dan kanan 
    glColor3f(1.0f, 0.8f, 0.6f);
    drawCube(-0.3f, 0.5f, 0.0f, 0.2f, 0.6f, 0.2f);
    drawCube(0.3f, 0.5f, 0.0f, 0.2f, 0.6f, 0.2f);
    //kaki kiri 
    glColor3f(0.0f, 0.0f, 1.0f);
    drawCube(-0.15f, 0.0f, 0.0f, 0.2f, 0.6f, 0.2f);
    //kaki kanan 
    drawCube(0.15f, 0.0f, 0.0f, 0.2f, 0.6f, 0.2f);
    
    glPopMatrix();
}

//keranjang balon udara 
void drawBalloonBasket() {

    glColor3f(0.5f, 0.25f, 0.0f);
    drawCube(0.0f, 0.0f, 0.0f, 0.8f, 0.1f, 0.8f);

    glColor3f(1.0f, 1.0f, 0.8f);

    drawCube(0.0f, 0.3f, 0.4f, 0.8f, 0.4f, 0.02f);
    drawCube(0.0f, 0.3f, -0.4f, 0.8f, 0.4f, 0.02f);
    drawCube(0.4f, 0.3f, 0.0f, 0.02f, 0.4f, 0.8f);
    drawCube(-0.4f, 0.3f, 0.0f, 0.02f, 0.4f, 0.8f);
    
    //bagian bawah keranjang 
    glColor3f(0.5f, 0.25f, 0.0f);
    drawCube(0.0f, 0.12f, 0.4f, 0.8f, 0.04f, 0.04f);
    drawCube(0.0f, 0.12f, -0.4f, 0.8f, 0.04f, 0.04f);
    drawCube(0.4f, 0.12f, 0.0f, 0.04f, 0.04f, 0.8f);
    drawCube(-0.4f, 0.12f, 0.0f, 0.04f, 0.04f, 0.8f);
    
    //bagian atas keranjang 
    drawCube(0.0f, 0.5f, 0.4f, 0.8f, 0.04f, 0.04f);
    drawCube(0.0f, 0.5f, -0.4f, 0.8f, 0.04f, 0.04f);
    drawCube(0.4f, 0.5f, 0.0f, 0.04f, 0.04f, 0.8f);
    drawCube(-0.4f, 0.5f, 0.0f, 0.04f, 0.04f, 0.8f);
}

//atap persegi diatas keranjang
void drawSquareRoof() {
    //atap 
    glColor3f(0.5f, 0.25f, 0.0f); //coklat
    drawCube(0.0f, 0.8f, 0.0f, 0.8f, 0.1f, 0.8f);
    
    //api 
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, 1.1f, 0.0f);
    glScalef(0.1f, 0.3f, 0.1f);
    glutSolidCone(1.0f, 1.0f, 16, 16);
    glPopMatrix();
}

//tali penghubung balon ke keranjang dan atap
void drawRopes() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    
    glBegin(GL_LINES);

    glVertex3f(-0.4f, 0.5f, 0.4f);
    glVertex3f(-0.5f, 2.0f, 0.5f);
    
    glVertex3f(0.4f, 0.5f, 0.4f);
    glVertex3f(0.5f, 2.0f, 0.5f);
    
    glVertex3f(-0.4f, 0.5f, -0.4f);
    glVertex3f(-0.5f, 2.0f, -0.5f);
    
    glVertex3f(0.4f, 0.5f, -0.4f);
    glVertex3f(0.5f, 2.0f, -0.5f);
    
    glEnd();
}

//balon udara 
void drawBalloon() {
    glPushMatrix();
    glTranslatef(0.0f, 3.0f, 0.0f);

    // Warna luar balon
    glColor3f(1.0f, 0.5f, 0.0f);
    glPushMatrix();
    glScalef(1.0f, 1.2f, 1.0f);
    glutSolidSphere(1.5f, 32, 32); // Balon utama
    glPopMatrix();

    // Efek rongga (bagian dalam balon)
    glColor3f(0.4f, 0.2f, 0.1f);
    glPushMatrix();
    glTranslatef(0.0f, -1.2f, 0.0f);
    glScalef(0.8f, 0.0f, 0.8f);
    glutSolidSphere(1.0f, 30, 30);
    glPopMatrix();

    //cincin 
    glColor3f(0.6f, 0.3f, 0.1f);
    glPushMatrix();
    glTranslatef(0.0f, -1.5f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glutSolidTorus(0.08, 0.75, 30, 30);
    glPopMatrix();

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(
        0.0f, 1.5f, 9.0f,
        0.0f, 1.5f, 0.0f,
        0.0f, 1.0f, 0.0f
    );

    glRotatef(rotationAngle/4, 0.0f, 1.0f, 0.0f);

    drawBalloon();
    drawSquareRoof();
    drawRopes();
    drawBalloonBasket();
    drawSteve(0.0f, 0.4f, 0.0f, 0.3f);
    
    glPopMatrix();
    glutSwapBuffers();
}

//pencahayaan dan lainnya
void init() {
    glClearColor(0.2f, 0.4f, 0.6f, 1.0f); //background
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    GLfloat lightAmbient[] = {0.3f, 0.3f, 0.3f, 1.0f};
    GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat lightPosition[] = {5.0f, 10.0f, 5.0f, 1.0f};
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0f, (float)width / (float)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27)
        exit(0);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Balon Udara dengan Steve");
    
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;
}