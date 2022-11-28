/* Program   : mainTabel.c*/
/* Deskripsi : aplikasi driver modul tabel*/
/* NIM/Nama  : 24060120120016-Agung Ramadhani*/
/* Tanggal   : 9 September 2021*/
/***********************************/

#include <stdio.h>
#include "tabel.h"
#include "boolean.h"

int main(){

    //Kamus Global
    Tabel A;
    int Pos;
    int Byk;

    //Algoritma
    //Menginisialisasi A
    createTable(&A);

    //Menampilkan semua elemen A ke layar sebelum diisi dengan printTable
    printf("Menampilkan semua elemen A ke layar sebelum diisi dengan printTable :\n");
    printTable(A);
    printf("\n---------------------------------------------------------------------\n");

    //mengisi elemen wadah A dengan masukan keyboard, sebanyak N kali dengan populateTabel
    printf("\nMengisi elemen wadah A dengan masukan keyboard, sebanyak N kali dengan populateTabel :\n");
    populateTabel(&A,5);
    //menampilkan semua elemen A ke layar setelah diisi dengan printTable
    printf("Menampilkan semua elemen A ke layar setelah diisi dengan printTable :\n");
    printTable(A);
    //menampilkan elemen A yang terisi ke layar dengan viewTable
    printf("\nMenampilkan elemen A yang terisi ke layar dengan viewTable :\n");
    viewTable(A);
    printf("\n---------------------------------------------------------------------\n");

    //mengembalikan tabel A dengan size=0, setiap elemen wadah=-999 dengan getNewTable
    printf("\nMengembalikan tabel A dengan size=0, setiap elemen wadah=-999 dengan getNewTable :\n");
    A=getNewTable();
    printTable(A);
    printf("\n---------------------------------------------------------------------\n");

    //Mengisi elemen A dengan masukan keyboard berulang hingga masukan bernilai <=0 dengan populateTabelMark
    printf("\nMengisi elemen A dengan masukan keyboard berulang hingga masukan bernilai <=0 dengan populateTabelMark :\n");
    populateTabelMark(&A);
    //Menampilkan semua elemen A ke layar setelah diisi dengan printTable
    printf("Menampilkan semua elemen A ke layar setelah diisi dengan printTable :\n");
    printTable(A);
    printf("\n---------------------------------------------------------------------\n");

    //Mengembalikan banyak elemen pengisi A dengan getSize
    printf("\nMengembalikan banyak elemen pengisi T dengan getSize :\n");
    printf("Banyaknya elemen pengisi = %d",getSize(A));
    printf("\n---------------------------------------------------------------------\n");

    //Mengembalikan banyak elemen A yang belum terisi dengan countEmpty
    printf("\nMengembalikan banyak elemen A yang belum terisi dengan countEmpty :\n");
    printf("Jumlah elemen A yang belum terisi = %d", countEmpty(A));
    printf("\n---------------------------------------------------------------------\n");

    //Mengembalikan True jika A kosong dengan isEmptyTable
    printf("\nMengembalikan True jika A kosong dengan isEmptyTable :\n");
    printf("Tabel merupakan tabel kosong = %d", isEmptyTable(A));
    printf("\n---------------------------------------------------------------------\n");

    //Mengembalikan True jika A penuh dengan isFullTable
    printf("\nMengembalikan True jika A penuh dengan isFullTable :\n");
    printf("Tabel merupakan tabel penuh = %d", isFullTable(A));
    printf("\n---------------------------------------------------------------------\n");

    //Mencari posisi elemen bernilai X dalam A.wadah dengan searchX1
    printf("\nMencari posisi elemen bernilai X dalam A.wadah dengan searchX1 :\n");
    searchX1(A,2,&Pos);
    printf ("Elemen  X yang dicari pada posisi = %d", Pos);
    printf("\n---------------------------------------------------------------------\n");

    //Menghitung elemen bernilai X dalam A.wadah dengan countX
    printf("\nMenghitung elemen bernilai X dalam A.wadah dengan countX :\n");
    countX(A,3,&Byk);
    printf("Banyak elemen X pada tabel = %d", Byk);
    printf("\n---------------------------------------------------------------------\n");

    //Mengembalikan nilai elemen terbesar dengan getMaxElm
    printf("\nMengembalikan nilai elemen terbesar dengan getMaxElm :\n");
    printf("Elemen terbesar yaitu = %d", getMaxElm(A));
    printf("\n---------------------------------------------------------------------\n");

    //Mengembalikan nilai elemen terkecil, tapi bukan -999 dengan getMinElm
    printf("\nMengembalikan nilai elemen terkecil, tapi bukan -999 dengan getMinElm :\n");
    printf("Elemen terkecil yaitu = %d",getMinElm(A));
    printf("\n---------------------------------------------------------------------\n");

    //Mengisi elemen A.wadah dengan nilai X menggunakan addX
    printf("\nMengisi elemen A.wadah dengan nilai X menggunakan addX :\n");
    addX(&A,3);
    printf("Tabel setelah diisi X = ");
    printTable(A);
    printf("\n---------------------------------------------------------------------\n");

    //Menghapus 1 elemen bernilai X, geser semua elemen sisa menggunakan delX
    printf("\nMenghapus 1 elemen bernilai X, geser semua elemen sisa menggunakan delX :\n");
    delX(&A,4);
    printf("Tabel setelah menghapus 1 elemen x = ");
    printTable(A);
    printf("\n---------------------------------------------------------------------\n");

    //Menghapus semua elemen bernilai X, geser elemen sisa menggunakan delAllX
    printf("\nMenghapus semua elemen bernilai X, geser elemen sisa menggunakan delAllX :\n");
    delAllX(&A,2);
    printTable(A);
    printf("\n---------------------------------------------------------------------\n");

    //Mengganti elemen pertama bernilai X dengan nilai Y menggunakan updateX
    printf("\nMengganti elemen pertama bernilai X dengan nilai Y menggunakan updateX :\n");
    updateX(&A,7,6);
    printTable(A);
    printf("\n---------------------------------------------------------------------\n");

}
