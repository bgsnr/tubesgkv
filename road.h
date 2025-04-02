#include <GL/glut.h>  // library untuk menggunakan OpenGL dan GLUT
#include "road.h"     // Header untuk fungsi displayRoad

// Fungsi inisialisasi OpenGL
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Set warna latar belakang (hitam)
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);  // Set sistem koordinat 2D
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);  // Inisialisasi GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set mode tampilan
    glutInitWindowSize(500, 500);  // Ukuran jendela
    glutCreateWindow("Jalan Raya Hitam");  // Membuat jendela dengan judul "Jalan Raya Hitam"
    
    init();  // Inisialisasi OpenGL
    glutDisplayFunc(displayRoad);  // Fungsi untuk menggambar

    glutMainLoop();  // Mulai loop utama GLUT
    return 0;
}

#ifndef ROAD_H
#define ROAD_H

#include <GL/glut.h>  // Library untuk menggunakan OpenGL dan GLUT

// Function to draw the road
void displayRoad() {
    // Set the road color to black
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.1f);  // Bottom-left
    glVertex2f(1.0f, -0.1f);   // Bottom-right
    glVertex2f(1.0f, 0.1f);    // Top-right
    glVertex2f(-1.0f, 0.1f);   // Top-left
    glEnd();

    // Draw white lane markings
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    for (float i = -1.0f; i < 1.0f; i += 0.2f) {
        glVertex2f(i, 0.0f);        // Start of the line
        glVertex2f(i + 0.1f, 0.0f); // End of the line
    }
    glEnd();
}

#endif // ROAD_H