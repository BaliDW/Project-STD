#include "kursus.h"

// Inisialisasi List
void createList(List &L) {
    L.first = nullptr;
}


adr_kursus newElementKursus(string nama, string kode) {
    adr_kursus P = new elm_kursus;
    P->info.namaKursus = nama;
    P->info.kodeKursus = kode;
    P->next = nullptr;
    P->firstModul = nullptr;
    return P;
}

// Buat elemen Modul baru (Child)
adr_modul newElementModul(string judul, string durasi, string diff) {
    adr_modul P = new elm_modul;
    P->info.judul = judul;
    P->info.durasi = durasi;
    P->info.difficulty = diff;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

// a. Insert Kursus (Insert Last - Singly List)
void insertKursus(List &L, adr_kursus P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adr_kursus Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

// c. Mencari Kursus
adr_kursus searchKursus(List L, string kodeKursus) {
    adr_kursus P = L.first;
    while (P != nullptr) {
        if (P->info.kodeKursus == kodeKursus) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

// b. & d. Menambahkan Modul ke Kursus (Insert Last - Doubly List)
void addModulToKursus(List &L, string kodeKursus, adr_modul C) {
    adr_kursus P = searchKursus(L, kodeKursus);
    if (P != nullptr) {
        if (P->firstModul == nullptr) {
            P->firstModul = C;
        } else {
            adr_modul Q = P->firstModul;
            while (Q->next != nullptr) {
                Q = Q->next;
            }
            Q->next = C;
            C->prev = Q;
        }
        cout << "Modul berhasil ditambahkan." << endl;
    } else {
        cout << "Kursus tidak ditemukan!" << endl;
    }
}

// e. Show Modul per Kursus
void showModulByKursus(List L, string kodeKursus) {
    adr_kursus P = searchKursus(L, kodeKursus);
    if (P != nullptr) {
        cout << "Kursus: " << P->info.namaKursus << endl;
        if (P->firstModul == nullptr) {
            cout << "  (Tidak ada modul)" << endl;
        } else {
            adr_modul Q = P->firstModul;
            int i = 1;
            while (Q != nullptr) {
                cout << "  " << i << ". " << Q->info.judul
                     << " (" << Q->info.durasi << ")" << endl;
                Q = Q->next;
                i++;
            }
        }
    } else {
        cout << "Kursus tidak ditemukan." << endl;
    }
}

// g. Hapus Modul (HANYA UNLINK POINTER, TIDAK DELETE MEMORI)
void deleteModul(List &L, string kodeKursus, string judulModul) {
    adr_kursus P = searchKursus(L, kodeKursus);
    if (P == nullptr) {
        cout << "Kursus tidak ditemukan." << endl;
        return;
    }

    adr_modul C = P->firstModul;
    while (C != nullptr) {
        if (C->info.judul == judulModul) {

            // --- Proses Unlink (Memutus Rantai) ---
            if (C == P->firstModul) {
                // Jika node di awal
                P->firstModul = C->next;
                if (P->firstModul != nullptr) {
                    P->firstModul->prev = nullptr;
                }
            } else if (C->next == nullptr) {
                // Jika node di akhir
                C->prev->next = nullptr;
            } else {
                // Jika node di tengah
                C->prev->next = C->next;
                C->next->prev = C->prev;
            }

            // Isolasi node C agar tidak menunjuk ke list lagi
            C->next = nullptr;
            C->prev = nullptr;

            // Catatan: Data C masih ada di RAM, tapi tidak bisa diakses dari List.
            cout << "Modul \"" << judulModul << "\" berhasil dilepas dari list." << endl;
            return;
        }
        C = C->next;
    }
    cout << "Modul tidak ditemukan." << endl;
}

// f. Hapus Kursus (HANYA UNLINK POINTER, TIDAK DELETE MEMORI)
void deleteKursus(List &L, string kodeKursus) {
    if (L.first == nullptr) return;

    adr_kursus P = L.first;
    adr_kursus prevP = nullptr;

    while (P != nullptr && P->info.kodeKursus != kodeKursus) {
        prevP = P;
        P = P->next;
    }

    if (P == nullptr) {
        cout << "Kursus tidak ditemukan." << endl;
        return;
    }

    // --- Proses Unlink Parent ---
    if (P == L.first) {
        L.first = P->next;
    } else {
        prevP->next = P->next;
    }

    // Isolasi Parent P
    P->next = nullptr;

    // Anak-anak (modul) milik P ikut terlepas dari List Utama L
    // karena mereka menempel pada P.

    cout << "Kursus \"" << P->info.namaKursus << "\" berhasil dilepas dari list." << endl;
}

// h. Show All Data
void showAllData(List L) {
    if (L.first == nullptr) {
        cout << "Belum ada data kursus." << endl;
        return;
    }

    adr_kursus P = L.first;
    while (P != nullptr) {
        cout << "-----------------------------------" << endl;
        cout << "[KURSUS] " << P->info.namaKursus << " (" << P->info.kodeKursus << ")" << endl;

        adr_modul Q = P->firstModul;
        if (Q == nullptr) {
            cout << "   (Belum ada modul)" << endl;
        } else {
            while (Q != nullptr) {
                cout << "   -> [MODUL] " << Q->info.judul
                     << " | " << Q->info.durasi << " | " << Q->info.difficulty << endl;
                Q = Q->next;
            }
        }
        P = P->next;
    }
    cout << "-----------------------------------" << endl;
}

// i. Helper: Hitung jumlah modul
int countModul(adr_kursus P) {
    int count = 0;
    if (P != nullptr) {
        adr_modul Q = P->firstModul;
        while (Q != nullptr) {
            count++;
            Q = Q->next;
        }
    }
    return count;
}

// j. Statistik Modul Terbanyak & Tersedikit
void showMinMaxModul(List L) {
    if (L.first == nullptr) {
        cout << "Data kosong." << endl;
        return;
    }

    adr_kursus P = L.first;
    adr_kursus maxP = P;
    adr_kursus minP = P;

    int maxVal = countModul(P);
    int minVal = countModul(P);

    P = P->next;
    while (P != nullptr) {
        int currentVal = countModul(P);

        if (currentVal > maxVal) {
            maxVal = currentVal;
            maxP = P;
        }
        if (currentVal < minVal) {
            minVal = currentVal;
            minP = P;
        }
        P = P->next;
    }

    cout << "=== Statistik Kursus ===" << endl;
    cout << "Terbanyak     : " << maxP->info.namaKursus << " (" << maxVal << " modul)" << endl;
    cout << "Paling Sedikit: " << minP->info.namaKursus << " (" << minVal << " modul)" << endl;
}
