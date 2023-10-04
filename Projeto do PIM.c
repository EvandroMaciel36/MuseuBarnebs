#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

int calcularIdade() {
    char dataNascimento[11]; // armazena a data de nascimento

    printf("Qual é a sua data de nascimento (dd/mm/yyyy)? ");
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

int main() {
    char nome[100]; // aqui eu defini como char o nome, para armazenar como string
    setlocale(LC_ALL, ""); // precisamos ajustar isso, não está funcionando

    printf("Olá! Você está no site do Museu da Barnebs Inc.\nPara dar continuidade no seu atendimento, precisamos de algumas informações\n");
    printf("Por favor, nos informe seu nome:\n");
    scanf("%s", nome);
    printf("Olá, %s! Seja bem-vindo!\n", nome);

    int idade = calcularIdade();

    char resposta[10];
    printf("Você é professor ou aluno? (Digite 'professor' ou 'aluno'): ");
    scanf("%s", resposta);
                                     /*nessa parte, eu estava esperando que
                                     o codigo pegasse a idade e se fosse maior que 65, ele pulasse direto para o
                                     retun. Mas ele pergunta se a pessoa é aluno ou professor e depois retorna se a pessoa
                                     é idosa. precisamos ajustar (ou não)*/
    if (idade >= 65) {
        printf("Você ganhou 50%% de desconto!\n");
        printf("Sua idade é: %d anos\n", idade);
    } else if ((strcmp(resposta, "professor") == 0 || strcmp(resposta, "aluno") == 0)) {
        printf("Você tem direito à meia-entrada com 50%% de desconto.\n");
    } else {
        printf("Você não se encaixa na categoria de meia-entrada.\n");
    }
    return 0;
}
