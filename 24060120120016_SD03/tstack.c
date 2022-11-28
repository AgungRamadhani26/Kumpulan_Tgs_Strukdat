#include <stdio.h>
#include "tstack.h"

/* Program   : tstack.c */
/* Deskripsi : realisasi body modul stack*/
/* NIM/Nama  : 24060120120016 - Agung Ramadhani*/
/* Tanggal   : 15-September-2021*/
/***********************************/

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    //Kamus Lokal
    int i;

    //Algoritma
    (*T).top = 0;
    for(i=1;i<=10;i++){
        (*T).wadah [i] = '#';
    }
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
/*int top (Tstack T){
    //Kamus Lokal

    //Algoritma
    return T.top;
}*/

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
/*char infotop (Tstack T){
    //Kamus Lokal

    //Algoritma
    return T.wadah[T.top];
}*/

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    //Kamus Lokal

    //Algoritma
    if(T.top == 0){
        return true;
    }
    else{
        return false;
    }
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    //Kamus Lokal

    //Algoritma
    if(T.top == 10){
        return true;
    }
    else{
        return false;
    }
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    //Kamus Lokal

    //Algoritma
    if(!isFullStack(*T)){
        (*T).top = (*T).top + 1;
        (*T).wadah[(*T).top] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    //Kamus Lokal

    //Algoritma
    if(isEmptyStack(*T)){
        (*X)='#';
    }else{
        (*X)=(*T).wadah[(*T).top];
        (*T).wadah[(*T).top] = '#';
        (*T).top=(*T).top-1;
    }
}

/*procedure prinTstack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar}
	{setiap elemen dipisah tanda titik koma } */
void prinTstack (Tstack T){
    //Kamus Lokal
    int i;

    //Algoritma
    for(i=1;i<=10;i++){
        printf("%c; ",T.wadah[i]);
    }

}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    //Kamus Lokal
    int i;

    //Algoritma
    for(i=1;i<=T.top;i++){
        printf("%c; ",T.wadah[i]);
    }
}

/* selanjutnya tugas algoritma palindrom dikerjakan di main */

/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */
/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau menjadi kosong bila penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E){
    //Kamus lokal
    int i;

    //algoritma
    if (isFullStack(*T)){
        for(i=1;i<=10;i++){
            (*T).wadah[i]='#';
        }
        (*T).top = 0;
    }
    else{
        (*T).top = (*T).top + 1;
        (*T).wadah[(*T).top] = E;
    }
}
