#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsável por cuidar da string

int registro() {
	setlocale(LC_ALL, "Portuguese"); //Definindo Idioma
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];

	printf("Digite o CPF a ser cadastrado:\n");
	scanf("%s", cpf);

	strcpy(arquivo, cpf); //Valores das strings

	FILE *file;// cria o arquivo
	file = fopen(cpf, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo

	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o nome a ser cadastrado:\n");
	scanf("%s",nome);

	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o sobrenome:\n");
	scanf("%s",sobrenome);

	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);




	int cargo=0;
	printf("\t1 - Aluno\n");
	printf("\t2 - Colaborador\n");
	printf("Escolha o Cargo");

	scanf("%d", &cargo);

	switch(cargo) {

		case 1:
			file = fopen(arquivo,"a");
			fprintf(file,"Aluno");
			fclose(file);
			system("pause");
			break;

		case 2:
			file = fopen(arquivo, "a");
			fprintf(file,"Colaborador");
			fclose(file);
			system("pause");
			break;

		default:
			printf("Escolha uma das Opcões Disponiveis\n");
			system("pause");
			system("cls");
			break;
			return 1;
	}

}

int consulta() {
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	char cpf[40];
	char conteudo[100];

	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r");

	if(file == NULL) {
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}

	while(fgets(conteudo, 100, file) != NULL) {
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system ("pause");
}
int deletar()  {
char cpf[40];

printf("Digite o CPF para ser deletado: \n");
scanf("%s", cpf);

remove(cpf);

FILE *file;
file = fopen(cpf,"r");
if(file == NULL) {
	printf("Usuário náo localizado! . \n");
	system("pause");
}

}




int main() {
	int opcao=0; //Definindo variáveis
	int x=1;

	for(x=1; x=1;) {

		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo Idioma
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a Opção Desejada do Menu: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("Opcão:\n"); //fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usuário

		system("cls");

		switch(opcao) {
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
				printf("Essa Opcao não Está Disponivel\n");
				system("pause");
				break; //fim da selecão
		}



	}








}
