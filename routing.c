#include "lib.h"

project RoutingManual(int baris, int kolom, project proyek)
{
    char simbol[4],*str;
    char koor[10],arr[10],c;
    int count=1;
    int length,i,j;
    int x,y;
    printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
    printf("Isi 'n' atau 'N' untuk memulai pada simpul (node) baru\n");

            printf("Pilih Simbol (!,@,#,$,%,^,&,*): ");
            scanf(" %s",&simbol);
            while((strcmp(simbol,"Q"))&&(strcmp(simbol,"q"))){
                while((strcmp(simbol,"!"))&&(strcmp(simbol,"@"))&&(strcmp(simbol,"#"))&&(strcmp(simbol,"$"))&&(strcmp(simbol,"%"))&&(strcmp(simbol,"^"))&&(strcmp(simbol,"&"))&&(strcmp(simbol,"*")))
                {
                    printf("Maaf input tidak valid, silahkan coba lagi\n");
                    printf("Pilih Simbol (!,@,#,$,%,^,&,*,(,): ");
                    scanf("%s",&simbol);
                }
                while((strcmp(koor,"n"))&&(strcmp(koor,"N")))
                {
                    printf("Koordinat %d: ",count);
                    scanf(" %[^\n]s", koor);
                    sscanf(koor,"%d %c %d", &x,&c,&y);
                    if((x>baris)||(y>kolom))
                    {
                        printf("Maaf input tidak valid,silahkan coba lagi\n");
                    }
                    else
                    {
                        strcpy(proyek.tabel.routing[x][y],simbol);
                        count++;
                    }
                }
                printf("Pilih Simbol (!,@,#,$,%,^,&,*): ");
                scanf(" %s",&simbol);
            }

    return proyek;
}
