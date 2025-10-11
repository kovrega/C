#include <stdio.h>
#include <time.h>
#include <stdlib.h>




int arr[20];
int carr[20];
int input_array(int* arr);
int validate(int* n);
void print_array(int* arr, int* arr_size);
int find_ind_max_el(int* arr, int* arr_size);
int find_ind_min_el(int* arr, int* arr_size);
void swap_min_max_el(int* arr, int* arr_size, int ind_max_el, int ind_min_el);
int create_new_arr(int* arr, int* carr, int* arr_size); 
void sort_arr_asc(int* arr, int* arr_size);
void sort_carr_desc(int* carr, int* carr_size);


int main() {
    srand(time(NULL));
    int arr_size = input_array(arr);
    printf("INPUT:\n");
    print_array(arr, &arr_size); 


    printf("SWAP:\n");
    int ind_max_el = find_ind_max_el(arr, &arr_size);
    int ind_min_el = find_ind_min_el(arr, &arr_size);
    swap_min_max_el(arr, &arr_size, ind_max_el, ind_min_el);
    print_array(arr, &arr_size); 


    printf("CUSTOM_ARRAY:\n");
    int carr_size = create_new_arr(arr, carr,  &arr_size);
    print_array(carr, &carr_size);

    printf("SORT_ARRAY:\n");
    sort_arr_asc(arr, &arr_size);
    print_array(arr, &arr_size);
    
    printf("SORT_CUSTOM_ARRAY:\n");
    sort_carr_desc(carr, &carr_size);
    print_array(carr, &carr_size);

    return 0;
}



int validate(int* N) {
    if (*N > 20 || *N < 1){
        return 0;
    } else {
        return 1;
    } 
}



int input_array(int* arr){
    char f;
    int N = 0;

    printf("Would you like to enter array (y) or to generate array (x)? (y / n)\n");
    scanf("%c", &f);
    
    if (f == 'y'){
    
        printf("Enter array size (0-20): ");
        scanf("%d", &N);
        if (validate(&N) == 1){

            printf("Cool, now enter your array: ");

            for (int i = 0; i < N; i ++)
                scanf("%d", &arr[i]); 
        } else {
            printf("You must enter N strictly in between 0 and 20: N = %d\n", N);
        } 

    } else if (f == 'n'){
        N = 20;

        for (int i = 0; i < 20; i ++ )
            arr[i] = rand() % 100 + 50;

    } else 
        printf("Smth gone wrong, please try again...\n");
     
    return N;
}




void print_array(int* arr, int* arr_size) {
    int f = 0;
    printf("Your array is:\n");
    for (int i = 0; i < *arr_size; i ++){
        if (i == 0)
            printf("| %d ", arr[i]);
        else if (i + 1 == *arr_size)
            printf("| %d |\n", arr[i]); 
        else 
            printf("| %d ", arr[i]);
    }
    

}





int find_ind_max_el(int* arr, int* arr_size){
    int ind_max_el = 0;

    for (int i = 0; i < *arr_size; i ++){
        if (arr[i] > arr[ind_max_el] )
            ind_max_el = i;
    }

    return ind_max_el;
}


int find_ind_min_el(int* arr, int* arr_size){
    int ind_min_el = 0;

    for (int i = 0; i < *arr_size; i ++){
        if (arr[i] < arr[ind_min_el] )
            ind_min_el = i;
    }

    return ind_min_el;
}



void swap_min_max_el(int* arr, int* arr_size, int ind_max_el, int ind_min_el){
    int swap_el = arr[ind_max_el];

    arr[ind_max_el] = arr[ind_min_el];
    arr[ind_min_el] = swap_el;

}




int create_new_arr(int* arr, int* carr, int* arr_size){
    int N = 0;
    for (int i = 0; i < *arr_size; i++){
        if (arr[i] % 3 == 0 || arr[i] % 5 == 0){
            carr[N] = arr[i];
            N ++;
        }
    }

    return N;   
} 




void sort_arr_asc(int* arr, int* arr_size){
   for (int i = 1; i < *arr_size; i++ ){
        int k = i;
        while (k > 0 && arr[k - 1] > arr[k])
        {
            int tmp = arr[k - 1];
            arr[k - 1] = arr[k];
            arr[k] = tmp;
            k --;
        }
    } 

}




void sort_carr_desc(int* carr, int* carr_size){
    for (int i = 1; i < *carr_size; i++ ){
        

        int k = i;
        while (k > 0 &&  carr[k - 1] < carr[k])
        {
            int tmp = carr[k - 1];
            carr[k - 1] = carr[k];
            carr[k] = tmp;
            k --;
        }
    }


}











