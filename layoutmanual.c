#include "lib.h"

void layoutmanual(int n, int m) {
component komponen[MAX_COMPONENT];
char k[MAX_CELL_SIZE];
int dx,dx2,dy,dy2,kotak,i,j,count=0;

    do {
        printf("Isi 'q' or 'Q' untuk kembali ke menu\n");
        printf("Pilih komponen(R, C, T, atau J) = ");
        scanf(" %s",k);
        if ((strcmp(k,"R")==0 ||strcmp(k,"C") ==0||strcmp(k,"J") ==0)){
            printf("Nama komponen = ");
            scanf("%s",&komponen[++count].nama);
            printf("Koordinat kaki 1 = ");
            scanf("%d %d",&komponen[count].n1.x, &komponen[count].n1.y);
            printf("Koordinat kaki 2 = "); scanf("%d %d",&komponen[count].n2.x, &komponen[count].n2.y);
            if (komponen[count].n1.x==komponen[count].n2.x || komponen[count].n1.y==komponen[count].n2.y) {
                if (strcmp(k,"R")==0) {
                    kotak=4;
                } else if (strcmp(k,"C")==0){
                    kotak=2;
                } else {
                    kotak=1;
                }
                dx=komponen[count].n1.x-komponen[count].n2.x;
                dy=komponen[count].n1.y-komponen[count].n2.y;
                if ((abs(dx)>=kotak)||(abs(dy)>=kotak)){
                    strcpy(proyek.tabel.layout[komponen[count].n1.x][komponen[count].n1.y],komponen[count].nama);
                    strcpy(proyek.tabel.layout[komponen[count].n2.x][komponen[count].n2.y],komponen[count].nama);
                }
            }
        }
        else if (strcmp(k,"T")==0){
            printf("Nama komponen = ");
            scanf("%s",&komponen[++count].nama);
            printf("Koordinat kaki Tb = ");
            scanf("%d %d",&komponen[count].n1.x, &komponen[count].n1.y);
            printf("Koordinat kaki Tc = ");
            scanf("%d %d",&komponen[count].n2.x, &komponen[count].n2.y);
            printf("Koordinat kaki Te = ");
            scanf("%d %d",&komponen[count].n3.x, &komponen[count].n3.y);
            kotak=2;
            dx=komponen[count].n1.x-komponen[count].n2.x;
            dx2=komponen[count].n1.x-komponen[count].n3.x;
            dy=komponen[count].n1.y-komponen[count].n2.y;
            dy2=komponen[count].n1.y-komponen[count].n3.y;
            if ((dx==0 && dx2==0)||(dy==0 && dy2==0)){
                if ((abs(dx)>=kotak)&&((abs(dx2)>=kotak))||((abs(dy)>=kotak)&&(abs(dy2)>=kotak))){
                    strcpy(proyek.tabel.layout[komponen[count].n1.x][komponen[count].n1.y],"Tb");
                    strcpy(proyek.tabel.layout[komponen[count].n2.x][komponen[count].n2.y],"Tc");
                    strcpy(proyek.tabel.layout[komponen[count].n3.x][komponen[count].n3.y],"Te");
                }
            }
        }else if (strcmp(k,"Q")==0||strcmp(k,"q")==0){
            Menu_Utama();
        }else {
            printf("Nama komponen tidak sesuai.\n");
            layoutmanual(m,n);
        }
        //printf("Isi 'q' or 'Q' untuk kembali ke menu\n");
        //printf("Pilih komponen(R, C, T, atau J) = ");
        //k=getchar();
        //gets(&k);
        //pilih komponen R/C/T/J jangan diberi angka atau huruf setelah komponen
    } while(strcmp(k,"R") ==0||strcmp(k,"C") ==0||strcmp(k,"J") ==0||strcmp(k,"T") ==0);
    printf("\n");
    for(int j=0;j<=m;j++){
        proyek.tabel.layout[0][j][4]=j + 0x30;
    }
    for(int i=0;i<=n;i++){
        proyek.tabel.layout[i][0][4]=i + 0x30;
    }
    for(int i=0;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%4s",proyek.tabel.layout[i][j]);
        }
        printf("\n");
    }
    return;
}
