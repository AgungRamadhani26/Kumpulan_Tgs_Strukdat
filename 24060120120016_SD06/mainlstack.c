/* Program   : mainlstack.c */
/* Deskripsi : file DRIVER modul stack berkait */
/* NIM/Nama  : Agung Ramadhani - 24060120120016*/
/* Tanggal   : 05 - Oktober - 2021*/
/***********************************/
#include <stdio.h>
#include "lstack.h"

int main(){
    //KAMUS GLOBAL----------------------------
    lstack LS;  /*variabel parameter aktual linked Stack */
    address A; /*variabel parameter aktual address */
    int Y;

    //ALGORITMA------------------------
    //membentuk stack kosong
    printf("=========================================\n");
    printf("**************STACK BERKAIT**************\n");
    printf("=========================================\n\n");

    createLStack(&LS);
    printf("###isEmptyLStack sebelum stack di push###\n");
    printf("Apakah stack kosong ?\n");
    if(isEmptyLStack(LS)){
        printf("Stack merupakan stack kosong\n");
    }
    else{
        printf("Stack tidak kosong\n");
    }

    printf("\n=========================================\n\n");
    printf("#######tinggiL stack sebelum dipush######\n");
    printf("Tinggi stack sekarang : %d\n", tinggiL(LS));
    printf("stack sebelum di push : ");
    viewLStack(LS);

    printf("\n=========================================\n\n");
    printf("##################pushL##################\n");
    pushL(&LS, 2);
    pushL(&LS, 1);
    pushL(&LS, 9);
    printf("stack setelah di push : ");
    viewLStack(LS);

    printf("\n\n=========================================\n\n");
    printf("###isEmptyLStack setelah stack di push###\n");
    printf("Apakah stack kosong ?\n");
    if(isEmptyLStack(LS)){
        printf("Stack merupakan stack kosong\n");
    }
    else{
        printf("Stack tidak kosong\n");
    }

    printf("\n=========================================\n\n");
    printf("######tinggiL stack setelah dipush#######\n");
    printf("Tinggi stack sekarang : %d\n", tinggiL(LS));

    printf("\n=========================================\n\n");
    printf("##################popL###################\n");
    popL(&LS, &Y);
    printf("stack setelah di pop: ");
    viewLStack(LS);

    printf("\n\n=========================================\n\n");
    printf("######tinggiL stack setelah dipop########\n");
    printf("Tinggi stack sekarang : %d\n", tinggiL(LS));
    printf("\n=========================================\n");

    return 0;
}
