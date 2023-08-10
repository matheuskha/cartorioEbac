#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de textos por regi�o
#include <string.h>

int registro() //Responsavel por cadastrar o usu�rio
{
	 //�nicio da cria��o das vari�veis/strings
	 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	//Fim da cria��o das vari�veis/strings
	
	printf("digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das srings
	
	FILE * file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o w significa escrever (writer)
	fprintf(file,cpf); //Salvo o valor da vari�vel
	fclose(file); //Fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem 
		
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE * file;
    file = fopen(cpf, "r"); // o r significa ler (read)
    
    if(file == NULL)
    {
    	printf("\nN�mero de CPF n�o cadastrado. \n\n ");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
    
    system("pause");
    
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s", cpf);
	
	remove(cpf);
		
	FILE * file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nUsu�rio n�o se encontra no sistema!\n\n");
		system("pause");
	}	
	
	if(file != NULL)
	{
		printf("\nUsu�rio deletado com sucesso.\n\n");
	    system("pause");
	}
	
}


int main ()
{
	int opcao=0; //Definindo as vari�veis
	int x=1;
	
	for (x=1;x=1;)
	{
	
	system ("cls"); //Resppons�vel por limpar a tela
		
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem 
	
	  printf("\t\t\t\t\t\t||| Cart�rio da EBAC |||\n\n"); //in�cio do menu
	  printf("Escolha a op��o desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
  	  printf("\t3 - Deletar nomes\n" "\t4 - sair do sistema\n\n" " Digite a op��o desejada: \n "); //Fim do menu
	  scanf("%d", &opcao); //Armazenando a escolha do us�ario
	
	  system("cls");
        
	  switch(opcao) // �nicio da selee��o do menu
	  {
	  	case 1:
	  	registro(); // Chamada de fun��es
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por acessar o programa :)\n");
		return 0;
		break;
							
		default:
		printf("Esta op��o n�o est� dipon�vel!\n\n");
		system("pause");
		break;

		} //Fim da sele��o do menu

      }
}
