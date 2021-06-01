/*

Definir se um ponto está dentro ou fora de um intervalo (X, Y)

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>

int main()
{
	int Xi, Yi, Xf, Yf, Xp, Yp;
	int MX, mX, MY, mY;

	scanf("%d %d %d %d %d %d", &Xi, &Yi, &Xf, &Yf, &Xp, &Yp);

	// máximo e mínimo de X
	if (Xf > Xi || Xi == Xf)
	{
		MX = Xf;
		mX = Xi;
	}
	if (Xi > Xf)
	{
		MX = Xi;
		mX = Xf;
	}

	// máximo e mínimo de Y
	if (Yf > Yi || Yi == Yf)
	{
		MY = Yf;
		mY = Yi;
	}
	if (Yi > Yf)
	{
		MY = Yi;
		mY = Yf;
	}

	/*
	_______________Poderia-se usar um operador ternário___________________________________________________

	MY = (Yf > Yi) ?Yf :Yi;

	Onde o MY (máximo de Y) seria Yf, se Yf (Y final) fosse maior que Yi (Y inicial). Se não, MY seria Yi.
	______________________________________________________________________________________________________
	*/


	//------------ definir se DENTRO ou FORA -----------------------
	if (Xp >= mX && Xp <= MX && Yp >= mY && Yp <= MY)
	{
		printf("Dentro");
	}

	else
	{
		printf("Fora");
	}

    return 0;
}