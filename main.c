/*
==================================================================================
                    Calculadora de C�digos de Cores para Resistores
==================================================================================
Empresa: Espartana
Equipe de Programadores:
               Fabr�cio Razera;
               Gabriel de Oliveira Buchara;
               Gabriel Toshio;
               Let�cia Alves Korzeniewski;
               Pedro Gabriel de Andrade;
               Rafael Vieira Rodrigues.
Curso: Tecnologia em An�lise e Desenvolvimento de Sistemas
Data de in�cio do projeto: 03/10/2022
----------------------------------------------------------------------------------
Descri��o do Programa:
		O programa tem o objetivo de ajudar na realiza��o do c�lculo
        da resist�ncia el�trica, por meio do uso de c�digo de cores de 4 faixas.
        O usu�rio dever� informar as cores das 4 faixas do resistor. Com isso, o
        programa ir� informar qual ser� o valor da resist�ncia e da sua toler�ncia,
        todos com a unidade de medida em Ohms.
Vers�o do programa: 1.0
Melhorias da vers�o: Primeira vers�o.
Data de lan�amento da vers�o: 11/10/2022
==================================================================================
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //biblioteca caracteres especiais
#include <string.h>

void instrucoes() {
    //Boas-vindas ao programa
    printf("*******************************************************************************************");
    printf("\nOl�, seja bem vindo(a) � calculadora de resist�ncia el�trica para resistores de 4 faixas!");
    printf("\n\nVoc� dever� informar as cores de quatro faixas.");
    printf("\nAo informar as cores corretamente, o programa calcular� a resist�ncia em ohms.");

    printf("\n*******************************************************************************************\n");
    //Mostrar os valores das faixas
    printf("\n\n------------------ Cores ------------------\n");
    printf("Preto\t\tMarrom\t\tVermelho\nLaranja\t\tAmarelo\t\tVerde\nAzul\t\tVioleta\t\tCinza\nBranco\t\tDourado\t\tPrata\n");
    printf("\n-----------------------------------------------\n");

}

int pega_digito(char cor[]) {
    /*
        Esta fun��o recebe o nome de uma cor e converte para um d�gito por compara��o com um vetor de strings contendo as cores.

        Retorna: o d�gito correspondente � cor, ou -1 se a cor informada for inv�lida.
    */
    int i, digito;

    char cores[][15] = {"preto", "marrom", "vermelho", "laranja", "amarelo", "verde", "azul", "violeta", "cinza", "branco"};
    
    char coresFem[][15] = {"preta", "marrom", "vermelha", "laranja", "amarela", "verde", "azul", "violeta", "cinza", "branca"};
    
    for ( i = 0; i < sizeof(cores) / sizeof(cores[0]); i++) {
        if (!strcmp(cor, cores[i]) || !strcmp(cor, coresFem[i])) {
            digito = i;
            break;
        } else {
            digito = -1;
        }
    }

    return digito;
}


void converteLowerCase(char str[]) {
    /*
        Esta fun��o converte a string para lower case, para que o usu�rio n�o seja obrigado a utilizar um case espec�fico.
    */
    int i;
    
    for ( i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
       str[i] = tolower(str[i]);
    }
}


float pegaMult(char multiplicador[]){
	
	
		if (!strcmp(multiplicador, "preto") || !strcmp(multiplicador, "preta")){
	
			return 1;
		}
		else if (!strcmp(multiplicador, "marrom")){
			
			return 10;
		}
		else if (!strcmp(multiplicador, "vermelho")){
			
			return 100;
		}
		else if (!strcmp(multiplicador, "laranja")){
			
			return 1000;
		}
		else if (!strcmp(multiplicador, "amarelo") || !strcmp(multiplicador, "amarela")){
		
			return 10000;
		}
		else if (!strcmp(multiplicador, "verde")){
			
			return 100000;
		}
		else if (!strcmp(multiplicador, "dourado") || !strcmp(multiplicador, "dourada")){
			
			return 0.1;
		}
		else if (!strcmp(multiplicador, "prata")){
			
			return 0.01;
		}
		else{
		
			return -1;
		}
	
}



float pegaTolerancia(char tolerancia[]){

	float tole;
		
	if (!strcmp(tolerancia, "preto") || !strcmp(tolerancia, "preto")){
	
		tole = 0.2;	
	}
	
	else if (!strcmp(tolerancia, "marrom")){
		
		tole = 0.01;
	}
	
	else if (!strcmp(tolerancia, "vermelho") || !strcmp(tolerancia, "vermelha")){
		
		tole = 0.02;
	}
	
	else if (!strcmp(tolerancia, "laranja")){
		
		tole = 0.03;
	}
	
	else if (!strcmp(tolerancia, "amarelo") || !strcmp(tolerancia, "amarela")){
		
		tole = 0.04;
	}
	
	else if (!strcmp(tolerancia, "dourado") || !strcmp(tolerancia, "dourada")){
		
		tole = 0.05;
	}
	
	else if (!strcmp(tolerancia, "prata")){
		
		tole = 0.1;
	}
	
	else {
	
		tole = -1;
	}
	
	return tole;
}

	


float calcVal(){
    float fx3,fx4,calc,tolerancia,calcMenor,calcMaior;
    int fx1, fx2;

    char nome_cor[15];

    //Receber valores das faixas
    //Condi��o para receber o valor da faixa 1
    do {
        printf("\nDigite a cor da primeira faixa: ");
        scanf(" %s", nome_cor);
        
        converteLowerCase(nome_cor);
        fx1 = pega_digito(nome_cor);


        if (fx1 == -1)
            printf("Cor informada inv�lida.");
        else
            printf("D�gito relativo � cor: %d", fx1);
    } while (fx1 == -1);

    //Condi��o para receber o valor da faixa 2
    do {
        printf("\n\nDigite a cor da segunda faixa: ");
        scanf(" %s", nome_cor);

        converteLowerCase(nome_cor);
        fx2 = pega_digito(nome_cor);

        if (fx2 == -1)
            printf("Cor informada inv�lida.");
        else
            printf("D�gito relativo � cor: %d", fx2);
            
    } while (fx2 == -1);

    //Condi��o para receber o valor da faixa 3
    do {
        printf("\n\nDigite a cor da terceira faixa (multiplicador): ");
        scanf(" %s", nome_cor);
		
		converteLowerCase(nome_cor);
		fx3 = pegaMult(nome_cor);
		if(fx3 == -1){
		
			printf("Cor informada inv�lida.");
		}
		else{	
			printf("Multiplicador correspondente � faixa �: %.2f", fx3 );
		}
		   
	} while (fx3 == -1);

	//Condi��o o para receber o valor da faixa 4
    do {
        printf("\n\nDigite o c�digo da quarta faixa de cor (toler�ncia): ");
        scanf(" %s", nome_cor);
        converteLowerCase(nome_cor);
        fx4 = pegaTolerancia(nome_cor);
        
        if (fx4 == -1){
        	printf("Cor informada inv�lida.");
		}
		else{
		
			printf("Toler�ncia correspondente �: %.2f%%", fx4 * 100);
		}
		
    } while (fx4 == -1);


	//C�lculo da resist�ncia
    calc = ((fx1 * 10) + fx2) * (fx3);

//Mostrar valores
    printf("\n\nO valor da resist�ncia e da sua toler�ncia, respectivamente: %.2f ohms +/- %.2f%%. \n",calc,fx4 * 100);
//Convertendo o valor para a realiza��oo do c�lculo
    tolerancia = (calc * (fx4));
    calcMenor = (calc  - tolerancia);
    calcMaior = (calc + tolerancia);
//Mostrando a taxa do valor da resist�ncia
    printf("A sua toler�ncia ser�a entre: %.2f e %.2f ohms. \n",calcMenor,calcMaior);

    printf("\nObrigado por utilizar nosso software! A Equipe Espartana agradece! \n");

    return 0;
}


int main()
{
    
    //Setando em pt-BR
    setlocale(LC_ALL, "Portuguese");


    //Mostra as boas vindas ao programa. Al�m, das cores e seus respectivos valores
    instrucoes();


    //Recebe os valores, calcula, valida e mostra seu resultado.
    calcVal();

    return 0;
}
