//importacao das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Operador
{
    char ID[5];
    char nome[71];
    char setor[5];
    int Nivel_Operacional;
    int Status;
    int QOR;
} opr;

typedef struct Equipamento
{
    char ID[4];
    char tipo[30];
    char setor[5];
    int estado_operacional;
    char ID_operador[5];
    int nivel_prioridade;
} eqp;

opr operadores[50];
eqp equipamentos[150];

int totalOperadores = 0;
int totalEquipamentos = 0;

void ler_id()
{
    int valido = 0; // Flag para controlar o loop

    do
    {
        // Lendo a entrada do usuário
        fgets(operadores[totalOperadores].ID, 5, stdin);
        
        // Remove o '\n' caso o usuário tenha digitado menos de 4 caracteres
        operadores[totalOperadores].ID[strcspn(operadores[totalOperadores].ID, "\n")] = '\0';

        // 1ª Validação: Verificar o tamanho exato de 4 caracteres
        if (strlen(operadores[totalOperadores].ID) != 4)
        {
            printf("\n\tID invalido! Deve conter exatamente 4 digitos.");
            printf("\n\tDigite novamente: ");
            
            // Limpa o buffer caso o usuário tenha digitado MAIS de 4 caracteres
            // Isso evita que o excesso de texto saia atropelando as próximas leituras
            while (getchar() != '\n'); 
            
            continue; // Volta para o início do loop
        }

        // 2ª Validação: Verificar se todos os caracteres são dígitos numéricos
        int apenas_digitos = 1;
        for (int i = 0; i < 4; i++)
        {
            if (!isdigit(operadores[totalOperadores].ID[i]))
            {
                apenas_digitos = 0;
                break;
            }
        }

        if (!apenas_digitos)
        {
            printf("\n\tID invalido! Deve conter apenas digitos.");
            printf("\n\tDigite novamente: ");
            continue; // Volta para o início do loop
        }

        while (getchar() != '\n');

        // Se passou por todas as validações, o ID é válido e podemos sair do loop
        valido = 1;

    } while (!valido);
}

void ler_nome()
{
    int valido = 0;

    do
    {
        // Lendo o nome (limite de 70 caracteres definido na struct)
        fgets(operadores[totalOperadores].nome, 71, stdin);
        
        // Remove o '\n' do final da string
        operadores[totalOperadores].nome[strcspn(operadores[totalOperadores].nome, "\n")] = '\0';

        // 1ª Validação: Verificar se o nome está vazio
        if (strlen(operadores[totalOperadores].nome) == 0)
        {
            printf("\n\tNome invalido! O nome nao pode estar vazio.");
            printf("\n\tDigite novamente: ");
            continue; // Volta para o início do loop
        }

        // 2ª Validação: Verificar se o primeiro caractere é um espaço
        if (operadores[totalOperadores].nome[0] == ' ')
        {
            printf("\n\tNome invalido! O nome nao pode comecar com um espaco.");
            printf("\n\tDigite novamente: ");
            continue;
        }

        // 3ª Validação: Verificar se contém apenas letras e espaços
        int apenas_letras = 1;
        for (int i = 0; i < strlen(operadores[totalOperadores].nome); i++)
        {
            char c = operadores[totalOperadores].nome[i];
            
            // isalpha(c) verifica se é letra, c == ' ' permite o espaço entre nomes
            // Nota: isalpha pode falhar com acentos dependendo do sistema, mas protege contra números/símbolos
            if (!isalpha(c) && c != ' ')
            {
                apenas_letras = 0;
                break;
            }
        }

        if (!apenas_letras)
        {
            printf("\n\tNome invalido! O nome deve conter apenas letras e espaços.");
            printf("\n\tDigite novamente: ");
            continue;
        }

        // Se passou por todas as travas, o nome é aceito
        valido = 1;

    } while (!valido);
}

void ler_setor()
{
    int valido = 0;

    do
    {
        // Lendo a entrada (limite de 5 garante espaço para 4 caracteres + \0)
        fgets(operadores[totalOperadores].setor, 5, stdin);
        
        // Remove o '\n' caso o usuário tenha digitado menos de 4 caracteres
        operadores[totalOperadores].setor[strcspn(operadores[totalOperadores].setor, "\n")] = '\0';

        // 1ª Validação: Verificar o tamanho exato de 4 caracteres
        if (strlen(operadores[totalOperadores].setor) != 4)
        {
            printf("\n\tSetor invalido! Deve conter exatamente 4 caracteres.");
            printf("\n\tDigite novamente: ");
            
            // Limpa o buffer caso o usuário tenha digitado MAIS de 4 caracteres
            while (getchar() != '\n'); 
            
            continue; // Volta para o início do loop
        }

        // 2ª Validação: Verificar o formato (2 letras seguidas de 2 dígitos)
        // Índice 0 e 1 -> Devem ser letras (isalpha)
        // Índice 2 e 3 -> Devem ser dígitos (isdigit)
        if (!isalpha(operadores[totalOperadores].setor[0]) ||
            !isalpha(operadores[totalOperadores].setor[1]) ||
            !isdigit(operadores[totalOperadores].setor[2]) ||
            !isdigit(operadores[totalOperadores].setor[3]))
        {
            printf("\n\tSetor invalido! Deve ser composto por 2 letras e 2 digitos (Ex: AB12).");
            printf("\n\tDigite novamente: ");
            continue; // Volta para o início do loop
        }

        // Converte as duas primeiras letras para maiúsculo automaticamente
        operadores[totalOperadores].setor[0] = toupper(operadores[totalOperadores].setor[0]);
        operadores[totalOperadores].setor[1] = toupper(operadores[totalOperadores].setor[1]);

        while (getchar() != '\n');

        // Se passou pelas validações, o setor é válido
        valido = 1;

    } while (!valido);
}

void ler_nivel()
{
    int valido = 0;
    int nvl;

    do
    {
        // Tenta ler o número inteiro
        nvl = scanf("%d", &operadores[totalOperadores].Nivel_Operacional);
        
        // Limpa o buffer de entrada (remove o '\n' ou qualquer letra que sobrou)
        while (getchar() != '\n');

        // 1ª Validação: O usuário digitou letras/símbolos em vez de número?
        if (nvl != 1)
        {
            printf("\n\tEntrada invalida! Digite apenas numeros.");
            printf("\n\tNivel Operacional (1-Basico, 2-Intermediario, 3-Supervisor): ");
            continue; // Volta para o início do loop
        }

        // 2ª Validação: O número está dentro do intervalo correto (1 a 3)?
        if (operadores[totalOperadores].Nivel_Operacional < 1 || 
            operadores[totalOperadores].Nivel_Operacional > 3)
        {
            printf("\n\tOpcao invalida! Escolha entre 1, 2 ou 3.");
            printf("\n\tNivel Operacional (1-Basico, 2-Intermediario, 3-Supervisor): ");
            continue; // Volta para o início do loop
        }

        // Se passou por ambos, a entrada é válida
        valido = 1;

    } while (!valido);
}

void ler_status()
{
    int valido = 0;
    int stt;

    do
    {
        // Tenta ler o número inteiro para o Status
        stt = scanf("%d", &operadores[totalOperadores].Status);
        
        // Limpa o buffer de entrada (remove o '\n' ou qualquer caractere inválido)
        while (getchar() != '\n');

        // 1ª Validação: O usuário digitou letras/símbolos em vez de número?
        if (stt != 1)
        {
            printf("\n\tEntrada invalida! Digite apenas numeros.");
            printf("\n\tStatus (1-Ativo, 2-Ocupado, 3-Inativo, 4-Bloqueado): ");
            continue; // Volta para o início do loop
        }

        // 2ª Validação: O número está dentro do intervalo correto (1 a 4)?
        if (operadores[totalOperadores].Status < 1 || 
            operadores[totalOperadores].Status > 4)
        {
            printf("\n\tOpcao invalida! Escolha entre 1, 2, 3 ou 4.");
            printf("\n\tStatus (1-Ativo, 2-Ocupado, 3-Inativo, 4-Bloqueado): ");
            continue; // Volta para o início do loop
        }

        // Se passou por ambos, a entrada é válida
        valido = 1;

    } while (!valido);
}

void cad_opr ()
{
    if (totalOperadores >= 50)                          //verifica disponibilidade para cadastro
    {
        printf("\n\tLimite de operadores atingido!");
        return;
    }

    // 1. Leitura e validação do ID
    printf("\n\tDigite o ID do operador (4 digitos): ");
    ler_id();

    // 2. Verificação de ID duplicado (Feito logo após ler um ID válido)
    for (int i = 0; i < totalOperadores; i++)
    {
        if (strcmp(operadores[i].ID, operadores[totalOperadores].ID) == 0)
        {
            printf("\n\tOperador com esse ID ja cadastrado! Cadastro cancelado.");
            return;
        }
    }
    
    // 3. Leitura e validação do Nome
    printf("\n\tDigite o nome do operador: ");
    ler_nome();

    // 4. Leitura e validação do Setor
    printf("\n\tDigite o setor (2 letras e 2 digitos): ");
    ler_setor();

    // 5. Leitura e validação do Nível Operacional
    printf("\n\tNivel Operacional (1-Basico, 2-Intermediario, 3-Supervisor): ");
    ler_nivel();

    // 6. Leitura e validação do Status
    printf("\n\tStatus (1-Ativo, 2-Ocupado, 3-Inativo, 4-Bloqueado): ");
    ler_status();

    operadores[totalOperadores].QOR = 0; // começa em zero no cadastro

    totalOperadores++;

    printf("\n\tOperador cadastrado com sucesso!\n");
    system("pause");                 //pausa antes de voltar ao menu
    system("cls");
}

void menu()           //Criacao do menu
{
    int escolha = -1; //variavel para escolha

    do
    {
    /*                   impressao do menu                         */
        printf("\n\t------Sistema para Controle Operacional------");
        printf("\n\t|  1. Cadastro de Operadores                |");
        printf("\n\t|  2. Cadastro do Equipamento/Modulo        |");
        printf("\n\t|  3. Atualizacao                           |");
        printf("\n\t|  4. Consultar Registros                   |");
        printf("\n\t|  5. Relatorios Operacionais               |");
        printf("\n\t|  0. Sair                                  |");
        printf("\n\t---------------------------------------------");
        printf("\n\n\tDigite para Escolher: ");

        escolha = -1;               //reset para evitar erros de opcao invalida
        scanf("%d", &escolha);      //escolha da opcao
        system("cls");
        while (getchar() != '\n');  //limpeza de characteres invalidos (evita loop infinito)

        switch(escolha)             //opcoes
        {
            case 1:
                printf("\n\tCadastro de Operadores");
                cad_opr();
                break;

            case 2:
                printf("\n\tCadastro do Equipamento/Módulo");
                break;

            case 3:
                printf("\n\tAtualização");
                break;

            case 4:
                printf("\n\tConsultar Registros");
                break;

            case 5:
                printf("\n\tRelatórios Operacionais");
                break;

            case 0:
                printf("\n\tSaindo...\n");       //escolha = 0 sai do menu
                break;

            default:
                printf("\n\tOpcao Invalida!\n"); //escolha != 0 a 6 opcao invalida
                system("pause");                 //pausa antes de voltar ao menu
                system("cls");
                break;
        }
    } while (escolha != 0); 
}
int main()
{
    menu();     //chama o menu 
    return 0; //encerra o programa
}