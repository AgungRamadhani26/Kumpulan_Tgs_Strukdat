/* Program   : driverlistDoubleLinier.c */
/* Deskripsi : Driver main file modul List Linear */
/* NIM/Nama  : 24060120120016/Agung Ramadhani */
/* Tanggal   : 22 November 2021*/
/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include <stdio.h>
#include <stdlib.h>
#include "listDoubleLinier.h"

int main(){
    /*Kamus Global*/
    List A, B, A1, B1, C1;
    address X,Y,Z,T,L;
    infotype C;
    boolean Simetris;

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
    InsertFirst(&A, X);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));
    printf("Alamat memory elemen 6 = %X\n", X);
    Y = Alokasi(7);
    InsertFirst(&A, Y);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));
    L = Alokasi(1);
    InsertFirst(&A, L);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));
    printf("Alamat memory elemen 1 = %X\n", L);
    printf("Alamat memory prev(7) = %X\n", prev(Y));
    printf("Alamat memory next(7) = %X\n", next(Y));

    /* ----- Mengisi Elemen List Setelah Elemen Tertentu ----- */
    printf("\n===MENGISI ELEMEN LIST SETELAH ELEMEN TERTENTU===\n");
    Z = Alokasi(8);
    InsertAfter(&A,Z,Y);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));
    printf("Alamat memory elemen 7 = %X\n", Y);
    printf("Alamat memory elemen 6 = %X\n", X);
    printf("Alamat memory prev(8) = %X\n", prev(Z));
    printf("Alamat memory next(8) = %X\n", next(Z));

    /* ----- Mengisi Elemen Terakhir List ----- */
    printf("\n==========MENGISI ELEMEN TERAKHIR LIST===========\n");
    T = Alokasi(9);
    InsertLast(&A, T);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));
    printf("Alamat memory elemen 6 = %X\n", X);
    printf("Alamat memory prev(9) = %X\n", prev(T));
    printf("Alamat memory next(9) = %X\n", next(T));

    /*Penghapusan Sebuah Elemen*/
    /* ----- Menghapus Elemen Pertama List ----- */
    printf("\n==========MENGHAPUS ELEMEN PERTAMA LIST==========\n");
    DelFirst(&A, &L);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));
    printf("Alamat memory elemen 8 = %X\n", Z);
    printf("Alamat memory prev(7) = %X\n", prev(Y));
    printf("Alamat memory next(7) = %X\n", next(Y));

    /* ----- Menghapus Elemen Terakhir List ----- */
    printf("\n=========MENGHAPUS ELEMEN TERAKHIR LIST==========\n");
    DelLast(&A, &T);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));
    printf("Alamat memory elemen 8 = %X\n", Z);
    printf("Alamat memory prev(6) = %X\n", prev(X));
    printf("Alamat memory next(6) = %X\n", next(X));

    /* ----- Menghapus Elemen List Setelah Elemen Tertentu ----- */
    printf("\n==MENGHAPUS ELEMEN LIST SETELAH ELEMEN TERTENTU==\n");
    DelAfter(&A, &Z, Y);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));
    printf("Alamat memory elemen 7 = %X\n", Y);
    printf("Alamat memory elemen 6 = %X\n", X);
    printf("Alamat memory prev(7) = %X\n", prev(Y));
    printf("Alamat memory next(7) = %X\n", next(Y));
    printf("Alamat memory prev(6) = %X\n", prev(X));
    printf("Alamat memory next(6) = %X\n\n\n", next(X));




    /* ----- Primitif Berdasarkan Nilai ----- */
    printf("\n/* ----- Primitif Berdasarkan Nilai ----- */");
    /* Penambahan Elemen Berdasarkan Nilai */
    /* ----- Mengisi Elemen Pertama List ----- */
    printf("\n===========MENGISI ELEMEN PERTAMA LIST===========\n");
    InsVFirst(&B, 2);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));
    InsVFirst(&B, 3);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));
    InsVFirst(&B, 9);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));

    /* ----- Mengisi Elemen List Setelah Elemen Tertentu ----- */
    printf("\n===MENGISI ELEMEN LIST SETELAH ELEMEN TERTENTU===\n");
    InsVAfter(&B, 4, 9);
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
    DelVAfter(&B, &C, 4);
    printf("Elemen terhapus : %d\n", C);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));

    /* ----- Kuis List Double Linier ----- */
    printf("\n=======TEST SIMETRIS LIST========\n");
    printf("List A :");
    PrintInfo(A);
    printf("List B :");
    PrintInfo(B);
    if (IsSimetriList(A, B)){
        printf("List A dan List B simetris\n");
    }
    else{
        printf("List A dan List B tidak simetris\n");
    }

    CreateList(&A1);
    CreateList(&B1);
    InsVFirst(&A1, 1);
    InsVFirst(&A1, 2);
    InsVFirst(&A1, 3);
    InsVFirst(&B1, 1);
    InsVFirst(&B1, 2);
    InsVFirst(&B1, 3);
    printf("List A1 :");
    PrintInfo(A1);
    printf("List B1 :");
    PrintInfo(B1);
    if (IsSimetriList(A1, B1)){
        printf("List A1 dan List B1 simetris\n");
    }
    else{
        printf("List A1 dan List B1 tidak simetris\n");
    }

    printf("\n==========INVERS LIST===========\n");
    printf("Isi list A1 sebelum di invers : ");
    PrintInfo(A1);
    InversList(&A1);
    printf("Isi list A1 sesudah di invers : ");
    PrintInfo(A1);

    printf("\n==========KONKAT LIST===========\n");
    printf("Isi list A : ");
    PrintInfo(A);
    printf("Isi list A1 : ");
    PrintInfo(A1);
    Konkat(A, A1, &C1);
    printf("Hasil konkat List A dan List A1 adalah List C1 : ");
    PrintInfo(C1);
}
