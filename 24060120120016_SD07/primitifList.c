/* File : primitifList.c */
/* Realisasi body ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* Nama - NIM : Agung Ramadhani - 24060120120016*/
/* Dibuat pada : 26 Oktober 2021*/


#include <stdio.h>
#include <stdlib.h>
#include "primitifList.h"

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
	free(*P);
}

/* ----- Pencarian Sebuah Elemen List ----- */
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan info(P)= X
   Jika ada, mengirimkan address elemen tersebut.
   Jika tidak ada, mengirimkan Nil */

    /*Kamus Lokal*/
    address P;

    /*Algoritma*/
    if(ListEmpty(L)){
        return Nil;
    }
    else{
        P = First(L);
        while(next(P)!=Nil && info(P)!=X){
            P = next(P);
        }
        if(info(P) == X){
            return P;
        }
        else {
            return Nil;
        }
    }
}

boolean FSearch (List L, address P){
/* Mencari apakah ada elemen list yang beralamat P
   Mengirimkan true jika ada, false jika tidak ada */

    /*Kamus Lokal*/
    boolean found;
    address PX;

    /*Algoritma*/
    if(ListEmpty(L)){
        return false;
    }else{
        PX = First(L);
        found = false;
        while(!found && PX != Nil){
            if(PX == P){
                return true;
            }else{
                PX = next(PX);
            }
        }
        return false;
    }
}

void AdrLast(List *L, address *Prec, address *Last){
/*mencari alamat elemen terakhir dan sebelumnya*/

    /*Kamus Lokal*/

    /*Algoritma*/
    (*Last) = First(*L);
    (*Prec) = Nil;
    while(next(*Last) != Nil){
        (*Prec) = (*Last);
        (*Last) = next(*Last);
    }
}

void SearchPrec (List L, infotype X, address *Prec){
/* Mengirimkan address elemen sebelum elemen yang nilainya=X
   Mencari apakah ada elemen list dengan info(P)= X
   Jika ada, mengirimkan address Prec, dengan Next(Prec)=P
   dan Info(P)=X.
   Jika tidak ada, mengirimkan Nil
   Jika P adalah elemen pertama, maka Prec=Nil
   Search dengan spesifikasi seperti ini menghindari
   traversal ulang jika setelah Search akan dilakukan operasi lain */
    /*Kamus Lokal*/
    address P, Q;

    /*Algoritma*/
    Q = Search(L, X);
    *Prec = Nil;

    if(Q != Nil && next(First(L)) != Nil){
        P = First(L);
        while(P != Nil){
            if(next(P) == Q){
                *Prec = P;
                break;
            }else{
                P = next(P);
            }
        }
    }
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P){
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */

    /*Kamus Lokal*/

    /*Algoritma*/
    next(P) = First(*L);
    First(*L) = P;
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
    if (ListEmpty(*L)){
        InsertFirst(&(*L), P);
    }
    else{
        Last = First(*L);
        while (next(Last) != Nil){
            Last = next(Last);
        }
        InsertAfter(&(*L), P, Last);
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
    (*P) = First(*L);
    First(*L) = next(First(*L));

}

void DelLast (List *L, address *P){
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
    // Kamus Lokal
    address Last;
    address PrecLast;

    // Algoritma
    AdrLast(&(*L), &PrecLast, &Last);
    (*P) = Last;
    if (PrecLast == Nil){
        First(*L) = Nil;
    }
    else {
        next(PrecLast) = Nil;
    }
}

void DelAfter (List *L, address * Pdel, address Prec){
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus */

    // Kamus Lokal

    // Algoritma
    (*Pdel) = next(Prec);
    next(Prec) = next(next(Prec));
    next(*Pdel) = Nil;
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

void InsVAfter (List *L, infotype X, infotype Y){
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen setelah Y
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  setelah Prec yaitu
   			  jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */

    /*Kamus Lokal*/
    address P;
    address Prec;

    /*Algoritma*/
    Prec = Search((*L), Y);
    if(Prec != Nil){
        P = Alokasi(X);
        if(P != Nil){
            InsertAfter(&(*L), P, Prec);
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
    (*X) = -999;
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

    // Kamus Lokal
    address P;

    // Algoritma
    (*X) = -999;
    if(!ListEmpty(*L)){
        DelLast(&(*L), &P);
        (*X) = info(P);
        Dealokasi(&P);
    }
}

void DelVAfter (List *L, infotype *X, infotype Y){
/* I.S.		: List L tidak kosong
   F.S.		: Elemen list setelah Y dihapus : nilai info disimpan pada X
   			  dan alamat elemen setelah Y di-dealokasi */
/* Asumsi   : Ketika Y tidak ada dalam list L, Y adalah elemen terakhir atau
              list L kosong; nilai X yang tersimpan menjadi -999 */

    /*Kamus Lokal*/
    address P;
    address Prec;

    /*Algoritma*/
    (*X) = -999;
    if(!ListEmpty(*L)){
        Prec = Search((*L), Y);
        if(Prec != Nil && next(Prec) != Nil){
            DelAfter(&(*L), &P, Prec);
            (*X) = info(P);
            Dealokasi(&P);
        }
    }
}

/* ----- Proses Semua Elemen List ----- */
void PrintInfo (List L){
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
    /*kamus lokal*/
    address P;

    /*algoritma*/
    if(ListEmpty(L)){
        printf("list kosong\n");
    }
    else{
        P = First(L);
        while (P != Nil){
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
    if(ListEmpty(L)){
        Nb = 0;
    }
    else{
        P = First(L);
        while(P != Nil){
            Nb = Nb+1;
            P = next(P);
        }
    }
    return Nb;
}



