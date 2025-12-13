#include "child.h"

adr_modul newElementModul(string judul, string durasi, string diff) {
// I.S. -
// F.S. Terbentuk node modul baru dengan info yang diberikan
    adr_modul P = new elm_modul;
    P->info.judul = judul;
    P->info.durasi = durasi;
    P->info.difficulty = diff;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}
using namespace std;