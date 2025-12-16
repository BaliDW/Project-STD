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
            cout << "Kode Kursus: ";  
            insertKursus(L, newElementKursus(k_nama, k_kode));
            break;
        case 2:
            cout << "Kode Kursus Target: ";  
            cout << "Judul Modul: ";  
            cout << "Durasi: ";  
            cout << "Difficulty: ";  
            addModulToKursus(L, target_kode, newElementModul(m_judul, m_durasi, m_diff));
            break;
        case 3:
            showAllData(L);
            break;
        case 4:
            cout << "Kode Kursus: ";  
            cout << "Judul Modul Hapus: ";  
            deleteModul(L, target_kode, m_judul);
            break;
        case 5:
            cout << "Kode Kursus Hapus: ";  
            deleteKursus(L, target_kode);
            break;
        case 6:
            cout << "Masukkan Kode Kursus: ";  
            {
                int jumlah = countModul(L, target_kode);
                cout << "Jumlah modul dalam kursus " << target_kode << " adalah: " << jumlah << endl;
            }
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



