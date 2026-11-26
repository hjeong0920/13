#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int number;
    char title[10];
};

int main(void){
    struct Book *p;

    p = malloc(2*sizeof(struct Book));
    if(p==NULL){
        printf("error\n");
        return 1;
    }
}