#include <stdio.h>
#include <stdio.h> //biblioteca de comunica??o com o usu?rio
#include <stdlib.h> //biblioteca de aloca??o de espa?o em mem?ria
#include <locale.h> //biblioteca de aloca??es de texto por regi?o 
#include <string.h> //biblioteca responsavel por cuidar da string

int registro() //Fun??o resposavel por cadastrar usu?rios no sistema 
{
	//Inicio da cria??es de vari?veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria??es de vari?veis/strings
	
	printf("Digite o CPF a ser registrado:"); // Coletando infoma??es de usu?rio
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
		printf("N?o foi possivel localizar esse CPF.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s?o as infoma??es do usu?rio: ");
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
		printf("Usuario n?o encontrado no sistema!\n");
		system("pause");
		
	}
	
}


int  main()
{
	int opcao=0; //Definindo variaveis
	char senhadigital[10]; // criando variavel
	int laco=1; //Sistema de repeti??o
	
	 printf("### Cartório da EBAC ###\n\n");
    printf("Digite a sua senha para acessar o software: ");
    scanf("%s", senhadigital);

    if (strcmp(senhadigital, "12345") == 0) {
        while (1) {
            system("cls");
            setlocale(LC_ALL, "Portuguese");
	
	for(laco=1; laco=1;)
	{
	
	   system("cls");
	
	   setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	   printf("### Cart?rio da EBAC ###\n\n"); //Inicio do menu
	   printf("Escolha a op??o desejada do menu:\n\n");
	   printf("\t1 - Registrar \n");
	   printf("\t2 - Consultar \n");
	   printf("\t3 - Deletar \n"); 
	   printf("\t4 - Sair do sistema \n\n"); // Fim do menu
	
	   scanf("%d", &opcao); //Armazenando a escolha do usu?rio
	
	   system("cls");//Responsavel por limpar a tela
	   
	   switch(opcao)//Inicio do sistema de op??es 
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
		break;
			
	   	default:
	   	printf("Essa op??o n?o est? disponivel!\n");
	   	system("pause");
	   	break;
	   	
	           }//Fim do sistema de op??es
	   
            }  
         }
      }
	  else {
      printf("Senha incorreta!\n");
      }
      
      return 0;
      
}
