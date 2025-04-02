#ifndef COIN_H
#define COIN_H

#include <GL/glut.h>  // Library untuk menggunakan OpenGL dan GLUT
#include <cmath>      // Untuk fungsi trigonometri seperti cos() dan sin()

// Fungsi untuk menggambar lingkaran (koin)
void drawCircle(float radius, float xCenter, float yCenter) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159f / 180.0f;  // Menghitung sudut dalam radian
        float x = xCenter + radius * cos(angle);  // Menghitung koordinat x
        float y = yCenter + radius * sin(angle);  // Menghitung koordinat y
        glVertex2f(x, y);  // Menambahkan titik ke lingkaran
    }
    glEnd();
}

#endif // COIN_H


// Fungsi untuk menggambar objek (koin)
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Bersihkan layar dengan warna latar belakang

    // Gambar koin (lingkaran berwarna kuning)
    glColor3f(1.0f, 1.0f, 0.0f);  // Warna kuning untuk koin
    drawCircle(0.2f, 0.0f, 0.0f);  // Gambar koin dengan radius 0.2 dan posisi tengah di (0, 0)

    glFlush();  // Proses gambar selesai, tampilkan ke layar
}

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
    glutCreateWindow("Gambar Koin Berwarna Kuning");  // Membuat jendela dengan judul "Gambar Koin Berwarna Kuning"
    
    init();  // Inisialisasi OpenGL
    glutDisplayFunc(display);  // Fungsi untuk menggambar

    glutMainLoop();  // Mulai loop utama GLUT
    return 0;
}