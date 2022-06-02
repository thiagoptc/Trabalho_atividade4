#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

typedef struct nomes {
    char nome[50];
} Nomes;

void calcPrefix(char p[], int lps[]) {
    lps[0] = 0;
    int i = 0, j = 1;
    while (j < strlen(p)) {
        if (p[i] == p[j]) {
            lps[j] = i + 1;
            i++;
            j++;
        } else if (p[i] != p[j] && i != 0) {
            i = lps[i - 1];
        } else if (p[i] != p[j]) {
            lps[j] = 0;
            j++;
        }
    }
}

int kmp(char t[], char p[]) {

    int lps[strlen(p)];
    calcPrefix(p, lps);

    int i = 0, j = 0, k, l = 0;

    while (i <= strlen(t)) {
        int r = i - j;
        k = j;
        for (l = i; j < strlen(p); j++, l++) {
            if (t[l] == p[j]) {
                k++;
            } else {
                break;
            }
        }
        if (k == strlen(p)) {
            return r;
        }
        if (lps[j - 1] == 0) {
            i = l + 1;
        } else {
            i = l;
        }
        j = lps[j - 1];
    }

    return -1;
}

int main () {
    FILE *arq = fopen("nomes.txt", "r");

    Nomes nomes[1000];
    int n = 0; //ler nomes
    int temp;
    char nome[100];

    char temp_nome[50];
    temp = fscanf(arq, "%[^\n]\n", nome);

    while (n < 1000){

            strcpy (nomes[n].nome, nome);

            temp = fscanf(arq, "%[^\n]\n", nome);
            n++;
    }

    printf ("Digite um nome para pesquisar: ");
    scanf ("%s", temp_nome);

    for (int i = 0; i < 1000; i++){
        if (kmp(nomes[i].nome, temp_nome) == -1){

        }else{
            printf ("%s\n", nomes[i].nome);
        }
    }
}
