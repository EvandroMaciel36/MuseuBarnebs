#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int calcularIdade() {
    char dataNascimento[11]; // armazena a data de nascimento

    printf("\nQual é a sua data de nascimento (dd/mm/yyyy)?\n");
    scanf("%s", dataNascimento);

    // data atual
    time_t t;
    struct tm* infoTempo;
    time(&t);
    infoTempo = localtime(&t);

    // Pega a data do nascimento
    int diaNascimento, mesNascimento, anoNascimento;
    sscanf(dataNascimento, "%d/%d/%d", &diaNascimento, &mesNascimento, &anoNascimento);

    // Calcula a idade
    int idade = infoTempo->tm_year + 1900 - anoNascimento;

    return idade;
}
int calcularIngresso() {
    int ingresso, quantidade;
        printf("\nPara entrar no Museu, é necessario comprar um ingresso.\n");
        printf("\nO valor da entrada é de R$62 reais.\n");
        printf("\nCaso você faça parte do grupo a seguir, você recebe 50%% de desconto no ingresso.\nO grupo que garante a meia-entrada são: Alunos, Professores ou PCDs.\n");
       char resposta[5];
             printf("\nVocê faz parte do grupo da meia-entrada? (s ou n)\n");
                scanf("%s", &resposta);
          if (strcmp(resposta, "s") == 0){
          printf("\nVocê tem direito à meia-entrada com 50%% de desconto!\n");
           ingresso = 31;
            } else {
                printf("\nVocê não tem direito a meia-entrada.\n");
           ingresso = 62;
            }
            printf("\nPor favor, quantos ingressos você quer comprar?\n");
                scanf("%d", &quantidade);

    ingresso = ingresso * quantidade;
            printf("\nO valor total dos seus ingressos é de: R$%d reais\n", ingresso);


  char pagamento[3];
  int senha;

    printf("\nAgora, iremos seguir para a finalização do pedido.");
    printf("\nNós aceitamos os métodos de pagamento em cartão de crédito, cartão de débito e dinheiro.\n");
    printf("\nPara pagar com cartão de crédito, digite C;\nPara pagar com cartão de débito, digite E;\nPara pagar dinheiro, digite D.\n");

    while (1) {
        printf("\nQual seria a forma de pagamento?\n");
        scanf("%s", pagamento);

        for (int i = 0; pagamento[i]; i++) {
            pagamento[i] = tolower(pagamento[i]);
        }

        if (strcmp(pagamento, "c") == 0) {
            printf("Digite a senha: ");
            scanf("%d", &senha);
            printf("\nCompra concluída!\n");
            break; // Sai do loop quando "c" é inserido.
        } else if (strcmp(pagamento, "e") == 0) {
            printf("Digite a senha: ");
            scanf("%d", &senha);
            printf("\nCompra concluída!\n");
            break; // Sai do loop quando "e" é inserido.
        } else if (strcmp(pagamento, "d") == 0) {
            printf("\nConferindo valor recebido...");
            printf("\nCompra concluída!\n");
            break; // Sai do loop quando "d" é inserido.
        } else {
            printf("\nMétodo de pagamento não reconhecido.\nPor favor, tente novamente.\n");
        }
    }

    printf("\nAbaixo estão os numeros de identificação de cada ingresso.\n");

     srand(time(NULL));
        int ticket = rand() % 200 + 1;
    for (int i = 1; i <= quantidade; i++) {
        int ticket = rand() % 200 + 1;
        printf("\nIngresso %d Numero de identificação: #%d", i, ticket);
                    }
}
int main(){
    char nome[30]; // aqui eu defini como char o nome, para armazenar como string
    setlocale(LC_ALL, ""); // precisamos ajustar isso, não está funcionando*******

    printf("Você está visitando o Museu da Barnebs.\nPara dar continuidade no seu atendimento, precisamos de algumas informações.\n");
    printf("_________________________________________________________________\n");
    printf("\nPor favor, nos informe seu nome:\n\n");
    scanf("%s", nome);
    printf("\nOlá, %s! Seja bem-vindo(a)!\n", nome);

    calcularIdade(); //chama a função calcularIdade
    printf("_________________________________________________________________\n");
    calcularIngresso(); //chama a função calcularIngresso
    printf("\n_________________________________________________________________\n");
    return 0;
}
