#include "lib.h"

void tampilan_PCB(char array[MAX_SIZE][MAX_SIZE][MAX_CELL_SIZE]){
    i=1; j=1;
    while(array[i][j][0]!=NULL){
        ++j;
    }
    printf("\n  ");
    for(i=1; i<j; i++){
        printf("\t%d", i);
    }
    printf(" \n");

    i=1; j=1;
    while(array[i][j][0]!=NULL){
        printf("%d\t", i);
        while(array[i][j][0]!=NULL){
            if(array[i][j][0]!='0'){
                printf("%s\t", array[i][j]);
            } else {
                printf(" \t");
            }
            ++j;
        }
        printf(" \n");
        j=1; ++i;
    }

    printf(" \n");
    return;
}
