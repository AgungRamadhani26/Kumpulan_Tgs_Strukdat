#include <stdio.h>
#include <stdlib.h>
#include "tqueue2.h"

/* Program   : maintqueue2.c*/
/* Deskripsi : Driver main ADT Queue representasi kontigu dengan array,
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060120120016 - Agung Ramadhani*/
/* Tanggal   : 30-September-2021*/
/***********************************/

int main(){
    //Kamus Global
    tqueue2 A;
    char X;


    //Algoritma
    //mengisi komponen dan elemen dengan '@' pada Queue A
    createQueue2(&A);

    //mengembalikan true jika A kosong (kondisi saat A kosong)
    printf("===mengembalikan true jika A kosong (kondisi saat A kosong)===\n");
    if(isEmptyQueue2(A)){
        printf("isEmptyQueue2 = True\n");
    }
    else{
        printf("isEmptyQueue2 = False\n");
    }
    printf("=========================================================\n\n");

    //mengembalikan true jika A penuh (kondisi saat A kosong)
    printf("===mengembalikan true jika A penuh (kondisi saat A kosong)===\n");
    if(isFullQueue2(A)){
        printf("isFullQueue2 = True\n");
    }
    else{
        printf("isFullQueue2 = False\n");
    }
    printf("=========================================================\n\n");

    //mengembalikan elemen terdepan antrian A saat kosong
    printf("===mengembalikan elemen terdepan antrian A saat kosong===\n");
    printf("head2 = %d\n", head2(A));
    printf("=========================================================\n\n");

    //mengembalikan elemen terakhir antrian A saat kosong
    printf("===mengembalikan elemen terakhir antrian A saat kosong===\n");
    printf("tail2 = %d\n", tail2(A));
    printf("=========================================================\n\n");

    //mengembalikan nilai elemen terdepan antrian A saat kosong
    printf("===mengembalikan nilai elemen terdepan antrian A saat kosong===\n");
    printf("infoHead2 = %c\n", infoHead2(A));
    printf("=========================================================\n\n");

    //mengembalikan nilai elemen terakhir antrian A saat kosong
    printf("===mengembalikan nilai elemen terakhir antrian A saat kosong===\n");
    printf("infoTail2 = %c\n", infoTail2(A));
    printf("=========================================================\n\n");

    //mengembalikan panjang antrian A saat kosong
    printf("===mengembalikan panjang antrian A saat kosong===\n");
    printf("sizeQueue2 = %d\n", sizeQueue2(A));
    printf("=========================================================\n\n");

    //menambah elemen wadah A
    printf("===menambah elemen wadah A===\n");
    enqueue2(&A,'A');
    enqueue2(&A,'M');
    enqueue2(&A,'I');
    enqueue2(&A,'N');
    enqueue2(&A,'O');
    printf("**mencetak semua elemen wadah ke layar**\n");
    printQueue2(A);
    printf("\n**mencetak elemen Queue yang terisi, ke layar**\n");
    viewQueue2(A);
    printf("\n=========================================================\n\n");

    //mengembalikan elemen terdepan antrian A setelah diisi
    printf("===mengembalikan elemen terdepan antrian A setelah diisi===\n");
    printf("head2 = %d\n", head2(A));
    printf("=========================================================\n\n");

    //mengembalikan elemen terakhir antrian A setelah diisi
    printf("===mengembalikan elemen terakhir antrian A setelah diisi===\n");
    printf("tail2 = %d\n", tail2(A));
    printf("=========================================================\n\n");

    //mengembalikan nilai elemen terdepan antrian A setelah diisi
    printf("===mengembalikan nilai elemen terdepan antrian A setelah diisi===\n");
    printf("infoHead2 = %c\n", infoHead2(A));
    printf("=========================================================\n\n");

    //mengembalikan nilai elemen terakhir antrian A setelah diisi
    printf("===mengembalikan nilai elemen terakhir antrian A setelah diisi===\n");
    printf("infoTail2 = %c\n", infoTail2(A));
    printf("=========================================================\n\n");

    //mengembalikan panjang antrian A setelah diisi
    printf("===mengembalikan panjang antrian A setelah diisi===\n");
    printf("sizeQueue2 = %d\n", sizeQueue2(A));
    printf("=========================================================\n\n");

    //mengembalikan true jika A kosong (kondisi A setelah diisi)
    printf("===mengembalikan true jika A kosong (kondisi A setelah diisi)===\n");
    if(isEmptyQueue2(A)){
        printf("isEmptyQueue2 = True\n");
    }
    else{
        printf("isEmptyQueue2 = False\n");
    }
    printf("=========================================================\n\n");

    //mengembalikan true jika A penuh (kondisi A setelah diisi)
    printf("===mengembalikan true jika A penuh (kondisi A setelah diisi)===\n");
    if(isFullQueue2(A)){
        printf("isFullQueue2 = True\n");
    }
    else{
        printf("isFullQueue2 = False\n");
    }
    printf("=========================================================\n\n");

    //mengembalikan true jika hanya ada 1 elemen pada antrian A
    printf("===mengembalikan true jika hanya ada 1 elemen pada antrian A===\n");
    if(isOneElement2(A)){
        printf("isOneElement2 = True\n");
    }
    else{
        printf("isOneElement2 = False\n");
    }
    printf("=========================================================\n\n");

    //mengurangi elemen wadah A
    printf("===mengurangi elemen wadah A===\n");
    dequeue2(&A,&X);
    dequeue2(&A,&X);
    printf("elemen wadah A sekarang = ");
    printQueue2(A);
    printf("\n=========================================================\n\n");

    //mengembalikan true jika Tail tidak dapat lagi geser
    printf("===mengembalikan true jika Tail tidak dapat lagi geser===\n");
    if(isTailStop2(A)){
        printf("isTailStop2 = True\n");
    }
    else{
        printf("isTailStop2 = False\n");
    }
    printf("=========================================================\n\n");

    //menambah elemen wadah A
    printf("===menambah elemen wadah A===\n");
    enqueue2(&A,'M');
    printf("**mencetak semua elemen wadah ke layar**\n");
    printQueue2(A);
    printf("\n**mencetak elemen Queue yang terisi, ke layar**\n");
    viewQueue2(A);
    printf("\n=========================================================\n\n");
}

