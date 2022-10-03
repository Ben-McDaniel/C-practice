#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("You must enter a string.\n");
        return -1;
    }

    //get total length of string including spaces
    int totalChars = argc - 2;
    for(int i = 1; i < argc; i++){
        totalChars += strlen(argv[i]);
    }
    printf("%i\n",totalChars);


    //concatonates multi-word strings
    char* inputString = malloc(sizeof('a') * totalChars + 8);
    for(int i = 1; i < argc; i++){
        strcat(inputString, argv[i]);
        
        if(i == argc - 1){
            strcat(inputString, "\0");
        }else{
            strcat(inputString, " ");
        }
    }







    free(inputString);
    return -1;
}