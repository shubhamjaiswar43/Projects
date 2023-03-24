#include <stdio.h>//8+9=17
int main()//3+6=9
{
    int letters = 0, words = 0, lines = 0;
    char count;
    FILE *fptr = NULL;
    fptr = fopen("NoOfWordsInCurrentFile.c", "r");
    while (1)
    {
        fscanf(fptr, "%c", &count);
        if (feof(fptr))
            break;
        printf("%c", count);
        if (count != ' ' || count != '\n')
            letters++;
        if (count == ' ' || count == '\n')
            words++;
        if (count == '\n')
            lines++;
    }
    lines++;
    printf("\nLetters : %d(!space), Words : %d(error>>>This is because it is code file but it will work in normal paragraph), Lines : %d(accuracy>>>)", letters, words, lines);
    fclose(fptr);
    // fptr = fopen("NoOfWordsInCurrentFile.c", "a");
    // for(int i=0;i<200;i++)
    // fprintf(fptr,"\n//Hello World");
    // fclose(fptr);
    
    return 0;
}