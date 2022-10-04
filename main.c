/*
==================================================================================

                    Calculadora de c�digos de cores para resistores

==================================================================================
Empresa: Espartana
Equipe de Programadores:
               Fabricio Razera;
               Gabriel de Oliveira Buchara;
               Gabriel Toshio;
               Nome do terceiro
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

int main()
{
    //Setando em pt-BR
    setlocale (LC_ALL, "Portuguese");
    //Declara��o de vari�veis
    float fx1,fx2,fx3,fx4,calc,calcMaior,calcMenor,tolerancia;
    //Mostrar os valores das faixas
    printf ("------------- Valores das Cores ---------------\n");
    printf ("\nPreto:         0      1        +-20%%      \n");
    printf ("Marrom:        1      10       +-1%%     \n");
    printf ("Vermelho:      2      10^2     +-2%%       \n");
    printf ("Laranja:       3      10^3     +-3%%       \n");
    printf ("Amarelo:       4      10^4     +-4%%       \n");
    printf ("Verde:         5      10^5            \n");
    printf ("Azul:          6                           \n");
    printf ("Violeta:       7                       \n");
    printf ("Cinza:         8                       \n");
    printf ("Branco:        9                       \n");
    printf ("Dourado:       10     10^-1    +-5%%      \n");
    printf ("Prateado:      11     10^-2    +-10%%      \n");
    printf ("-----------------------------------------------\n");
    //Receber valores das faixas
    printf("Digite o c�digo da primeira faixa de cor: ");
    scanf("%f", &fx1);
    printf("Digite o c�digo da segunda  faixa de cor: ");
    scanf("%f", &fx2);
    printf("Digite o c�digo da terceira faixa multiplicadora de cor: ");
    scanf("%f", &fx3);
    printf("Digite o c�digo da quarta faixa de cor (toler�ncia): ");
    scanf("%f", &fx4);
    //Condi��o while para receber o valor correto da quarta faixa de cor
    while (fx4 != 0 && fx4 != 1 && fx4 != 2 && fx4 != 3 && fx4 != 4 && fx4 != 10 && fx4 != 11){
        printf("Digite o c�digo da quarta faixa de cor (toler�ncia): ");
        scanf("%f", &fx4);
    }
    //Condi��es para o fx3 (Dourado e Prata)
    if (fx3 == 10){
        fx3 = -1;
    }
    else if (fx3 == 11){
        fx3 = -2 ;
    }
    //C�lculo da resist�ncia
    calc = ((fx1 * 10) + fx2) * (pow(10, fx3)); //fun��o pow() serve como um potencia. Ex: pow(10,fx3) = 10^fx3.

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

    //Mostrar valores
    printf("\nO valor da resist�ncia e da sua toler�ncia, respectivamente: %.2f ohms +/- %.2f%%. \n",calc,fx4);


    //C�lculo do valor da resist�ncia, tanto para menos quanto para mais (PROT�TIPO, EM TESTES)
 //   tolerancia = (calc * (fx4/100));
  //  calcMenor = (calc  - tolerancia);
  //  calcMaior = (calc + tolerancia);
    //
  //  printf("A sua toler�ncia ser� entre: %.2f e %.2f ohms. ",calcMenor,calcMaior);



    return 0;
}
