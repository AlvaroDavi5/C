#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"

#define TRUE 1
#define FALSE 0

struct acc // implementacao da estrutura
{
	Usuario *usuario;
	int agencia; // optei por manter a agência
	int conta;
	float saldo;
	int nMov;
	float transacoes[50];
};


Conta * gerarConta(Usuario *user, int numAcc)
{
	Conta *account = (Conta *) malloc(sizeof(Conta)); // opaque pointer/ponteiro opaco - ponteiro para estrutura opaca (uma estrutura nao declarada ou inicializada no codigo, tornando-a protegida em outro arquivo, portavel entre versoes e tornando o codigo mais rapido e limpo, escondendo a implementacao do cliente)

	account->usuario = user;
	account->agencia = (rand() % 9989) + 10;
	account->conta = (int) numAcc;
	account->saldo = 0.00;
	account->nMov = 0;

	return account;
}

void deletarConta(Conta *account)
{
	if (account != NULL)
	{
		deletarUsuario(account->usuario);

		free(account);
		account = NULL;
	}
}

void operacao(Conta **accounts, int qtdAcc)
{
	int op = 999, numConta1 = 0, numConta2 = 0, qtdMov = 0;
	int cpf = 0, numConta = 0;
	char nome[46] = "";
	float valor = 0.00;
	Usuario *usuario = NULL;
	Conta *conta1 = NULL, *conta2 = NULL;
	FILE *i_arq = fopen("./input/entrada.txt", "r");

	if (i_arq == NULL)
	{
		printf("Erro na abertura: arquivo não encontrado!\n");
		exit(1);
	}

	do
	{
		printf("\nEscolha uma operação (0-sair; 1-saque; 2-deposito; 3-transferência; 4-criar conta; 5-relatorio; 6-extrato): ");
		fscanf(i_arq, "%d", &op);

		switch(op)
		{
			case 0:
				printf("\nSAINDO...\n \n");
				deletarTodasContas(accounts, qtdAcc);
				fclose(i_arq);
				exit(0);
				break;

			case 1:
				printf("\nDigite o número da conta e o valor de saque: ");
				fscanf(i_arq, "%d %f", &numConta1, &valor);
				conta1 = buscarConta(accounts, qtdAcc, numConta1);
				if (conta1)
					sacar(conta1, valor, FALSE);
				else
					printf("\nConta inexistente!\n");
				break;

			case 2:
				printf("\nDigite o número da conta e o valor de deposito: ");
				fscanf(i_arq, "%d %f", &numConta1, &valor);
				conta1 = buscarConta(accounts, qtdAcc, numConta1);
				if (conta1)
					depositar(conta1, valor, FALSE);
				else
					printf("\nConta inexistente!\n");
				break;

			case 3:
				printf("\nDigite o número das contas (origem >> destino) e o valor da transferência: ");
				fscanf(i_arq, "%d %d %f", &numConta1, &numConta2, &valor);
				conta1 = buscarConta(accounts, qtdAcc, numConta1);
				conta2 = buscarConta(accounts, qtdAcc, numConta2);
				if (conta1 && conta2)
					transferir(conta1, conta2, valor);
				else
					printf("\nUma das contas não existe!\n");
				break;

			case 4:
				qtdAcc++;
				accounts = (Conta **) realloc(accounts, qtdAcc * sizeof(Conta *));
				printf("\nDigite NOME e CPF: ");
				fscanf(i_arq, "%s %d %d", nome, &cpf, &numConta);
				usuario = criarUsuario(nome, cpf, numConta);
				accounts[qtdAcc - 1] = gerarConta(usuario, numConta);
				break;

			case 5:
				printf("\n -----------------------  GERANDO RELATORIO ----------------------- \n");
				imprimeRelatorio(accounts, qtdAcc);
				printf("\n");
				break;

			case 6:
				printf("Digite CONTA e N de movimentacoes: ");
				fscanf(i_arq, "%d %d", &numConta1, &qtdMov);
				char path[30] = "./output/", sConta[9] = "";
				snprintf(sConta, 9, "%d", numConta1);
				strcat(path, sConta);
				strcat(path, ".txt");
				FILE *contaF = fopen(path, "w");
				fprintf(contaF, "===| Imprimindo Extrato |===\n");
				infoConta(contaF, buscarConta(accounts, qtdAcc, numConta1), qtdMov, TRUE);
				fclose(contaF);
				break;

			default:
				printf("\nOperação inválida!\n");
				exit(127);
				break;
		}

		numConta1 = 0; numConta2 = 0;
		qtdMov = 0;

	} while (op != 0);

	free(usuario);
	usuario = NULL;
}

void depositar(Conta *account, float valor, int transfer)
{
	printf("\nDEPOSITANDO...\n");
	account->saldo += valor;

	if (transfer || (! transfer))
	{
		account->nMov += 1;
		account->transacoes[account->nMov -1] = valor;
	}
}

int sacar(Conta *account, float valor, int transfer)
{
	if (account->saldo >= valor)
	{
		account->saldo -= valor;
		printf("\nSACANDO/TRANSFERINDO...\n");
		if (transfer || (! transfer))
		{
			account->nMov += 1;
			account->transacoes[account->nMov -1] = -valor;
		}
		return 1;
	}
	else
	{
		printf("\nValor excede o saldo atual!\n");
		return 0;
	}
}

int transferir(Conta *contaOrig, Conta *contaDest, float valor)
{
	if (sacar(contaOrig, valor, TRUE))
	{
		depositar(contaDest, valor, TRUE);
		return 1;
	}
	else
		return 0;
}

Conta * buscarConta(Conta **accounts, int qtdAcc, int nConta)
{
	for (int i = 0; i < qtdAcc; i++)
	{
		if (accounts[i]->conta == nConta)
			return accounts[i];
	}

	return NULL;
}

void infoConta(FILE *file, Conta *account, int transactions, int extract)
{
	fprintf(file, "Conta: %d\n", obterContaUsuario(account->usuario));
	//fprintf(file, "Agência: %d \n", account->agencia);
	fprintf(file, "Saldo: %.2f\n", account->saldo);
	fprintf(file, "Nome: %s\n", obterNomeUsuario(account->usuario));
	fprintf(file, "CPF: %d\n", obterCpfUsuario(account->usuario));

	if (extract)
	{
		fprintf(file, "\nUltimas %d transacoes\n", transactions);
		imprimeTransacoes(file, account, transactions);
	}
}

void imprimeTransacoes(FILE *file, Conta *account, int transactions)
{
	for (int i = 0; i < transactions; i++)
	{
		int index = (account->nMov)-1 - i;
		fprintf(file, "%.2f\n", account->transacoes[index]);
	}
}

void imprimeRelatorio(Conta **contas, int qtdAcc)
{
	FILE *rel = fopen("./output/relatorio.txt", "w");

	fprintf(rel, "===| Imprimindo Relatorio |===\n");

	fclose(rel);

	FILE *o_arq = fopen("./output/relatorio.txt", "a+");

	for (int i = 0; i < qtdAcc; i++)
	{
		infoConta(o_arq, contas[i], 0, FALSE);
		fprintf(o_arq, "\n");
	}

	fclose(o_arq);
}

void deletarTodasContas(Conta **accounts, int qtdAcc)
{
	for (int i = 0; i < qtdAcc; i++)
	{
		deletarConta(accounts[i]);
	}
	free(accounts);
	accounts = NULL;
}

Usuario * obterUsuario(Conta *account)
{
	return account->usuario;
}

int obterAgencia(Conta *account)
{
	return account->agencia;
}

float obterSaldo(Conta *account)
{
	return account->saldo;
}
