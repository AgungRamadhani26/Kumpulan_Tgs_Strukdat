#include <stdio.h>
#include "tstack.h"

/* Program   : maintstack.c*/
/* Deskripsi : Aplikasi driver modul stack*/
/* NIM/Nama  : 24060120120016 - Agung Ramadhani*/
/* Tanggal   : 15-September-2021*/
/***********************************/

int main(){
    //Kamus Global
    Tstack A;
    char Y;

    Tstack B;
	char kata [] = {'N','A','B','A','B','A','N'};
	int M;
	int i;
	int N;
	char F;

    //Algoritma
    //menginisialisasi stack A
    createStack(&A);

    //Mengembalikan posisi puncak stack A
    printf("Mengembalikan posisi puncak stack A :\n");
    printf("Top = %d", top(A));
    printf("\n=========================================\n");

    //Mengembalikan True jika A kosong
    printf("Mengembalikan True jika A kosong :\n");
    if(isEmptyStack(A)){
        printf("True, stack kosong");
    }
    else{
        printf("False, stack tidak kosong");
    }
    printf("\n=========================================\n");

    //Mengembalikan True jika T penuh
    printf("Mengembalikan True jika T penuh :\n");
    if(isFullStack(A)){
        printf("True, stack penuh");
    }
    else{
        printf("False, stack tidak penuh");
    }
    printf("\n=========================================\n");

    //Mengisi elemen top baru, bila belum penuh
    printf("Mengisi elemen top baru, bila belum penuh");
    printf("\ndan mengembalikan nilai elemen top stack A :\n");
    push(&A,'S');
    push(&A,'A');
    push(&A,'Y');
    push(&A,'A');
    push(&A,'N');
    push(&A,'G');
    //Mengembalikan nilai elemen top stack A
    printf("Infotop = %c", infotop(A));
    printf("\n=========================================\n");

    //Menampilkan kondisi wadah A ke layar
    printf("Menampilkan kondisi wadah A ke layar :\n");
    printf("prinTstack = ");
    prinTstack(A);
    printf("\n=========================================\n");

    //Menampilkan elemen tak kosong A ke layar
    printf("menampilkan elemen tak kosong A ke layar :\n");
    printf("viewStack = ");
    viewStack(A);
    printf("\n=========================================\n");

    //Mengambil elemen top, bila belum kosong
    printf("Mengambil elemen top, bila belum kosong :\n");
    pop(&A,&Y);
    printf("elemen top yang diambil = %c\n",Y);
    printf("Isi stack sekarang = ");
    prinTstack(A);
    printf("\n=========================================\n");

    //selanjutnya tugas algoritma palindrom dikerjakan di main
    //Algoritma Palindrom
    printf("Algoritma Palindrom :\n");
	printf("STACK KATA = ");
	M = strlen (kata);
	for(i=0; i<M; i++){
 		printf("%c ",kata[i]);
	}
	createStack(&B);
	for (i=0;i<M/2;i++){
		push(&B, kata[i]);
	}
	if (M % 2 == 1){
		i = i + 1;
	}
	printf("\nApakah Stack ini merupakan Palindrom ?");
	while (i<M){
		pop(&B,&F);
		if (F == kata[i] && i < M - 1){
			i++;
		}
		else if(F == kata[i] && i == M - 1){
			printf("\nstack kata ini palindrom :)");
			break;
		}
		else{
			printf("\nstack kata ini bukan palindrom :(");
			break;
		}
	}
	printf("\n=========================================\n");

	//A bertambah 1 elemen atau menjadi kosong bila penuh
    push(&A,'G');
    push(&A,'K');
    push(&A,'A');
    push(&A,'M');
    printf("A bertambah 1 elemen atau menjadi kosong bila penuh :\n");
    printf("Kondisi jika A belum penuh = ");
    pushBabel1(&A,'U');
    prinTstack(A);
    printf("\n");
    printf("Kondisi jika A sudah penuh = ");
    pushBabel1(&A,'E');
    prinTstack(A);
    printf("\n=========================================\n");
return 0;
}


