/*

	Exercicio Avaliativo
	Alvaro Davi, Eng Comp, 2020.1

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int nulo;
	int branco;
	int dijkstra;
	int turing;
	int shaw;
} tCandPres;

typedef struct
{
	int nulo;
	int branco;
	int tim;
	int torvalds;
	int lovelace;
} tCandMin;


void mostrarVencedorP(tCandPres candidatosP, int votos_validos);
void mostrarVencedorM(tCandMin candidatosM, int votos_validos);
int verifGanhadorP(int dijkstra, int turing, int shaw);
int verifGanhadorM(int tim, int torvalds, int lovelace);
int empatou(int qtd1, int qtd2, int qtd3);
double percentCalcule(int num, int total);
void anulaEleicao();
void imprimeEleValida(tCandPres candidatosP, tCandMin candidatosM, int qtd_eleitores, int votos_validos, int votos_invalidosP, int votos_invalidosM);



int main()
{
	tCandPres candidatosP;
	tCandMin candidatosM;

	int qtd_eleitores, cont = 0;
	int id_eleitor, id_temp, num_pres, num_min;
	int votos_validos = 0, votos_invalidosP = 0, votos_invalidosM = 0;
	int verificador = 0;

	candidatosP.dijkstra = 0, candidatosP.turing = 0, candidatosP.shaw = 0, candidatosP.branco = 0, candidatosP.nulo = 0;
	candidatosM.tim = 0, candidatosM.torvalds = 0, candidatosM.lovelace = 0, candidatosM.branco = 0, candidatosM.nulo = 0;


	scanf("%d", &qtd_eleitores);

	while (scanf("%d %d %d", &id_eleitor, &num_pres, &num_min) == 3)
	{
		cont++;
		if (cont == 1)
		{
			id_temp = id_eleitor;
		}
		if (cont != 1 && (cont > qtd_eleitores || id_temp == id_eleitor))
		{
			anulaEleicao();
		}
	
		if (num_pres == 0 && num_min == 0)
			votos_validos++;

		if (num_pres != 10 && num_pres != 42 && num_pres != 26)
			votos_invalidosP++;
		if (num_min != 36 && num_min != 64 && num_min != 18)
			votos_invalidosM++;

		else
		{
			votos_validos++;
      		if (num_pres == 10)
        		candidatosP.dijkstra++;
      		if (num_pres == 42)
        		candidatosP.turing++;
      		if (num_pres == 26)
        		candidatosP.shaw++;

      		if (num_min == 36)
        		candidatosM.tim++;
      		if (num_min == 64)
        		candidatosM.torvalds++;
      		if (num_min == 18)
        		candidatosM.lovelace++;
		}
	}

	imprimeEleValida(candidatosP, candidatosM, qtd_eleitores, votos_validos, votos_invalidosP, votos_invalidosM);

	return 0;
}



void mostrarVencedorP(tCandPres candidatosP, int votos_validos)
{
	switch (verifGanhadorP(candidatosP.dijkstra, candidatosP.turing, candidatosP.shaw))
	{
	case 10:
		printf("Edsger Dijkstra (Partido do Melhor Caminho (PMC)), %d, %.2f%%\n", candidatosP.dijkstra, percentCalcule(candidatosP.dijkstra, votos_validos));
		break;
	case 42:
		printf("Alan Turing (Partido dos Avanço Intelectual (PAI)), %d, %.2f%%\n", candidatosP.turing, percentCalcule(candidatosP.turing, votos_validos));
		break;
	case 26:
		printf("Carol Shaw (Gamers Unidos (GU)), %d, %.2f%%\n", candidatosP.shaw, percentCalcule(candidatosP.shaw, votos_validos));
		break;
	default:
		break;
	}
}

void mostrarVencedorM(tCandMin candidatosM, int votos_validos)
{
	switch (verifGanhadorM(candidatosM.tim, candidatosM.torvalds, candidatosM.lovelace))
	{
	case 36:
		printf("Tim Berners-Lee (World Wide Web (WWW)), %d, %.2f%%\n", candidatosM.tim, percentCalcule(candidatosM.tim, votos_validos));
		break;
	case 64:
		printf("Linus Torvalds (Linux (Linux)), %d, %.2f%%\n", candidatosM.torvalds, percentCalcule(candidatosM.torvalds, votos_validos));
		break;
	case 18:
		printf("Ada Lovelace (Mulheres Programadoras Unidas (MPU)), %d, %.2f%%\n", candidatosM.lovelace, percentCalcule(candidatosM.lovelace, votos_validos));
		break;
	default:
		break;
	}
}

int verifGanhadorP(int dijkstra, int turing, int shaw)
{
  if (dijkstra > turing && dijkstra > shaw)
    return 10;
  else if (turing > shaw)
    return 42;
  else
    return 26;
}

int verifGanhadorM(int tim, int torvalds, int lovelace)
{
  if (tim > torvalds && tim > lovelace)
    return 36;
  else if (torvalds > lovelace)
    return 64;
  else
    return 18;
}

int empatou(int qtd1, int qtd2, int qtd3)
{
  if (qtd1 == 0 || qtd2 == 0 || qtd3 == 0)
    return 0;
  else if (qtd1 == qtd2 || qtd1 == qtd3)
    return 1;
  else if (qtd2 == qtd3)
    return 1;
  else
    return 0;
}

double percentCalcule(int num, int total)
{
	return (100.0 * num) / total;
}

void anulaEleicao()
{
	printf("ELEICAO ANULADA");
	exit(0);
}

void imprimeEleValida(tCandPres candidatosP, tCandMin candidatosM, int qtd_eleitores, int votos_validos, int votos_invalidosP, int votos_invalidosM)
{
	printf("FIM DA ELEICAO\n");

	if (empatou(candidatosP.dijkstra, candidatosP.turing, candidatosP.shaw))
	{
		printf("- PRESIDENTE ELEITO: ");
		printf("EMPATE\n");
		printf("- PRIMEIRO MINISTRO ELEITO: ");
		mostrarVencedorM(candidatosM, votos_validos);
	}

	else if (votos_validos <= (votos_invalidosP + votos_invalidosM))
	{
		printf("- PRESIDENTE ELEITO: ");
		printf("SEM DECISAO\n");
		printf("- PRIMEIRO MINISTRO ELEITO: ");
		mostrarVencedorM(candidatosM, votos_validos);
	}
	
	else
	{
		printf("- PRESIDENTE ELEITO: ");
		mostrarVencedorP(candidatosP, votos_validos);
		printf("- PRIMEIRO MINISTRO ELEITO: ");
		mostrarVencedorM(candidatosM, votos_validos);
	}

	printf("- COMPARECIMENTO: %.2f%%\n", percentCalcule(votos_validos, qtd_eleitores));
	printf("- NULOS E BRANCOS: %d, %d", votos_invalidosP, votos_invalidosM);
}
