/* File : listLinier.c */
/* Realisasi body ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* Nama - NIM : Agung Ramadhani - 24060120120016*/
/* Dibuat pada : 26 Oktober 2021*/


#include <stdio.h>
#include <stdlib.h>
#include "listLinier.h"

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

void AdrLast(List *L, address *Prec, address *Last){
/*mencari alamat elemen terakhir dan sebelumnya*/

    /*Kamus Lokal*/

    /*Algoritma*/
    if(!ListEmpty(*L)){
        (*Last) = First(*L);
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

/****************** PROSES SEMUA ELEMEN LIST ******************/

void PrintInfo (List L){
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
    /*kamus lokal*/
    address P;

    /*algoritma*/
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

float Average (List L){
/* Mengirimkan nilai rata-rata info(P) */

    /*Kamus Lokal*/
    address P;
    float Sum;

    /*Algoritma*/
    if(ListEmpty(L)){
        return 0;
    }
    else{
        P = First(L);
        Sum = info(P);
        while(next(P) != Nil){
            Sum = Sum + info(next(P));
            P = next(P);
        }
        return (Sum / NbElmt(L));
    }
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
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
        found = false;
    }else{
        PX = First(L);
        found = false;
        while(!found && PX != Nil){
            if(PX == P){
                found = true;
            }
            else{
                PX = next(PX);
            }
        }
    }
    return found;
}

address SearchPrec (List L, infotype X){
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/

    /*Kamus Lokal*/
    address P, Prec;

    /*Algoritma*/
    Prec = Nil;
    if(!ListEmpty(L)){
        P = First(L);
        while(P != Nil){
            if(X == info(P)){
                return Prec;
            }
            else{
                Prec = P;
                P = next(P);
            }
        }
    }
    return Prec;
}

/****************** PROSES TERHADAP LIST ******************/

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

void InversList (List *L){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

    /*Kamus Lokal*/
    address cur, prev, temp;

    /*Algoritma*/
    prev = Nil;
    cur = First(*L);
    while(cur != Nil){
        temp = next(cur);
        next(cur) = prev;
        prev = cur;
        cur = temp;
    }
    First(*L) = prev;
}

List FInversList (List L){
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

    /*Kamus Lokal*/
    List Ln;
    address P, Pn;
    boolean gagal;

    /*Algoritma*/
    CreateList(&Ln);
    P = First(L);
    gagal = false;
    while((P != Nil) && (!gagal)){
        Pn = Alokasi(info(P));
        if(Pn != Nil){
            InsertFirst(&Ln, Pn);
            P = next(P);
        }
        /*Jika alokasi gagal*/
        else {
            DelAll(&Ln);
            gagal = true;
        }
    }
    return Ln;
}

void CopyList (List *L1, List *L2){
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

    /*Kamus Lokal*/

    /*Algoritma*/
    First(*L2) = First(*L1);
}

List FCopyList (List L ){
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */

    /*Kamus Lokal*/
    List Lc;
    address P, Pc;
    boolean gagal;

    /*Algoritma*/
    CreateList(&Lc);
    P = First(L);
    gagal = false;
    while((P!=Nil) && (!gagal)){
        Pc = Alokasi(info(P));
        if(Pc != Nil){
            InsertLast(&Lc, Pc);
            P = next(P);
        }
        else {
            DelAll(&Lc);
            gagal = true;
        }
    }
    return Lc;
}

void CpAlokList (List Lin, List *Lout){
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur
dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */

    /*Kamus Lokal*/

    /*Algoritma*/
    (*Lout) = FCopyList(Lin);
}

void Konkat (List L1, List L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang baru */
/* Elemen L3 adalah hasil alokasi elemen yang baru. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */

    /*Kamus Lokal*/
    address Last3, Prec3;
    List LTemp;

    /*Algoritma*/
    if (First(L1) == Nil) {
        CpAlokList(L2, &(*L3));
    }
    else {
        CpAlokList(L1, &(*L3)); // Mengalokasi L3 dengan elemen dari L1
        AdrLast(&(*L3), &Prec3, &Last3); // Mencari Last dari List L3
        CpAlokList(L2, &LTemp); // Mengalokasi LTemp dengan elemen dari L1
        next(Last3) = First(LTemp);
    }

}

void Konkat1 (List *L1, List *L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2 */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

    /*Kamus Lokal*/
    address Prec3, Last3;

	/*Algoritma*/
	if(First(*L1) == Nil){
        First(*L3) = First(*L2);
    }
    else{
        First(*L3) = First(*L1);
        AdrLast(&(*L3), &Prec3, &Last3);
        next(Last3) = First(*L2);
    }
    First(*L1) = Nil;
    First(*L2) = Nil;
}

void PecahList (List *L1, List *L2, List L){
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */

// Kamus Lokal
    address P, Pn;
    int count, N;
    boolean gagal;

    // Algoritma
    CreateList(&(*L1));
    CreateList(&(*L2));
    N = NbElmt(L)/2;
    count = 1;
    P = First(L);
    gagal = false;
    while(P != Nil && !gagal) {
        if(count <= N) {
            if(Pn != Nil){
                InsVLast(&(*L1), info(P));
                P = next(P);
                count = count + 1;
            }
            else {
                DelAll(&(*L1));
                gagal = true;
            }
        }
        else {
            if (Pn != Nil){
                InsVLast(&(*L2), info(P));
                P = next(P);
                count = count + 1;
            }
            else {
                DelAll(&(*L1));
                DelAll(&(*L2));
                gagal = true;
            }
        }
    }
}


