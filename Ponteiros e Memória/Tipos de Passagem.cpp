// incluindo bibliotecas
#include <iostream>


// declarando escopos
using namespace std;


// funcoes de passagem
void porValor(int num)
{
	num = 11;
	cout << "Numero na funcao: " << num << endl;
}

void porValorConstante(const int num)
{
	// num = 22; // erro: num nao e modificavel
	cout << "Numero na funcao: " << num << endl;
}

void porNome(int *pNum)
{
	*pNum = 33;
	cout << "Numero na funcao: " << *pNum << endl;
	pNum = NULL;
	cout << "Ponteiro na funcao: " << pNum << endl;
}

void porReferencia(int &aNum)
{
	aNum = 44;
	cout << "Numero na funcao: " << aNum << endl;
	cout << "Endereco na funcao: " << &aNum << endl;
}


int main()
{
	int numero = 55;
	int *pNumero = &numero;

	cout << "Numero fora da funcao: " << numero << endl;
	porValor(numero);
	cout << "Numero fora da funcao: " << numero << endl << endl;

	cout << "Numero fora da funcao: " << numero << endl;
	porValorConstante(numero);
	cout << "Numero fora da funcao: " << numero << endl << endl;

	cout << "Numero fora da funcao: " << numero << endl;
	cout << "Ponteiro fora da funcao: " << pNumero << endl;
	porNome(&numero);
	cout << "Numero fora da funcao: " << numero << endl;
	cout << "Ponteiro fora da funcao: " << pNumero << endl << endl;

	cout << "Numero fora da funcao: " << numero << endl;
	cout << "Endereco fora da funcao: " << &numero << endl;
	porReferencia(numero);
	cout << "Numero fora da funcao: " << numero << endl;
	cout << "Endereco fora da funcao: " << &numero << endl;

	return 0;
}

