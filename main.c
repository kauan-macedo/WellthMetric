#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para limpar o buffer de entrada
void limpar_buffer()
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main(void)
{
    char nome[50];
    float peso;
    float altura;
    float imc;
    int tentativas = 0;
    char continuar;

    do
    {
        // Pergunta as informações do usuário e valida
        do
        {
            if (tentativas > 0)
            {
                printf("Seu nome não está correto\n\n");
            }
            printf("Caro usuário, qual é o seu nome?\n");
            scanf(" %[^\n]%*c", nome);
            printf("\n");
            tentativas++;
        } while ((strlen(nome) <= 2) || (strlen(nome) > 50));

        tentativas = 0;

        do
        {
            if (tentativas > 0)
            {
                printf("Peso inválido\n\n");
            }
            printf("Digite seu peso em Kg\n");
            scanf("%f", &peso);
            printf("\n");
            tentativas++;
        } while ((peso <= 0) || (peso >= 640));

        tentativas = 0;
        limpar_buffer();

        do
        {
            if (tentativas > 0)
            {
                printf("Altura inválida\n\n");
            }
            printf("Digite sua altura em metros\n");
            scanf("%f", &altura);
            printf("\n");
            tentativas++;
        } while ((altura <= 0) || (altura >= 2.60));

        tentativas = 0;
        limpar_buffer();

        // Exibe o IMC do usuário e informações adicionais com base nos padrões da OMS
        printf("\n=== Seu Resultado ===\n");
        imc = (peso / (altura * altura));
        printf("%s, seu IMC é %.1f,", nome, imc);

        if (imc < 18.5)
        {
            printf(" você está abaixo do peso\n");
        }
        else if (imc <= 24.9)
        {
            printf(" você está no peso ideal\n");
        }
        else if (imc <= 29.9)
        {
            printf(" você está com sobrepeso\n");
        }
        else if (imc <= 39.9)
        {
            printf(" você está com obesidade\n");
        }
        else
        {
            printf(" você está com obesidade grave\n\n");
        }

        // Pergunta ao usuário se ele quer continuar calculando
        do
        {
            if ((tentativas > 0))
            {
                printf("\nOpção inválida\n");
            }
            printf("\nDeseja continuar calculando? Responda com \"S\" ou \"N\"\n");
            scanf(" %c", &continuar);
            printf("\n");
            continuar = toupper(continuar);
            tentativas++;
        } while ((continuar != 'S') && (continuar != 'N'));
        tentativas = 0;
        limpar_buffer();
    } while (continuar == 'S');
    return 0;
}