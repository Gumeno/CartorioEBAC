#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsavel por cuidar da string

int registro() //Função resposavel por cadastrar usuários no sistema 
{
	//Inicio da criações de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criações de variáveis/strings
	
	printf("Digite o CPF a ser registrado:"); // Coletando infomações de usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copia os valores das string
	
	FILE *file; //pedi para criar um arquivo 
	file = fopen(arquivo,"w");//cria um arquivo e a
	fprintf(file, cpf); //salva o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser registrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite sobrenome a ser registrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];

	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel localizar esse CPF.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as infomações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPf a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuario não encontrado no sistema!\n");
		system("pause");
		
	}
	
}


int  main()
{
	int opcao=0; //Definindo variaveis
	int laco=1; //Sistema de repetição
	
	for(laco=1; laco=1;)
	{
	
	   system("cls");
	
	   setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	   printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	   printf("Escolha a opção desejada do menu:\n\n");
	   printf("\t1 - Registrar \n");
	   printf("\t2 - Consultar \n");
	   printf("\t3 - Deletar \n\n"); // Fim do menu
	
	   scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	   system("cls");//Responsavel por limpar a tela
	   
	   switch(opcao)//Inicio do sistema de opções 
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
	   		
	   	default:
	   	printf("Essa opção não está disponivel!\n");
	   	system("pause");
	   	break;
	   	
	   }//Fim do sistema de opções

    }
}
