/* File : driverListLinier.c */
/* Driver main ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* Nama - NIM : Agung Ramadhani - 24060120120016*/
/* Dibuat pada : 26 Oktober 2021*/

#include <stdio.h>
#include <stdlib.h>
#include "listLinier.h"

int main(){
    /*Kamus Global*/
    List A, B, B_invers, B_copy, B_Fcopy, B_cpalok, BA, B_FcopyBA, R, J;
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


    printf("\n/****************** PROSES SEMUA ELEMEN LIST ******************/");
    printf("\n=======MENGIRIMKAN NILAI RATA-RATA INFO(P)========\n");
    InsVFirst(&B, 3);
    InsVFirst(&B, 5);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Rata - rata = %f\n", Average(B));

    printf("\n/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/\n");
    InsVFirst(&B, 9);
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Panjang list B saat ini : %d\n", NbElmt(B));

    D = Search(B, 9);
    printf("\naddress : %X\n", D);
    if(FSearch(B, D) == 1){
        printf("Pencarian : ketemu\n");
    }
    else{
        printf("Pencarian : Tidak ketemu\n");
    }
    printf("info : %d\n", info(D));
    printf("Alamat sebelum elemen 7 adalah : %X\n", SearchPrec(B,7));

    printf("\n/****************** PROSES TERHADAP LIST ******************/");
    printf("\n=============DELETE SEMUA ELEMEN LIST=============\n");
    DelAll(&B);
    PrintInfo(B);

    printf("\n=MEMBALIK ELEMEN LIST, TANPA MELAKUKAN ALOKASI/DEALOKASI=\n");
    InsVFirst(&B, 1);
    InsVFirst(&B, 2);
    InsVFirst(&B, 3);
    InsVFirst(&B, 4);
    printf("Isi list B  : ");
    PrintInfo(B);
    InversList(&B);
    printf("InversList B : ");
    PrintInfo(B);

    printf("\n====MEMBALIK ELEMEN LIST DENGAN ALOKASI/DEALOKASI====\n");
    printf("Isi list B  : ");
    PrintInfo(B);
    B_invers = FInversList(B);
    printf("FInversList B : ");
    PrintInfo(B_invers);

    printf("\n===LIST B DAN B_copy MENUNJUK KEPADA LIST YANG SAMA==\n");
    printf("Isi list B  : ");
    PrintInfo(B);
    CopyList(&B, &B_copy);
    printf("Isi list B_copy : ");
    PrintInfo(B_copy);

    printf("\n=======MENGIRIMKAN LIST YANG MERUPAKAN SALINAN=======\n");
    printf("Isi list B  : ");
    PrintInfo(B);
    B_Fcopy = FCopyList(B);
    printf("Isi list B_Fcopy : ");
    PrintInfo(B_Fcopy);

    printf("\n====MEMBUAT LIST B_cpalok YANG MERUPAKAN SALINAN B===\n");
    printf("Isi list B  : ");
    PrintInfo(B);
    CpAlokList(B, &B_cpalok);
    printf("Isi list B_cpalok : ");
    PrintInfo(B_cpalok);

    printf("\n==============KONKATENASI DUA BUAH LIST==============\n");
    printf("Isi list B  : ");
    PrintInfo(B);
    printf("Isi list A  : ");
    PrintInfo(A);
    Konkat(B, A, &BA);
    printf("Isi list BA  : ");
    PrintInfo(BA);

    printf("\n===KONKATENASI DUA BUAH LIST KEMUDIAN MENGHAPUS KEDUANYA===\n");
    printf("Isi list B_Fcopy : ");
    PrintInfo(B_Fcopy);
    printf("Isi list BA  : ");
    PrintInfo(BA);
    Konkat1(&B_Fcopy, &BA, &B_FcopyBA);
    printf("Isi list B_FcopyBA : ");
    PrintInfo(B_FcopyBA);
    printf("Isi list B_Fcopy : ");
    PrintInfo(B_Fcopy);
    printf("Isi list BA  : ");
    PrintInfo(BA);

    printf("\n================PECAH LIST================\n");
    PecahList(&J, &R, B_FcopyBA);
    printf("Isi list B_FcopyBA : ");
    PrintInfo(B_FcopyBA);
    printf("Isi list J : ");
    PrintInfo(J);
    printf("Isi list R : ");
    PrintInfo(R);
}

