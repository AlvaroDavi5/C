#include <stdio.h>
#include <math.h>

int main(void)
{

	int n, id, n1, n2, n3, n4;
    
    scanf("%d %d", &n, &id); // CASO DOS 0000 NAO FUNCIONA, POIS O scanf LÊ APENAS ATÉ 00
    
    if (n >= 0 && n <= 9)
    {
        if (id == 0)
        {
            printf("VOID\n");
        }
        else
        {
            printf("%d\n", n);
        }
    }

    if (n >= 10 && n <= 99){
        if (id == 0){
            n1 = n % 10;
            printf("%d\n", n1);
            }
        if (id == 1){
            n1 = n % 10;
            n2 = n - n1;
            n2 = n2 / 10;
            printf("%d\n", n2);
            }
        if (id > 1){
            if (n1 > n2){
                printf("%d, %d\n", n2, n1);
                }
            else{
                printf("%d, %d\n", n1, n2);
                }
        }
    }
    if (n >= 100 && n <= 999){
        if (id == 0){
            n1 = n % 100;
            n2 = n1 % 10;
            n1 = n1 - n2;
            n1 = n1 / 10;
                if (n1 > n2){
                    printf("%d, %d", n2, n1);
                }
                else{
                    printf("%d, %d", n1, n2);
                }
        }
        if (id == 1){
            n1 = n % 100;
            n2 = n1 % 10;
            n1 = n - n2;
            n1 = n1 / 100;
            if (n1 > n2){
                printf("%d, %d", n2, n1);
            }
            else{
                printf("%d, %d", n1, n2);
            }
        }
        if (id == 2){
            n1 = n % 100;
            n2 = n % 10;
            n1 = n1 - n2;
            n1 = n1 / 10;
            n2 = n - n1;
            n2 = n2 / 100;
            if (n2 > n1){
                printf("%d, %d", n1, n2);
            }
            else{
                printf("%d, %d", n2, n1);
            }

        }
        if (id == 3){
            n1 = n % 100;
            n2 = n1 % 10;
            n3 = n - n1;
            n3 = n3 / 100;
            n1 = n1 - n2;
            n1 = n1 / 10;
            if (n3 > n1 && n1 > n2){
                printf("%d, %d, %d", n2, n1, n3);
            }
            if (n3 > n2 && n2 > n1){
                printf("%d, %d, %d", n1, n2, n3);
            }
            if (n2 > n3 && n3 > n1){
                printf("%d, %d, %d", n1, n3, n2);
            }
            if (n2 > n1 && n1 > n3){
                printf("%d, %d, %d", n3, n1, n2);
            }
            if (n1 > n3 && n3 > n2){
                printf("%d, %d, %d", n2, n3, n1);
            }
            if (n1 > n2 && n2 > n3){
                printf("%d, %d, %d", n3, n2, n1);
            }                
            
            
        }
    }
        if (n >= 1000 && n <= 9999){
            if (id == 0){
                n1 = n % 1000;
                n2 = n1 % 100;
                n3 = n2 % 10;
                n4 = n - n1;
                n4 = n4 / 1000;
                n1 = n1 - n2;
                n1 = n1 / 100;
                n2 = n2 - n3;
                n2 = n2 / 10;
                if (n1 > n2 && n2 > n3){
                    printf("%d, %d, %d", n3, n2, n1);
                }
                if (n1 > n3 && n3 > n2){
                    printf("%d, %d, %d", n2, n3, n1);
                }
                if (n2 > n3 && n3 > n1){
                    printf("%d, %d, %d", n1, n3, n2);
                }
                if (n2 > n1 && n1 > n3){
                    printf("%d, %d, %d", n3, n1, n2);
                }
                if (n3 > n2 && n2 > n1){
                    printf("%d, %d, %d", n1, n2, n3);
                }
                if (n3 > n1 && n1 > n2){
                    printf("%d, %d, %d", n2, n1, n3);
                } 
            }
            if (id == 1){
                n1 = n % 1000;
                n2 = n1 % 100;
                n3 = n2 % 10;
                n4 = n - n1;
                n4 = n4 / 1000;
                n2 = n2 - n3;
                n2 = n2 / 10;
                if (n2 > n4 && n4 > n3){
                    printf("%d, %d, %d", n3, n4, n2);
                }
                if (n2 > n3 && n3 > n4){
                    printf("%d, %d, %d", n4, n3, n2);
                }
                if (n4 > n3 && n3 > n2){
                    printf("%d, %d, %d", n2, n3, n4);
                }
                if (n4 > n2 && n2 > n3){
                    printf("%d, %d, %d", n3, n2, n4);
                }
                if (n3 > n2 && n2 > n4){
                    printf("%d, %d, %d", n4, n2, n3);
                }
                if (n3 > n4 && n4 > n2){
                    printf("%d, %d, %d", n2, n4, n3);
                }
            }
            if (id == 2){
                n1 = n % 1000;
                n2 = n1 % 100;
                n3 = n2 % 10;
                n4 = n - n1;
                n4 = n4 / 1000;
                n1 = n1 - n2;
                n1 = n1 / 100;
                n2 = n2 - n3;
                n2 = n2 / 10;
                if (n4 > n1 && n1 > n3){
                    printf("%d, %d, %d", n3, n1, n4);
                }
                if (n4 > n3 && n3 > n1){
                    printf("%d, %d, %d", n1, n3, n4);
                }
                if (n1 > n3 && n3 > n4){
                    printf("%d, %d, %d", n4, n3, n1);
                }
                if (n1 > n4 && n4 > n3){
                    printf("%d, %d, %d", n3, n4, n1);
                }
                if (n3 > n1 && n1 > n4){
                    printf("%d, %d, %d", n4, n1, n3);
                }
                if (n3 > n4 && n4 > n1){
                    printf("%d, %d, %d", n1, n4, n3);
                }
            }
            if (id == 3){
                n1 = n % 1000;
                n2 = n1 % 100;
                n3 = n2 % 10;
                n4 = n - n1;
                n4 = n4 / 1000;
                n1 = n1 - n2;
                n1 = n1 / 100;
                n2 = n2 - n3;
                n2 = n2 / 10;
                if (n4 > n2 && n2 > n1){
                    printf("%d, %d, %d", n1, n2, n4);
                }
                if (n4 > n1 && n1 > n2){
                    printf("%d, %d, %d", n2, n1, n4);
                }
                if (n1 > n4 && n4 > n2){
                    printf("%d, %d, %d", n2, n4, n1);
                }
                if (n1 > n2 && n2 > n4){
                    printf("%d, %d, %d", n4, n2, n1);
                }
                if (n2 > n1 && n1 > n4){
                    printf("%d, %d, %d", n4, n1, n2);
                }
                if (n2 > n4 && n4 > n1){
                    printf("%d, %d, %d", n1, n4, n2);
                }
            }
        }
    return 0;
}

/*

// SEGUNDO CODIGO, o separador está na ordem inversa da pedida pelo repl.it

#include <stdio.h>
#include <math.h>

int main()
{
	int num, id;
	int algU, algD, algC, algM;

	scanf("%i %i", &num, &id);  // CASO DOS 0000 NAO FUNCIONA, POIS O scanf LÊ APENAS ATÉ 00
	algU = (num % 10);
	algD = (num % 100)/10;
	algC = (num % 1000)/100;
	algM = (num % 10000)/1000;

	// ZEROS
	if (num == 0)
	{
		if (id == 0)
		{
			printf("VOID");
		}
		else if (id >= 1)
		{
			printf("0");
		}
	}
	else if (num == 00)
	{
		if (id == 0)
		{
			printf("0");
		}
		else if (id == 1)
		{
			printf("0");
		}
		else if (id >= 2)
		{
			printf("0, 0");
		}
	}
	else if (num == 000)
	{
		if (id == 0)
		{
			printf("0, 0");
		}
		else if (id == 1)
		{
			printf("0, 0");
		}
		else if (id == 2)
		{
			printf("0, 0");
		}
		else if (id >= 3)
		{
			printf("0, 0, 0");
		}
	}
	else if (num == 0000)
	{
		if (id == 0)
		{
			printf("0, 0, 0");
		}
		else if (id == 1)
		{
			printf("0, 0, 0");
		}
		else if (id == 2)
		{
			printf("0, 0, 0");
		}
		else if (id == 3)
		{
			printf("0, 0, 0");
		}
		else if (id >= 4)
		{
			printf("0, 0, 0, 0");
		}
	}

	else
	{
		// UNIDADES
		if (num < 10 && id == 0) // para obter VOID
		{
			printf("VOID");
		}
		else if (num < 10 && id >= 1) // para obter Unidade
		{
			printf("%d", algU);
		}

		// DEZENAS
		else if (num < 100 && id == 0) // para obter Dezena
		{
			printf("%d", algD);
		}
		else if (num < 100 && id == 1) // para obter Unidade
		{
			printf("%d", algU);
		}
		else if (num < 100 && id >= 2) // para comparar Unidade X Dezena
		{
			if (algU >= algD)
			{
				printf("%d, %d", algD, algU);
			}
			if (algU < algD)
			{
				printf("%d, %d", algU, algD);
			}
		}

		// CENTENAS
		else if (num < 1000 && id == 0) // para comparar Denzena X Centena
		{
			if (algD >= algC)
			{
				printf("%d, %d", algC, algD);
			}
			if (algD < algC)
			{
				printf("%d, %d", algD, algC);
			}
		}
		else if (num < 1000 && id == 1) // para comparar Unidade X Centena
		{
			if (algU >= algC)
			{
				printf("%d, %d", algC, algU);
			}
			if (algU < algC)
			{
				printf("%d, %d", algU, algC);
			}
		}
		else if (num < 1000 && id == 2) // para comparar Unidade X Dezena
		{
			if (algU >= algD)
			{
				printf("%d, %d", algD, algU);
			}
			if (algU < algD)
			{
				printf("%d, %d", algU, algD);
			}
		}
		else if (num < 1000 && id >= 3) // para comparar Unidade X Dezena X Centena
		{
			if (algU >= algD)
			{
				if (algD >= algC)
				{
					printf("%d, %d, %d", algC, algD, algU);
				}
				if (algD < algC)
				{
					printf("%d, %d, %d", algD, algC, algU);
				}
			}
			if (algU < algD)
			{
				if (algD >= algC)
				{
					printf("%d, %d, %d", algU, algC, algD);
				}
				if (algD < algC)
				{
					printf("%d, %d, %d", algC, algU, algD);
				}
			}
		}

		// UNIDADES DE MILHAR
		else if (num < 10000 && id == 0) // para comparar Denzena X Centena X Milhar
		{
			if (algD >= algC)
			{
				if (algC >= algM)
				{
					printf("%d, %d, %d", algM, algC, algD);
				}
				if (algC < algM)
				{
					printf("%d, %d, %d", algC, algM, algD);
				}
			}
			if (algD < algC)
			{
				if (algC >= algM)
				{
					if (algD >= algM)
					{
						printf("%d, %d, %d", algM, algD, algC);
					}
					if (algD < algM)
					{
						printf("%d, %d, %d", algD, algM, algC);
					}
				}
				if (algC < algM)
				{
					if (algC >= algD)
					{
						printf("%d, %d, %d", algD, algC, algM);
					}
					if (algC < algD)
					{
						printf("%d, %d, %d", algC, algD, algM);
					}
				}
			}
		}
		else if (num < 10000 && id == 1) // para comparar Unidade X Centena X Milhar
		{
			if (algU >= algC)
			{
				if (algC >= algM)
				{
					printf("%d, %d, %d", algM, algC, algU);
				}
				if (algC < algM)
				{
					printf("%d, %d, %d", algC, algM, algU);
				}
			}
			if (algU < algC)
			{
				if (algC >= algM)
				{
					if (algU >= algM)
					{
						printf("%d, %d, %d", algM, algU, algC);
					}
					if (algU < algM)
					{
						printf("%d, %d, %d", algU, algM, algC);
					}
				}
				if (algC < algM)
				{
					if (algC >= algU)
					{
						printf("%d, %d, %d", algU, algC, algM);
					}
					if (algC < algU)
					{
						printf("%d, %d, %d", algC, algU, algM);
					}
				}
			}
		}
		else if (num < 10000 && id == 2) // para comparar Unidade X Dezena X Milhar
		{
			if (algU >= algD)
			{
				if (algD >= algM)
				{
					printf("%d, %d, %d", algM, algD, algU);
				}
				if (algD < algM)
				{
					printf("%d, %d, %d", algD, algM, algU);
				}
			}
			if (algU < algD)
			{
				if (algD >= algM)
				{
					if (algU >= algM)
					{
						printf("%d, %d, %d", algM, algU, algD);
					}
					if (algU < algM)
					{
						printf("%d, %d, %d", algU, algM, algD);
					}
				}
				if (algD < algM)
				{
					if (algD >= algU)
					{
						printf("%d, %d, %d", algU, algD, algM);
					}
					if (algD < algU)
					{
						printf("%d, %d, %d", algD, algU, algM);
					}
				}
			}
		}
		else if (num < 10000 && id == 3) // para comparar Unidade X Dezena X Centena
		{
			if (algU >= algD)
			{
				if (algD >= algC)
				{
					printf("%d, %d, %d", algC, algD, algU);
				}
				if (algD < algC)
				{
					printf("%d, %d, %d", algD, algC, algU);
				}
			}
			if (algU < algD)
			{
				if (algD >= algC)
				{
					if (algU >= algC)
					{
						printf("%d, %d, %d", algC, algU, algD);
					}
					if (algU < algC)
					{
						printf("%d, %d, %d", algU, algC, algD);
					}
				}
				if (algD < algC)
				{
					if (algD >= algU)
					{
						printf("%d, %d, %d", algU, algD, algC);
					}
					if (algD < algU)
					{
						printf("%d, %d, %d", algD, algU, algC);
					}
				}
			}
		}
		else if (num < 10000 && id >= 4) // para comparar Unidade X Dezena X Centena X Milhar
		{
			if (algU >= algD)
			{
				if (algD >= algC)
				{
					if (algC >= algM)
					{
						printf("%d, %d, %d, %d", algM, algC, algD, algU);
					}
					if (algC < algM)
					{
						printf("%d, %d, %d, %d", algC, algM, algD, algU);
					}
				}
				if (algD < algC)
				{
					if (algD >= algM)
					{
						printf("%d, %d, %d, %d", algM, algD, algC, algU);
					}
					if (algD < algM)
					{
						printf("%d, %d, %d, %d", algD, algM, algC, algU);
					}
				}
			}
			if (algU < algD)
			{
				if (algU >= algC)
				{
					if (algU >= algM)
					{
						printf("%d, %d, %d, %d", algC, algM, algU, algD);
					}
					if (algU < algM)
					{
						printf("%d, %d, %d, %d", algC, algU, algM, algD);
					}
				}
				if (algD < algC)
				{
					if (algD >= algM)
					{
						printf("%d, %d, %d, %d", algM, algD, algC, algD);
					}
					if (algD < algM)
					{
						printf("%d, %d, %d, %d", algD, algM, algC, algD);
					}
				}
			}
		}
	}

	return 0;
}

*/