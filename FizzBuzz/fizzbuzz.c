#include <stdio.h>
#include <stdlib.h>

//requires input to be an integer
int main(int argc, char *argv[]){
    printf("FizzBuzz from 1 to %s \n",argv[1]);
    int maxNum = atoi(argv[1]);

    //printf("%i\n", maxNum);
    for(int i = 1; i <= maxNum; i++){
        printf("%i - ", i);

        //for my fizzbuzz 2 is fizz, 3 is buzz, 2 & 3 is fizzbuzz

        if(i % 6 == 0){
            printf("FizzBuzz\n");
        }else if(i % 3 == 0){
            printf("Buzz\n");
        }else if(i % 2 == 0){
            printf("Fizz\n");
        }else{
            printf("\n");
        }
        
    }
    return 0;
}