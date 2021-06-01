#ifndef LEAPYEARFUCN_H

	#define DATAFUNC_H 

	typedef struct
	{
		int dia;
		int mes;
		int ano;
	} tData;

	tData lerData();
	tData defineDMA(int dia, int mes, int ano);
	int ehBissexto(int ano);
	void imprimeData(tData data);

#endif
