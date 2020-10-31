/*
NOME: Eduardo Fernandes
CURSO: Análise e Desenvolvimento de Sistemas
DATA: 29/10/2020
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>

int main(void) {

  int opc, voltar, novo;
  opc = voltar = novo = 1;

  while (opc != 3 && voltar == 1) {
    system("clear");

    printf("\n            MENU DE OPCOES\n");
    printf("            ==============\n");
    printf("        [1]   VIABILIDADE DE COMPRA\n");
    printf("        [2]   DESCREVER EM UNIDADE, DEZENA, CENTENA\n");
    printf("        [3]   SAIR\n\n");
    printf("Escolha o numero de uma das opcoes acima...: ");
    scanf("%d", & opc);
    while (opc < 1 || opc > 3) {
      printf("Opcao invalida, por favor, digite novamente ..: ");
      scanf("%d", & opc);
    }

    //PRIMEIRA OPÇÃO
    if (opc == 1) {
      novo = 1;

      int mes, novo, lojas;
      float valorpago, parcela, jurosaa, jurosam, valorquitado, jurospago, jurostotal;
      valorpago = jurosaa = jurosam = jurospago = valorquitado = jurostotal = 0;
      mes = novo = 1;
      parcela = lojas = 0;

      while (novo == 1) {
        lojas++;
        system("clear");
        printf("\nValor do aparelho .....: ");
        fflush(stdin);
        scanf("%f", & valorpago);

        printf("Valor da prestacao ....: ");
        fflush(stdin);
        scanf("%f", & parcela);

        printf("Valor do juros anual (Ex.: 18) ..: ");
        fflush(stdin);
        scanf("%f", & jurosaa);

        jurosaa = jurosaa / 100.00;
        jurosam = jurosaa / 12.00;
        jurospago = valorpago * jurosam;
        valorquitado = parcela - valorpago * jurosam;

        printf("\n\nMes %d > Saldo devedor | R$ %.2f | parcela = R$ %.2f | juros = R$ %.2f | valor quitado = R$ %.2f", mes, valorpago, parcela, jurospago, valorquitado);
        jurostotal = jurostotal + jurospago;

        while (valorpago > parcela) {
          mes++;
          valorpago = valorpago - valorquitado;
          jurospago = valorpago * jurosam;
          valorquitado = parcela - valorpago * jurosam;
          jurostotal = jurostotal + jurospago;

          printf("\n\nMes %d > Saldo devedor = R$ %.2f | parcela = R$ %.2f | juros = R$ %.2f | valor quitado = R$ %.2f", mes, valorpago, parcela, jurospago, valorquitado);
        }

        printf("\n\n\nVoce levara %d meses para pagar o produto, pagando R$ %.2f de juros.", mes, jurostotal);
        if (lojas == 1)
          printf("\nVoce pesquisou em %d loja.", lojas);
        else
          printf("\nVoce pesquisou em %d lojas.", lojas);
        mes = 1;
        printf("\n\nDeseja refazer essa opcao?\n");
        printf("[1] Sim - [2] Nao ...: ");
        fflush(stdin);
        scanf("%d", & novo);
        while (novo < 1 || novo > 2) {
          printf("\nResposta Invalida\nDeseja refazer a opcao 1?\n");
          printf("[1] Sim - [2] Nao ...: ");
          fflush(stdin);
          scanf("%d", & novo);
        }
      }

      printf("\nDeseja voltar ao menu?\n");
      printf("[1] Voltar - [2] Finalizar ...: ");
      scanf("%d", & voltar);
      while (voltar < 1 || voltar > 2) {
        printf("Opcao invalida, por favor, digite novamente ..: ");
        scanf("%d", & voltar);
      }
    }

    //SEGUNDA OPÇÃO
    if (opc == 2) {
      novo = 1;

      while (novo == 1) {
        int valor, cent, dez, uni, cont, cont_total, cent_total, dez_total, valorfixo;
        valor = cent = dez = uni = cent_total = dez_total = valorfixo = cont = cont_total = 0;

        system("clear");
        printf("\n\n        CONTADOR DE CASAS\n");
        printf("        =================\n\n");
        printf("Digite um valor entre 0 e 1000 ..: ");
        fflush(stdin);
        scanf("%d", & valor);

        valorfixo = valor;
        while (cont_total <= valor) {
          cont_total++;
          cont++;
          while (cont == 100) {
            cent = cent + 1;
            cont = 0;
          }
        }

        cent_total = cent * 100;
        valor = valor - cent_total;
        cont_total = 0;
        cont = 0;

        while (cont_total <= valor) {
          cont_total++;
          cont++;
          while (cont == 10) {
            dez = dez + 1;
            cont = 0;
          }
        }

        dez_total = dez * 10;
        valor = valor - dez_total;
        cont_total = 0;
        cont = 0;

        while (cont_total < valor) {
          cont_total++;
          cont++;
          while (cont == 1) {
            uni = uni + 1;
            cont = 0;
          }
        }

        if (valorfixo != 0) {
          printf("\n\n%d = ", valorfixo);

          if (cent > 1 && cent != 0)
            printf("%d centenas", cent);
          else {
            if (cent == 1) {
              printf("%d centena", cent);
            }
          }

          if (cent > 0 && (dez > 0 || uni > 0))
            printf(", ");

          if (dez > 1 && dez != 0)
            printf("%d dezenas", dez);
          else {
            if (dez == 1) {
              printf("%d dezena", dez);
            }
          }

          if (dez > 0 && uni > 0)
            printf(", ");

          if (uni > 1 && uni != 0)
            printf("%d unidades", uni);
          else {
            if (uni == 1) {
              printf("%d unidade", uni);
            }
          }
        }

        printf("\n\nDeseja refazer essa opcao?\n");
        printf("[1] Sim - [2] Nao ...: ");
        fflush(stdin);
        scanf("%d", & novo);
        while (novo < 1 || novo > 2) {
          printf("\nResposta Invalida\nDeseja refazer a opcao 1?\n");
          printf("[1] Sim - [2] Nao ...: ");
          fflush(stdin);
          scanf("%d", & novo);
        }
      }

      printf("\n\nDeseja voltar ao menu?\n");
      printf("[1] Voltar - [2] Finalizar ...: ");
      scanf("%d", & voltar);
      while (voltar < 1 || voltar > 2) {
        printf("Opcao invalida, por favor, digite novamente ..: ");
        scanf("%d", & voltar);
      }
    }

  }
  printf("\n\nPrograma finalizado com sucesso.\nFeito por Eduardo Fernandes Silva\n\n");
  return 0;
}