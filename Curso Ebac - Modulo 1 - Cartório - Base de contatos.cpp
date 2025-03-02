#include <stdio.h>  // biblioteca de comunicação com usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h>  //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicia criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string - salvar
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores da string 
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o w significa escrever
	fprintf(file,cpf);  //Salvo o valor da variavel
	fclose(file);
	
	file = fopen(arquivo, "a"); //arquivando valor 
	fprintf(file,","); //separando por , 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação nome
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação sobrenome
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação cargo
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta() //Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digiteo CPF a ser consultado: "); //coletando informação do usuário para consulta
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
	
	
}

int deletar() //Função responsável por deletar os usuários no sistema
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
}

int main()
	{
	int opcao=0; //Definindo Variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
     
    	system("cls"); //responsável por limpar a tela 
    
		setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	
		printf("### Base de Contatos ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Incluir Contato\n");
		printf("\t2 - Consultar Contato\n");
		printf("\t3 - Deletar Contato\n\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("opção: ");//Final do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela 
		
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamando funções
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
			printf("Essa opção não esta disponível !\n");
			system("pause");
			break;
			
		} //fim da seleção
	
		
	}
}
