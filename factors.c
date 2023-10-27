#include <stdio.h>
#include <stdlib.h>

/**
 * factorise - function that factorise a given number
 * @numb: the given number
 */
void factorise(long long int numb)
{
	long int p, q;

	p = 2;
	while (p < numb)
	{
		if (numb % p == 0)
		{
			q = numb / p;
			printf("%lld=%ld*%ld\n", numb, p, q);
			return;
		}
		p++;
	}
}
/**
 * main - the entry point of the program
 * @argc: the number of arguments
 * @argv: the array store arguments
 * Return: 0 if sucess
 */
int main(int argc, char *argv[])
{
	FILE *file;
	int num;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening the file");
		return (1);
	}

	while (fscanf(file, "%d", &num) == 1)
	{
		if (num <= 1)
		{
			fprintf(stderr, "Invalid input: %d should be greater than 1\n", num);
		}
		else
		{
			factorise(num);
		}
	}
	fclose(file);
	return (0);
}
