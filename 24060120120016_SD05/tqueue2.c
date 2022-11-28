#include <stdio.h>
#include <stdlib.h>
#include "tqueue2.h"

/* Program   : tqueue2.c*/
/* Deskripsi : Realisasi body ADT Queue representasi kontigu dengan array,
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060120120016 - Agung Ramadhani*/
/* Tanggal   : 30-September-2021*/
/***********************************/

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    if(Q.tail==0 && Q.head==0){
        return true;
    }
    else{
        return false;
    }
}

/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    if(Q.tail==5 && Q.head==1){
        return true;
    }
    else{
        return false;
    }
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    if(!isEmptyQueue2(Q)){
        return (Q).head == (Q).tail;
    }
    else{
        return false;
    }
}

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='@'}*/
void createQueue2(tqueue2 *Q){
    //Kamus lokal
    int i;

    //Algoritma
    (*Q).head = 0;
    (*Q).tail = 0;
    for(i=1;i<=5;i++){
        (*Q).wadah [i] = '@';
    }
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    return Q.tail;
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan}
Asumsi : bila Q kosong, Q.wadah = #*/
char infoHead2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    if(!isEmptyQueue2(Q)){
        return Q.wadah[Q.head];
    }
    else{
        return '#'; //kita asumsikan saja kalau kosong
                   //infoHead2 diisi #, biar program gak bocor
    }
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    if(!isEmptyQueue2(Q)){
        return Q.wadah[Q.tail];
    }
    else{
        return '#'; //kita asumsikan saja kalau kosong
                   //infoHead2 diisi #, biar program gak bocor
    }
}

/*function sizeQueue2(Q:tQueue2)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
     //Algoritma
    if(!isEmptyQueue2(Q)){
        return Q.tail-Q.head+1;
    }
    else{
        return 0;
    }
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q){
    //Kamus Lokal
    int i;

    //Algoritma
    for(i=1;i<=5;i++){
        printf("%c ", Q.wadah[i]);
    }
    printf("\n");
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q){
    //Kamus Lokal
    int i;

    //Algoritma
    if(! isEmptyQueue2(Q)){
        for(i=Q.head;i<=Q.tail;i++){
            printf("%c ", Q.wadah[i]);
        }
        printf("\n");
    }
}

/*Function IsTailStop2(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop2(tqueue2 Q){
    //Kamus Lokal

    //Algoritma
    if(Q.head>1 && Q.tail==5){
        return true;
    }
    else{
        return false;
    }
}

/*Procedure ResetHead2(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead2(tqueue2 *Q){
    //Kamus Lokal
    int i;
    int Temp;

    //Algoritma
    if(!isEmptyQueue2(*Q)){
        Temp = 0;
		for(i=(*Q).head;i<=(*Q).tail;i++){
			Temp = Temp + 1;
			(*Q).wadah[Temp] = (*Q).wadah[i];
			(*Q).wadah[i] = '@';
		}
		(*Q).head = 1;
		(*Q).tail = Temp;
	}
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E){
    //Kamus Lokal

    //Algoritma
    if(!isFullQueue2(*Q)){
        if(isEmptyQueue2(*Q)){
            (*Q).head=1;
        }
        else{
            if(isTailStop2(*Q)){
                resetHead2(&(*Q));
            }
        }
        (*Q).tail=(*Q).tail+1;
        (*Q).wadah[(*Q).tail]=E;
    }
}

/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E){
    //Kamus Lokal

    //Algoritma
    if(!isEmptyQueue2(*Q)){
        (*E)=infoHead2(*Q);
        (*Q).wadah[(*Q).head]='@';
        if(isOneElement2(*Q)){
            (*Q).head=0;
            (*Q).tail=0;
        }
        else{
            (*Q).head=(*Q).head+1;
        }
    }
    else{
        (*E)='@';
    }
}

