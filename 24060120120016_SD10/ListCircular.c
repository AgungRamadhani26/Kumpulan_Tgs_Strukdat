/* File : listCircular.c */
/* Realisasi body ADT list Circular dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* Nama - NIM : Agung Ramadhani - 24060120120016*/
/* Dibuat pada : 16 November 2021*/


#include <stdio.h>
#include <stdlib.h>
#include "listCircular.h"

/*Prototype*/
/* ----- Test List Kosong ----- */
boolean ListEmpty (List L){
/* Mengirim true jika list kosong */

    /*Kamus Lokal*/

    /*Algoritma*/
    return(First(L) == Nil);
}

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L){
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */

    /*Kamus Lokal*/

    /*Algoritma*/
    First(*L) = Nil;
}

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = (address)malloc(sizeof(ElmtList));
    if(P != Nil){
        info(P) = X;
        next(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P){
/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */

    /*Kamus Lokal*/

    /*Algoritma*/
    info(*P) = 0;
    next(*P) = Nil;
    (*P) = Nil;
    free(*P);
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P){
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */

    /*Kamus Lokal*/
    address Last;

    /*Algoritma*/
    if(First(*L) == Nil){
        First(*L) = P;
        next(First(*L)) = First(*L);
    }
    else{
        Last = First(*L);
        while(next(Last) != First(*L)){
            Last = next(Last);
        }
        next(P) = First(*L);
		First(*L) = P;
		next(Last) = First(*L);
    }
}

void InsertAfter (List *L, address P, address Prec){
/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */

    /*Kamus Lokal*/

    /*Algoritma*/
    next(P) = next(Prec);
    next(Prec) = P;
}

void InsertLast (List *L, address P){
/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */

    /*Kamus Lokal*/
    address Last;

    /*Algoritma*/
    if(ListEmpty(*L)){
        InsertFirst(&(*L), P);
    }
    else{
        Last = First(*L);
        while(next(Last) != First(*L)){
            Last = next(Last);
        }
        next(P) = next(Last);
        next(Last) = P;
        next(P) = First(*L);
    }
}

/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P){
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */

    /*Kamus Lokal*/
    address Last;

    /*Algoritma*/
    (*P) = First(*L);
    if(next(First(*L)) == First(*L)){ /*List 1 elemen*/
        First(*L) = Nil;
    }
    else{
        Last = First(*L);
        while(next(Last) != First(*L)){
            Last = next(Last);
        }
        First(*L) = next(First(*L));
        next(Last) = First(*L);
    }
}

void DelLast (List *L, address *P){
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */

    /*Kamus Lokal*/
    address PrecLast;
    address Last;

    /*Algoritma*/
    Last = First(*L);
    PrecLast = Nil;
    while(next(Last) != First(*L)){
        PrecLast = Last;
        Last = next(Last);
    }
    (*P) = Last;
    if(PrecLast == Nil){ /*List 1 elemen*/
        First(*L) = Nil;
    }
    else{
        Last = PrecLast;
        next(Last) = First(*L);
    }
}

void DelAfter (List *L, address * Pdel, address Prec){
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus

    /*Kamus Lokal*/

    /*Algoritma*/
    if(!ListEmpty(*L)){
        (*Pdel) = next(Prec);
        next(Prec) = next(next(Prec));
        next(*Pdel) = Nil;
    }
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
void InsVFirst (List *L, infotype X){
/* I.S.		: L mungkin kosong
   F.S. 	: X ditambahkan sebagai elemen pertama L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen
   			  pertama dengan nilai X jika alokasi berhasil.
   			  Jika alokasi gagal, maka I.S.= F.S. */

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = Alokasi(X);
    if(P != Nil){
        InsertFirst(&(*L), P);
    }
}

void InsVLast (List *L, infotype X){
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen terakhir L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  di akhir yaitu
   			  jika alokasi berhasil, elemen terakhir yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    P = Alokasi(X);
    if(P != Nil){
        InsertLast(&(*L), P);
    }
}

void InsVAfter (List *L, infotype X, infotype XPrec){
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen setelah Prec
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  setelah Prec yaitu
   			  jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */

    /*Kamus Lokal*/
    address P;
    address Prec;

    /*Algoritma*/
    Prec = First(*L);
    while((next(Prec) != First(*L)) && (info(Prec) != XPrec)){
        Prec = next(Prec);
    }
    if(info(Prec) == XPrec){
        P = Alokasi(X);
        if(P != Nil){
            InsertAfter(&(*L), P, Prec);
        }
    }
}

void InsVAfter1 (List *L, infotype X){
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen setelah Prec
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  setelah Prec yaitu
   			  jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */

    /*Kamus Lokal*/
    address P, Prec, Last;

    /*Algoritma*/
    if (!ListEmpty(*L)){
        AdrLast(&(*L), &Prec, &Last);
        if (Prec != Nil){
            P = Alokasi(X);
            if (P != Nil) {
                InsertAfter(&(*L), P, Prec);
            }
        }
    }
}

void AdrLast(List *L, address *Prec, address *Last){
/*mencari alamat elemen terakhir dan sebelumnya*/

    /*Kamus Lokal*/

    /*Algoritma*/
    if(!ListEmpty(*L)){
        (*Last) = First(*L);
        (*Prec) = Nil;
        while(next(*Last) != First(*L)){
            (*Prec) = (*Last);
            (*Last) = next(*Last);
        }
    }
    else{
        *Last = Nil;
        *Prec = Nil;
    }
}

/* Penghapusan ELemen */
void DelVFirst (List *L, infotype *X){
/* I.S.		: List L tidak kosong
   F.S.		: Elemen pertama list dihapus den nilai info disimpan pada X
   			 dan alamat elemen pertama di-dealokasi */

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    if(!ListEmpty(*L)){
        DelFirst(&(*L), &P);
        (*X) = info(P);
        Dealokasi(&P);
    }
}

void DelVLast (List *L, infotype *X){
/* I.S.		: List L tidak kosong
   F.S.		: Elemen terakhir list dihapus : nilai info disimpan pada X
   			  dan alamat elemen terakhir di-dealokasi */

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    if(!ListEmpty(*L)){
        DelLast(&(*L), &P);
        (*X) = info(P);
        Dealokasi(&P);
    }
}

void DelVAfter (List *L, infotype *X, infotype XPrec){
/* I.S.		: List L tidak kosong
   F.S.		: Elemen list setelah Prec dihapus : nilai info disimpan pada X
   			  dan alamat elemen setelah Prec di-dealokasi */

    /*Kamus Lokal*/
    address P;
    address Prec;

    /*Algoritma*/
    Prec = First(*L);
    while((next(Prec) != First(*L)) && (info(Prec) != XPrec)){
        Prec = next(Prec);
    }
    if(info(Prec) == XPrec){
        DelAfter(&(*L), &P, Prec);
        (*X) = info(P);
        Dealokasi(&P);
    }
}

void DelVAfter1 (List *L, infotype *X){
/* I.S.		: List L tidak kosong
   F.S.		: Elemen list setelah Prec dihapus : nilai info disimpan pada X
   			  dan alamat elemen setelah Prec di-dealokasi */

    /*Kamus Lokal*/
    address P, Prec, Last;

    /*Algoritma*/
    if (!ListEmpty(*L)){
        AdrLast(&(*L), &Prec, &Last);
        DelAfter(&(*L), &P, Prec);
        (*X) = info(P);
        Dealokasi(&P);
    }
}

/* ----- Proses Semua Elemen List ----- */
void PrintInfo (List L){
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    if(ListEmpty(L)){
        printf("List Kosong\n");
    }
    else{
        P = First(L);
        printf("%d ", info(P));
        P = next(P);
        while(P != First(L)){
            printf("%d ", info(P));
            P = next(P);
        }
        printf("\n");
    }
}

int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

    /*Kamus Lokal*/
    int Nb;
    address A;

    /*Algoritma*/
    Nb = 0;
    A  = First(L);
    while(next(A) != First(L)){
        Nb = Nb + 1;
        A = next(A);
    }
    return (Nb + 1);
}


