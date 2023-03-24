#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main()
{
	// rock,paper & scissor game
	int x, i, r;
	int p1, p2;
	char a[10], b[10], n1[20];
	p1 = 0;
	p2 = 0;
	srand(time(NULL));
	printf("\n\n\t\t\t----ROCK,PAPER & SCISSOR GAME----\n");
	printf("Enter your Name : ");
	scanf("%s", n1);
label:
	printf("Enter 0 for rules, 1 to play and 2 for exit\n");
	scanf("%d", &r);
	if (r == 0)
	{
		printf("\n-------------------------------RULES-------------------------------\n\n\n");
		printf("In this game you have to choose any one of rock,scissor and paper\n");
		printf("And Computer will also choose anyone of them\n");
		printf("following is given which player win according to pairs\n");
		printf("rock-scissor===rock wins\n");
		printf("rock-paper===paper wins\n");
		printf("scissor-paper===scissor wins\n");
		printf("NOTE : rock/paper/scissor all should written in small letters\n");
		printf("three round will be there\nthose with higher points will be a winner\n\n\n\n");
		goto label;
	}
	else if (r == 1)
	{
		for (i = 0; i < 3; i++)
		{
		play:
			printf("\n\n\n\t\t\t\t   Round %d\n", i + 1);
			printf("%s's turn\n", n1);
			scanf("%s", &a);
			x = rand() % 3;
			if (x == 0)
			{
				strcpy(b, "rock");
			}
			if (x == 1)
			{
				strcpy(b, "paper");
			}
			if (x == 2)
			{
				strcpy(b, "scissor");
			}
			printf("You have chosen %s and computer has chosen %s \n", a, b);

			if (!strcmp(a, b))
			{
				printf("draw match \n");
			}
			else if (!strcmp(a, "scissor") && !strcmp(b, "rock"))
			{
				printf("Computer got one point\n");
				p2 += 1;
			}
			else if (!strcmp(a, "scissor") && !strcmp(b, "paper"))
			{
				printf("%s got one point\n", n1);
				p1 += 1;
			}
			else if (!strcmp(a, "rock") && !strcmp(b, "scissor"))
			{
				printf("%s got one point\n", n1);
				p1 += 1;
			}
			else if (!strcmp(a, "rock") && !strcmp(b, "paper"))
			{
				printf("Computer got one point\n");
				p2 += 1;
			}
			else if (!strcmp(a, "paper") && !strcmp(b, "scissor"))
			{
				printf("Computer got one point\n");
				p2 += 1;
			}
			else if (!strcmp(a, "paper") && !strcmp(b, "rock"))
			{
				printf("You got one point\n", n1);
				p1 += 1;
			}
			else
			{
				printf("Invalid Entry!!\nTry Again\n");
				goto play;
			}
			if (i == 2)
			{
				printf("\n\nYou got  %d  points and Computer got  %d  point\n\n", p1, p2);
				if (p1 < p2)
				{
					printf("**You lose**\nTry again later\n");
				}
				if (p1 > p2)
				{
					printf("****You win****\n");
				}
				if (p1 == p2)
				{
					printf("***Draw***\nTry again later\n");
				}
			}
		}
	}
	else if (r == 2)
	{
		printf("\nExiting....\n");
		goto end;
	}
	else
	{
		printf("Invalid Entry!!!\nTry Again...\n");
		goto label;
	}
	printf("\nEnter 0 to play again and 1 for exit\n");
	scanf("%d", &r);
	if (r == 0)
	{
		p1 = 0;
		p2 = 0;
		printf("\nRestarting the game.....\n\n");
		goto label;
	}
	if (r == 1)
	{
		printf("\nExiting....\n");
	}
end:
	return 0;
}
