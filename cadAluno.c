#include "cadAluno.h"
int main(){
	int tamanho;

	printf("Informe a quantidade de alunos a ser cadastrados:\n");
	scanf("%d", &tamanho);

	menuPrincipal(tamanho);
	system("cls");

	return 0;
}

void menuPrincipal(int tam){
	 Usuario* p_listaUsuario = (Usuario*) malloc(tam*sizeof(Usuario));
	int op, x = 0; //op = opção

	do{
		system("cls");
		printf("\n+--------------INFORME UMA OPCAO--------------+");
		printf("\n+---------------------------------------------+");
		printf("\n|  (1) - CADASTRAR USUARIO                    |");
		printf("\n|  (2) - PESQUISAR SOBRENOME                  |");
		printf("\n|  (3) - PESQUISAR MES NASCIMENTO             |");
		printf("\n|  (4) - PESQUISAR ANO NASCIMENTO             |");
		printf("\n|  (5) - PESQUISAR MATRICULA                  |");
		printf("\n|  (0) - SAIR                                 |");
		printf("\n+---------------------------------------------+");

		printf("\n\nESCOLHA UMA OPCAO: ");
		scanf("%d", &op);
		fflush(stdin);

		switch(op){
			case 0 : break;
			case 1 :
                if(x < tam){
                    cadastroAluno(p_listaUsuario, x);
                    x++;
                }else{
                    printf("Lista de alunos cheia!");
                }
                break;
			case 2 :
				//pesquisarSobreNome (p_User,tam);
				break;
            case 3:
				//pesquisarMesNasc(p_User,tam);
				break;
			case 4:
				//pesquisarAnoNasc(p_User,tam);
				break;
			case 5:
				//pesquisarMatricula(p_User, tam);
				break;
			default:
				fflush(stdin);
				printf("\n\nOpcao invalida! Por favor, informe outra opcao\n\n ");
				break;

		}//fim switch
		system("pause");
	}while (op !=0);
    free(p_listaUsuario);
}

void cadastroAluno(Usuario* lista, int indice){
	Usuario user;
	int i, x, y,j;
	int verdadeiro;
	String str = new;

	printf("\n\n+-------------- CADASTRO --------------+");

		do{
			verdadeiro = 1;

			printf("\nInforme NOME e SOBRENOME do aluno:\n");
			fflush(stdin);
			gets(user.nome);
			//scanf("%s", &user->nome );
			//printf("%s", user->nome );

			verdadeiro = !camposVazios(user.nome);

			if(!verdadeiro){
				printf("\nAtencao! O nome deve ser preenchido\n");
			}

		}while(!verdadeiro);

		do {
			verdadeiro = 1;
			printf("\nInforme o endereco e numero (Separandos por virgula (,))\n");
			fflush(stdin);
			gets(user.endereco);

			if(camposVazios(user.endereco)) {
				printf("\nAtencao! O endereco deve ser preenchido!\n");
				verdadeiro = 0;
			}

			y = str.firstIndexOf(user.endereco, ',');

			if(y <= 0) {
				printf("\nAtencao! Endereco e numero devem ser separados por virgula\n");
				verdadeiro = 0;
			}


			}while(!verdadeiro);

		do{
			printf("\nInforme a DATA de NASCIMENTO do aluno:\n");
			fflush(stdin);
			gets(user.dtNasc);
			//printf("%s", user->dtNasc);
			x = validarData(user.dtNasc);
		} while (x==1);

		//gerar matricula
		y = str.lastIndexOf(user.nome, '\0');
		user.matricula[0] = user.nome[0];
		user.matricula[1] = user.nome[y-1];
		user.matricula[2] = user.dtNasc[6];
		user.matricula[3] = user.dtNasc[7];
		user.matricula[4] = user.dtNasc[8];
		user.matricula[5] = user.dtNasc[9];
		sprintf(user.matricula + 6, "%d", indice);

		printf("\n MATRICULA: %s", user.matricula);
}

int camposVazios(char *str) {
	int i = 0;
	char *auxiliar1;

	auxiliar1 = str;
		for(i = 0; *(auxiliar1) != '\0'; i++) {
		if(*(auxiliar1) != ' ') {
			//printf("%c", *auxiliar1);
			return 0;
		}
		auxiliar1++;
	}
	return 1;
}

int validarData (char *data){

	int dia, mes, ano;
    int i;
    char *data_aux;
    char *fimPonteiro;
    char *aux_mes;
    char * aux_ano;

	data_aux = data;

	if ((length(data_aux) != 10) || (equalsIgnoreCase(data_aux," ")) ==1){
	return 1;
	data_aux = data_aux+2;
 	 }

  else if ((equalsIgnoreCase(data,"/")) == 1){
  	printf("parou aqui 2 - equals /");
  return 1;
  data_aux = data;
  data_aux = data +5;
  }
  else if ((equalsIgnoreCase(data,"/")) ==1) {
	printf("parou aqui 3 - equals /");
  return 1;
  }

	data_aux = data;
	substring(data_aux,0,2);
	dia = strtol(data_aux, &fimPonteiro,10);

	aux_mes = substring(data_aux,3,4);
	mes = strtol(aux_mes, &fimPonteiro,10);

	aux_ano = substring(data_aux,6,10);
	ano = strtol(aux_ano, &fimPonteiro,10);

	if (dia < 0 || dia >31){
         return 1;
	}

	if ((mes < 0) ||(mes > 12)){
         return 1;
	}

	if (ano < 1900 || ano > 2016){
         return 1;
	}

	if ((dia >= 0 && dia <= 31) && (mes >= 0 && mes <= 12) && (ano >= 1900 && ano <= 2016)){
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)){
                return 1;
            }
            if (dia > 28 && mes == 2){
                return 1;
            }
            if ((dia > 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)){
                return 1;
            }
            if ((dia >31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)){
                return 1;
            }
            else
            {
                return 0;
            }
      }
 }


void pesquisarSobreNome (Usuario *user, int tam){
	Usuario *auxiliar;
	char sobrenome1 [100];
	char sobrenome2 [100];
	char sobrenomeInformado [100];
	int y, i;
	String str = new

	auxiliar = user;
	printf("\nInforme o SOBRENOME:\n");
	fflush(stdin);
	gets(sobrenomeInformado);

	y = str.lastIndexOf((*auxiliar).nome, ' ' );
	for (i=0; i< tam; i++){
		strcpy(sobrenome1, str.substring((*auxiliar).nome, (y + 1), length((*auxiliar).nome))) ;
		if (str.equalsIgnoreCase(sobrenome1,sobrenomeInformado)){

			printf("\n\n+-------------- RESULTADO PESQUISA --------------+");
			printf("\nNOME: %s",   (*auxiliar).nome);
			printf("\nENDERECO: %s",   (*auxiliar).endereco);
			printf("\nDATA NASCIMENTO: %s\n\n", (*auxiliar).dtNasc);
			printf("\n\n+-------------------------------------------------+\n\n");
		}else {
		printf("\n\nUsuario nao encontrado\n\n!");
		 auxiliar++;
		}

		}
	}

/*
char gerarMatricula(Usuario *user, int tam){
	Usuario *auxiliar;
	auxiliar = user;
	char *matricula [8];
	int i, y;
	String str = new;

	for(i = 0; i < tam; i++){
		y = str.lastIndexOf((*auxiliar).nome, '/0' - 1);
		matricula[0] = (*auxiliar).nome[0];
		matricula[1] = (*auxiliar).nome[y];
		matricula[2] = (*auxiliar).dtNasc[6];
		matricula[3] = (*auxiliar).dtNasc[7];
		matricula[4] = (*auxiliar).dtNasc[8];
		matricula[5] = (*auxiliar).dtNasc[9];
		matricula[6] = (*auxiliar).sequencial[0];
		auxiliar++;
		}
	return matricula;

}
*/

void pesquisarMesNasc (Usuario *user, int tam){
	Usuario *auxiliar;
	char mes[2];
	char mesBusca[2];
	int y, i;
	String str = new

	auxiliar = user;
	printf("\nInforme o MES DE NASCIMENTO: \n");
	fflush(stdin);
	gets(mesBusca);

	y = str.firstIndexOf((*auxiliar).dtNasc, '/' );
	for (i=0; i< tam; i++){
		strcpy(mes, str.substring((*auxiliar).dtNasc, (y + 1), (y + 3))) ;
		if (str.equals(mes,mesBusca)){

			printf("\nNOME: %s",   				(*auxiliar).nome);
			printf("\nENDERECO: %s",   			(*auxiliar).endereco);
			printf("\nDATA NASCIMENTO: %s\n\n", (*auxiliar).dtNasc);
		}else {
			printf("Usuario nao encontrado\n\n!");
		 auxiliar++;
		}

		}
	}

void pesquisarAnoNasc (Usuario *user, int tam){
	Usuario *auxiliar;
	char anoNasc[4];
	char anoNascBusca[4];
	int y, i;
	String str = new

	auxiliar = user;
	printf("\nInforme o ANO DE NASCIMENTO: \n");
	fflush(stdin);
	gets(anoNascBusca);

	y = str.lastIndexOf((*auxiliar).dtNasc, '/' );
	for (i=0; i< tam; i++){
		strcpy(anoNasc, str.substring((*auxiliar).dtNasc, (y + 1), length((*auxiliar).dtNasc))) ;
		if (str.equalsIgnoreCase(anoNasc,anoNascBusca)){

			printf("\nNOME: %s",   				(*auxiliar).nome);
			printf("\nENDERECO: %s",   			(*auxiliar).endereco);
			printf("\nDATA NASCIMENTO: %s\n\n", (*auxiliar).dtNasc);
		}else {
			printf("Usuario nao encontrado\n\n!");
		 auxiliar++;
		}

		}
	}

void pesquisarMatricula (Usuario *user, int tam){
	Usuario *auxiliar;
	char matBusca[8];
	char matricula[8];
	int i;
	String str = new

	auxiliar = user;
	printf("\nInforme a MATRICULA: \n");
	fflush(stdin);
	gets(matBusca);

	if (str.equals(matricula,matBusca)){

		printf("\nNOME: %s",   				(*auxiliar).nome);
		printf("\nENDERECO: %s",   			(*auxiliar).endereco);
		printf("\nDATA NASCIMENTO: %s\n\n",             (*auxiliar).dtNasc);
	}else {
		printf("Usuario nao encontrado!\n\n");
		auxiliar++;
	}
}
