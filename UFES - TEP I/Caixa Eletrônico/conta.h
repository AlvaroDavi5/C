#ifndef _CONTA_H_

	#define _CONTA_H_

	#include "usuario.h"

	typedef struct acc Conta; // estrutura opaca

	Conta * gerarConta(Usuario *user, int numAcc);
	void deletarConta(Conta *account);
	void operacao(Conta **accounts, int qtdAcc);
	void depositar(Conta *account, float valor, int transfer);
	int sacar(Conta *account, float valor, int transfer);
	int transferir(Conta *contaOrig, Conta *contaDest, float valor);
	Conta * buscarConta(Conta **accounts, int qtdAcc, int nConta);
	Usuario * obterUsuario(Conta *account);
	int obterAgencia(Conta *account);
	float obterSaldo(Conta *account);
	void imprimeRelatorio(Conta **contas, int qtdAcc);
	void infoConta(FILE *file, Conta *account, int transactions, int extract);
	void imprimeTransacoes(FILE *file, Conta *account, int transactions);
	void deletarTodasContas(Conta **contas, int qtdAcc);

#endif
