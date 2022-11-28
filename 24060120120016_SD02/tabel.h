#ifndef tabel_H
#define tabel_H
/* Program   : tabel.h*/
/* Deskripsi : header file modul tabel*/
/* NIM/Nama  : 24060120120016-Agung Ramadhani*/
/* Tanggal   : 9 September 2021*/
/***********************************/
#include <stdio.h>
#include "boolean.h"

/* type Tabel = < wadah : array[1..10] of integer,
                   size : integer > */
/* asumsi1: indeks 0 tidak digunakan */
/* asumsi2: nilai elemen wadah tabel >=0 */
/* asumsi3: bila nilai elemen wadah -999 berarti kosong */
typedef	struct { int wadah[11];
                 int size;
			   } Tabel;

/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T);

/*function getNewTable() --> Tabel
	{mengembalikan tabel dengan size=0, setiap elemen wadah=-999} */
Tabel getNewTable ();

/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T);

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T);

/* procedure populateTabel( input/output T: Tabel, input N: integer )
{I.S.: T terdefinisi }
{F.S.: T terisi sebanyak N elemen}
{Proses: mengisi elemen wadah T dengan masukan keyboard, sebanyak N kali}
{Syarat: angka-angka masukan keyboard > 0 }*/
void populateTabel (Tabel *T, int N);

/* procedure populateTabelMark( input/output T: Tabel)
{I.S: T terdefinisi }
{F.S: T terisi sejumlah elemen }
{proses: mengisi elemen dengan masukan keyboard berulang hingga masukan bernilai <=0} */
void populateTabelMark (Tabel *T);

/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T);

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T);

//PREDIKAT
/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T);

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T);

//OPERATOR LAIN
/*procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi pertama ketemu X di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah}*/
void searchX1 (Tabel T, int X, int *Pos);

/*procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah}*/
void countX (Tabel T, int X, int *Byk);

/*function getMaxElm ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxElm (Tabel T);

/*function getMinElm ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil, tapi bukan -999 } */
int getMinElm (Tabel T);

/*procedure addX ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addX (Tabel *T, int X);

/*procedure delX ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delX (Tabel *T, int X);

/*procedure delAllX ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllX (Tabel *T, int X);

/*procedure updateX ( input/output T:Tabel, input X: integer, input Y: integer )
	{I.S.: T terdefinisi, Y >= 0}
	{F.S.: isi T.wadah bernilai X diganti nilainya dengan Y}
	{Proses: mengganti elemen pertama bernilai X dengan nilai Y }*/
void updateX (Tabel *T, int X, int Y);
#endif


