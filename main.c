//
//  main.c
//  Impiccato
//
//  Created by Giovanni Bassi on 04/04/21.
//
#include <stdio.h>
#include <stdlib.h>
#include "hangman.c"

int main(){
    char words[N_W][N_C];
    FILE *f ;
    if((f = openFile()) == NULL)
        exit(EXIT_FAILURE);
    int number_words = 0;
    if((number_words = readFile(words, f)) == 0 )
    {
        printf("Error: the file is empty.");
        exit(2);
    }
    fclose(f);
    printf("Welcome to the hangman game. \nMade by Bassi Giovanni");
    sleep(2);
    system("clear");
    char r, ch ;
    do{
        char hidden[N_C], l_used[26];
        int attempts = 6,  word_sel = getWord(number_words), i, n_l = 0, letter_right = 0;
        empty(l_used, 26, ' ');
        //init hidden word
        for(i = 0; words[word_sel][i]!='\0'; i++)
            hidden[i] = '_';
        hidden[i] = '\0';
        do {
            //game loop
            do {
                printf("\nYou have %d attempts.\n Letter right: %d/ %d\n", attempts, letter_right,i-1);
                printHangman(attempts);
                for(int j = 0; words[word_sel][j] != '\0';j++)
                    printf("%c ",hidden[j]);
                printf("\n\nInsert a letter:\n");
                ch = getch();
                fflush(stdin);
                system("clear");
            } while(!valid(ch));
            if((int)ch == 27) break;
            int v = 0;
            if(( v = insert(words[word_sel], hidden, ch))==0 && !letterUsed(l_used, ch)) attempts--;
            else
                letter_right += v;
            l_used[n_l] = ch;
            n_l++;
            if(win(letter_right , i)) break;
        } while (attempts > 0);
        if(attempts == 0) lose(attempts, words[word_sel]);
        do
        {
            fflush(stdin);
            system("clear");
            printf("You want to play again(y=yes; n=no):");
            scanf("%c", &r);
            system("clear");
            if(r=='y'||r=='n') break;
        } while(r != 'y' || r != 'n');
    } while (r =='y');
    system("clear");
    printf("Thank you for plaing.\n");
    exit(EXIT_SUCCESS);
}
