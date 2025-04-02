#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include "road.h"        // Header for road-related functions
#include "airballoon.h"  // Header for air balloon-related functions
#include "cloud.h"       // Header for cloud-related functions
#include "bird.h"        // Header for bird-related functions
#include "coin.h"        // Header for coin-related functions

// Variabel player
float playerX = 0.0f;
float playerZ = 0.0f;
float moveSpeed = 0.1f;
bool keyStates[256] = {false}; // Fixed typo: changed `falsem` to `false`

// Variabel kamera
float cameraX = 0.0f, cameraY = 2.0f, cameraZ = 5.0f;

// Function to draw a cube
void drawCube(float x, float y, float z, float sizeX, float sizeY, float sizeZ) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(sizeX, sizeY, sizeZ);
    glutSolidCube(1.0);
    glPopMatrix();
}

// Function to draw the player using the air balloon
void drawPlayer() {
    glPushMatrix();
    glTranslatef(playerX, 1.0f, playerZ);
    drawBalloon(); // Use the balloon from airballoon.h
    glPopMatrix();
}

// Function to draw the ground
void drawGround() {
    glColor3f(0.3f, 0.6f, 0.3f);
    for (int i = -10; i < 50; ++i) {
        drawCube(0.0f, -0.5f, i * 2.0f, 10.0f, 0.1f, 2.0f);
    }
}

// Function to draw coins
void drawCoins() {
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow for coins
    for (int i = 0; i < 10; ++i) {
        glPushMatrix();
        glTranslatef(0.0f, 0.5f, playerZ - i * 5.0f);
        drawCircle(0.2f, 0.0f, 0.0f); // Use the coin from coin.h
        glPopMatrix();
    }
}

// Function to draw clouds
void drawClouds() {
    for (int i = -5; i < 5; ++i) {
        glPushMatrix();
        glTranslatef(i * 5.0f, 3.0f, playerZ - i * 10.0f);
        drawBlockyCloud(); // Use the cloud from cloud.h
        glPopMatrix();
    }
}

// Function to draw birds
void drawBirds() {
    for (int i = -3; i < 3; ++i) {
        glPushMatrix();
        glTranslatef(i * 5.0f, 2.0f, playerZ - i * 15.0f);
        displayBird(); // Use the bird from bird.h
        glPopMatrix();
    }
}

// Function to update the game state
void updateGame(int value) {
    playerZ -= moveSpeed;
    cameraZ -= moveSpeed;

    if (keyStates['a'] && playerX > -3.5f) playerX -= moveSpeed;
    if (keyStates['d'] && playerX < 3.5f) playerX += moveSpeed;

    glutPostRedisplay();
    glutTimerFunc(16, updateGame, 0);
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(cameraX, cameraY, cameraZ, playerX, 1.0f, playerZ, 0.0f, 1.0f, 0.0f);

    drawGround();
    drawPlayer();
    drawCoins();
    drawClouds();
    drawBirds();

    glPushMatrix();
    glTranslatef(0.0f, -0.5f, playerZ);
    displayRoad(); // Use the road from road.h
    glPopMatrix();

    glutSwapBuffers();
}

// Function to handle key press events
void keyboardDown(unsigned char key, int x, int y) {
    keyStates[key] = true;
}

// Function to handle key release events
void keyboardUp(unsigned char key, int x, int y) {
    keyStates[key] = false;
}

// Function to initialize OpenGL settings
void init() {
    glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

// Function to handle window resizing
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Endless Runner");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutTimerFunc(16, updateGame, 0);

    glutMainLoop();
    return 0;
}
