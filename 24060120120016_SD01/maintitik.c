/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060120120016 - Agung Ramadhani*/
/* Tanggal   : 1 September 2021*/
/***********************************/
#include <stdio.h>
#include "titik.h"

int main() {
	//kamus main
	Titik P,Q;

	//algoritma
	//membuat titik dengan nilai komponen absis dan ordinat P dengan 0
	printf("**membuat titik dengan nilai komponen absis dan ordinat P dengan 0**\n");
	makeTitik(&P);
	printf("Absis P = %d\n", getAbsis(P));
	printf("Ordinat P = %d\n", getOrdinat(P));
	printf("------------------------------\n");

	//mengisi nilai komponen absis P dan komponen ordinat P
	printf("**mengisi nilai komponen absis P dan komponen ordinat P**\n");
	setAbsis(&P, 2);
	setOrdinat(&P, 4);
	printf("Absis P = %d\n", getAbsis(P));
	printf("Ordinat P = %d\n", getOrdinat(P));
	printf("------------------------------\n");

    //mengecek apakah titik P merupakan titik origin
    printf("**mengecek apakah titik P merupakan titik origin**\n");
	if(isOrigin(P)){
        printf("Titik P merupakan titik origin\n");
	}
	else{
        printf("Titik P bukan merupakan titik origin\n");
	}
	printf("------------------------------\n");

	//mengubah nilai komponen absis dan ordinat P
	//dengan menggeser titk P sejauh (dx,dy)
	printf("**mengubah nilai komponen absis dan ordinat P dengan menggeser titk P sejauh (dx,dy)**\n");
	geserXY(&P,3,2);
    printf("Titik saat ini berada pada (%d,%d)\n",getAbsis(P),getOrdinat(P));
    printf("------------------------------\n");

    //Mencerminkan titik P dengan sumbu X
    printf("**Mencerminkan titik P dengan sumbuh X**\n");
    refleksiSumbuX(&P);
    printf("Hasil refleksi titik P terhadap sumbu X yaitu (%d,%d)\n",getAbsis(P),getOrdinat(P));
    printf("------------------------------\n");

    //Mencerminkan titik P dengan sumbu Y
    printf("**Mencerminkan titik P dengan sumbuh Y**\n");
    refleksiSumbuY(&P);
    printf("Hasil refleksi titik P terhadap sumbu Y yaitu (%d,%d)\n",getAbsis(P),getOrdinat(P));
    printf("------------------------------\n");

    //Menampilkan kuadran titik P
    printf("**Menampilkan kuadran titik P**\n");
    printf("kuadran titik P = %d\n", Kuadran(P));
    printf("------------------------------\n");

    //Menampilkan jarak euclidian titik P dan Q
    printf("**Menampilkan jarak euclidian titik P dan Q**\n");
    setAbsis(&Q, 1);
    setOrdinat(&Q, 3);
    printf("Jarak antara titik P dan Q = %f\n",Jarak(P,Q));
    printf("------------------------------\n");

	return 0;
}

