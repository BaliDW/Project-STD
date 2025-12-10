#include "kursus.h"
// Note: Jika menggunakan IDE (CodeBlocks/VSCode) dengan project manager,
// include "kursus.h" saja, dan compile kedua file cpp.
// Namun untuk compile manual sederhana, include "kursus.cpp" sering dipakai.

int main() {
    List L;
    createList(L);
    int pilihan;

    string k_nama, k_kode, m_judul, m_durasi, m_diff, target_kode;

    do {
        cout << "\n=== PLATFORM KURSUS (MLL) ===" << endl;
        cout << "1. Tambah Kursus (Parent)" << endl;
        cout << "2. Tambah Modul ke Kursus (Child)" << endl;
        cout << "3. Tampilkan Semua Data" << endl;
        cout << "4. Cari & Lihat Modul Kursus" << endl;
        cout << "5. Hapus Modul (Unlink)" << endl;
        cout << "6. Hapus Kursus (Unlink)" << endl;
        cout << "7. Info Kursus Terbanyak/Sedikit Modul" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            cout << "Nama Kursus: "; getline(cin, k_nama);
            cout << "Kode Kursus: "; getline(cin, k_kode);
            insertKursus(L, newElementKursus(k_nama, k_kode));
            break;

        case 2:
            cout << "Kode Kursus Tujuan: "; getline(cin, target_kode);
            if (searchKursus(L, target_kode) != nullptr) {
                cout << "Judul Modul: "; getline(cin, m_judul);
                cout << "Durasi: "; getline(cin, m_durasi);
                cout << "Difficulty: "; getline(cin, m_diff);
                addModulToKursus(L, target_kode, newElementModul(m_judul, m_durasi, m_diff));
            } else {
                cout << "Kursus tidak ditemukan." << endl;
            }
            break;

        case 3:
            showAllData(L);
            break;

        case 4:
            cout << "Kode Kursus: "; getline(cin, target_kode);
            showModulByKursus(L, target_kode);
            break;

        case 5:
            cout << "Kode Kursus: "; getline(cin, target_kode);
            cout << "Judul Modul dihapus: "; getline(cin, m_judul);
            deleteModul(L, target_kode, m_judul);
            break;

        case 6:
            cout << "Kode Kursus dihapus: "; getline(cin, target_kode);
            deleteKursus(L, target_kode);
            break;

        case 7:
            showMinMaxModul(L);
            break;
        }
    } while (pilihan != 0);

    return 0;
}
