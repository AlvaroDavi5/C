/*

	Registro de Senhas (EA-6)
	Álvaro davi Santos Alves, Eng Comp, UFES, 2020.1

----------------------------------------------------------------------------------------------

		ALGORITOMO
ler string1, string2, chave

verificar (nessa ordem):
	A) 8 <= strlen(string1) <= 20
	B) 'A' <= string1[i] <= 'Z'
	C) 'a' <= string1[j] <= 'z'
	D) '0' <= string1[n] <= '9'
	E) 'A' > string1[k] > 'Z' E 'a' > string1[k] > 'z' E '0' > string1[k] > '9'
	F) string2 == string1

se não:
	imprimir "ITEM * INVALIDO" (onde * vai de A-F)

se sim:
	salvar senha com Criptografia XOR
	imprimir senha

----------------------------------------------------------------------------------------------

		Criptografia XOR (EXCLUSIVE OR)
Criptografar senha usando operador:
	cripto = caractere ^ chave
		onde caractere == 'C' e chave == 23

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0


void CriptografarSenha(char senha1[], int chave);
int Min_Max_Caracteres(char senha1[]);
int temMaiuscula(char senha1[]);
int temMinuscula(char senha1[]);
int temNumero(char senha1[]);
int temCaractereEspecial(char senha1[]);


int main()
{
	char senha1[40], senha2[40]; // de 0 a 40
	int chave;

	scanf("%[^,], %[^,], %d", senha1, senha2, &chave);

	// ITEM A
	if (Min_Max_Caracteres(senha1))
	{
		// ITEM B
		if (temMaiuscula(senha1))
		{
			// ITEM C
			if (temMinuscula(senha1))
			{
				// ITEM D
				if (temNumero(senha1))
				{
					// ITEM E
					if (temCaractereEspecial(senha1))
					{
						// ITEM F
						if (strcmp(senha1, senha2) == 0)
						{
							// CRIPTOGRAFIA XOR
							CriptografarSenha(senha1, chave);
							printf("%s", senha1);
						}
						else
						{
							printf("ITEM F INVALIDO");
						}
					}
					else
					{
						printf("ITEM E INVALIDO");
						exit(0);
					}
				}
				else
				{
					printf("ITEM D INVALIDO");
					exit(0);
				}
			}
			else
			{
				printf("ITEM C INVALIDO");
				exit(0);
			}
		}
		else
		{
			printf("ITEM B INVALIDO");
			exit(0);
		}
	}
	else
	{
		printf("ITEM A INVALIDO");
		exit(0);
	}

	return 0;
}


void CriptografarSenha(char senha1[], int chave)
{
	for (int i = 0; i < strlen(senha1); i++)
	{
		senha1[i] = senha1[i] ^ chave;
	}
}

int Min_Max_Caracteres(char senha1[])
{
	if (strlen(senha1) >= 8 && strlen(senha1) <= 20)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int temMaiuscula(char senha1[])
{
	int verif = FALSE;

	for (int i = 0; i < strlen(senha1); i++)
	{
		if (senha1[i] >= 'A' && senha1[i] <= 'Z')
		{
			verif = TRUE;
			break;
		}
	}

	return verif;
}

int temMinuscula(char senha1[])
{
	int verif = FALSE;

	for (int i = 0; i < strlen(senha1); i++)
	{
		if (senha1[i] >= 'a' && senha1[i] <= 'z')
		{
			verif = TRUE;
			break;
		}
	}

	return verif;
}

int temNumero(char senha1[])
{
	int verif = FALSE;

	for (int i = 0; i < strlen(senha1); i++)
	{
		if (senha1[i] >= '0' && senha1[i] <= '9')
		{
			verif = TRUE;
			break;
		}
	}

	return verif;
}

int temCaractereEspecial(char senha1[])
{
	int verif = FALSE;

	for (int i = 0; i < strlen(senha1); i++)
	{
		if (senha1[i] == '!' || senha1[i] == '@' || senha1[i] == '#' || senha1[i] == '$' || senha1[i] == '%' || senha1[i] == '&') // ou algo mais problemático como: if ((senha1[i] < '0' && senha1[i] > '9') && (senha1[i] < 'A' && senha1[i] > 'Z') && (senha1[i] < 'a' && senha1[i] > 'z'))
		{
			verif = TRUE;
			break;
		}
	}

	return verif;
}
