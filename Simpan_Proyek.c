#include "lib.h"

void simpan_proyek(project proyek){
int i,j,k,y=1;
char temp[MAX_SIZE][MAX_CELL_SIZE];
FILE *file=fopen(proyek.nama.layout,"w+");
memset(temp,0,sizeof temp);
    y=0; i=1; j=1; k=0;
    while(proyek.tabel.layout[i][j][k]!=NULL){
        while(proyek.tabel.layout[i][j][k]!=NULL){
            while(proyek.tabel.layout[i][j][k]!=NULL){
                if(proyek.tabel.layout[i][j][k]!='0'){
                    temp[i][++y]=proyek.tabel.layout[i][j][k];
                    fputc(temp[i][y], file);
                }
                    ++k;
            }
            temp[i][++y]=',';
            fputc(temp[i][y], file);
            ++j;
            k=0;
        }
        fputc('\n', file);
        ++i;
        j=1;
        k=0;
        y=0;
    }
    fclose(file);

    file=fopen(proyek.nama.routing,"w+");
    memset(temp,0,sizeof temp);
    y=0; i=1; j=1; k=0;
    while(proyek.tabel.routing[i][j][k]!=NULL){
        while(proyek.tabel.routing[i][j][k]!=NULL){
            while(proyek.tabel.routing[i][j][k]!=NULL){
                if(proyek.tabel.routing[i][j][k]!='0'){
                    temp[i][++y]=proyek.tabel.routing[i][j][k];
                    fputc(temp[i][y], file);
                }
                    ++k;
            }
            temp[i][++y]=',';
            fputc(temp[i][y], file);
            ++j;
            k=0;
        }
        fputc('\n', file);
        ++i;
        j=1;
        k=0;
        y=0;
    }
    fclose(file);
    printf("Layout disimpan dalam berkas %s\n", proyek.nama.layout);
    printf("Routing disimpan dalam berkas %s\n", proyek.nama.routing);
    return;
}

