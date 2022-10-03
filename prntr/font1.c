#include <string.h>


struct Letter{
    char* line1 = malloc(sizeof("a") * 11);
    char* line2 = malloc(sizeof("a") * 11);
    char* line3 = malloc(sizeof("a") * 11);
    char* line4 = malloc(sizeof("a") * 11);
    char* line5 = malloc(sizeof("a") * 11);
    char* line6 = malloc(sizeof("a") * 11);
}

void printLetter(char* phrase, int totalChars){
    //for letter in phrase
    //print line by line of every letter, eg a.line1 + b.line1 \n a.line2 + b.line2 ect.
    char* line1 = malloc(sizeof('a') * totalChars);
    for(i = 0; i < sizeof(phrase)/sizeof('a'); i++){
        if(phrase[i] == A){
            strcat(line1, A.line1);
        }
    }

    printf(line1);


    //define whole charset
    struct Letter A;
    A.line1 = "     /\\    ";
    A.line2 = "    /  \\   ";
    A.line3 = "   / /\\ \\  ";
    A.line4 = "  / ____ \\ ";
    A.line5 = " /_/    \\_\\";


}

int main(){
    printLetter("AA", 2);
    return 0;
}