#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include "child.h"
struct infotype_kursus {
    string namaKursus;
    string kodeKursus;
};

typedef struct elm_kursus *adr_kursus;

struct elm_kursus {
    infotype_kursus info;
    adr_kursus next;
    adr_modul firstModul; 
};

struct List {
    adr_kursus first;
};

void createList(List &L);
adr_kursus newElementKursus(string nama, string kode);
void insertKursus(List &L, adr_kursus P);
adr_kursus searchKursus(List L, string kodeKursus);
void deleteKursus(List &L, string kodeKursus);

void addModulToKursus(List &L, string kodeKursus, adr_modul C);
void showModulByKursus(List L, string kodeKursus);
void deleteModul(List &L, string kodeKursus, string judulModul);
void showAllData(List L);
int countModul(List L, string kodeKursus);
void showJumModul(List L);
#endif
