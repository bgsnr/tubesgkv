#include <GL/glut.h>  // library untuk menggunakan OpenGL dan GLUT

// Fungsi untuk menggambar objek (jalan raya dan marka jalan)
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Bersihkan layar dengan warna latar belakang

    // Gambar jalan raya dengan warna hitam
    glColor3f(0.0f, 0.0f, 0.0f);  // Warna hitam untuk jalan
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.1f);  // Kiri bawah
    glVertex2f(1.0f, -0.1f);   // Kanan bawah
    glVertex2f(1.0f, 0.1f);    // Kanan atas
    glVertex2f(-1.0f, 0.1f);   // Kiri atas
    glEnd();

    // Gambar marka jalan (garis putih)
    glColor3f(1.0f, 1.0f, 1.0f);  // Warna putih untuk marka jalan
    glBegin(GL_LINES);
    for (float i = -1.0f; i < 1.0f; i += 0.2f) {
        glVertex2f(i, 0.0f);        // Titik kiri
        glVertex2f(i + 0.1f, 0.0f); // Titik kanan
    }
    glEnd();

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
    glutCreateWindow("Jalan Raya Hitam");  // Membuat jendela dengan judul "Jalan Raya Hitam"
    
    init();  // Inisialisasi OpenGL
    glutDisplayFunc(display);  // Fungsi untuk menggambar

    glutMainLoop();  // Mulai loop utama GLUT
    return 0;
}