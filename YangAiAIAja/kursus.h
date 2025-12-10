#ifndef KURSUS_H_INCLUDED
#define KURSUS_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

// --- Definisi Struktur Data MLL ---

// 1. Info Data
struct infotype_modul {
    string judul;
    string durasi;
    string difficulty;
};

struct infotype_kursus {
    string namaKursus;
    string kodeKursus;
};

// 2. Pointer Definitions
typedef struct elm_kursus *adr_kursus;
typedef struct elm_modul *adr_modul;

// 3. Node Modul (Child: Doubly Linked List)
struct elm_modul {
    infotype_modul info;
    adr_modul next;
    adr_modul prev;
};

// 4. Node Kursus (Parent: Singly Linked List)
struct elm_kursus {
    infotype_kursus info;
    adr_kursus next;
    adr_modul firstModul; // Pointer penghubung ke Child
};

// 5. List Utama
struct List {
    adr_kursus first;
};

// --- Deklarasi Fungsi & Prosedur ---

// Inisialisasi & Pembuatan Elemen
void createList(List &L);
adr_kursus newElementKursus(string nama, string kode);
adr_modul newElementModul(string judul, string durasi, string diff);

// Operasi Penambahan
void insertKursus(List &L, adr_kursus P);
void addModulToKursus(List &L, string kodeKursus, adr_modul C);

// Operasi Pencarian & Penampilan
adr_kursus searchKursus(List L, string kodeKursus);
void showModulByKursus(List L, string kodeKursus);
void showAllData(List L);

// Operasi Penghapusan (Hanya Unlink/Putus Pointer)
void deleteKursus(List &L, string kodeKursus);
void deleteModul(List &L, string kodeKursus, string judulModul);

// Operasi Statistik
int countModul(adr_kursus P);
void showMinMaxModul(List L);

#endif // KURSUS_H_INCLUDED
