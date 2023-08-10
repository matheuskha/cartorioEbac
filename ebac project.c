#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de textos por região
#include <string.h>

int registro() //Responsavel por cadastrar o usuário
{
	 //Ínicio da criação das variáveis/strings
	 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	//Fim da criação das variáveis/strings
	
	printf("digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das srings
	
	FILE * file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o w significa escrever (writer)
	fprintf(file,cpf); //Salvo o valor da variável
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
    	printf("\nNúmero de CPF não cadastrado. \n\n ");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("\nUsuário não se encontra no sistema!\n\n");
		system("pause");
	}	
	
	if(file != NULL)
	{
		printf("\nUsuário deletado com sucesso.\n\n");
	    system("pause");
	}
	
}


int main ()
{
	int opcao=0; //Definindo as variáveis
	int x=1;
	
	for (x=1;x=1;)
	{
	
	system ("cls"); //Respponsável por limpar a tela
		
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem 
	
	  printf("\t\t\t\t\t\t||| Cartório da EBAC |||\n\n"); //início do menu
	  printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
  	  printf("\t3 - Deletar nomes\n" "\t4 - sair do sistema\n\n" " Digite a opção desejada: \n "); //Fim do menu
	  scanf("%d", &opcao); //Armazenando a escolha do usúario
	
	  system("cls");
        
	  switch(opcao) // ínicio da seleeção do menu
	  {
	  	case 1:
	  	registro(); // Chamada de funções
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
		printf("Esta opção não está diponível!\n\n");
		system("pause");
		break;

		} //Fim da seleção do menu

      }
}
