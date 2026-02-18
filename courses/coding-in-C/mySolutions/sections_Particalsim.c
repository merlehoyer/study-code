#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    // TODO: complete the output statements
    printf("x = %d\n", x);
    printf("x via p = %d\n", *p);
    printf("x via pp = %d\n", **pp);

  /* char np_argv[]={};
    //char **argv= np_argv;
    
    while()

    fgets(*argv, sizeof(*argv), stdin);
    **(argv+strcspn(*argv,"\n"))='\0';

    argc= strcspn(*argv, "\0");

    printf("%s", *argv);
    

    */

    for (int i =0; i<argc; i++){
        printf("Argument %d at address %x has conntent: %s , length (%d) \n", i, argv+i, *(argv+i), strlen(*(argv+i)));
    }

    return 0;
}