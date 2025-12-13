#ifndef child_H_INCLUDED
#define child_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;
struct infotype_modul {
    string judul;
    string durasi;
    string difficulty;
};

typedef struct elm_modul *adr_modul;

struct elm_modul {
    infotype_modul info;
    adr_modul next;
    adr_modul prev;
};
adr_modul newElementModul(string judul, string durasi, string kesulitan);
#endif
