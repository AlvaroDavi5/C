/*

Criptografia de Textos com Cifra Caesar

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>

char Code(char word, int key);
char Decode(char word, int key);

int main()
{
	int option, key;
	char word;

	scanf("%d ", &option);
	if (option == 1 || option == 2)
	{
		scanf("%d ", &key);

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
					if (key > 0)
					{
						if (word >= 'a' && word <= 'z')
						{
							for (int i = 0; i < key; i++)
							{
								if (word >= 'a' && word <= 'z')
								{
									word++;
								}
								if (! (word >= 'a' && word <= 'z'))
								{
									word = ('a' - 1);
									word++;
								}
							}
						}
					}
					if (key < 0)
					{
						if (word >= 'a' && word <= 'z')
						{
							for (int i = 0; i > key; i--)
							{
								if (word >= 'a' && word <= 'z')
								{
									word--;
								}
								if (! (word >= 'a' && word <= 'z'))
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
				}
				if (option == 2)
				{
					if (key > 0)
					{
						if (word >= 'a' && word <= 'z')
						{
							for (int i = 0; i < key; i++)
							{
								if (word >= 'a' && word <= 'z')
								{
									word--;
								}
								if (! (word >= 'a' && word <= 'z'))
								{
									word = ('z' + 1);
									word--;
								}
							}
						}
					}
					if (key < 0)
					{
						if (word >= 'a' && word <= 'z')
						{
							for (int i = 0; i > key; i--)
							{
								if (word >= 'a' && word <= 'z')
								{
									word++;
								}
								if (! (word >= 'a' && word <= 'z'))
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
