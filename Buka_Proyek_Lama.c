#include "lib.h"

int opsi,i,k,n,j,N,y=1;
char array[MAX_SIZE][MAX_SIZE][MAX_CELL_SIZE];
char str[MAX_SIZE][MAX_STRLEN], temp[MAX_SIZE][MAX_STRLEN];

void format_program(){
    memset(array, 0, sizeof array);
    memset(temp, 0, sizeof temp);

    for(n=1; n<MAX_SIZE; n++){
        i=0; j=0;
        while ((str[n][i+1]!='\n')&&(str[n][i+1]!=NULL)){
            if((i==0)&&(str[n][i]==',')){
                temp[n][++j]='0';
            }
            temp[n][++j]=str[n][i];
            if ((str[n][i]==',')&&((str[n][i+1]==',')||(str[n][i+1]==NULL))){
                temp[n][++j]='0';
            }
            ++i;
        }
    }

    i=1; j=1; k=0;
    for(n=1; n<MAX_SIZE; n++){
        while(temp[n][i]!=NULL){
            if(temp[n][i]!=','){
                array[n][j][k]=temp[n][i];
                ++i; ++k;
            } else {
                ++i; ++j; k=0;
            }
        }
        i=1; j=1; k=0;
    }
    return;
}

void baca_proyek(FILE *file){
    memset(str, 0, sizeof str);
    i=1;
    while (fgets(str[i], MAX_SIZE, file) != NULL){
        ++i;
    }
    fclose(file);
    format_program();
    return;
}

void buka_proyek(){
    printf("====== Memuat Proyek dari Berkas ======\n");
    printf("Masukkan nama proyek: ");
    scanf(" %[^\n]s", proyek.nama.input);
    strcpy(proyek.nama.layout, proyek.nama.input);
    strcat(proyek.nama.layout, "_layout.csv");
    strcpy(proyek.nama.routing, proyek.nama.input);
    strcat(proyek.nama.routing, "_routing.csv");
    proyek.file.layout=fopen(proyek.nama.layout,"r");
    proyek.file.routing=fopen(proyek.nama.routing,"r");
    if ((proyek.file.layout==NULL)&&(proyek.file.routing==NULL)){
        printf("\nProyek '%s' tidak ditemukan.\n", proyek.nama.input);
        fclose(proyek.file.layout);
        fclose(proyek.file.routing);
        error_buka_proyek();
    } else if ((proyek.file.layout==NULL)&&(proyek.file.routing!=NULL)){
        printf("\n'%s' tidak ditemukan.\n", proyek.nama.layout);
        fclose(proyek.file.layout);
        fclose(proyek.file.routing);
        error_buka_proyek();
    } else if ((proyek.file.layout!=NULL)&&(proyek.file.routing==NULL)){
        printf("\n'%s' tidak ditemukan.\n", proyek.nama.routing);
        fclose(proyek.file.layout);
        fclose(proyek.file.routing);
        error_buka_proyek();
    } else {
        proyek.file.layout=fopen(proyek.nama.layout,"r");
        baca_proyek(proyek.file.layout);
        memset(proyek.tabel.layout,0,sizeof proyek.tabel.layout);
        i=1; j=1;
        while(array[i][j][0]!=NULL){
            while(array[i][j][0]!=NULL){
                strcpy(proyek.tabel.layout[i][j], array[i][j]);
                ++j;
            } proyek.N=j-1; j=1; ++i;
        }
        proyek.M=i-1;

        proyek.file.routing=fopen(proyek.nama.routing,"r");
        baca_proyek(proyek.file.routing);
        memset(proyek.tabel.routing,0,sizeof proyek.tabel.routing);
        i=1; j=1;
        while(array[i][j][0]!=NULL){
            while(array[i][j][0]!=NULL){
                strcpy(proyek.tabel.routing[i][j], array[i][j]);
                ++j;
            } j=1; ++i;
        }
    }
    Menu_Utama();
    return;
}

void error_buka_proyek(){
    tab(); printf("1. Masukkan ulang\n");
    tab(); printf("2. Kembali\n");
    printf("Masukan: ");
    opsi=baca_opsi();
    switch(opsi){
        case 1: buka_proyek(); break;
        case 2: exit(0);
        default: printf("Masukan salah.\n\n");
                 error_buka_proyek();
    }
    return;
}
