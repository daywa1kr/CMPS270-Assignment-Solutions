#include "my_pointers.h"
/*
    Requires: two arrays of strings and their sizes
    Effects: merges the two arrays into one and returns it
    Assumes: both arrays are sorted
*/
char** merge(char* a[], char* b[], int n1, int n2){
    int i =0, j = 0, k=0;
    char** array = malloc(sizeof(char*) * (n1 + n2));
    if (!array)
        return NULL;
 
    while (i < n1 && j < n2) {
        if (strcmp(a[i], b[j]) <= 0) {
            array[k] = malloc(sizeof(char) * strlen(a[i]) + 1);
            if (!array[k]) {
                free(array);
                return NULL;
            }
            strncpy_s(array[k], sizeof(char) * strlen(a[i]) + 1, a[i], strlen(a[i]));
            i++;
        }
        else {
            array[k] = malloc(sizeof(char) * strlen(b[j]) + 1);
            if (!array[k]) {
                free(array);
                return NULL;
            }
            strncpy_s(array[k], sizeof(char) * strlen(b[j]) + 1, b[j], strlen(b[j]));
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = malloc(sizeof(char) * strlen(a[i]) + 1);
        if (!array[k]) {
            free(array);
            return NULL;
        }
        strncpy_s(array[k], sizeof(char) * strlen(a[i]) + 1, a[i], strlen(a[i]));
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = malloc(sizeof(char) * strlen(b[j]) + 1);
        if (!array[k]) {
            free(array);
            return NULL;
        }
        strncpy_s(array[k], sizeof(char) * strlen(b[j]) + 1, b[j], strlen(b[j]));
        j++;
        k++;
    }
    return array;
}
 
int main_4() {
    char* a[2] = { "ab", "ac" };
    char* b[3] = { "zb", "zc", "zzzzc" };
    char** res = merge(a, b, 2, 3);
    if (!res) {
        printf("ERROR\n");
        return 1;
    }
    else {
        for (int i = 0; i < 5; i++)
            printf("%s\n", res[i]);
    }

    free(res);

    return 0;
}