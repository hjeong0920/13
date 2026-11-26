#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int number;
    char title[10];
};

int main(void){
    int i;
    struct Book **bookshelf;

    bookshelf = malloc(3*sizeof(struct Book));
    if (bookshelf == NULL){
        printf("error\n");
        return 1;
        }

    for(i=0;i<3;i++){
        bookshelf[i]= malloc(10*sizeof(struct Book));
        if (bookshelf[i]==NULL){
            for (int j=0;j<1;j++){
                free(bookshelf[j]);
            }
            free(bookshelf);
            printf("error\n");
            return 1;
        }
    }

    bookshelf[1][3].number = 5;
    strcpy(bookshelf[1][3].title, "C++ Programming");

    (bookshelf[2]+4)->number = 3;
    strcpy((bookshelf[2]+4)->title, "Communications Theory");

    printf("book (1,3) : %i, %s\n", (bookshelf[1]+3)->number, (bookshelf[1]+3)->title);
    printf("book(2,4): %i, %s\n", bookshelf[2][4].number, bookshelf[2][4].title);

    for(i=0;i<3;i++){
        free(bookshelf[i]);
    }
    free(bookshelf);

    return 0;
}


