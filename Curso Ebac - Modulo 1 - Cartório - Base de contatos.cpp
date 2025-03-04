#include <stdio.h>  // biblioteca de comunica��o com usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() {
    // Inicia cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Fim da cria��o de vari�veis/string

    while (1) { // Inicia um loop que vai continuar at� o usu�rio escolher sair
        system("cls"); // Limpa a tela antes de iniciar um novo registro (Windows)
        // system("clear"); // Use esta linha se estiver em Linux/macOS
        printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
        scanf("%s", cpf); // %s refere-se a string - salvar

        strcpy(arquivo, cpf); // Respons�vel por copiar os valores da string

        FILE *file; // Cria o arquivo
        file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
        fprintf(file, cpf);  // Salva o valor da vari�vel
        fclose(file);

        file = fopen(arquivo, "a"); // Arquivando valor
        fprintf(file, ","); // Separando por v�rgula
        fclose(file);

        printf("Digite o nome a ser cadastrado: "); // Coletando informa��o nome
        scanf("%s", nome);

        file = fopen(arquivo, "a");
        fprintf(file, nome);
        fclose(file);

        file = fopen(arquivo, "a");
        fprintf(file, ",");
        fclose(file);

        printf("Digite o sobrenome a ser cadastrado: "); // Coletando informa��o sobrenome
        scanf("%s", sobrenome);

        file = fopen(arquivo, "a");
        fprintf(file, sobrenome);
        fclose(file);

        file = fopen(arquivo, "a");
        fprintf(file, ",");
        fclose(file);

        printf("Digite o cargo a ser cadastrado: "); // Coletando informa��o cargo
        scanf("%s", cargo);

        file = fopen(arquivo, "a");
        fprintf(file, cargo);
        fclose(file);

        system("pause");

        // Pergunta ap�s o cadastro completo
        int opcao;
        printf("\nDeseja cadastrar outro usuario?\n");
        printf("1 - Sim\n");
        printf("2 - Voltar para o menu principal\n");
        printf("Digite a op��o: ");
        scanf("%d", &opcao);

        if (opcao == 2) {
            break; // Sai do loop, voltando para o menu principal
        }
    }

    return 0;
}

int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digiteo CPF a ser consultado: "); //coletando informa��o do usu�rio para consulta
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
	
	
}

int deletar() //Fun��o respons�vel por deletar os usu�rios no sistema
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
}

int main()
{
    int opcao = 0;
    int x = 1;
    char senhadigitada[20]; // Tamanho suficiente para evitar problemas

    setlocale(LC_ALL, "portuguese");

    printf("### Cart�rio da EBAC ###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);

    // Compara��o correta de strings
    if (strcmp(senhadigitada, "admin") == 0)
    {
        while (x == 1) // Corrigindo a estrutura de repeti��o
        {
            system("cls"); // Limpa a tela

            printf("### Base de Contatos ###\n\n");
            printf("Escolha a op��o desejada no menu:\n\n");
            printf("\t1 - Incluir Contato\n");
            printf("\t2 - Consultar Contato\n");
            printf("\t3 - Deletar Contato\n\n");
            printf("\t4 - Sair do sistema\n\n");
            printf("Op��o: ");

            scanf("%d", &opcao);

            system("cls");

            switch (opcao)
            {
                case 1:
                    registro();
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
                default:
                    printf("Essa op��o n�o est� dispon�vel!\n");
                    system("pause");
                    break;
            }
        }
    }
    else
    {
        printf("Senha incorreta! Acesso negado.\n");
    }

    return 0;
}
