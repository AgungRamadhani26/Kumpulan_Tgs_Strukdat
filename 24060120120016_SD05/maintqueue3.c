#include <stdio.h>
#include <stdlib.h>
#include "tqueue3.h"

/* Program   : maintqueue3.c*/
/* Deskripsi : Driver main ADT Queue representasi kontigu dengan array,
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060120120016 - Agung Ramadhani*/
/* Tanggal   : 30-September-2021*/
/***********************************/

int main(){
    //Kamus Global
    tqueue3 A;
    char X;

    //Algoritma
    //mengisi komponen dan elemen dengan '@' pada Queue A
    createQueue3(&A);

    //mengembalikan true jika A kosong (kondisi saat A kosong)
    printf("===mengembalikan true jika A kosong (kondisi saat A kosong)===\n");
    if(isEmptyQueue3(A)){
        printf("isEmptyQueue3 = True\n");
    }
    else{
        printf("isEmptyQueue3 = False\n");
    }
    printf("=========================================================\n\n");

    //mengembalikan true jika A penuh (kondisi saat A kosong)
    printf("===mengembalikan true jika A penuh (kondisi saat A kosong)===\n");
    if(isFullQueue3(A)){
        printf("isFullQueue3 = True\n");
    }
    else{
        printf("isFullQueue3 = False\n");
    }
    printf("=========================================================\n\n");

    //mengembalikan elemen terdepan antrian A saat kosong
    printf("===mengembalikan elemen terdepan antrian A saat kosong===\n");
    printf("head3 = %d\n", head3(A));
    printf("=========================================================\n\n");

    //mengembalikan elemen terakhir antrian A saat kosong
    printf("===mengembalikan elemen terakhir antrian A saat kosong===\n");
    printf("tail3 = %d\n", tail3(A));
    printf("=========================================================\n\n");

    //mengembalikan nilai elemen terdepan antrian A saat kosong
    printf("===mengembalikan nilai elemen terdepan antrian A saat kosong===\n");
    printf("infoHead3 = %c\n", infoHead3(A));
    printf("=========================================================\n\n");

    //mengembalikan nilai elemen terakhir antrian A saat kosong
    printf("===mengembalikan nilai elemen terakhir antrian A saat kosong===\n");
    printf("infoTail3 = %c\n", infoTail3(A));
    printf("=========================================================\n\n");

    //mengembalikan panjang antrian A saat kosong
    printf("===mengembalikan panjang antrian A saat kosong===\n");
    printf("sizeQueue3 = %d\n", sizeQueue3(A));
    printf("=========================================================\n\n");

    //menambah elemen wadah A
    printf("===menambah elemen wadah A===\n");
    enqueue3(&A,'A');
    enqueue3(&A,'M');
    enqueue3(&A,'I');
    enqueue3(&A,'N');
    enqueue3(&A,'O');
    printf("**mencetak semua elemen wadah ke layar**\n");
    printQueue3(A);
    printf("\n**mencetak elemen Queue yang terisi, ke layar**\n");
    viewQueue3(A);
    printf("\n=========================================================\n\n");

    //mengembalikan elemen terdepan antrian A setelah diisi
    printf("===mengembalikan elemen terdepan antrian A setelah diisi===\n");
    printf("head3 = %d\n", head3(A));
    printf("=========================================================\n\n");

    //mengembalikan elemen terakhir antrian A setelah diisi
    printf("===mengembalikan elemen terakhir antrian A setelah diisi===\n");
    printf("tail3 = %d\n", tail3(A));
    printf("=========================================================\n\n");

    //mengembalikan nilai elemen terdepan antrian A setelah diisi
    printf("===mengembalikan nilai elemen terdepan antrian A setelah diisi===\n");
    printf("infoHead3 = %c\n", infoHead3(A));
    printf("=========================================================\n\n");

    //mengembalikan nilai elemen terakhir antrian A setelah diisi
    printf("===mengembalikan nilai elemen terakhir antrian A setelah diisi===\n");
    printf("infoTail3 = %c\n", infoTail3(A));
    printf("=========================================================\n\n");

    //mengembalikan panjang antrian A setelah diisi
    printf("===mengembalikan panjang antrian A setelah diisi===\n");
    printf("sizeQueue3 = %d\n", sizeQueue3(A));
    printf("=========================================================\n\n");

    //mengembalikan true jika A kosong (kondisi A setelah diisi)
    printf("===mengembalikan true jika A kosong (kondisi A setelah diisi)===\n");
    if(isEmptyQueue3(A)){
        printf("isEmptyQueue3 = True\n");
    }
    else{
        printf("isEmptyQueue3 = False\n");
    }
    printf("=========================================================\n\n");

    //mengembalikan true jika A penuh (kondisi A setelah diisi)
    printf("===mengembalikan true jika A penuh (kondisi A setelah diisi)===\n");
    if(isFullQueue3(A)){
        printf("isFullQueue3 = True\n");
    }
    else{
        printf("isFullQueue3 = False\n");
    }
    printf("=========================================================\n\n");

    //mengembalikan true jika hanya ada 1 elemen pada antrian A
    printf("===mengembalikan true jika hanya ada 1 elemen pada antrian A===\n");
    if(isOneElement3(A)){
        printf("isOneElement3 = True\n");
    }
    else{
        printf("isOneElement3 = False\n");
    }
    printf("=========================================================\n\n");

    //mengurangi elemen wadah A
    printf("===mengurangi elemen wadah A===\n");
    dequeue3(&A,&X);
    printf("elemen wadah A sekarang = ");
    printQueue3(A);
    printf("\n=========================================================\n\n");

}
