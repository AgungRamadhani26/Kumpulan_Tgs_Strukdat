#include <stdio.h>
#include <stdlib.h>
#include "tqueue.h"

/* Program   : maintqueue.c */
/* Deskripsi : Driver main ADT Queue representasi kontigu dengan array,
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060120120016 - Agung Ramadhani*/
/* Tanggal   : 23-September-2021*/
/***********************************/

int main(){
    //Kamus Global
    tqueue A;
    tqueue B;
    char X;
    char Z;

    //Algoritma
    //mengisi komponen dan elemen dengan '@' pada Queue A
    createQueue(&A);

    //mengembalikan elemen terdepan antrian A saat kosong
    printf("===mengembalikan elemen terdepan antrian A saat kosong===\n");
    printf("head = %d\n", head(A));
    printf("=========================================================\n\n");

    //mengembalikan elemen terakhir antrian A saat kosong
    printf("===mengembalikan elemen terakhir antrian A saat kosong===\n");
    printf("tail = %d\n", tail(A));
    printf("=========================================================\n\n");

    //mengembalikan nilai elemen terdepan antrian A saat kosong
    printf("===mengembalikan nilai elemen terdepan antrian A saat kosong===\n");
    printf("infoHead = %c\n", infoHead(A));
    printf("=========================================================\n\n");

    //mengembalikan nilai elemen terakhir antrian A saat kosong
    printf("===mengembalikan nilai elemen terakhir antrian A saat kosong===\n");
    printf("infoTail = %c\n", infoTail(A));
    printf("=========================================================\n\n");

    //mengembalikan panjang antrian A saat kosong
    printf("===mengembalikan panjang antrian A saat kosong===\n");
    printf("sizeQueue = %d\n", sizeQueue(A));
    printf("=========================================================\n\n");

    //mengembalikan true jika A kosong (kondisi saat A kosong)
    printf("===mengembalikan true jika A kosong (kondisi saat A kosong)===\n");
    if(isEmptyQueue(A)){
        printf("isEmptyQueue = True\n");
    }
    else{
        printf("isEmptyQueue = False\n");
    }
    printf("=========================================================\n\n");

    //mengembalikan true jika A penuh (kondisi saat A kosong)
    printf("===mengembalikan true jika A penuh (kondisi saat A kosong)===\n");
     if(isFullQueue(A)){
        printf("isFullQueue = True\n");
    }
    else{
        printf("isFullQueue = False\n");
    }
    printf("=========================================================\n\n");

    //menambah elemen wadah A
    printf("===menambah elemen wadah A===\n");
    enqueue(&A,'A');
    enqueue(&A,'M');
    enqueue(&A,'I');
    enqueue(&A,'N');
    printf("**mencetak semua elemen wadah ke layar**\n");
    printQueue(A);
    printf("\n**mencetak elemen Queue yang terisi, ke layar**\n");
    viewQueue(A);
    printf("\n=========================================================\n\n");

    //mengembalikan elemen terdepan antrian A setelah diisi
    printf("===mengembalikan elemen terdepan antrian A setelah diisi===\n");
    printf("head = %d\n", head(A));
    printf("=========================================================\n\n");

    //mengembalikan elemen terakhir antrian A setelah diisi
    printf("===mengembalikan elemen terakhir antrian A setelah diisi===\n");
    printf("tail = %d\n", tail(A));
    printf("=========================================================\n\n");

    //mengembalikan nilai elemen terdepan antrian A setelah diisi
    printf("===mengembalikan nilai elemen terdepan antrian A setelah diisi===\n");
    printf("infoHead = %c\n", infoHead(A));
    printf("=========================================================\n\n");

    //mengembalikan nilai elemen terakhir antrian A setelah diisi
    printf("===mengembalikan nilai elemen terakhir antrian A setelah diisi===\n");
    printf("infoTail = %c\n", infoTail(A));
    printf("=========================================================\n\n");

    //mengembalikan panjang antrian A setelah diisi
    printf("===mengembalikan panjang antrian A setelah diisi===\n");
    printf("sizeQueue = %d\n", sizeQueue(A));
    printf("=========================================================\n\n");

    //mengembalikan true jika A kosong (kondisi A setelah diisi)
    printf("===mengembalikan true jika A kosong (kondisi A setelah diisi)===\n");
    if(isEmptyQueue(A)){
        printf("isEmptyQueue = True\n");
    }
    else{
        printf("isEmptyQueue = False\n");
    }
    printf("=========================================================\n\n");

    //mengembalikan true jika A penuh (kondisi A setelah diisi)
    printf("===mengembalikan true jika A penuh (kondisi A setelah diisi)===\n");
     if(isFullQueue(A)){
        printf("isFullQueue = True\n");
    }
    else{
        printf("isFullQueue = False\n");
    }
    printf("=========================================================\n\n");

    //mengembalikan true jika hanya ada 1 elemen pada antrian A
    printf("===mengembalikan true jika hanya ada 1 elemen pada antrian A===\n");
    if(isOneElement(A)){
        printf("isOneElement = True\n");
    }
    else{
        printf("isOneElement = False\n");
    }
    printf("=========================================================\n\n");

    //mengurangi elemen wadah A, semua elemen di belakang head digeser maju
    printf("===mengurangi elemen wadah A, semua elemen di belakang head digeser maju===\n");
    dequeue(&A,&X);
    printf("elemen wadah A sekarang = ");
    printQueue(A);
    printf("\n=========================================================\n\n");

    //mengembalikan ukuran yang terpanjang dari 2 antrian
    printf("===mengembalikan ukuran yang terpanjang dari 2 antrian===\n");
    createQueue(&B);
    enqueue(&B,'N');
    printf("elemen wadah B sekarang = ");
    printQueue(B);
    printf("\npanjang antrian B = %d\n", sizeQueue(B));
    printf("elemen wadah A sekarang = ");
    printQueue(A);
    printf("\npanjang antrian A = %d\n", sizeQueue(A));
    printf("ukuran terpanjang antara antrian A dan B (maxlength(A,B)) yaitu = %d",maxlength(A,B));
    printf("\n=========================================================\n\n");

    //menambah elemen wadah pada antrian terpendek dari A atau B
    printf("===menambah elemen wadah pada antrian terpendek dari A atau B===\n");
    printf("elemen wadah B = ");
    printQueue(B);
    printf("\npanjang antrian B = %d\n", sizeQueue(B));
    printf("elemen wadah A = ");
    printQueue(A);
    printf("\npanjang antrian A = %d\n", sizeQueue(A));
    enqueue2(&A,&B,'I');
    printf("**Panjang antrian setelah menggunakan prosedur enqueue2**\n");
    printf("elemen wadah B sekarang = ");
    printQueue(B);
    printf("\npanjang antrian B sekarang = %d\n", sizeQueue(B));
    printf("elemen wadah A sekarang = ");
    printQueue(A);
    printf("\npanjang antrian A sekarang = %d\n", sizeQueue(A));
    printf("=========================================================\n\n");

    //mengurangi elemen wadah antrian terpanjang A atau B
    printf("===mengurangi elemen wadah antrian terpanjang A atau B===\n");
    printf("elemen wadah B = ");
    printQueue(B);
    printf("\npanjang antrian B = %d\n", sizeQueue(B));
    printf("elemen wadah A = ");
    printQueue(A);
    printf("\npanjang antrian A = %d\n", sizeQueue(A));
    dequeue2(&A,&B,&Z);
    printf("**Panjang antrian setelah menggunakan prosedur dequeue2**\n");
    printf("elemen wadah B sekarang = ");
    printQueue(B);
    printf("\npanjang antrian B sekarang = %d\n", sizeQueue(B));
    printf("elemen wadah A sekarang = ");
    printQueue(A);
    printf("\npanjang antrian A sekarang = %d\n", sizeQueue(A));
    printf("=========================================================\n\n");
}
