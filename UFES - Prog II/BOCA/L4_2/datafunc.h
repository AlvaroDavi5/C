#ifndef DATAFUNC_H

	#define DATAFUNC_H 

	// definição do tipo complexo
	typedef struct
	{
		int dia;
		int mes;
		int ano;
	} tData;

	tData lerData();
	tData defineDMA(int dia, int mes, int ano);
	tData aumentaDMA(tData data);
	int diasDoMes(int mes, int ano);
	int ehBissexto(int ano);
	int ehIgual(tData data, tData dataFim);
	void imprimeData(tData data);

#endif
