#include "parent.h"

void createList(List &L) {
// I.S. -
// F.S. Terbentuk List kosong (first = NULL)
    L.first = nullptr;
}

adr_kursus newElementKursus(string nama, string kode) {
// I.S. -
// F.S. Terbentuk node kursus baru
    adr_kursus P = new elm_kursus;
    P->info.namaKursus = nama;
    P->info.kodeKursus = kode;
    P->next = nullptr;
    P->firstModul = nullptr;
    return P;
}

void insertKursus(List &L, adr_kursus P) {
// I.S. L mungkin kosong
// F.S. Elemen P ditambahkan sebagai elemen PERTAMA (Insert First)
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

adr_kursus searchKursus(List L, string kodeKursus) {
// I.S. L terdefinisi, kodekursus berisi kode kursus
// F.S. Mengembalikan address jika ketemu, NULL jika tidak 
    adr_kursus P = L.first;
    adr_kursus foundP = nullptr;
    bool found = false;

    while (P != nullptr && !found) {
        if (P->info.kodeKursus == kodeKursus) {
            foundP = P;
            found = true;
        } else {
            P = P->next;
        }
    }
    return foundP;
}
void addModulToKursus(List &L, string kodeKursus, adr_modul C) {
// I.S. L terdefinisi, kodeKursus  kursus yang ingin diadd modul C
// F.S. Modul C disambungkan ke Kursus (Insert Last pada DLL Child)
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

void showModulByKursus(List L, string kodeKursus) {
// I.S. L terdefinisi, kodeKursus dari kursus
// F.S. Menampilkan seluruh modul milik kursus tertentu
    adr_kursus P = searchKursus(L, kodeKursus);
    if (P != nullptr) {
        cout << "Kursus: " << P->info.namaKursus << endl;
        adr_modul Q = P->firstModul;
        int i = 1;
        while (Q != nullptr) {
            cout << "  " << i << ". " << Q->info.judul 
                 << " (" << Q->info.durasi << ")" << endl;
            Q = Q->next;
            i++;
        }
    } else {
        cout << "Kursus tidak ditemukan." << endl;
    }
}

void deleteModul(List &L, string kodeKursus, string judulModul) {
// I.S. L terdefinisi, kodeKursus dari kursus, judulModul berisi judul modul yang ingin dihapus
// F.S. L berisi list baru tanpa modul yang telah dihapus
    adr_kursus P = searchKursus(L, kodeKursus);
    if (P == nullptr) {
        cout << "Kursus tidak ditemukan." << endl;
    } else {
        adr_modul C = P->firstModul;
        bool found = false;

        while (C != nullptr && !found) {
            if (C->info.judul == judulModul) {
                found = true; 
                
                if (C == P->firstModul) {
                    P->firstModul = C->next;
                    if (P->firstModul != nullptr) {
                        P->firstModul->prev = nullptr;
                    }
                } else if (C->next == nullptr) {
                    C->prev->next = nullptr;
                } else {
                    C->prev->next = C->next;
                    C->next->prev = C->prev;
                }
                
                C->next = nullptr;
                C->prev = nullptr;
                cout << "Modul berhasil dihapus." << endl;
            } else {
                C = C->next;
            }
        }
        if (!found) {
            cout << "Modul tidak ditemukan." << endl;
        }
    }
}
int countModul(List L, string kodeKursus) {
// I.S. L terdefinisi, kodeKursus ada atau tidak
// F.S. Mengembalikan integer jumlah modul
    adr_kursus P = searchKursus(L, kodeKursus);
    int jum = 0;

    if (P != nullptr) {
        adr_modul Q = P->firstModul;
        while (Q != nullptr) {
            jum++;
            Q = Q->next;
        }
    }
    return jum;
}
void showJumModul(List L) {
// I.S. L terdefinisi
// F.S. Menampilkan nama kursus dengan modul terbanyak dan tersedikit
    if (L.first == nullptr) {
        cout << "Data Kursus masih kosong." << endl;
    } else {
        adr_kursus P = L.first;
        
        adr_kursus maxP = P;
        adr_kursus minP = P;
        
        int maxJum = 0; 
        int minJum = 0;
        
        adr_modul Q = P->firstModul;
        while(Q != nullptr) { maxJum++; Q = Q->next; }
        minJum = maxJum;

        P = P->next;
        
        while (P != nullptr) {
            int currentJum = 0;
            Q = P->firstModul;
            while(Q != nullptr) { 
                currentJum++; 
                Q = Q->next; 
            }

            if (currentJum > maxJum) {
                maxJum = currentJum;
                maxP = P;
            }
            if (currentJum < minJum) {
                minJum = currentJum;
                minP = P;
            }
            
            P = P->next;
        }

        cout << "=== STATISTIK KURSUS ===" << endl;
        cout << "Modul Terbanyak  : " << maxP->info.namaKursus 
             << " (" << maxJum << " modul)" << endl;
        cout << "Modul Tersedikit : " << minP->info.namaKursus 
             << " (" << minJum << " modul)" << endl;
    }
}
void deleteKursus(List &L, string kodeKursus) {
// I.S. L terdefinisi
// F.S. Node dengan kodeKursus dihapus dari List
    if (L.first == nullptr) return;

    adr_kursus P = L.first;
    adr_kursus prevP = nullptr;
    bool found = false;

    while (P != nullptr && !found) {
        if (P->info.kodeKursus == kodeKursus) {
            found = true;
        } else {
            prevP = P;
            P = P->next;
        }
    }

    if (found) {
        if (P == L.first) {
            L.first = P->next;
        } else {
            prevP->next = P->next;
        }
        P->next = nullptr;
        cout << "Kursus berhasil dihapus." << endl;
    } else {
        cout << "Kursus tidak ditemukan." << endl;
    }
}
void showAllData(List L) {
// I.S. L terdefinisi
// F.S. Menampilkan semua Parent beserta Child-nya
    adr_kursus P = L.first;
    if (P == nullptr) {
        cout << "Data Kosong." << endl;
    }
    while (P != nullptr) {
        cout << "--------------------------------" << endl;
        cout << "[" << P->info.kodeKursus << "] " << P->info.namaKursus << endl;
        adr_modul Q = P->firstModul;
        while (Q != nullptr) {
            cout << "   -> " << Q->info.judul << " (" << Q->info.difficulty << ")" << endl;
            Q = Q->next;
        }
        P = P->next;
        if (P == nullptr){
            cout << "--------------------------------" << endl;
        }
    }
}
