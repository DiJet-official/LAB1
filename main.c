#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

void show_array(double* a , int n) {
     for(int i = 0 ; i < n; i++) {
        printf("%lf" , a[i]);
        printf("\n");
    }
    printf("\n");
}

/////////////////////////////Task2//////////////////////////////////////////////
double max_element(double* a , int n) {
    double max = a[0];

    for (int i = 1; i < n; i++)
        if(max < a[i])
            max = a[i];

    return max;
}

double min_element(double* a , int n) {
    double min = a[0];

    for (int i = 1; i < n; i++)
        if(min > a[i])
            min = a[i];

    return min;
}

double average_value(double* a, int n) {
    double sum = 0;

    for(int i = 0; i < n; i++)
        sum+=a[i];

    double value = sum / n;
    return value;
}

double average_root_value(double* a, int n) {
    double sum = 0;

    for(int i = 0; i < n; i++)
        sum = sum + a[i]*a[i];



    double value = sqrt(sum / n);
    return value;
}

/////////////////////////////Task3//////////////////////////////////////////////
double* first_derivative_array(double* a, int n){
    double *arr;
    arr = (double*)malloc(n*sizeof(double));

    for(int i = 1; i < n - 1; i++){
        arr[i] = (a[i + 1] - a[i - 1])/0.4;
    }

    arr[0] = a[1];
    arr[n - 1] = arr[n - 2];

    return arr;
}

double* second_derivative_array(double* a, int n){
    double *arr;
    arr = (double*)malloc(n*sizeof(double));

    for(int i = 2; i < n - 1; i++){
        arr[i] = (a[i + 2] - 2*a[i] + a[i - 2])/0.16;
    }

    arr[0] = arr[1] = a[2];
    arr[n - 1] = arr[n - 2] = a[n - 3];

    return arr;
}

/////////////////////////////Task4//////////////////////////////////////////////
double* recursive_filter_array(double* a, int n){
    double *arr;
    arr = (double*)malloc(n*sizeof(double));

    arr[0] = a[0];
    arr[1] = a[1];

    for(int i = 2; i < n; i++)
        arr[i] = -0.7192*arr[i - 1] + 0.2645*arr[i - 2] + 0.1363*a[i] + 0.2727*a[i - 1] + 0.1363*a[i - 2];

    return arr;
}

/////////////////////////////Task5//////////////////////////////////////////////

double* local_max(double* a, int n) {
    double* max_arr = (double*)malloc(sizeof(double));
    int size = 1;

    for(int i = 1; i < n - 1; i++)
        if(a[i] > a [i - 1] && a[i] > a[i + 1]) {
            max_arr[size] = a[i];
            max_arr = realloc(max_arr,++size*sizeof(double));
        }


    max_arr = realloc(max_arr,--size*sizeof(double));
    return max_arr;
}

/////////////////////////////Task6//////////////////////////////////////////////
double* points_at_level (double* a, int n , double level) {
    double* delta = (double*)malloc(sizeof(double));
    int size = 1;

    for(int i = 1; i < n; i++)
        if( (a[i] >= level && a[i - 1] <= level) || (a[i] <= level && a[i - 1] >= level) ) {
            delta[size] = 0.1*(i - 1)*level;
            delta = realloc(delta,++size*sizeof(double));
        }

    delta = realloc(delta,--size*sizeof(double));
    return delta;

}

/////////////////////////////Task7//////////////////////////////////////////////
void file_write(double* a , int n, const char* filename) {
    FILE* f = fopen(filename, "w");

    if(f == NULL) printf("Error!\n");

    for(int i = 0; i < n; i++)
        fprintf(f, "%lf\n", *(a + i));

    fclose(f);
}



int main()
{

    //Task1
    int n = 1;
    double *a;
    a = (double*)malloc(sizeof(double));

    FILE *fd;

    fd = fopen("l1v04.txt" , "rt");

    while(!feof(fd)){
        fscanf(fd,"%lf",&a[n-1]);
        a = realloc(a,++n*sizeof(double));
    }

    n--;

    //Task2
    /*
    show_array(a , n);
    printf("\n");
    printf("max: %20le" , max_element(a,n));
    printf("\n");
    printf("min: %20le" , min_element(a,n));
    printf("\n");
    printf("average value: %20le" , average_value(a,n));
    printf("\n");
    printf("average root value: %20le" , average_root_value(a,n));
    printf("\n");
    */

    //Task3

    double* arr1 = first_derivative_array(a,n);
    double* arr2 = second_derivative_array(a,n);
    show_array(arr1,n);
    printf("\n");
    show_array(arr2,n);
    printf("\n");


    //Task4

    double* arr3 = recursive_filter_array(a,n);
    show_array(arr3,n);


    //Task5
    /*
    double* arr4 = local_max(a,n);
    show_array(arr4,sizeof(arr4));
    printf("\n");
    */

    //Task6
    /*
    double* level_array = points_at_level(a,n,0.0001318818);
    show_array(level_array,sizeof(level_array));
    printf("\n");
    */

    //Task7
    file_write(arr1,n,"first_derevative.txt");
    file_write(arr2,n,"second_derevative.txt");
    file_write(arr3,n,"recursive_filter.txt");


    return 0;
}
