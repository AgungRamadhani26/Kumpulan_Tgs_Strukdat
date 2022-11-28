/* Program   : tabel.c*/
/* Deskripsi : realisasi body modul tabel*/
/* NIM/Nama  : 24060120120016-Agung Ramadhani*/
/* Tanggal   : 9 September 2021*/
/***********************************/
#ifndef tabel_C
#define tabel_C
#include <stdio.h>
#include "tabel.h"

/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T){
    //Kamus Lokal
    int i;

    //Algoritma
    (*T).size = 0;
    for(i=1;i<=10;i++){
        (*T).wadah[i] = -999;
    }
}

/*function getNewTable() --> Tabel
	{mengembalikan tabel dengan size=0, setiap elemen wadah=-999} */
Tabel getNewTable (){
    //Kamus Lokal
    int i;
    Tabel T;

    //Algoritma
    T.size = 0;
    for(i=1;i<=10;i++){
        T.wadah[i] = -999;
    }
    return T;
}

/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T){
    //Kamus lokal
    int i;

    //Algoritma
    for(i=1;i<=10;i++){
        printf("%d ", T.wadah[i]);
    }
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T){
    //Kamus Lokal
    int i;

    //Algoritma
    for(i=1;i<=T.size;i++){
        printf("%d ", T.wadah[i]);
    }
}

/* procedure populateTabel( input/output T: Tabel, input N: integer )
{I.S.: T terdefinisi }
{F.S.: T terisi sebanyak N elemen}
{Proses: mengisi elemen wadah T dengan masukan keyboard, sebanyak N kali}
{Syarat: angka-angka masukan keyboard > 0 }*/
void populateTabel (Tabel *T, int N){
    //Kamus lokal
    int i;
    int x;

    //Algoritma
    (*T).size = N;
    for(i=1;i<=(*T).size;i++){
        printf("Masukkan elemen A ke-%d = ", i);
        scanf("%d", &x);
        (*T).wadah[i]=x;
    }
}

/* procedure populateTabelMark( input/output T: Tabel)
{I.S: T terdefinisi }
{F.S: T terisi sejumlah elemen }
{proses: mengisi elemen dengan masukan keyboard berulang hingga masukan bernilai <=0} */
void populateTabelMark (Tabel *T){
    //Kamus lokal
    int i;
    int x;

    //Algoritma
    i=0;
    printf("Masukkan elemen ke-1 = ");
    scanf("%d", &x);
    while(x>0 && i<10){
        i=i+1;
        (*T).wadah[i]=x;
        printf("Masukkan elemen ke-%d = ", i+1);
        scanf("%d", &x);
    }
    (*T).size=i;
}

/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
    //Kamus lokal

    //Algoritma
    return T.size;
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
    //Kamus lokal

    //Algoritma
    return 10-T.size;
}

//PREDIKAT
/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
    //Kamus lokal
    int i;
    boolean empty;

    //Algoritma
    if(T.size==0){
        empty = true;
    }
    else{
        empty = false;
    }
    return empty;

}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
    //Kamus lokal
    int i;
    boolean full;

    //Algoritma
    if(T.size==10){
        full=true;
    }
    else{
        full=false;
    }
    return full;
}

//OPERATOR LAIN
/*procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi pertama ketemu X di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah}*/
void searchX1 (Tabel T, int X, int *Pos){
    //Kamus lokal
    int i;

    //Algoritma
    (*Pos)= -999;
    if(T.size!=0){
        i=1;
        while(T.wadah[i]!=X && i<T.size){
            i++;
        }
        if(T.wadah[i]==X){
            (*Pos)=i;
        }
    }
}

/*procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah}*/
void countX (Tabel T, int X, int *Byk){
    //Kamus lokal
    int i;

    //Algoritma
    (*Byk)=0;
    for(i=1;i<=T.size;i++){
        if(T.wadah[i]==X){
            (*Byk)=(*Byk)+1;
        }
    }
}

/*function getMaxElm ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxElm (Tabel T){
    //Kamus Lokal
    int i;
    int max;

    //Algoritma
    if(T.size!=0){
        max=T.wadah[1];
        for(i=2;i<=T.size;i++){
            if (T.wadah[i]>max){
                max=T.wadah[i];
            }
        }
    }
    else{
        max=-999;
    }
    return max;
}

/*function getMinElm ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil, tapi bukan -999 } */
int getMinElm (Tabel T){
    //Kamus Lokal
    int i;
    int min;

    //Algoritma
    if(T.size!=0){
        min=T.wadah[1];
        for(i=2;i<=10;i++){
            if(T.wadah[i]<min && T.wadah[i]!=-999){
                min=T.wadah[i];
            }
        }
    }
    else{
        min=-999;
    }
    return min;
}

/*procedure addX ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addX (Tabel *T, int X){
    //Kamus lokal
    int i;

    //Algoritma
    if((*T).size<10){
        (*T).size=(*T).size+1;
        (*T).wadah[(*T).size]=X;
    }
}

/*procedure delX ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delX (Tabel *T, int X){
//Kamus Lokal
    int i;

//Algoritma
    if((*T).size!=0){
        i=1;
        while((*T).wadah[i]!=X && i<(*T).size){
            i++;
        }
        if((*T).wadah[i]==X){
            while(i<(*T).size){
                (*T).wadah[i]=(*T).wadah[i+1];
                i++;
            }
            (*T).wadah[i] = -999;
        }
        (*T).size=(*T).size-1;
    }
}

/*procedure delAllX ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllX (Tabel *T, int X){
    //Kamus lokal
    int i;
    int N;

    //Algoritma
   countX(*T,X,&N);
   for(i=1; i<=N; i++){
        delX(T,X);
   }
}

/*procedure updateX ( input/output T:Tabel, input X: integer, input Y: integer )
	{I.S.: T terdefinisi, Y >= 0}
	{F.S.: isi T.wadah bernilai X diganti nilainya dengan Y}
	{Proses: mengganti elemen pertama bernilai X dengan nilai Y }*/
void updateX (Tabel *T, int X, int Y){
    //Kamus lokal
    int poss;

    //Algoritma
    if(Y>=0){
        searchX1(*T, X, &poss);
        (*T).wadah[poss]=Y;
    }
}
#endif
