//
//  hangman.c
//  Impiccato
//
//  Created by Giovanni Bassi on 05/04/21.
//

#include "hangman.h"


int getch(void)
{
    int ch;
    struct termios oldt;
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
    newt = oldt; /* copy old settings to new settings */
    newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
    ch = getchar(); /* standard getchar call */
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
    return ch; /*return received char */
}

FILE *openFile() { return fopen("vocabulary.txt","r"); }

bool valid(char c) { return (c >= 'a' && c <= 'z') || (int)c == 27; }

// return the number of the words read in the file
int readFile(char words[N_W][N_C], FILE *file)
{
    int i = 0;
    for(; !feof(file) || i <= N_W; i++)
        fscanf(file,"%s",words[i]);
    return i;
}

int getWord(int n_w)
{
    srand(time(NULL));
    int n = rand() % (n_w - 1) + 1;
    return n;
}

int countCharWord(char *word, char *hidden)
{
    int i;
    for(i = 0; word[i]!='\0'; i++)
        hidden[i] = '_';
    hidden[i] = '\0';
    return i;
}

int insert(char *word, char *hidden, char c)
{
    int i, n;
    for(i = 0, n = 0; word[i]!='\0'; i++){
        //letter == letter of random word
        if(c == word[i] && c != hidden[i])
        {
            hidden[i] = c;
            n++;
        }
    }
    return n;
}

bool win(int letter_right, int letter)
{
    if(letter_right != letter) return false;
    for(int d=0; d < 6; d++)
    {
        printf("You Win!\n");
        if(d%2==0)
        {
            printf("\n\n        O \n");
            printf("       /|\\ \n");
            printf("       / \\ \n");
            printf("--------------\n");
        } else {
            printf("\n       \\O/ \n");
            printf("        |  \n");
            printf("       / \\ \n");
            printf("\n--------------\n");
        }
        usleep(500000);
        system("clear");
    }
    return true;
}

bool lose(int a, char *w)
{
    if(a>0) return false;
    printf("You lose\n\n");
    printf(" ________\n");
    printf("|       O \n");
    printf("|      /|\\ \n");
    printf("|      / \\ \n");
    printf("\n--------------\n");
    printf("\nThe word was %s\n", w);
    sleep(2);
    system("clear");
    return true;
}

void printHangman(int a)
{
    switch(a){
        case 6:
            printf(" ________\n");
            for(int d=0;d<5;d++){
                printf("|\n");
            }
            printf("_________\n\n");
        break;
        case 5:
            printf(" ________\n");
            printf("|       O\n");
            for(int d=0;d<4;d++){
                printf("|\n");
            }
            printf("_________\n\n");
        break;
        case 4:
            printf(" ________\n");
            printf("|       O \n");
            printf("|      / \n");
            for(int d=0;d<3;d++){
                printf("|\n");
            }
            printf("_________\n\n");
        break;
        case 3:
            printf(" ________\n");
            printf("|       O \n");
            printf("|      / \\ \n");
            for(int d=0;d<3;d++){
                printf("|\n");
            }
            printf("_________\n\n");
        break;
        case 2:
            printf(" ________\n");
            printf("|       O \n");
            printf("|      /|\\ \n");
            for(int d=0;d<3;d++){
                printf("|\n");
            }
            printf("_________\n\n");
        break;
        case 1:
            printf(" ________\n");
            printf("|       O \n");
            printf("|      /|\\ \n");
            printf("|      /\n");
            for(int d=0;d<2;d++){
                printf("|\n");
            }
            printf("_________\n\n");
        break;
    }
}

bool letterUsed(char *l_used, char c){
    for(int i = 0; l_used[i]!='\0'; i++)
        if(l_used[i] == c)
        {
            system("clear");
            printf("The %c letter has already been inserted", c);
            getch();
            return true;
        }
    return false;
}
void empty(char *array, int size, char init)
{
    int i = 0;
    for (; i < size; i++) {
        array[i] = init;
    }
    array[i] = '\0';
}
