#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// TODO: Input array
// TODO: Print array
// TODO: Swap min max elem
// TODO: Create new array, which elem is % 3 == 0 or % 5 == 0
// TODO: Sort array (2 variants)




int* input_arr(int* arr, int* f, int* N);
void printf_arr(int* arr, int* N);    
struct Extremum{
    int ind_max;
    int ind_min;
};
struct Extremum find_extremums(int* arr, int* N);
int* custom_arr(int* carr, int* arr, int *N);






int main() {
    
    int N = 20, f = 0;
    int* arr = malloc(20 * sizeof(int));
    srand(time(NULL));

    printf("Would you like to enter array (1) or to generate array (2)? (1 or 2)\n");
    scanf("%d", &f);

    arr = input_arr(arr, &f, &N);       
    printf_arr(arr, &N);

    struct Extremum ext = find_extremums(arr, &N);
    printf("MAx_ind: %d, Min_ind: %d\n", ext.ind_max, ext.ind_min);

    int swap = arr[ext.ind_max];
    arr[ext.ind_max] = arr[ext.ind_min];
    arr[ext.ind_min] = swap;
    printf_arr(arr, &N);


    int* carr = malloc(20 * sizeof(int));
    carr[0] = 0;
    carr = custom_arr(carr, arr, &N);
    if (carr[0] == 0)
        printf("We have not a custon array...\n");
    else 
        printf_arr(carr, &N);





    free(arr);
    return 0;
}




int* input_arr(int* arr, int* f, int* N){

    
    if (*f == 1){
    
        printf("Enter array size (0-20): ");
        scanf("%d", N);
        printf("Cool, now enter your array: ");
        for (int i = 0; i < *N; i ++){
            scanf("%d", &arr[i]); 
        } 

    } else if (*f == 2){
        
        for (int i = 0; i < 20; i ++ ){
            arr[i] = rand() % 100 + 50;
        }

    } else 
        printf("Smth gone wrong, please try again...\n");
       
    return arr;                 
}




void printf_arr(int* arr, int* N) {
    printf("Your array is: ");
    for (int i = 0; i < *N; i ++)
        printf("| %d ", arr[i]);

    printf("\n");
} 



struct Extremum find_extremums(int* arr, int* N){
    struct Extremum ext;

    int max_el = -100000;
    int min_el = 100000;

    for (int i = 0; i < *N; i ++){
        if (arr[i] > max_el) {
            max_el = arr[i];
            ext.ind_max = i;
        } 
        if (arr[i] < min_el) {
            min_el = arr[i];
            ext.ind_min = i;
        }
    }

    return ext;         
}








int* custom_arr(int* carr, int* arr, int *N){
    int cnt_carr_el = 1;
    for (int i = 0; i < *N; i ++){
        if (arr[i] % 3 == 0 || arr[i] % 5 == 0){
            carr[0] = 1;
            carr[cnt_carr_el] = arr[i];
            cnt_carr_el ++;
        }
    }

    return carr;
}















