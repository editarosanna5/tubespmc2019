#include "lib.h"

project proyek;

void projectsize(){
int i,j;
    printf("Masukkan ukuran PCB NxM (N,M<40): ");
    scanf("%d %d", &proyek.N, &proyek.M);
    if ((proyek.N<1)||(proyek.N>40)||(proyek.M<1)||(proyek.M>40)){
        printf("Ukuran tidak sesuai (N,M<40)\n");
        projectsize();
    }
    for(i=1; i<=proyek.M; i++){
        for(j=1; j<=proyek.N; j++){
            proyek.tabel.layout[i][j][0]='0';
            proyek.tabel.routing[i][j][0]='0';
        }
    }
    return;
}
project buat_proyek(){
    proyek.file.layout=fopen(proyek.nama.layout,"w");
    fclose(proyek.file.layout);
    proyek.file.routing=fopen(proyek.nama.routing,"w");
    fclose(proyek.file.routing);
    projectsize();
    return proyek;
}

void initial_array(){
int i,j;
    for(i=1; i<=proyek.M; i++){
        for(j=1; j<=proyek.N; j++){
            proyek.tabel.layout[i][j][0]='0';
            proyek.tabel.routing[i][j][0]='0';
        }
    }
    return;
}

void buat_proyek_baru(){
    printf("\n====== Membuat Proyek Baru ======\n");
    printf("Masukkan nama proyek: ");
    scanf(" %[^\n]s", proyek.nama.input);
    strcpy(proyek.nama.layout, proyek.nama.input);
    strcat(proyek.nama.layout, "_layout.csv");
    strcpy(proyek.nama.routing, proyek.nama.input);
    strcat(proyek.nama.routing, "_routing.csv");
    proyek.file.layout=fopen(proyek.nama.layout,"r");
    proyek.file.routing=fopen(proyek.nama.routing,"r");
    if ((proyek.file.layout!=NULL)||(proyek.file.routing!=NULL)){
        fclose(proyek.file.layout);
        fclose(proyek.file.routing);
        printf("\nProyek bernama '%s' sudah ada:\n", proyek.nama.input);
        error_buat_proyek();
    } else {
        proyek=buat_proyek(proyek);
    }

    printf("\n");
    Menu_Utama();
    return;
}

void error_buat_proyek(){
int opsi;
    tab(); printf("1. Overwrite\n");
    tab(); printf("2. Masukkan ulang\n");
    tab(); printf("3. Kembali\n");
    printf("Masukan: ");
    opsi=baca_opsi();
    switch(opsi){
        case 1: proyek=buat_proyek();
                initial_array();
                Menu_Utama(); break;
        case 2: buat_proyek_baru(); break;
        case 3: Menu(); break;
        default: printf("Masukan tidak sesuai.\n");
                 error_buat_proyek();
    }
    return;
}
