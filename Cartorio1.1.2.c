#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel pelas strings

int registro()
{
	char arquivo[40]; char cpf[40]; char nome[40]; char sobrenome[40]; char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria arquivo
	file = fopen(arquivo, "w"); //cria arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser Cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("\npause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf ("Não foi possivel localizar o arquivo!.\n");
	}
	while(fgets(conteudo, 200, file) !=NULL);
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}


int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usuario não se encontra no sistema!.\n");
		system("pause");
	}
	
	remove(cpf);
	
	if(file != NULL)
	{
		printf("Usuario deletado com sucesso!\n");
		system("pause");
	}
}



int main()
{
	int opcao=0; //Definindo as Variaveis
    int laco=1;	

	for(laco=1;laco=1;)
	{
	
	    system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartório de EBAC ###\n\n"); //inicio do Menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n\n"); 
	    printf("\t4 - Fim do Programa\n\n"); //Fim do Menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuario
	
	    system("cls"); //responsavel por limpar a tela
	
	    switch(opcao) //inicio da selação de menu
	    
		{
	    	case 1:
	        registro(); //chamada de funçôes
	    	break;
	    	
	    	case 2:
	    	consulta();
	    	break;
	    		
	    	case 3:
	    	deletar();
	    	break;
	    	
	    	case 4:
	    	printf("Obrigado por ultilizar este programa!");
	    	return 0;
	    	break;
	    		
	    	default:
	    	printf("Essa opção não esta disponivel!\n");
	    	system("pause");
	    	break;
		}
    }

}
