/*
Title : hardwired-dfa.c
Author : Lee Gyu(Marvin)
Date : 2021/3/20
Description : A short program of DFA in hardwired method
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

int main(void){

    // In this program, M = ({p, q, r}, {0, 1}, delta, p, {r})
    char state = 'p';   // start state = p
    char input[MAX];    // input Ex) 1001
    char target;        // current symbol (character)
    int idx = 0;        // current index

    printf("Insert to check! : ");
    scanf("%s", input);

    // Run until last symbol
    while (idx < strlen(input)){
        target = input[idx];
        int symbol = atoi(&target); //current symbol to check(integer)

        switch(state){
            case 'p':                   // current state = p
                if(symbol == 0)         // 0 -> q
                    state = 'q';
                else if(symbol == 1)    // 1 -> p
                    state  = 'p';
                else exit(1);   break;  // else, error

            case 'q':                   // current state = q
                if(symbol == 0)         // 0 -> r
                    state = 'r';
                else if(symbol == 1)    // 1 -> p
                    state  = 'p';
                else exit(1);   break;  // else, error

            case 'r':                   // current state = r
                if(symbol == 0 || symbol == 1)  // 0, 1 -> r
                    state = 'r';
                else exit(1);   break;  // else, error
            default: exit(1);   //else, error   (State must be p,q or r)
        }
        idx++;  //next character
    }

    // Check 
    if(state == 'r')
        printf("%s is Available!\n", input);
    else
        printf("%s is NOT Available!\n", input);

    printf("This program was created by 1891073 Lee Gyu.\n");
    return 0;
}