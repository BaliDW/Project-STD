#include <iostream>
using namespace std;

void tampilkanMenu() {
    // Membersihkan layar konsol (opsional, agar menu selalu terlihat bersih di atas)
    // Di Windows bisa pakai system("cls"), di Linux/macOS pakai system("clear").
    // Untuk contoh sederhana ini kita skip dulu agar tidak perlu library tambahan.
    cout << "\n======================================" << endl;
    cout << "           MENU UTAMA C++" << endl;
    cout << "======================================" << endl;
    cout << "  0. Defaults    - Tampilkan/Ubah default" << endl;
    cout << "  1. View        - Lihat data" << endl;
    cout << "  2. Edit        - Ubah data" << endl;
    cout << "  3. Utility     - Menu utilitas" << endl;
    cout << "  X. Exit        - Keluar dari program" << endl;
    cout << "======================================" << endl;
    cout << "Pilihan Anda (0-3, X): ";
    
}