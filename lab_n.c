#include <stdio.h>

#define fname "laba_txt.txt"

void write_to_f(int *sarr, int size);
void print_file(int *barr, int size);
void add_to_file(int sum);
void change_num(int pos, int nnum);


int main(void){
    int sarr[] = {1, 2, 3, 4, 5};  
    int barr[10];
    int narr[10];
    int s = 0;

    write_to_f(sarr, 5);
    print_file(barr, 5);
    for (int i = 0; i < 5; i ++){
        s += barr[i];
    }
    printf("S = %d\n", s);
    add_to_file(s);
    print_file(narr, 6);    

    change_num(0, 100);
    print_file(narr, 6);

    return 0;
}



void write_to_f(int *sarr, int size){

    FILE *fp = fopen(fname, "wb");
    if (fp == NULL){
        printf("smth gone wrong..\n");
    }

    fwrite(sarr, sizeof(int), size , fp);  

    fclose(fp);
}


void print_file(int *arr, int size){

    FILE *fp = fopen(fname, "rb");
    if (fp == NULL){
        printf("smth gone wrong..\n");
    }

    fread(arr, sizeof(int),  size, fp);


    printf("\n");
    for (int i = 0; i < size; i ++)
        printf("%d, ", arr[i]);
    printf("\n");


    fclose(fp);
}



void add_to_file(int sum){
    FILE *fp = fopen(fname, "ab");
    if (fp == NULL){
        perror("Error opening file for appending in add_to_file");
        return;
    }

    printf("s = %d", sum);
    size_t written_elements = fwrite(&sum, sizeof(int), 1, fp);
    if (written_elements != 1) {
        printf("Error: Could not write the sum to the file. Expected 1, wrote %zu.\n", written_elements);
    }

    fclose(fp);
}








void change_num(int pos, int nnum){
    FILE *fp = fopen(fname, "wb");
    if (fp == NULL){
        perror("Error opening file for appending in add_to_file");
        return;
    }

    long byte_offset = pos * sizeof(int); 
    fseek(fp, byte_offset, SEEK_SET);

    size_t written_elements = fwrite(&nnum, sizeof(int), 1, fp);
    if (written_elements != 1) {
        printf("Error: Could not write the sum to the file. Expected 1, wrote %zu.\n", written_elements);
    }

    fclose(fp);



}



