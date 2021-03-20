/*
Title : hybrid-dfa.c
Author : Lee Gyu(Marvin)
Date : 2021/3/20
Description : A short program of DFA in new method (Mix of Table-driven & hardwired)
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

typedef struct arcStruct{
    char state; // state name
    struct arcStruct* link0;    // next state link if symbol == 0
    struct arcStruct* link1;    // next state link if symbol == 1
    char accept;    // Accept if matches start-state
}arc;

// initialize arc
void init_arc(arc* new_arc, char state, arc* link0, arc* link1, char accept){
    new_arc->state = state;
    new_arc->link0 = link0;
    new_arc->link1 = link1;
    new_arc->accept = accept;
}

int main(void){

    // In this program, M = ({p, q, r}, {0, 1}, delta, p, {r})
    
    // I use this array for instance, but will read data from file if followed real plan
    //                                      delta     0    1
    char stateTable[STAT_CNT][SYM_CNT] = {  /*p*/   {'q', 'p'},
                                            /*q*/   {'r', 'p'},
                                            /*r*/   {'r', 'r'}
                                            };
    // acceptance of             p   q    r
    int acceptTable[STAT_CNT] = {NO, NO, YES};   // Acceptance table
    arc p_arc, q_arc, r_arc;    // arcs uesd
    arc state;   // current state
    char start_state = 'p';   // start state = p
    char input[MAX];    // input Ex) 1001
    char target;        // current symbol (character)
    int idx = 0;        // current index
    int nullflag = 0;   // current state null check

    // initialize arcs
    init_arc(&p_arc, 'p', &q_arc, &p_arc, '0');
    init_arc(&q_arc, 'q', &r_arc, &p_arc, '0');
    init_arc(&r_arc, 'r', &r_arc, &r_arc, 'p');

    state = p_arc;  //start state = p

    printf("Insert to check! : ");
    scanf("%s", input);

    // Run until last symbol & not NULL
    while (idx < strlen(input) && !nullflag){
        target = input[idx];
        int symbol = atoi(&target); //current symbol to check(integer)

        // move current state by arc links
        switch(symbol){
            case 0: state = *(state.link0);
                break;
            case 1: state = *(state.link1);
                break;
            default: exit(1);   //error   (Symbol must be 0 or 1)
        }

        // if current NULL, end process
        if(!state.state)
            nullflag = 0;

        idx++;  //next character
    }

    // Check if start_state
    if(state.accept == start_state)
        printf("%s is Available!\n", input);
    else
        printf("%s is NOT Available!\n", input);

    printf("This program was created by 1891073 Lee Gyu.\n");
    
    return 0;
}