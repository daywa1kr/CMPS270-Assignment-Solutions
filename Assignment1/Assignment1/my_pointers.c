#include "my_pointers.h"
#define MAX_STRING 1024
/*
    Requires: two arrays of strings and their sizes
    Effects: merges the two arrays into one and returns it
*/
char** merge(char* a[], char* b[], int n1, int n2){
    int i = 0;
    char** array = malloc(sizeof(char*) * (n1 + n2));
    if (!array)
        return NULL;
    for (int j = 0; j < n1; j++) {
        array[i] = malloc(MAX_STRING + 1);
        if (!array[i]) {
            free(array);
            return NULL;
        }
        strncpy_s(array[i], sizeof(array[i]), a[j], strlen(a[j]));
        i++;
    }
    for (int j = 0; j < n2; j++) {
        array[i] = malloc(sizeof(b[j]));
        if (!array[i]) {
            free(array);
            return NULL;
        }
        strncpy_s(array[i], sizeof(array[i]), b[j], strlen(b[j]));
        i++;
    }
    return array;
}
 
int main_4() {
    char* a[2] = { "ab", "ac" };
    char* b[3] = { "za", "zb", "zzzzc" };
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