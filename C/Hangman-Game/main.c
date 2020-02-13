#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#define TC 100
#define COL 9
#define ROW 8

struct fichaPalavra {
    char palavra[TC];
    char dica[TC];
};

struct fichaJogador {
    char nome[TC];
    int pontos;
};

void carregarForca();
void printForca();
void sortearRanking(struct fichaJogador JOGADOR[]);
int lerNumPalavras();
void lerPalavras(struct fichaPalavra PALAVRA[], int numPalavras);
void erro(int* qntdErros);
int checkLetra(char letra, char* palavra, char* palavraSecreta);

const char FILENAME[] = "palavras.txt";
const char forcaBase[ROW][COL] =  {
                            {' ', ' ', ' ', ' ', '_' , '_', '_', ' ', ' '},
                            {' ', ' ', ' ', '|', ' ' , ' ', ' ', '|', ' '},
                            {' ', ' ', ' ', '|', ' ' , ' ', ' ', 'O', ' '},
                            {' ', ' ', ' ', '|', ' ' , ' ', '/', '|', 92},
                            {' ', ' ', ' ', '|', ' ' , ' ', ' ', '|', ' '},
                            {' ', ' ', ' ', '|', ' ' , ' ', '/', ' ', 92},
                            {' ', ' ', ' ', '|', ' ' , ' ', ' ', ' ', ' '},
                            {'_', '_', '_', '|', '_' , '_', '_', ' ', ' '}
                        };
char forca[ROW][COL];

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int opcao = 0, i;
    int numPalavras = lerNumPalavras();
    struct fichaPalavra PALAVRA[numPalavras];
    struct fichaJogador JOGADOR[2];
    printf("Cadastro de jogadores:\n");
    printf("\tJogador 1: ");
    scanf("\n%[^\n]", JOGADOR[0].nome);
    JOGADOR[0].pontos = 0;
    printf("\tJogador 2: ");
    scanf("\n%[^\n]", JOGADOR[1].nome);
    JOGADOR[1].pontos = 0;

    lerPalavras(PALAVRA, numPalavras);
    int qntdErros, qntdPartidas, vez = 0, acertos, qntdLetras, fimPartida;
    char letra, palavraSecreta[TC], tentativas[TC];
    do {
        system("cls");
        printf("MENU:\n");
        printf("\t1 - Nova Partida\n");
        printf("\t2 - Ranking\n");
        printf("\t3 - Sair do Jogo\n");
        printf("\nOpcao: ");
        scanf("%i", &opcao);
        system("cls");
        int numeroRandom, numerosSorteados[numPalavras];
        if(opcao == 1) {
            qntdPartidas = 0;
            do {
                i = 0;
                numeroRandom = rand() % numPalavras;
                while(i < numPalavras) {
                    if(numerosSorteados[i] == numeroRandom) {
                        numeroRandom = rand() % numPalavras;
                        i = 0;
                    }
                    else
                        i++;
                }
                numerosSorteados[qntdPartidas] = numeroRandom;
                i = 0;
                while(i < strlen(PALAVRA[numeroRandom].palavra)) {
                    palavraSecreta[i] = '_';
                    i++;
                }
                palavraSecreta[i] = '\0';
                qntdErros = 0;
                acertos = 0;
                carregarForca(forca);
                fimPartida = 0;
                do {
                    system("cls");
                    printf("#Vez de %s\n", JOGADOR[vez].nome);
                    printForca();
                    printf("Palavra: %s\n", palavraSecreta);
                    printf("Dica: %s\n", PALAVRA[numeroRandom].dica);
                    printf("Tentativas: ");
                    for(i = 0; i < qntdErros; i++)
                        printf("%c, ", tentativas[i]);
                    printf("Escolha uma letra: ");
                    scanf("\n%c", &letra);
                    qntdLetras = checkLetra(letra, PALAVRA[numeroRandom].palavra, palavraSecreta);
                    acertos += qntdLetras;
                    if(acertos == strlen(PALAVRA[numeroRandom].palavra)) {
                        JOGADOR[vez].pontos += 10 * qntdLetras;
                        system("cls");
                        printForca();
                        printf("Parabéns, você acertou a palavra %s.\n", palavraSecreta);
                        printf("Indo para a próxima palavra...\n");
                        fimPartida = 1;
                        system("pause");
                    }
                    else {
                        if(qntdLetras == 0) {
                            tentativas[qntdErros] = letra;
                            qntdErros++;
                            erro(&qntdErros);
                            tentativas[qntdErros] = '\0';
                            if(qntdErros == 6) {
                                system("cls");
                                printForca();
                                printf("Você perdeu. A palavra era %s.\n", PALAVRA[numeroRandom].palavra);
                                printf("Indo para a próxima palavra...\n");
                                fimPartida = 1;
                                system("pause");
                            }
                        }
                        else
                            JOGADOR[vez].pontos += 10 * qntdLetras;
                        vez++;
                        if(vez == 2)
                            vez = 0;
                    }
                } while(fimPartida == 0);
                strcpy(tentativas, "");
                qntdPartidas++;
            } while(qntdPartidas < numPalavras);

        }
        else if(opcao == 2) {
            sortearRanking(JOGADOR);
            printf("RANKING\n\n");
            printf("#1 %s - %i pontos\n", JOGADOR[0].nome, JOGADOR[0].pontos);
            printf("#2 %s - %i pontos\n", JOGADOR[1].nome, JOGADOR[1].pontos);
            system("pause");
        }
        else if(opcao == 3)
            printf("Fim do jogo, obrigado por jogar.\n");
        else
            printf("Opção inválida, tente novamente.\n");
    } while(opcao != 3);


    return 0;
}

void carregarForca()
{
    int i, j;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++)
            forca[i][j] = forcaBase[i][j];
    }
}

void printForca()
{
    int i, j;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++)
            printf("%c", forca[i][j]);
        printf("\n");
    }
}

void sortearRanking(struct fichaJogador JOGADOR[])
{
    struct fichaJogador aux;
    if(JOGADOR[1].pontos > JOGADOR[0].pontos) {
        aux = JOGADOR[0];
        JOGADOR[0] = JOGADOR[1];
        JOGADOR[1] = aux;
    }
}

int lerNumPalavras()
{
    FILE *arquivo;
    arquivo = fopen(FILENAME, "r+");
    char c;
    int qntd;
    c = getc(arquivo);
    qntd = c - '0';
    fclose(arquivo);
    return qntd;
}

void lerPalavras(struct fichaPalavra PALAVRA[], int numPalavras)
{
    FILE *arquivo;
    arquivo = fopen(FILENAME, "r");
    int i = 0, j = 0, campo = 1;
    char c, aux[TC];
    //Para ignorar o começo do arquivo
    c = getc(arquivo);
    c = getc(arquivo);
    do{
        c = getc(arquivo);
        if(c != '\n' && c != EOF) {
            aux[i] = c;
            i++;
        }
        else {
            aux[i] = '\0';
            switch(campo) {
            case 1:
                strcpy(PALAVRA[j].palavra, aux);
                break;
            case 2:
                strcpy(PALAVRA[j].dica, aux);
                campo = 0;
                j++;
            }
            campo++;
            i = 0;
        }
    } while(j < numPalavras);
}

void erro(int* qntdErros)
{
    switch(*qntdErros) {
        case 1:
            forca[5][6] = ' ';
            break;
        case 2:
            forca[5][8] = ' ';
            break;
        case 3:
            forca[3][6] = ' ';
            break;
        case 4:
            forca[3][8] = ' ';
            break;
        case 5:
            forca[3][7] = ' ';
            forca[4][7] = ' ';
            break;
        case 6:
            forca[2][7] = ' ';
            break;
    }
}

int checkLetra(char letra, char* palavra, char* palavraSecreta)
{
    int i = 0, cont = 0;
    while(palavra[i] != '\0') {
        if(letra == palavra[i]) {
            cont++;
            palavraSecreta[i] = letra;
        }
        i++;
    }

    return cont;
}
