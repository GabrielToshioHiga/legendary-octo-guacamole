/*
==================================================================================

                    Calculadora de códigos de cores para resistores

==================================================================================
Empresa: Espartana
Equipe de Programadores:
               Gabriel de Oliveira Buchara;
               Gabriel Toshio;
               Nome do terceiro
               Rafael Vieira Rodrigues.
Curso: Tecnologia em Análise e Desenvolvimento de Sistemas
Data de início do projeto: 03/10/2022
----------------------------------------------------------------------------------
Descrição do Programa:
		O programa têm o objetivo de ajudar na realização do cálculo
        da resistência elétrica, por meio do uso de código de cores de 4 faixas.
        O usuário deverá informar as cores das 4 faixas do resistor. Com isso, o
        programa irá informar qual será o valor da resistência e da sua tolerância,
        todos com a unidade de medida em Ohms.

Versão do programa: 1.0
Melhorias da versão: Primeira versão.
Data de lançamento da versão: 11/10/2022
==================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //biblioteca caracteres especiais

int main()
{
    //Setando em pt-BR
    setlocale (LC_ALL, "Portuguese");
    //Declaração de variáveis
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
    printf("Digite o código da primeira faixa de cor: ");
    scanf("%f", &fx1);
    printf("Digite o código da segunda  faixa de cor: ");
    scanf("%f", &fx2);
    printf("Digite o código da terceira faixa multiplicadora de cor: ");
    scanf("%f", &fx3);
    printf("Digite o código da quarta faixa de cor (tolerância): ");
    scanf("%f", &fx4);
    //Condição while para receber o valor correto da quarta faixa de cor
    while (fx4 != 0 && fx4 != 1 && fx4 != 2 && fx4 != 3 && fx4 != 4 && fx4 != 10 && fx4 != 11){
        printf("Digite o código da quarta faixa de cor (tolerância): ");
        scanf("%f", &fx4);
    }
    //Condições para o fx3 (Dourado e Prata)
    if (fx3 == 10){
        fx3 = -1;
    }
    else if (fx3 == 11){
        fx3 = -2 ;
    }
    //Cálculo da resistência
    calc = ((fx1 * 10) + fx2) * (pow(10, fx3)); //função pow() serve como um potencia. Ex: pow(10,fx3) = 10^fx3.

    //Condições para o fx4 (Dourado, Prateado e Preto)
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
    printf("\nO valor da resistência e da sua tolerância, respectivamente: %.2f ohms +/- %.2f%%. \n",calc,fx4);


    //Cálculo do valor da resistÊncia, tanto para menos quanto para mais (PROTÓTIPO, EM TESTES)
 //   tolerancia = (calc * (fx4/100));
  //  calcMenor = (calc  - tolerancia);
  //  calcMaior = (calc + tolerancia);
    //
  //  printf("A sua tolerância será entre: %.2f e %.2f ohms. ",calcMenor,calcMaior);



    return 0;
}
