/*
==================================================================================
                    Calculadora de Códigos de Cores para Resistores
==================================================================================
Empresa: Espartana
Equipe de Programadores:
               Fabrício Razera;
               Gabriel de Oliveira Buchara;
               Gabriel Toshio;
               Letícia Alves Korzeniewski;
               Pedro Gabriel de Andrade;
               Rafael Vieira Rodrigues.
Curso: Tecnologia em Análise e Desenvolvimento de Sistemas
Data de início do projeto: 03/10/2022
----------------------------------------------------------------------------------
Descrição do Programa:
		O programa tem o objetivo de ajudar na realização do cálculo
        da resistência elétrica, por meio do uso de código de cores de 4 faixas.
        O usuário deverá informar as cores das 4 faixas do resistor. Com isso, o
        programa irá informar qual será o valor da resistência e da sua tolerância,
        todos com a unidade de medida em Ohms.
Versão do programa: 1.0
Melhorias da versão: Primeira versão.
Data de lançamento da versão: 11/10/2022
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
    printf("\nOlá, seja bem vindo(a) à calculadora de resistência elétrica para resistores de 4 faixas!");
    printf("\n\nVocê deverá informar as cores de quatro faixas.");
    printf("\nAo informar as cores corretamente, o programa calculará a resistência em ohms.");

    printf("\n*******************************************************************************************\n");
    //Mostrar os valores das faixas
    printf("\n\n------------------ Cores ------------------\n");
    printf("Preto\t\tMarrom\t\tVermelho\nLaranja\t\tAmarelo\t\tVerde\nAzul\t\tVioleta\t\tCinza\nBranco\t\tDourado\t\tPrata\n");
    printf("\n-----------------------------------------------\n");

}

int pega_digito(char cor[]) {
    /*
        Esta função recebe o nome de uma cor e converte para um dígito por comparação com um vetor de strings contendo as cores.

        Retorna: o dígito correspondente à cor, ou -1 se a cor informada for inválida.
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
        Esta função converte a string para lower case, para que o usuário não seja obrigado a utilizar um case específico.
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
    //Condição para receber o valor da faixa 1
    do {
        printf("\nDigite a cor da primeira faixa: ");
        scanf(" %s", nome_cor);
        
        converteLowerCase(nome_cor);
        fx1 = pega_digito(nome_cor);


        if (fx1 == -1)
            printf("Cor informada inválida.");
        else
            printf("Dígito relativo à cor: %d", fx1);
    } while (fx1 == -1);

    //Condição para receber o valor da faixa 2
    do {
        printf("\n\nDigite a cor da segunda faixa: ");
        scanf(" %s", nome_cor);

        converteLowerCase(nome_cor);
        fx2 = pega_digito(nome_cor);

        if (fx2 == -1)
            printf("Cor informada inválida.");
        else
            printf("Dígito relativo à cor: %d", fx2);
            
    } while (fx2 == -1);

    //Condição para receber o valor da faixa 3
    do {
        printf("\n\nDigite a cor da terceira faixa (multiplicador): ");
        scanf(" %s", nome_cor);
		
		converteLowerCase(nome_cor);
		fx3 = pegaMult(nome_cor);
		if(fx3 == -1){
		
			printf("Cor informada inválida.");
		}
		else{	
			printf("Multiplicador correspondente à faixa é: %.2f", fx3 );
		}
		   
	} while (fx3 == -1);

	//Condição o para receber o valor da faixa 4
    do {
        printf("\n\nDigite o código da quarta faixa de cor (tolerância): ");
        scanf(" %s", nome_cor);
        converteLowerCase(nome_cor);
        fx4 = pegaTolerancia(nome_cor);
        
        if (fx4 == -1){
        	printf("Cor informada inválida.");
		}
		else{
		
			printf("Tolerância correspondente é: %.2f%%", fx4 * 100);
		}
		
    } while (fx4 == -1);


	//Cálculo da resistência
    calc = ((fx1 * 10) + fx2) * (fx3);

//Mostrar valores
    printf("\n\nO valor da resistência e da sua tolerância, respectivamente: %.2f ohms +/- %.2f%%. \n",calc,fx4 * 100);
//Convertendo o valor para a realizaçãoo do cálculo
    tolerancia = (calc * (fx4));
    calcMenor = (calc  - tolerancia);
    calcMaior = (calc + tolerancia);
//Mostrando a taxa do valor da resistência
    printf("A sua tolerância sería entre: %.2f e %.2f ohms. \n",calcMenor,calcMaior);

    printf("\nObrigado por utilizar nosso software! A Equipe Espartana agradece! \n");

    return 0;
}


int main()
{
    
    //Setando em pt-BR
    setlocale(LC_ALL, "Portuguese");


    //Mostra as boas vindas ao programa. Além, das cores e seus respectivos valores
    instrucoes();


    //Recebe os valores, calcula, valida e mostra seu resultado.
    calcVal();

    return 0;
}
