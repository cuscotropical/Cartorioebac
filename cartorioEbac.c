#include <stdio.h> //biblioteca de comunicacao com usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //funcao responsavel por cadastrar os usuarios no sistema
{
    //inicio criacao de variaveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criacao de variaveis/string

    printf("Digite o Cpf a ser cadastrado: "); //coletando informacao do usuario
    scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf); //responsavel por copiar os valores das string

    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o w seguinifica escrever
    fprintf(file, cpf); //salva o valor da variavel
    fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file); //fecha o arquvio

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file); //fecha o arquivo

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome); //%s refere-se a string

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a"); //cria o arquivo
    fprintf(file, cargo);
    fclose(file); //fecha o arquivo

    system("pause");

}
int consulta() //funcao responsavel por consultar no sistema
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

    char cpf[40];
    char conteudo[200];

    printf("Digite o Cpf a ser consultado: ");
    scanf("%s", cpf);

    FILE *file; //cria o arquivo
    file = fopen(cpf, "r"); //o r significa ler

    if(file ==NULL)
    {
        printf("Nao foi possivel abrir o arquivo, nao localizado! \n");
    }

    while(fgets(conteudo, 200, file) != NULL);
    {
        printf("\nEssas sao as informacoes do usuario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}
int deletar() //funcao responsavel por deletar no sistema
{
    char cpf[40];

    printf("Digite o CPF do usuario a ser deletado: ");
    scanf("%s", cpf); //%s refere-se a string

    remove(cpf);

    FILE *file; //cria o arquivo
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("Usuario nao encontrado no sistema!.\n");
        system("pause");
    }
}
int main ()
{
    int opcao=0;
    int laco=1;
    for(laco=1;laco=1;)
    {
        system("cls");
        setlocale (LC_ALL, "Portuguese");
        printf ("###Cartório da EBAC###\n\n");
        printf ("Escolha a opcao desejada do menu: \n\n");  // (\t) responsavel por este espaco
        printf ("\t1 - Registrar nomes \n");
        printf ("\t2 - Consultar nomes \n");
        printf ("\t3 - Deletar nomes \n");
        printf ("\t4 - Sair do sistema \n\n");
        printf("Opcao: "); //fim do menu
        scanf("%d", &opcao); //armazenando a escolha do usuario

        system("cls"); //responsavel por limpar a tela

        switch (opcao) //inicio da selecao do menu
        {
            case 1:
                registro(); //chamada de funcoes
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;

            case 4:
                printf("Obrigado por utilizar o sistema!\n");
                return 0;
                break;

            default:
                printf("essa opcao nao esta disponivel\n");
                system("pause");
                break;
        } //fim da selecao

    }
}
