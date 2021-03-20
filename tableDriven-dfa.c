/*
Title : tableDriven-dfa.c
Author : Lee Gyu(Marvin)
Date : 2021/3/20
Description : A short program of DFA in tableDriven method
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#define NO 0
#define YES 1
#define STAT_CNT 3    // number of states
#define SYM_CNT 2   // number of symbols

int main(void){

    // In this program, M = ({p, q, r}, {0, 1}, delta, p, {r})
    //                                      delta     0    1
    char stateTable[STAT_CNT][SYM_CNT] = {  /*p*/   {'q', 'p'},
                                            /*q*/   {'r', 'p'},
                                            /*r*/   {'r', 'r'}
                                            };
    // acceptance of             p   q    r
    int acceptTable[STAT_CNT] = {NO, NO, YES};   // Acceptance table
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

        if (symbol != 0 && symbol != 1)
            exit(1);   //error   (Symbol must be 0 or 1)
        else
            state = stateTable[state-'p'][symbol];  // move to next state
        
        idx++;  //next character
    }

    // Check if YES(1)
    if(acceptTable[state-'p'])
        printf("%s is Available!\n", input);
    else
        printf("%s is NOT Available!\n", input);

    printf("This program was created by 1891073 Lee Gyu.\n");
    return 0;
}