/* File : mainList.c */
/* Driver main ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* Nama - NIM : Agung Ramadhani - 24060120120016*/
/* Dibuat pada : 26 Oktober 2021*/

#include <stdio.h>
#include <stdlib.h>
#include "primitifList.h"

int main(){
    /*Kamus Global*/
    List A, B;
    infotype C;
    address X,Y,Z,T;
    address D,Q;

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
    Y = Alokasi(7);
    InsertFirst(&A,Y);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));

    /* ----- Mengisi Elemen List Setelah Elemen Tertentu ----- */
    printf("\n===MENGISI ELEMEN LIST SETELAH ELEMEN TERTENTU===\n");
    Z = Alokasi(8);
    InsertAfter(&A,Z,Y);
    printf("Isi list A  : ");
    PrintInfo(A);
    printf("Panjang list A saat ini : %d\n", NbElmt(A));

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
    DelFirst(&A, &Y);
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
    DelAfter(&A, X, Z);
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
    InsVFirst(&B, 3);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));

    /* ----- Mengisi Elemen List Setelah Elemen Tertentu ----- */
    printf("\n===MENGISI ELEMEN LIST SETELAH ELEMEN TERTENTU===\n");
    InsVAfter(&B, 4, 2);
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
    DelVAfter(&B, &C, 2 );
    printf("Elemen terhapus : %d\n", C);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));

    /* ----- Pencarian Sebuah Elemen List ----- */
    printf("\n\n\n==PENCARIAN SEBUAH ELEMEN LIST==\n");
    InsVFirst(&B, 3);
    InsVFirst(&B, 5);
    InsVFirst(&B, 9);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));

    D = Search(B, 9);
    printf("\naddress : %d\n", D);
    if(FSearch(B, D) == 1){
        printf("Pencarian : ketemu\n");
    }
    else{
        printf("Pencarian : Tidak ketemu\n");
    }
    printf("info : %d\n\n", info(D));

    SearchPrec(B, 5, &Q);
    printf("address = %d\n", Q);
    if(FSearch(B, Q) == 1){
        printf("Pencarian : ketemu\n");
    }
    else{
        printf("Pencarian : Tidak ketemu\n");
    }
    printf("info = %d\n", info(Q));
}
