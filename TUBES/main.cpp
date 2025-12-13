#include <iostream>
#include "parent.h"

using namespace std;

int main() {
    List L;
    createList(L);
    int pilihan;
    string k_nama, k_kode, m_judul, m_durasi, m_diff, target_kode;

     while (pilihan != 0) {
        cout << "\n=== APLIKASI KURSUS (TUBES STD) ===" << endl;
        cout << "1. Tambah Kursus (Insert First)" << endl;
        cout << "2. Tambah Modul (Insert Last)" << endl;
        cout << "3. Tampilkan Semua" << endl;
        cout << "4. Hapus Modul" << endl;
        cout << "5. Hapus Kursus" << endl;
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
            cout << "Kode Kursus Target: "; getline(cin, target_kode);
            cout << "Judul Modul: "; getline(cin, m_judul);
            cout << "Durasi: "; getline(cin, m_durasi);
            cout << "Difficulty: "; getline(cin, m_diff);
            addModulToKursus(L, target_kode, newElementModul(m_judul, m_durasi, m_diff));
            break;
        case 3:
            showAllData(L);
            break;
        case 4:
            cout << "Kode Kursus: "; getline(cin, target_kode);
            cout << "Judul Modul Hapus: "; getline(cin, m_judul);
            deleteModul(L, target_kode, m_judul);
            break;
        case 5:
            cout << "Kode Kursus Hapus: "; getline(cin, target_kode);
            deleteKursus(L, target_kode);
            break;
        case 0:
            cout << "Keluar program." << endl;
            break;
        default:
            cout << "Pilihan salah." << endl;
        }
    };

    return 0;
}
