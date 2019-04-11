#include "Buat_Proyek_Baru.c"
#include "Buka_Proyek_Lama.c"
#include "Simpan_Proyek.c"
#include "layoutmanual.c"
#include "lib.h"
#include "routing.c"
#include "tampilan_pcb.c"

int opsi;
void Menu(){
    printf("\nMenu:\n");
    tab(); printf("1. Buat Proyek Baru\n");
    tab(); printf("2. Muat Proyek dari Berkas\n");
    tab(); printf("3. Keluar\n");
    printf("Masukan: ");
    opsi=baca_opsi();
    switch(opsi){
        case 1: buat_proyek_baru(); break;
        case 2: buka_proyek(); break;
        case 3: exit(0);
        default: printf("Masukan tidak sesuai.\n");
                 Menu();
    }
    return;
}

void Menu_Utama(){
    printf("\n[Menu Utama]\n");
    printf("Pilih Mode:\n");
    tab(); printf("1. Tampilkan Layout\n");
    tab(); printf("2. Layouting Manual\n");
    tab(); printf("3. Tampilkan Routing\n");
    tab(); printf("4. Routing Manual\n");
    tab(); printf("5. Layout Otomatis\n");
    tab(); printf("6. Routing Otomatis\n");
    tab(); printf("7. Design Rule Checker\n");
    tab(); printf("8. Simpan Proyek dan Keluar\n");
    printf("Pilih Mode: ");
    opsi=baca_opsi();
    switch(opsi){
        case 1: printf("\n[Layout Rangkaian pada PCB Dot Matriks]"); tampilan_PCB(proyek.tabel.layout); Menu_Utama(); break;
        case 2: printf("\n[Mode Layout]\n"); layoutmanual(proyek.M, proyek.N); Menu_Utama(); break;
        case 3: printf("\n[Routing Rangkaian pada PCB Dot Matriks]"); tampilan_PCB(proyek.tabel.routing); Menu_Utama(); break;
        case 4: printf("\n[Mode Routing]\n"); proyek=RoutingManual(proyek.M, proyek.N, proyek); Menu_Utama(); break;
        case 5: printf("Fitur belum tersedia.\n"); Menu_Utama(); break;
        case 6: printf("Fitur belum tersedia.\n"); Menu_Utama(); break;
        case 7: printf("Fitur belum tersedia.\n"); Menu_Utama(); break;
        case 8: simpan_proyek(proyek); Menu(); break;
        default: printf("Masukan tidak sesuai.\n");
        Menu_Utama();
    }
}

int main(){
    Menu();
}
