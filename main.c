#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//Fun��o respons�vel pela convers�o de (Bin�rio -> Decimal)
int convertBD(int bin_aux){
    int i, dec_num = 0, rem;
    for (i = 0; bin_aux != 0; ++i){
        rem = bin_aux % 10;
        bin_aux /= 10;
        dec_num += (rem) * ( pow (2, i));
    }
    return dec_num;
}

//Fun��o respons�vel pela convers�o de (Decimal -> Bin�rio)
int convertDB(int n){
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

int main(int argc, char *argv[]) {
	int x, i, n, dec, bin, aux, decimal, pc, RI, A, B, num, stop;
	char aux1;
	
	setlocale(LC_ALL, "Portuguese");
	
//vetor respons�vel pelo armazenamento dos dados
	int memoria_num[31];
	
//criando documento(.txt) para inser��o dos dados
	FILE *notas;
	notas = fopen("traduzido.txt", "r");//mesmo nome do arquivo gerado pela atividade II

//Caso o arquivo n�o exista, imprimir o erro	
	if (notas == NULL) {
        printf("ERRO: Arquivo (traduzido.txt), n�o existe!");
		return 0;
	}
//Lendo dados fornecidos pelo .txt	
	for (i = 0; i<31; i++){
		aux = fscanf(notas, "%05d", &num);
		if(aux == 1){
			memoria_num[i] = num;
		}
	}
	
	fclose(notas);
	
	//criando documento(.txt) para imprimir os dados
	notas = fopen("print.txt", "w");
	
    pc = 0;
    RI = memoria_num[pc];
	
	//inicio do looping
	while (stop == 0) {
        pc++;
        //executando a soma
        if (RI == 10100) { 
        	//passando dado a ser convertido em bin�rio
        	bin = memoria_num[pc];
        	//passando dado convertido para "decimal"
            int decimal = convertBD(bin);          
			A = decimal;
			
            pc++;
            
			//passando dado a ser convertido em bin�rio          
            bin = memoria_num[pc];
            
            //passando dado convertido para "decimal"
            decimal = convertBD(bin);
            B = decimal;
           
            pc++; 
			//fazendo a soma e guardando na pr�xima casa do vetor         
            memoria_num[pc] = A + B;
            n = memoria_num[pc];
            
            //passando de decimal para bin�rio novamente
            int binario_O = convertDB(n);
		    memoria_num[pc] = binario_O;		    		    			
		   
            pc++;        
        } 	
		RI = memoria_num[pc];
		pc++;
		
        //executando a subtra��o
        if (RI == 11000) { 
            //passando dado a ser convertido em bin�rio
        	bin = memoria_num[pc];
        	//passando dado convertido para "decimal"
            int decimal = convertBD(bin);          
			A = decimal;
			
            pc++;
			          
            //passando dado a ser convertido em bin�rio          
            bin = memoria_num[pc];
            
            //passando dado convertido para "decimal"
            decimal = convertBD(bin);
            B = decimal;
          
            pc++; 
			         
            //fazendo a subtra��o e guardando na pr�xima casa do vetor         
            memoria_num[pc] = A - B;
            n = memoria_num[pc];
            
            //passando de decimal para bin�rio novamente
            int binario_O = convertDB(n);
		    memoria_num[pc] = binario_O;		    		    			
		   
            pc++; 
            
        }
        RI = memoria_num[pc];
        pc++;

        //executando a multiplica��o
        if (RI == 10101) { 
           	//passando dado a ser convertido em bin�rio
        	bin = memoria_num[pc];
        	//passando dado convertido para "decimal"
            int decimal = convertBD(bin);          
			A = decimal;
			
            pc++;
			          
            //passando dado a ser convertido em bin�rio          
            bin = memoria_num[pc];
            
            //passando dado convertido para "decimal"
            decimal = convertBD(bin);
            B = decimal;
          
            pc++; 
			         
            //fazendo a multiplica��o e guardando na pr�xima casa do vetor         
            memoria_num[pc] = A * B;
            n = memoria_num[pc];
            
            //passando de decimal para bin�rio novamente
            int binario_O = convertDB(n);
		    memoria_num[pc] = binario_O;		    		    			
		   
            pc++; 
        }
        RI = memoria_num[pc];
        pc++;

        //executando a divis�o
        if (RI == 11100) { 
            //passando dado a ser convertido em bin�rio
        	bin = memoria_num[pc];
        	//passando dado convertido para "decimal"
            int decimal = convertBD(bin);          
			A = decimal;
			
            pc++;
			          
            //passando dado a ser convertido em bin�rio          
            bin = memoria_num[pc];
            
            //passando dado convertido para "decimal"
            decimal = convertBD(bin);
            B = decimal;
          
            pc++; 
			         
            //fazendo a divis�o e guardando na pr�xima casa do vetor         
            memoria_num[pc] = A / B;
            n = memoria_num[pc];
            
            //passando de decimal para bin�rio novamente
            int binario_O = convertDB(n);
		    memoria_num[pc] = binario_O;		    		    			
		   
            pc++;
        }
        RI = memoria_num[pc];
        pc++;

    	//executando a media
        if (RI == 10011) { 
            //passando dado a ser convertido em bin�rio
        	bin = memoria_num[pc];
        	//passando dado convertido para "decimal"
            int decimal = convertBD(bin);          
			A = decimal;
			
            pc++;
			          
            //passando dado a ser convertido em bin�rio          
            bin = memoria_num[pc];
            
            //passando dado convertido para "decimal"
            decimal = convertBD(bin);
            B = decimal;
          
            pc++; 
			         
            //fazendo a m�dia e guardando na pr�xima casa do vetor         
            memoria_num[pc] = (A + B) / 2;
            n = memoria_num[pc];
            
            //passando de decimal para bin�rio novamente
            int binario_O = convertDB(n);
		    memoria_num[pc] = binario_O;		    		    			
		   
            pc++;
        }
        RI = memoria_num[pc];
        pc++;

        //elevando vari�vel a 2� pot�ncia
        if (RI == 10111) { 
            //passando dado a ser convertido em bin�rio
        	bin = memoria_num[pc];
        	//passando dado convertido para "decimal"
            int decimal = convertBD(bin);          
			A = decimal;
           
            pc++; 
            
			//fazendo a pot�ncia e guardando na pr�xima casa do vetor          
            memoria_num[pc] = pow(A,2);
            n = memoria_num[pc];
            
            //passando de decimal para bin�rio novamente
            int binario_O = convertDB(n);
		    memoria_num[pc] = binario_O;		    		    			
		   
            pc++;
        }
        RI = memoria_num[pc];
        pc++;

        //incrementando (+1) vari�vel
        if (RI == 10110) { 
            //passando dado a ser convertido em bin�rio
        	bin = memoria_num[pc];
        	//passando dado convertido para "decimal"
            int decimal = convertBD(bin);          
			A = decimal;
	
            pc++;
            
			//incrementando e guardando na pr�xima casa do vetor         
            memoria_num[pc] = A + 1;
            n = memoria_num[pc];
            
            //passando de decimal para bin�rio novamente
            int binario_O = convertDB(n);
		    memoria_num[pc] = binario_O;		    		    			
		   
            pc++;
        }
        RI = memoria_num[pc];
        pc++;

        //decrementando (-1) vari�vel
        if (RI == 11110) { 
            //passando dado a ser convertido em bin�rio
        	bin = memoria_num[pc];
        	//passando dado convertido para "decimal"
            int decimal = convertBD(bin);          
			A = decimal;
	
            pc++;
            
			//decrementando e guardando na pr�xima casa do vetor         
            memoria_num[pc] = A - 1;
            n = memoria_num[pc];
            
            //passando de decimal para bin�rio novamente
            int binario_O = convertDB(n);
		    memoria_num[pc] = binario_O;
		    
            pc++;
        }
        RI = memoria_num[pc];
        pc++;

        //parando o looping
       if (RI == 10000) { 
            stop = 1;
        }
    }
	
	//printando o "vetor" no bloco de notas
	for (i = 0; i < 30; i++){
		fprintf(notas, "%05d\n", memoria_num[i]);
    }
    
    fclose(notas);
	return 0;
}	
