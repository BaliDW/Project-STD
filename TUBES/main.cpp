#include <iostream>
#include "parent.h"

using namespace std;

int main() {
    List L;
    createList(L);
    int pilihan = -1;
    string k_nama, k_kode, m_judul, m_durasi, m_diff, target_kode;

     while (pilihan != 0) {
        cout << "\n=== APLIKASI KURSUS (TUBES STD) ===" << endl;
        cout << "1. Tambah Kursus " << endl;
        cout << "2. Tambah Modul " << endl;
        cout << "3. Tampilkan Semua" << endl;
        cout << "4. Hapus Modul" << endl;
        cout << "5. Hapus Kursus" << endl;
        cout << "6. Cari Kursus & Hitung Modul " << endl;
        cout << "7. Statistik Terbanyak/Tersedikit " << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            cout << "Nama Kursus: ";
            cin >> k_nama;  
            cout << "Kode Kursus: ";
            cin >> k_kode;  
            insertKursus(L, newElementKursus(k_nama, k_kode));
            break;
        case 2:
            cout << "Kode Kursus Target: ";
            cin >> target_kode;
            if (searchKursus(L, target_kode) != nullptr) {
                cout << "Judul_Modul (Tanpa Spasi): ";
                cin >> m_judul;
                cout << "Durasi: ";
                cin >> m_durasi;
                cout << "Difficulty: ";
                cin >> m_diff;
                addModulToKursus(L, target_kode, newElementModul(m_judul, m_durasi, m_diff));
            } else {
                cout << "Error: Kursus tidak ditemukan!" << endl;
            }
            break;
        case 3:
            showAllData(L);
            break;
        case 4:
            showAllData(L);
            cout << "Kode Kursus: ";
            cin >> target_kode;
            cout << "Judul Modul Hapus: ";
            cin >> m_judul;
            deleteModul(L, target_kode, m_judul);
            break;
        case 5:
            showAllData(L);
            cout << "Kode Kursus Hapus: ";
            cin >> target_kode;
            deleteKursus(L, target_kode);
            break;
        case 6:
            showAllData(L);
            cout << "Masukkan Kode Kursus: ";
            cin >> target_kode;
            cout << "Jumlah modul: " << countModul(L, target_kode) << endl;
            break;
        case 7:
            showJumModul(L);
            break;

        case 0:
            cout << "Keluar program." << endl;
            break;
        default:
            cout << "Pilihan salah." << endl;
        }

    }
    return 0;
};



