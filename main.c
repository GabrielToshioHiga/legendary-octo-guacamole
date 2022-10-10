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
		O programa t�m o objetivo de ajudar na realiza��o do c�lculo
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
#include <math.h>
#include <string.h>

void instrucoes() {
    //Boas-vindas ao programa
    printf("*******************************************************************************************");
    printf("\nOl�, seja bem vindo(a) � calculadora de resist�ncia el�trica para resistores de 4 faixas!");
    printf("\n\nVoc� dever� informar as cores de quatro faixas.");
    printf("\nAp�s informar as cores corretamente, o programa calculará a resistência em ohms.");

    printf("\n*******************************************************************************************\n");
    //Mostrar os valores das faixas
    printf("\n\n---------------- Cores ------------------\n");
    printf("Preto\t\tMarrom\t\tVermelho\nLaranja\t\tAmarelo\t\tVerde\nAzul\t\tVioleta\t\tCinza\nBranco\t\tDourado\t\tPrateado\n");
    printf("\n-----------------------------------------------\n");

}

int pega_digito(char *cor) {
    /*
        Esta função recebe o nome de uma cor e converte para um dígito por comparação com um vetor de strings contendo as cores.

        Retorna: o dígito correspondente à cor, ou -1 se a cor informada for inválida.
    */
    int digito;

    char cores[][15] = {"preto", "marrom", "vermelho", "laranja", "amarelo", "verde", "azul", "violeta", "cinza", "branco", "dourado", "prateado"};
    for (int i = 0; i < sizeof(cores) / sizeof(cores[0]); i++) {
        if (!strcmp(cor, cores[i])) {
            digito = i;
            break;
        } else {
            digito = -1;
        }
    }

    return digito;
}


void converteLowerCase(char *str) {
    /*
        Esta função converte a string para lower case, para que o usuário não seja obrigado a utilizar um case específico.
    */
    for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
       str[i] = tolower(str[i]);
    }
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
            printf("Cor informada inválida.");
        else
            printf("Dígito relativo à cor: %d", fx1);
    } while (fx1 == -1);

    //Condi��o para receber o valor da faixa 2
    do {
        printf("\nDigite a cor da segunda faixa: ");
        scanf(" %s", nome_cor);

        converteLowerCase(nome_cor);
        fx2 = pega_digito(nome_cor);

        if (fx2 == -1)
            printf("Cor informada inválida.");
        else
            printf("Dígito relativo à cor: %d", fx2);
            
    } while (fx2 == -1);

    //Condi��o para receber o valor da faixa 3
    do {
        printf("Digite o c�digo da terceira faixa de cor (multiplicador): ");
        scanf("%f", &fx3);
    } while (fx3 != 0 && fx3 != 1 && fx3 != 2 && fx3 != 3 && fx3 != 4 && fx3 != 5 && fx3 != 10 && fx3 != 11);

//Condi��o para receber o valor da faixa 4
    do {
        printf("Digite o c�digo da quarta faixa de cor (toler�ncia): ");
        scanf("%f", &fx4);
    } while (fx4 != 0 && fx4 != 1 && fx4 != 2 && fx4 != 3 && fx4 != 4 && fx4 != 10 && fx4 != 11);

//Condi��es para o fx3 (Dourado e Prata)
    if (fx3 == 10){
        fx3 = -1;
    }
    else if (fx3 == 11){
        fx3 = -2 ;
    }
//Condi��es para o fx4 (Dourado, Prateado e Preto)
    if (fx4 == 10){
        fx4 = 5;
    }
    else if (fx4 == 11){
        fx4 = 10;

    }
    else if (fx4 == 0){
        fx4 = 20;
    }
//C�lculo da resist�ncia
    calc = ((fx1 * 10) + fx2) * (pow(10, fx3)); //fun��o pow() serve como uma pot�ncia. Ex: pow(10,fx3) = 10^fx3.

//Mostrar valores
    printf("\nO valor da resist�ncia e da sua toler�ncia, respectivamente: %.2f ohms +/- %.2f%%. \n",calc,fx4);
//Convertendo o valor para a realiza��o do c�lculo
    tolerancia = (calc * (fx4/100));
    calcMenor = (calc  - tolerancia);
    calcMaior = (calc + tolerancia);
//Mostrando a taxa do valor da resist�ncia
    printf("A sua toler�ncia ser� entre: %.2f e %.2f ohms. \n",calcMenor,calcMaior);

    printf("\nObrigado por utilizar nosso software! A Equipe Espartana agradece! \n");

    return 0;
}


int main()
{
    char cor[15];
    int digito;
    //Setando em pt-BR
    setlocale(LC_ALL, "Portuguese");


    //Mostra as boas vindas ao programa. Al�m, das cores e seus respectivos valores
    instrucoes();


    //Recebe os valores, calcula, valida e mostra seu resultado.
    calcVal();

    return 0;
}
