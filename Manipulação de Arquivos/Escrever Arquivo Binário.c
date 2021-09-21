#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int age;
	char *name;
	long int regist;
	char *address;
} Person;


int main()
{
	FILE *fp = fopen("./arquivo.bin", "w+b");

	Person ps;
	ps.age = 18;
	ps.name = strdup("Gandalf,Mithrandir,Olorin,the_White");
	ps.address = strdup("Taniquetil,Valinor");
	ps.regist = 10123;

	fwrite(&ps, sizeof(Person), 1, fp);
	fwrite(ps.name, sizeof(char *), 1, fp);
	fwrite(ps.address, sizeof(char *), 1, fp);
	fwrite(&(ps.age), sizeof(int), 1, fp);

	free(ps.name);
	free(ps.address);
	fclose(fp);
}

