#include <stdio.h>
#include <stdlib.h>


int main()
{
	FILE *fp = fopen("./arquivo.txt", "a");
	char content[] = "\n \tAdicionando mais \buma linha";

	fprintf(fp, "%s", content);

	fclose(fp);
}

