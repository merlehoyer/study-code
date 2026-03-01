#include <stdio.h>
#include <stdlib.h>

int main(){

    int N[20]; // 0-(n-1) numbers are supposed to be squared plus saved
    
    if(fscanf(stdin , "%d", N)!=1){
        return -1;
    }

    printf("%d\n", *N);
    
    //printf(" rechnungs versuch: %d", *N+2);
    
    int *p_squares = calloc( *N, sizeof(*N) );
    

    for( int i=0; i<*N; i++){
        p_squares[i]= i*i;
        printf("%d ", *(p_squares+i));
    }

    p_squares= realloc(p_squares, (*N)*2*sizeof(*N));

    printf("\n");

    for( int i=0; i<(*N)*2; i++){
        p_squares[i]= i*i;
        printf("%d ", *(p_squares+i));
    }

    free(p_squares);

    return 0;
}