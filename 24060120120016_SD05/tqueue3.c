#include <stdio.h>
#include <stdlib.h>
#include "tqueue3.h"

/* Program   : tqueue3.h */
/* Deskripsi : Realisasi body ADT Queue representasi kontigu dengan array,
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060120120016 - Agung Ramadhani*/
/* Tanggal   : 30-September-2021*/
/***********************************/

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    if(Q.tail==0 && Q.head==0){
        return true;
    }
    else{
        return false;
    }
}

/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    if(Q.head == (Q.tail%5)+1){
        return true;
    }
    else{
        return false;
    }
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    if(!isEmptyQueue3(Q)){
		if (Q.head = Q.tail){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='@'}*/
void createQueue3(tqueue3 *Q){
    //Kamus lokal
    int i;

    //Algoritma
    (*Q).head = 0;
    (*Q).tail = 0;
    for(i=1;i<=5;i++){
        (*Q).wadah [i] = '@';
    }
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    return Q.head;
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    return Q.tail;
}

/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    if(!isEmptyQueue3(Q)){
        return Q.wadah[Q.head];
    }
    else{
        return '#'; //kita asumsikan saja kalau kosong
                   //infoHead2 diisi #, biar program gak bocor
    }
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    if(!isEmptyQueue3(Q)){
        return Q.wadah[Q.tail];
    }
    else{
        return '#'; //kita asumsikan saja kalau kosong
                   //infoHead2 diisi #, biar program gak bocor
    }
}

/*function sizeQueue3(Q:tQueue3)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q){
    //Kamus Lokal

    //Algoritma
    if(!isEmptyQueue3(Q)){
        if(Q.head <= Q.tail){
            return Q.tail-Q.head+1;
        }
		else{
			return 5-(Q.head-Q.tail)+1;
        }
    }
	else{
		return 0;
	}
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar}*/
void printQueue3(tqueue3 Q){
    //Kamus Lokal
    int i;

    //Algoritma
    for(i=1;i<=5;i++){
        printf("%c ", Q.wadah[i]);
    }
    printf("\n");
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q){
    //Kamus Lokal
    int i;

    //Algoritma
    if(!isEmptyQueue3(Q)){
        if(Q.head < Q.tail){
            for(i=Q.head;i<=Q.tail;i++){
                printf("%c ", Q.wadah[i]);
            }
        }
        else{
            if(Q.head > Q.tail){
                for(i=Q.head;i<=5;i++){
                    printf("%c ", Q.wadah[i]);
                }
                for(i=1;i<=Q.tail;i++){
                    printf("%c ", Q.wadah[i]);
                }
            }
            else{
                printf("%c ",Q.wadah[Q.head]);
            }
        }
    }
    printf("\n");
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E){
    //Kamus Lokal

    //Algoritma
    if(!isFullQueue3(*Q)){
        if (isEmptyQueue3(*Q)){
            (*Q).head = 1;
            (*Q).tail = 1;
            (*Q).wadah[(*Q).head] = E;
        }
        else{
            (*Q).tail = (((*Q).tail % 5) + 1);
            (*Q).wadah[(*Q).tail] = E;
        }
    }
}

/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E){
    //Kamus Lokal

    //Algoritma
    if(!isEmptyQueue3(*Q)){
        (*E)=(*Q).wadah[(*Q).head];
        (*Q).wadah[(*Q).head]='@';
        if(isOneElement3(*Q)){
            (*Q).head=0;
            (*Q).tail=0;
        }
        else{
            (*Q).head=(*Q).head%5+1;
        }
    }
    else{
        (*E)='@';
    }
}
