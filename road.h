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