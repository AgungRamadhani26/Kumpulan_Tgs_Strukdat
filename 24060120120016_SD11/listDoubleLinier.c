/* Program   : listDoubleLinier.c */
/* Deskripsi : Realisasi body file modul List Linear */
/* NIM/Nama  : 24060120120016/Agung Ramadhani */
/* Tanggal   : 22 November 2021*/
/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#ifndef listDoubleLinier_C
#define listDoubleLinier_C
#include <stdio.h>
#include <stdlib.h>
#include "listDoubleLinier.h"

/*Prototype*/
/* ----- Test List Kosong ----- */
boolean ListEmpty (List L){
/* Mengirim true jika list kosong */

    /*Kamus Lokal*/

    /*Algoritma*/
    return (First(L) == Nil);
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
        prev(P) = Nil;
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
    prev(*P) = Nil;
    next(*P) = Nil;
    (*P) = Nil;
    free(*P);
}

void AdrLast(List L, address *Prec, address *Last){
/*mencari alamat elemen terakhir dan sebelumnya*/

    /*Kamus Lokal*/

    /*Algoritma*/
    if(!ListEmpty(L)){
        (*Last) = First(L);
        (*Prec) = Nil;
        while(next(*Last) != Nil){
            (*Prec) = (*Last);
            (*Last) = next(*Last);
        }
    }
    else{
        *Last = Nil;
        *Prec = Nil;
    }
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P){
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */

    /*Kamus Lokal*/

    /*Algoritma*/
    if (ListEmpty(*L)){
		First(*L) = P;
	}
	else{
		next(P) = First(*L);
		prev(First(*L)) = P;
		First(*L) = P;
		prev(P) = Nil;
	}
}

void InsertAfter (List *L, address P, address Prec){
/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */

    /*Kamus Lokal*/

    /*Algoritma*/
    next(P) = next(Prec);
    prev(next(Prec)) = P;
	next(Prec) = P;
	prev(P) = Prec;
}

void InsertLast (List *L, address P){
/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */

    /*Kamus Lokal*/
    address Last;

    /*Algoritma*/
    if (ListEmpty(*L)){
        InsertFirst(&(*L), P);
    }
    else{
        Last = First(*L);
        while (next(Last) != Nil){
            Last = next(Last);
        }
        next(Last) = P;
        prev(P) = Last;
        next(P) = Nil;
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

    /*Algoritma*/
    if(!ListEmpty(*L)){
        (*P) = First(*L);
        First(*L) = next(First(*L));
        prev(First(*L)) = Nil;
    }
}

void DelLast (List *L, address *P){
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */

    /*Kamus Lokal*/
    address Last;

    /*Algoritma*/
    if(!ListEmpty(*L)){
        Last = First(*L);
        while(next(Last) != Nil){
            Last = next(Last);
        }
        (*P) = Last;
        if(prev(*P) == Nil){ /*List 1 elemen*/
            First(*L) = Nil;
        }
        else{
            Last = prev(*P);
            next(Last) = Nil;
        }
    }
}

void DelAfter (List *L, address * Pdel, address Prec){
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus*/

    /*Kamus Lokal*/

    /*Algoritma*/
    if(!ListEmpty(*L)){
		(*Pdel) = next(Prec);
		next(Prec) = next(next(Prec));
		prev(next(Prec)) = Prec;
		next(*Pdel) = Nil;
		prev(*Pdel) = Nil;
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
    while((next(Prec) != Nil) && (info(Prec) != XPrec)){
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
        AdrLast(*L, &Prec, &Last);
        if (Prec != Nil){
            P = Alokasi(X);
            if (P != Nil){
                InsertAfter(&(*L), P, Prec);
            }
        }
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
    while((next(Prec) != Nil) && (info(Prec) != XPrec)){
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
        AdrLast(*L, &Prec, &Last);
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
        while(P != Nil){
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
    address P;

    /*Algoritma*/
    Nb = 0;
    P = First(L);
    while(P != Nil){
        Nb = Nb+1;
        P = next(P);
    }
    return Nb;
}

void DelAll (List *L){
/* I.S. sembarang
   F.S. Delete semua elemen list dan alamat elemen di-dealokasi
        List L menjadi list kosong*/

    /*Kamus Lokal*/
    address P, Px;

    /*Algoritma*/
    P = First(*L);
    while(P != Nil){
        DelFirst(&(*L), &Px);
        Dealokasi(&Px);
        P = First(*L);
    }
}

/* ----- Kuis List Double Linier ----- */
boolean IsSimetriList (List L1, List L2){
/* Mengirimkan TRUE jika jumlah elemen List L1 dan L2 sama, dan nilai */
/* setiap elemen yang bersesuaian pada List L1 dan L2 sama */

    /*Kamus Lokal*/
    boolean Simetris;
    address PL1;
    address PL2;

    /*Algoritma*/
    if (NbElmt(L1) == NbElmt(L2)){
        Simetris = true;
        PL1 = First(L1);
        PL2 = First(L2);
        while ((PL1 != Nil) && (Simetris == true)){
            if (info(PL1) == info(PL2)){
                PL1 = next(PL1);
                PL2 = next(PL2);
            }
            else{
                Simetris = false;
            }
        }
    }
    else{
        Simetris = false;
    }
    return Simetris;
}

void InversList(List *L){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

    /*Kamus Lokal*/
    address P;
    address cur;
    address prec;

    /*Algoritma*/
    P = First(*L);
    prec = Nil;
    while (P != Nil){
        cur = next(P);
        next(P) = prec;
        prec = P;
        P = cur;
    }
    First(*L) = prec;
}

void Konkat(List L1, List L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi} */
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasiharus}{di-dealokasi dan L3=Nil */
/* Konkatenasi dua buah list: L1 & L2 menghasilkan L3 baru */
/* Elemen L3 adalah hasil alokasi elemen yang baru. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil */
/* dan semua elemen yang pernah dialokasi didealokasi */

    /*Kamus Lokal*/
    boolean gagal;
    address P;
    address Pal;

    /*Algoritma*/
    CreateList(L3);
    gagal = false;
    P = First(L1);
    while ((P != Nil) && (gagal == false)){
        Pal = Alokasi(info(P));
        if (Pal != Nil){
            InsertLast(&(*L3), Pal);
            P = next(P);
        }
        else{
            gagal = true;
            DelAll(&(*L3));
        }
    }
    if (gagal == false){
        P = First(L2);
        while ((P != Nil) && (gagal == false)){
            Pal = Alokasi(info(P));
            if (Pal != Nil){
                InsertLast(&(*L3), Pal);
                P = next(P);
            }
            else{
                gagal = true;
                DelAll(&(*L3));
            }
        }
    }
}

#endif
