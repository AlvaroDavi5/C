/*

Criptografia de Textos com Cifra Caesar (Maiusculas e Minusculas, com chave diferente)

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>

char Code(char word, int key);
char Decode(char word, int key);
int inasciiLower(char word);
int inasciiUpper(char word);
char convertWord(char word);

int main()
{
	int option, keyword;
	char word;

	scanf("%d ", &option);
	if (option == 1 || option == 2)
	{
		scanf("%d ", &keyword);

		while (1)
		{
			scanf("%c", &word);

			if (word == '.')
			{
				printf(".");
				break;
			}
			else
			{
				if (option == 1)
				{
					word = Code(word, keyword);
				}
				if (option == 2)
				{
					word = Decode(word, keyword);
				}
				printf("%c", word);
			}
		}
	}
	else
	{
		printf("Operacao invalida.");
	}

	return 0;
}



char Code(char word, int key)
{
	int wordTemp = word;

	if (inasciiUpper(wordTemp))
	{
		key = 2 * key;
		word = convertWord(word); // convert to lower
	}

	if (key > 0)
	{
		if (inasciiLower(word))
		{
			for (int i = 0; i < key; i++)
			{
				if (inasciiLower(word))
				{
					word++;
				}
				if (! inasciiLower(word))
				{
					word = ('a' - 1);
					word++;
				}
			}
		}
	}
	if (key < 0)
	{
		if (inasciiLower(word))
		{
			for (int i = 0; i > key; i--)
			{
				if (inasciiLower(word))
				{
					word--;
				}
				if (! inasciiLower(word))
				{
					word = ('z' + 1);
					word--;
				}
			}
		}
	}
	else /* key == 0 */
	{
		word = word;
	}

	if (inasciiUpper(wordTemp))
	{
		word = convertWord(word); // convert to upper
	}

	return word;
}

char Decode(char word, int key)
{
	int wordTemp = word;

	if (inasciiUpper(wordTemp))
	{
		key = 2 * key;
		word = convertWord(word); // convert to lower
	}

	if (key > 0)
	{
		if (inasciiLower(word))
		{
			for (int i = 0; i < key; i++)
			{
				if (inasciiLower(word))
				{
					word--;
				}
				if (! inasciiLower(word))
				{
					word = ('z' + 1);
					word--;
				}
			}
		}
	}
	if (key < 0)
	{
		if (inasciiLower(word))
		{
			for (int i = 0; i > key; i--)
			{
				if (inasciiLower(word))
				{
					word++;
				}
				if (! inasciiLower(word))
				{
					word = ('a' - 1);
					word++;
				}
			}
		}
	}
	else /* key == 0 */
	{
		word = word;
	}

	if (inasciiUpper(wordTemp))
	{
		word = convertWord(word); // convert to upper
	}

	return word;
}

int inasciiLower(char word)
{
	return (word >= 'a' && word <= 'z');
}

int inasciiUpper(char word)
{
	return (word >= 'A' && word <= 'Z');
}

char convertWord(char word)
{
	if (word >= 'A' && word <= 'Z')
	{
		word -= ('A' - 'a');	/*	word = word - ('A' - 'a') ---> (word - 32)	*/
	}
	else if (word >= 'a' && word <= 'z')
	{
		word += ('A' - 'a');
	}
	else
	{
		word = word;
	}

	return word;
}
