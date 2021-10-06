//
//  hangman.h
//  Impiccato
//
//  Created by Giovanni Bassi on 05/04/21.
//

#ifndef hangman_h
#define hangman_h

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <termios.h>
#define N_W 100 // Max number of words
#define N_C 45 // Max number of char

int getch(void);
FILE *openFile(void);
bool valid(char);
int readFile(char [N_W][N_C], FILE*);
int getWord(int);
int countCharWord(char*, char*);
int insert(char*, char *, char);
bool win(int, int );
bool lose(int, char*);
void printHangman(int);
bool letterUsed(char *, char);
void empty(char *, int , char);
bool isUsed(int , int * , int);
#endif /* hangman_h */
