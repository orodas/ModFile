//Oscar Rodas


/* this program modifies a word list according to the user's input.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void prompt();
void lower();
void upper();
int dup();
void caps();

FILE *inPtr;
FILE *outPtr;
int c;

int main(int argc, char *argv[])
{
	//FILE *outPtr2;
	//linecntr = 0;
	if(argc != 3)
	{
		puts("Usage: arg1 arg2");
		exit(1);
	}
	else
	{
		inPtr = fopen(argv[1],"r");
		if(!inPtr)
		{
			perror("File couldnot be opened for reading:");
			exit(1);
		}

		outPtr = fopen(argv[2],"w");
		if(!outPtr)
		{
			perror("File could not be opened for appending:");
			exit(1);
		}
	}
	prompt();
	printf("Wordlist complete. Check the outfile for the results.\n");  
	fclose(inPtr);
	fclose(outPtr);
	return 0;
}
	
void prompt()
{
	int choice = 0;
	while(choice<1 || choice>4)
	{
		puts("Enter an option:\n1.Change the first letter to a capital letter.\n2.Make each word lowercase\n3.Make each word uppercase\n4.Duplicate each word 10 times and display the word with its duplicate # after it.");
		scanf("%d", &choice);
	}
		
	switch(choice)
	{
		case 1:
			caps();
			break;
		case 2:
			lower();
			break;
		case 3:
			upper();
			break;
		case 4:
			dup();
			break;
		default:
			break;
	}
}

void caps()
{
	int count = 0;
	while((c = fgetc(inPtr)) != EOF)
	{
		if(count == 0)
			c=toupper(c);
		putc(c, outPtr);
		count++;
		if(c == '\n')
			count = 0;
	}
	rewind(inPtr);
}

void lower()
{
	while((c = fgetc(inPtr)) != EOF)
	{
		c = tolower(c);
		putc(c, outPtr);
	}
	rewind(inPtr);
}

void upper()
{
	while((c = fgetc(inPtr)) != EOF)
	{
		c = toupper(c);
		putc(c, outPtr);
	}
	rewind(inPtr);
}

int dup()
{
	char line[30]={0};
	int i;
	while(!feof(inPtr))
	{
		while(fscanf(inPtr,"%s", line) == 1)
		{
			fprintf(outPtr, "%s\n", line);
			for(i = 0; i <= 9; i++)
				fprintf(outPtr, "%s%d\n", line, i);
		}
	}
	return 10;
}
