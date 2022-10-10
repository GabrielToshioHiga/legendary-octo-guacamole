/*
==================================================================================
                    Calculadora de C�digos de Cores para Resistores
==================================================================================
Empresa: Espartana
Equipe de Programadores:
               Fabr�cio Razera;
               Gabriel de Oliveira Buchara;
               Gabriel Toshio;
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

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //biblioteca caracteres especiais
#include <math.h>

void instrucoes(){
    //Boas-vindas ao programa
    printf("*******************************************************************************************");
    printf("\nOl�, seja bem vindo(a) � calculadora de resist�ncia el�trica para resistores de 4 faixas!");
    printf("\n\nVoc� dever� informar o valor de cada uma das faixas 4 faixas: faixa 1, faixa 2, faixa");
    printf("\nmultiplicadora e a faixa de toler�ncia.\n");
    printf("\nAp�s informar os valores corretamente, ser� realizado e mostrado o c�lculo da resist�ncia.");
    printf("\nA unidade de medida utilizada ser� em Ohms.");
    printf("\nOBS: Em caso de utilizar algum separador decimal, por favor, utilizado a V�RGULA.");

    printf("\n*******************************************************************************************\n");
    //Mostrar os valores das faixas
    printf ("\n\n------------- Valores das Cores ---------------\n");
    printf ("Preto:         0\t1\t+-20%%      \n");
    printf ("Marrom:        1 \t10\t+-1%%     \n");
    printf ("Vermelho:      2 \t10^2\t+-2%%       \n");
    printf ("Laranja:       3 \t10^3\t+-3%%       \n");
    printf ("Amarelo:       4 \t10^4\t+-4%%       \n");
    printf ("Verde:         5 \t10^5            \n");
    printf ("Azul:          6                           \n");
    printf ("Violeta:       7                       \n");
    printf ("Cinza:         8                       \n");
    printf ("Branco:        9                       \n");
    printf ("Dourado:       10 \t10^-1\t+-5%%      \n");
    printf ("Prateado:      11 \t10^-2\t+-10%%      \n");
    printf ("\n-----------------------------------------------\n");

}

float calcVal(){
    float fx1,fx2,fx3,fx4,calc,tolerancia,calcMenor,calcMaior;
//Receber valores das faixas
//Condi��o para receber o valor da faixa 1
    do {
        printf("\nDigite o c�digo da primeira faixa de cor: ");
        scanf("%f", &fx1);
    } while (fx1 != 0 && fx1 != 1 && fx1 != 2 && fx1 != 3 && fx1 != 4 && fx1 != 5 && fx1 != 6 && fx1 != 7 && fx1 != 8 && fx1 != 9);
//Condi��o para receber o valor da faixa 2
   do {
        printf("Digite o c�digo da segunda faixa de cor: ");
        scanf("%f", &fx2);
    } while (fx2 != 0 && fx2 != 1 && fx2 != 2 && fx2 != 3 && fx2 != 4 && fx2 != 5 && fx2 != 6 && fx2 != 7 && fx2 != 8 && fx2 != 9);

//Condi��o para receber o valor da faixa 3
    do {
        printf("Digite o c�digo da terceira faixa multiplicadora de cor: ");
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
    //Setando em pt-BR
    setlocale(LC_ALL, "Portuguese");
    //Declara��o de vari�veis
    float mostrar_instrucoes;
    //Mostra as boas vindas ao programa. Al�m, das cores e seus respectivos valores
    instrucoes();
    //Recebe os valores, calcula, valida e mostra seu resultado.
    calcVal();

    return 0;
}
