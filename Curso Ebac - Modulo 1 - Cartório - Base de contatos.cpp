#include <stdio.h>  // biblioteca de comunica��o com usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicia cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string - salvar
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string 
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o w significa escrever
	fprintf(file,cpf);  //Salvo o valor da variavel
	fclose(file);
	
	file = fopen(arquivo, "a"); //arquivando valor 
	fprintf(file,","); //separando por , 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o nome
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o sobrenome
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o cargo
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
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
	int opcao=0; //Definindo Vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
     
    	system("cls"); //respons�vel por limpar a tela 
    
		setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	
		printf("### Base de Contatos ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Incluir Contato\n");
		printf("\t2 - Consultar Contato\n");
		printf("\t3 - Deletar Contato\n\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("op��o: ");//Final do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela 
		
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamando fun��es
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
			printf("Essa op��o n�o esta dispon�vel !\n");
			system("pause");
			break;
			
		} //fim da sele��o
	
		
	}
}
