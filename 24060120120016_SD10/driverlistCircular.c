/* File : driverlistCircular.c */
/* Driver main ADT list Circular dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* Nama - NIM : Agung Ramadhani - 24060120120016*/
/* Dibuat pada : 16 November 2021*/

#include <stdio.h>
#include <stdlib.h>
#include "listCircular.h"

int main(){
    /*Kamus Lokal*/
    List A, B;
    address X,Y,Z,T,L;
    infotype C;

    /*Algoritma*/
    /* ----- Pembuatan List Kosong ----- */
    printf("======MEMBUAT LIST KOSONG======\n");
    CreateList(&A);
    printf("List A sudah dibuat :)\n");
    CreateList(&B);
    printf("List B sudah dibuat :)\n");

    /* ----- Test List Kosong ----- */
    printf("\n=======TEST LIST KOSONG========\n");
    printf("Apakah list A kosong ?\n");
    if(ListEmpty(A)){
        printf("List A kosong :(\n");
    }
    else{
        printf("List A sudah memiliki isi :)\n");
    }
    printf("Apakah list B kosong ?\n");
    if(ListEmpty(B)){
        printf("List B kosong :(\n");
    }
    else{
        printf("List B sudah memiliki isi :)\n");
    }

    /* ----- Primitif Berdasarkan Alamat ------ */
    printf("\n/* ----- Primitif Berdasarkan Alamat ------ */");
    /* Penambahan Elemen Berdasarkan Alamat */
    /* ----- Mengisi Elemen Pertama List ----- */
    printf("\n==========MENGISI ELEMEN PERTAMA LIST===========\n");
    X = Alokasi(6);
    InsertFirst(&A,X);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));
    printf("Alamat memory First(A) = %X\n", First(A));
    printf("Alamat memory Last(A) = %X\n", next(First(A)));
    Y = Alokasi(7);
    InsertFirst(&A,Y);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));
    printf("Alamat memory First(A) = %X\n", First(A));
    printf("Alamat memory Last(A) = %X\n", next(next(First(A))));
    L = Alokasi(1);
    InsertFirst(&A,L);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));

    /* ----- Mengisi Elemen List Setelah Elemen Tertentu ----- */
    printf("\n===MENGISI ELEMEN LIST SETELAH ELEMEN TERTENTU===\n");
    Z = Alokasi(8);
    InsertAfter(&A,Z,Y);
    printf("Isi list A  : ");
    PrintInfo(A);

    /* ----- Mengisi Elemen Terakhir List ----- */
    printf("\n==========MENGISI ELEMEN TERAKHIR LIST===========\n");
    T = Alokasi(9);
    InsertLast(&A, T);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));

    /*Penghapusan Sebuah Elemen*/
    /* ----- Menghapus Elemen Pertama List ----- */
    printf("\n==========MENGHAPUS ELEMEN PERTAMA LIST==========\n");
    DelFirst(&A, &L);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));

    /* ----- Menghapus Elemen Terakhir List ----- */
    printf("\n=========MENGHAPUS ELEMEN TERAKHIR LIST==========\n");
    DelLast(&A, &T);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));

    /* ----- Menghapus Elemen List Setelah Elemen Tertentu ----- */
    printf("\n==MENGHAPUS ELEMEN LIST SETELAH ELEMEN TERTENTU==\n");
    DelAfter(&A, &Z, Y);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n\n\n", NbElmt(A));




    /* ----- Primitif Berdasarkan Nilai ----- */
    printf("\n/* ----- Primitif Berdasarkan Nilai ----- */");
    /* Penambahan Elemen Berdasarkan Nilai */
    /* ----- Mengisi Elemen Pertama List ----- */
    printf("\n===========MENGISI ELEMEN PERTAMA LIST===========\n");
    InsVFirst(&B, 2);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));
    printf("Alamat memory First(B) = %X\n", First(B));
    printf("Alamat memory Last(B) = %X\n", next(First(B)));
    InsVFirst(&B, 3);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));
    printf("Alamat memory First(B) = %X\n", First(B));
    printf("Alamat memory Last(B) = %X\n", next(next(First(B))));
    InsVFirst(&B, 1);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));

    /* ----- Mengisi Elemen List Setelah Elemen Tertentu ----- */
    printf("\n===MENGISI ELEMEN LIST SETELAH ELEMEN TERTENTU===\n");
    InsVAfter(&B, 4, 3);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));

    /* ----- Mengisi Elemen Terakhir List ----- */
    printf("\n==========MENGISI ELEMEN TERAKHIR LIST===========\n");
    InsVLast(&B, 11);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));

    /*Penghapusan Sebuah Elemen*/
    /* ----- Menghapus Elemen Pertama List ----- */
    printf("\n==========MENGHAPUS ELEMEN PERTAMA LIST==========\n");
    DelVFirst(&B, &C);
    printf("Elemen terhapus : %d\n", C);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));

    /* ----- Menghapus Elemen Terakhir List ----- */
    printf("\n=========MENGHAPUS ELEMEN TERAKHIR LIST==========\n");
    DelVLast(&B, &C);
    printf("Elemen terhapus : %d\n", C);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));

     /* ----- Menghapus Elemen List Setelah Elemen Tertentu ----- */
    printf("\n==MENGHAPUS ELEMEN LIST SETELAH ELEMEN TERTENTU==\n");
    DelVAfter(&B, &C, 3 );
    printf("Elemen terhapus : %d\n", C);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));
}



