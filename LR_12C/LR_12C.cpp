#include <stdio.h>
#define _CRT_SECURE_NO_WARNIGNS
#include <stdlib.h>

void CreateBIN(const char* fname) {
    FILE* fout = fopen(fname, "wb");
    if (fout == NULL) {
        printf("Error: Cannot create file %s\n", fname);
        return;
    }
    
    char ch;
    int num;

    do {
        printf("Enter a number: ");
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, fout);

        printf("Continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    fclose(fout);
}

void PrintBIN(const char* fname) {
    FILE* fin = fopen(fname, "rb");
    if (fin == NULL) {
        printf("Error: Cannot open file %s\n", fname);
        return;
    }

    int num;
    printf("File content (%s):\n", fname);
    while (fread(&num, sizeof(int), 1, fin)) {
        printf("%d ", num);
    }
    printf("\n");

    fclose(fin);
}

void ProcessBIN(const char* fname, const char* gname) {
    FILE* fin = fopen(fname, "rb");
    FILE* fout = fopen(gname, "wb");

    if (fin == NULL) {
        printf("Error: Cannot open input file %s\n", fname);
        return;
    }
    if (fout == NULL) {
        printf("Error: Cannot create output file %s\n", gname);
        fclose(fin);
        return;
    }

    int num, sum = 0;
    while (fread(&num, sizeof(int), 1, fin)) {
        sum += num;
        fwrite(&sum, sizeof(int), 1, fout);
    }

    fclose(fin);
    fclose(fout);
}

int main() {
    char fname[100], gname[100];

    printf("Enter file name 1: ");
    scanf("%s", fname);
    CreateBIN(fname);
    PrintBIN(fname);

    printf("Enter file name 2: ");
    scanf("%s", gname);
    ProcessBIN(fname, gname);

    PrintBIN(gname);

    return 0;
}
