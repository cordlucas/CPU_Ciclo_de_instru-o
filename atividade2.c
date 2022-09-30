
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//Função responsável pela conversão de (Binário -> Decimal)
long long convertDB(int n) {
  long long bin2 = 0;
  int rem, i = 1;

  while (n!=0) {
    rem = n % 2;
    n /= 2;
    bin2 += rem * i;
    i *= 10;
  }

  return bin2;
}

int main(void) {
    int i = 0, k = 0, j;
    int executando = 1;
    char* infos[256]; //recebendo os dados do notas 
    char busca[256]; // busca os dados no notas
    
    setlocale(LC_ALL, "Portuguese");

	/*Abre e lê o notas do programa em ling. de máquina*/
    FILE *notas;
    notas = fopen("registrar.txt", "r"); //busca arquivo com o nome escolhido.
    
    /*Gerar um novo notas com os binários*/
    FILE *novaNota;
    novaNota = fopen("traduzido.txt", "w");

    if (notas == NULL || novaNota == NULL) {
        printf("ERRO: Um dos arquivos não existe!");
		return 0;
	}

    while(fgets(busca, sizeof busca, notas) != NULL) {
        /*Adiciona cada palavra do notas registro.txt no vetor*/
        infos[i] = strdup(busca);
    		i++;
    }
	
	while (executando) {
		/*Compara as instruções em char*/

		if(strcpy(infos[k], "ADD")) {
		k++;
			long long a = convertDB(atoi(infos[k])); //atoi char -> int
		k++;
			long long b = convertDB(atoi(infos[k]));
		k++;
			long long c = convertDB(atoi(infos[k]));
		k++;
			//printf("%d \n", a);
			fprintf(novaNota, "10100");//soma
			fprintf(novaNota, "\n%05lld", a);
			fprintf(novaNota, "\n%05lld", b);
			fprintf(novaNota, "\n%05lld\n", c); // variável de armazenamento
		}
		
		if(strcpy(infos[k], "SUB")) {
		k++;
			long long a = convertDB(atoi(infos[k]));
		k++;
			long long b = convertDB(atoi(infos[k]));
		k++;
			long long c = convertDB(atoi(infos[k]));
		k++;
			fprintf(novaNota, "11000");
			fprintf(novaNota, "\n%05lld", a);
			fprintf(novaNota, "\n%05lld", b);
			fprintf(novaNota, "\n%05lld\n", c); // variável de armazenamento
		}
		
		if(strcpy(infos[k], "MULTI")) {
		k++;
			long long a = convertDB(atoi(infos[k]));
		k++;
			long long b = convertDB(atoi(infos[k]));
		k++;
			long long c = convertDB(atoi(infos[k]));
		k++;
			fprintf(novaNota, "10101");
			fprintf(novaNota, "\n%05lld", a);
			fprintf(novaNota, "\n%05lld", b);
			fprintf(novaNota, "\n%05lld\n", c); // variável de armazenamento
		}
		
		if(strcpy(infos[k], "DIV")) {
		k++;
			long long a = convertDB(atoi(infos[k]));
		k++;
			long long b = convertDB(atoi(infos[k]));
		k++;
		long long c = convertDB(atoi(infos[k]));
		k++;
			fprintf(novaNota, "11100");
			fprintf(novaNota, "\n%05lld", a);
			fprintf(novaNota, "\n%05lld", b);
			fprintf(novaNota, "\n%05lld\n", c); // variável de armazenamento
		}
		
		if(strcpy(infos[k], "MED")) {
		k++;
			long long a = convertDB(atoi(infos[k]));
		k++;
			long long b = convertDB(atoi(infos[k]));
		k++;
			long long c = convertDB(atoi(infos[k]));
		k++;
			fprintf(novaNota, "10011");
			fprintf(novaNota, "\n%05lld", a);
			fprintf(novaNota, "\n%05lld", b);
			fprintf(novaNota, "\n%05lld\n", c); // variável de armazenamento
		}
		
		if(strcpy(infos[k], "POT")) {
		k++;
			long long a = convertDB(atoi(infos[k]));
		k++;
			long long b = convertDB(atoi(infos[k]));
		k++;
			fprintf(novaNota, "10111");
			fprintf(novaNota, "\n%05lld", a);
			fprintf(novaNota, "\n%05lld\n", b); // variável de armazenamento
		}
		
		if(strcpy(infos[k], "INC")) {
		k++;
			long long a = convertDB(atoi(infos[k]));
		k++;
			long long b = convertDB(atoi(infos[k]));
		k++;
			fprintf(novaNota, "10110");
			fprintf(novaNota, "\n%05lld", a);
			fprintf(novaNota, "\n%05lld\n", b); // variável de armazenamento
		}
		
		if(strcpy(infos[k], "DEC")) {
		k++;
			long long a = convertDB(atoi(infos[k]));
		k++;
			long long b = convertDB(atoi(infos[k]));
		k++;
			fprintf(novaNota, "11110");
			fprintf(novaNota, "\n%05lld", a);
			fprintf(novaNota, "\n%05lld\n", b); // variável de armazenamento
		}
		
		//STOP -> encerra processo ao encontrar 11000
		if(strcpy(infos[k], "STOP")) {
		k++;
			fprintf(novaNota, "10000");
			executando = 0;
		}
	}
    fclose(notas);

	system("pause");
    return 0;
}
