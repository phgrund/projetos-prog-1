/*
FANTASY LEGENDS RPG - DESAFIO DE GAME PROGRAMAÇÃO I - CC1M/2018
GAME FEITO EM ESTILO RPG DE ATAQUE ALTERNADO

PARTICIPANTES DO GRUPO:
ALEF GARCIA GAIGHER
ISAQUE SPALENZA SOARES
OTÁVIO BORTOLI
PAULO HENRIQUE RODRIGUES GRUND
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define HEALTHMINIMO 50
#define HEALTHMAXIMO 100
#define HEALTHEXTRAMAXIMO 20
#define HEALTHEXTRAMINIMO 1
#define CRITICOMAXIMO 30
#define ESQUIVAMAXIMO 20
#define QNTDPERSONAGENS 4
#define QNTDARMASMELEE 3
#define QNTDARMASRANGED 5

void introducaoGame();
void historiaGame();
void vitoria();
void derrota();
void menuInicial(int opcaoInt);

void selecionarPersonagem(int opcaoPersonagem);
void selecionarPersonagemHistoria(int opcaoPersonagem);
void selecionarArmaMelee(int opcaoArmaMelee);
void selecionarArmaRanged(int opcaoArmaRanged);
void mostrarHP(int healthPlayer, int healthIA);


char tipoPersonagem[QNTDPERSONAGENS][100] = {{"Braum"}, {"Kirito"}, {"Naruto"}, {"Sasuke"}};
char tipoArmaMelee[QNTDARMASMELEE][100] = {{"Adaga"}, {"Espada"}, {"Machado"}};
char tipoArmaRanged[QNTDARMASRANGED][100] = {{"Arco"}, {"Besta"}, {"Cajado Mágico"}, {"Kunai"}, {"Shuriken"}};
char opcaoChar;
int opcaoInt;
int statsPlayer[7];
/*
[0] = tipoPersonagem;
[1] = healthPersonagem;
[2] = tipoArmaMelee;
[3] = tipoArmaRanged;
[4] = extraHealthPersonagem;
[5] = chanceCritico;
[6] = chanceEsquiva;
*/
int statsIA[7];
/*
[0] = tipoPersonagem;
[1] = healthPersonagem;
[2] = tipoArmaMelee;
[3] = tipoArmaRanged;
[4] = extraHealthPersonagem;
[5] = chanceCritico;
[6] = chanceEsquiva;
*/
int flag = 0;
int fimJogo = 0;
int fimSelecao = 0;
int fimRodada = 0;
int numRodadas;
int rodada = 0;
int dado;
int vitoriaPlayer = 0;
int vitoriaIA = 0;

int main()
{
        // Definição para acentos e cedilha
        setlocale(LC_ALL, "Portuguese");

        // Definição para maior aleatoriedade da função rand();

        srand(time(NULL));

        // Início do Jogo

        do{
            introducaoGame();
            printf("Bem vindo ao Fantasy Legends RPG.\n\n");
            printf("[1] Iniciar o jogo.\n");
            printf("[2] Tutorial.\n");
            printf("[3] Créditos.\n");
            printf("Resposta: ");
            scanf("%i", &opcaoInt);
            if(opcaoInt < 1 || opcaoInt > 3){
                flag = 0;
                system("cls");
                introducaoGame();
                printf("Opção inválida, tente novamente.\n\n");
                system("pause");
                system("cls");
            }
            else{
                menuInicial(opcaoInt);
                if(opcaoInt == 1)
                    flag = 1;
                else
                    flag = 2;
            }
        }while(flag == 0 || flag == 2);
        do{
        system("cls");
        historiaGame();
        introducaoGame();
        printf("Digite a quantidade de rodadas a ser jogada: ");
        scanf("%i", &numRodadas);
        system("cls");
        if(numRodadas < 1){
            flag = 0;
            introducaoGame();
            printf("Quantidade de rodadas inválida, tente novamente.\n\n");
            system("pause");
            system("cls");
        }
        else
            flag = 1;
        }while(flag == 0);
        flag = 0;
        introducaoGame();
        printf("Iniciando o game com %i rodada", numRodadas);
        if(numRodadas > 1)
            printf("s");
        printf(".\nPartindo para o menu de seleção de personagens.\n\n");
        system("pause");
        system("cls");
        int log[numRodadas][31];
        /*
        [0] = Personagem Player;
        [1] = Arma melee Player;
        [2] = Arma ranged Player;
        [3] = Porcentagem crítico Player;
        [4] = Porcentagem esquiva Player
        [5] = Contador golpes Player;
        [6] = Contador uso arma melee Player;
        [7] = Contador uso arma ranged Player;
        [8] = Contador acerto crítico Player;
        [9] = Contador esquivas Player;
        [10] = HP inicial Player;
        [11] = HP extra Player;
        [12] = HP final Player;
        [13] = Personagem IA;
        [14] = Arma melee IA;
        [15] = Arma ranged IA;
        [16] = Porcentagem crítico IA;
        [17] = Porcentagem esquiva IA;
        [18] = Contador golpes IA;
        [19] = Contador uso arma melee IA;
        [20] = Contador uso arma ranged IA;
        [21] = Contador acerto crítico;
        [22] = Contador esquivas IA;
        [23] = HP inicial IA;
        [24] = HP extra IA;
        [25] = HP final IA;
        [26] = Vencedor (1 = Player / 2 = IA);
        [27] = Vitória Player;
        [28] = Vitória IA;
        [29] = Dano total Player
        [30] = Dano total IA
        */

        while(fimJogo == 0){

            vitoriaPlayer = 0;
            vitoriaIA = 0;

            // MENU DE SELEÇÃO

            do{

                //SELEÇÃO DE PERSONAGEN

                do{
                    int opcaoPersonagem;
                    introducaoGame();
                    printf("Escolha seu personagem:\n");
                    printf("[1] %s.\n", tipoPersonagem[0]);
                    printf("[2] %s.\n", tipoPersonagem[1]);
                    printf("[3] %s.\n", tipoPersonagem[2]);
                    printf("[4] %s.\n", tipoPersonagem[3]);
                    printf("Resposta: ");
                    scanf("%i", &opcaoPersonagem);
                    opcaoPersonagem--;
                    statsPlayer[0] = opcaoPersonagem;
                    system("cls");
                    if(opcaoPersonagem < 0 || opcaoPersonagem >= QNTDPERSONAGENS){
                        introducaoGame();
                        printf("Opção de personagem inválida, tente novamente.\n\n");
                        system("pause");
                        system("cls");
                        flag = 0;
                    }
                    else{
                        do{
                            selecionarPersonagem(opcaoPersonagem);
                            selecionarPersonagemHistoria(opcaoPersonagem);
                            introducaoGame();
                            printf("Deseja realmente selecionar %s como personagem?\n[S] Sim.\n[N] Não.\nResposta: ", tipoPersonagem[opcaoPersonagem]);
                            scanf("\n%c", &opcaoChar);
                            system("cls");
                            introducaoGame();
                            switch(opcaoChar){
                                case 'N': case 'n':
                                    flag = 0;
                                    printf("Voltando seleção de personagens...");
                                    break;
                                case 'S': case 's':
                                    flag = 1;
                                    printf("Você selecionou %s com sucesso, partindo para a seleção de armas melee.", tipoPersonagem[opcaoPersonagem]);
                                    log[rodada][0] = opcaoPersonagem;
                                    break;
                                default:
                                    flag = 2;
                                    printf("Opção inválida, por favor selecione uma válida.");
                            }
                            printf("\n\n");
                            system("pause");
                            system("cls");
                        }while(flag == 2);
                    }
                }while(flag == 0);

                //SELEÇÃO ARMAS MELEE

                do{
                    int opcaoArmaMelee;
                    introducaoGame();
                    printf("Escolha sua arma melee (de curto alcance):\n");
                    printf("[1] %s.\n", tipoArmaMelee[0]);
                    printf("[2] %s.\n", tipoArmaMelee[1]);
                    printf("[3] %s.\n", tipoArmaMelee[2]);
                    printf("Resposta: ");
                    scanf("%i", &opcaoArmaMelee);
                    opcaoArmaMelee--;
                    statsPlayer[2] = opcaoArmaMelee;
                    system("cls");
                    introducaoGame();
                    if(opcaoArmaMelee < 0 || opcaoArmaMelee >= QNTDARMASMELEE){
                        printf("Opção de arma melee inválida, tente novamente.\n\n");
                        system("pause");
                        system("cls");
                        flag = 0;
                    }
                    else{
                        do{
                            selecionarArmaMelee(opcaoArmaMelee);
                            printf("\n");
                            printf("Deseja realmente selecionar %s como arma melee?\n[S] Sim.\n[N] Não.\nResposta: ", tipoArmaMelee[opcaoArmaMelee]);
                            scanf("\n%c", &opcaoChar);
                            system("cls");
                            introducaoGame();
                            switch(opcaoChar){
                                case 'N': case 'n':
                                    flag = 0;
                                    printf("Voltando seleção de armas melee...");
                                    break;
                                case 'S': case 's':
                                    flag = 1;
                                    printf("Você selecionou %s com sucesso, partindo para a seleção de armas de longo alcance.", tipoArmaMelee[opcaoArmaMelee]);
                                    log[rodada][1] = opcaoArmaMelee;
                                    break;
                                default:
                                    flag = 2;
                                    printf("Opção inválida, por favor selecione uma válida.");
                            }
                            printf("\n\n");
                            system("pause");
                            system("cls");
                        }while(flag == 2);
                    }
                }while(flag == 0);

                //SELEÇÃO ARMAS RANGED

                do{
                    int opcaoArmaRanged;
                    introducaoGame();
                    printf("Escolha sua arma de longo alcance:\n");
                    printf("[1] %s.\n", tipoArmaRanged[0]);
                    printf("[2] %s.\n", tipoArmaRanged[1]);
                    printf("[3] %s.\n", tipoArmaRanged[2]);
                    printf("[4] %s.\n", tipoArmaRanged[3]);
                    printf("[5] %s.\n", tipoArmaRanged[4]);
                    printf("Resposta: ");
                    scanf("%i", &opcaoArmaRanged);
                    opcaoArmaRanged--;
                    statsPlayer[3] = opcaoArmaRanged;
                    system("cls");
                    introducaoGame();
                    if(opcaoArmaRanged < 0 || opcaoArmaRanged >= QNTDARMASRANGED){
                        printf("Opção de arma de longo alcance inválida, tente novamente.\n\n");
                        system("pause");
                        system("cls");
                        flag = 0;
                    }
                    else{
                        do{
                            selecionarArmaRanged(opcaoArmaRanged);
                            printf("\n");
                            printf("Deseja realmente selecionar %s como arma de longo alcance?\n[S] Sim.\n[N] Não.\nResposta: ", tipoArmaRanged[opcaoArmaRanged]);
                            scanf("\n%c", &opcaoChar);
                            system("cls");
                            introducaoGame();
                            switch(opcaoChar){
                                case 'N': case 'n':
                                    flag = 0;
                                    printf("Voltando seleção de armas de longo alcance...");
                                    break;
                                case 'S': case 's':
                                    flag = 1;
                                    printf("Você selecionou %s com sucesso, partindo para o início do RPG.", tipoArmaRanged[opcaoArmaRanged]);
                                    log[rodada][2] = opcaoArmaRanged;
                                    break;
                                default:
                                    flag = 2;
                                    printf("Opção inválida, por favor selecione uma válida.");
                            }
                            printf("\n\n");
                            system("pause");
                            system("cls");
                        }while(flag == 2);
                    }
                }while(flag == 0);

                //VERIFICAÇÃO DA SELEÇÃO

                do{
                    introducaoGame();
                    printf("Verifique se estas são mesmo as suas escolhas:\n\n");
                    printf("Personagem: %s.\n", tipoPersonagem[statsPlayer[0]]);
                    printf("Arma melee: %s.\n", tipoArmaMelee[statsPlayer[2]]);
                    printf("Arma de longo alcance: %s.\n", tipoArmaRanged[statsPlayer[3]]);
                    printf("\n[S] Sim.\n[N] Não.\n");
                    printf("Resposta: ");
                    scanf("\n%c", &opcaoChar);
                    system("cls");
                    introducaoGame();
                    switch(opcaoChar){
                        case 'N': case 'n':
                            flag = 0;
                            printf("Voltando ao início da seleção...");
                            break;
                        case 'S': case 's':
                            flag = 1;
                            printf("Você confirmou com sucesso suas escolhas. Preparando o início do RPG...");
                            fimSelecao = 1;
                            break;
                        default:
                            flag = 2;
                            printf("Opção inválida, por favor selecione uma válida.");
                    }

                    printf("\n\n");
                    system("pause");
                    system("cls");
                }while(flag == 2);
            }while(fimSelecao == 0);    // FIM DO MENU DE SELEÇÃO

            // SELEÇÃO RANDOM VARIÁVEIS PLAYER

            statsPlayer[1] = rand() % (HEALTHMAXIMO - HEALTHMINIMO + 1) + HEALTHMINIMO;                 // Random Health
            log[rodada][10] = statsPlayer[1];
            statsPlayer[4] = rand() % (HEALTHEXTRAMAXIMO - HEALTHEXTRAMINIMO + 1) + HEALTHEXTRAMINIMO;  // Random Health Extra
            statsPlayer[5] = rand() % (CRITICOMAXIMO + 1);                                              // Random Chance Critico
            log[rodada][3] = statsPlayer[5];
            statsPlayer[6] = rand() % (ESQUIVAMAXIMO + 1);                                              // Random Chance Esquiva
            log[rodada][4] = statsPlayer[6];

            // SELEÇÃO RANDOM VARIÁVEIS IA

            statsIA[0] = rand() % (QNTDPERSONAGENS + 1);                                                // Random Personagem
            log[rodada][13] = statsIA[0];
            statsIA[1] = rand() % (HEALTHMAXIMO - HEALTHMINIMO + 1) + HEALTHMINIMO;                     // Random Health
            log[rodada][23] = statsIA[1];
            statsIA[2] = rand() % (QNTDARMASMELEE);                                                     // Random Arma Melee
            log[rodada][14] = statsIA[2];
            statsIA[3] = rand() % (QNTDARMASRANGED);                                                    // Random Arma Ranged
            log[rodada][15] = statsIA[3];
            statsIA[4] = rand() % (HEALTHEXTRAMAXIMO - HEALTHEXTRAMINIMO + 1) + HEALTHEXTRAMINIMO;      // Random Extra Health
            statsIA[5] = rand() % (CRITICOMAXIMO + 1);                                                  // Random Chance Critico
            log[rodada][16] = statsIA[5];
            statsIA[6] = rand() % (ESQUIVAMAXIMO + 1);                                                  // Random Chance Esquiva
            log[rodada][17] = statsIA[6];

            // HP EXTRA PLAYER

            int n;
            do{
                introducaoGame();
                printf("Digite um numero aleatório entre %i a %i: ", HEALTHEXTRAMINIMO, HEALTHEXTRAMAXIMO);
                scanf("%i", &n);
                system("cls");
                introducaoGame();
                if(n < HEALTHEXTRAMINIMO || n > HEALTHEXTRAMAXIMO){
                    flag = 0;
                    printf("Valor incorreto, digite um valor entre %i e %i.", HEALTHEXTRAMINIMO, HEALTHEXTRAMAXIMO);
                }
                else{
                    flag = 1;
                    printf("Você chutou o número %i e ", n);
                    if(statsPlayer[4] == n){
                        statsPlayer[4] *= 3;
                        printf("acertou, recebeu %i de HP extra.", statsPlayer[4]);
                    }
                    else{
                        printf("errou, o número correto era %i, portanto não irá começar com HP extra.", statsPlayer[4]);
                        statsPlayer[4] = 0;
                    }
                    log[rodada][11] = statsPlayer[4];
                }
                printf("\n\n");
                system("pause");
                system("cls");
            }while(flag == 0);
            flag = 0;

            // HP EXTRA IA

            n = rand() % (20 + 1);
            statsIA[4] = rand() % (20 + 1);
            introducaoGame();
            printf("A IA chutou o número %i e ", n);
            if(statsIA[4] == n){
                statsIA[4] *= 3;
                printf("acertou, foi adicionado %i de HP extra.", statsIA[4]);
            }
            else{
                printf("errou, o número correto era %i, portanto não irá começar com HP extra.", statsIA[4]);
                statsIA[4] = 0;
            }
            log[rodada][24] = statsIA[4];
            printf("\n\n");
            system("pause");
            system("cls");

            // AMOSTRAGEM DADOS PLAYER

            introducaoGame();
            printf("Dados Player:\n\n");
            printf("Personagem: %s\n", tipoPersonagem[statsPlayer[0]]);
            printf("HP: %i\n", statsPlayer[1]);
            printf("HP Extra: %i\n", statsPlayer[4]);
            printf("Arma melee (curto alcance): %s\n", tipoArmaMelee[statsPlayer[2]]);
            printf("Arma ranged (longo alcance): %s\n", tipoArmaRanged[statsPlayer[3]]);
            printf("Chances de ataque crítico: %i%%\n", statsPlayer[5]);
            printf("Chances de esquiva: %i%%\n\n", statsPlayer[6]);

            // AMOSTRAGEM DADOS IA

            printf("Dados IA:\n\n");
            printf("Personagem: %s\n", tipoPersonagem[statsIA[0]]);
            printf("HP: %i\n", statsIA[1]);
            printf("HP Extra: %i\n", statsIA[4]);
            printf("Arma melee (curto alcance): %s\n", tipoArmaMelee[statsIA[2]]);
            printf("Arma ranged (longo alcance): %s\n", tipoArmaRanged[statsIA[3]]);
            printf("Chances de ataque crítico: %i%%\n", statsIA[5]);
            printf("Chances de esquiva: %i%%\n\n", statsIA[6]);

            system("pause");
            system("cls");

            // INÍCIO DA RODADA

            fimRodada = 0;
            int healthPlayer = statsPlayer[1] + statsPlayer[4];
            int healthIA = statsIA[1] + statsIA[4];
            int dano[3];
            /*
            [0] = danoRound
            [1] = danoMelee
            [2] = danoRanged
            */
            flag = rand() % (2) + 1;    // Define quem irá começar a partida
            do{                             // Começo da rodada
                log[rodada][5] = 0;
                log[rodada][6] = 0;
                log[rodada][7] = 0;
                log[rodada][8] = 0;
                log[rodada][9] = 0;
                log[rodada][18] = 0;
                log[rodada][19] = 0;
                log[rodada][20] = 0;
                log[rodada][21] = 0;
                log[rodada][22] = 0;
                log[rodada][27] = 0;
                log[rodada][28] = 0;
                log[rodada][29] = 0;
                log[rodada][30] = 0;
                do{
                    dano[0] = 0;
                    dano[1] = rand() % (12 - 3 + 1) + 3;
                    dano[2] = rand() % (17 - 8 + 1) + 8;
                    if(flag == 1){          // Ataque Player
                        mostrarHP(healthPlayer, healthIA);
                        printf("Sua vez de atacar:\n\n");
                        printf("Escolha que arma usar:\n");
                        printf("[1] %s\n[2] %s\n", tipoArmaMelee[statsPlayer[2]], tipoArmaRanged[statsPlayer[3]]);
                        printf("Resposta: ");
                        scanf("%i", &opcaoInt);
                        system("cls");
                        mostrarHP(healthPlayer, healthIA);
                        printf("Sua vez de atacar:\n\n");
                        dado = rand() % (100 + 1);
                        if(opcaoInt == 1) {         // Arma Melee
                            log[rodada][6]++;
                            dano[0] = dano[1];
                            printf("Você usou %s.\n", tipoArmaMelee[statsPlayer[2]]);
                            if(dado < (statsPlayer[5]) * 1.3){      // Crítico
                                log[rodada][8]++;
                                dano[0] *=  2;
                                printf("Ataque crítico, dará o dobro de dano.\n");
                            }
                        }
                        else if(opcaoInt == 2) {    // Arma Ranged
                            log[rodada][7]++;
                            dano[0] = dano[2];
                            printf("Você usou %s.\n", tipoArmaRanged[statsPlayer[3]]);
                            if(dado < statsPlayer[5]){              // Crítico
                                log[rodada][8]++;
                                dano[0] *= 2;
                                printf("Ataque crítico, dará o dobro de dano.\n");
                            }
                        }
                        else {
                            system("cls");
                        }
                        if(opcaoInt == 1 || opcaoInt == 2) {
                            if(opcaoInt == 1)
                                dado = rand() % (100 + 1);
                            else if(opcaoInt == 2)
                                dado = (rand() % (100 + 1)) / 1.5;
                            if(dado < statsIA[6]){
                                log[rodada][22]++;
                                dano[0] = 0;
                                printf("O oponente conseguiu se esquivar do ataque, seu ataque não teve efeito.\n");
                            }
                            else{
                                printf("Você deu %i de dano ao oponente.\n", dano[0]);
                                healthIA -= dano[0];
                            }
                            printf("\n");
                            system("pause");
                            system("cls");
                            flag = 2;       // Troca de lados
                            if(healthIA < 0){
                                healthIA = 0;
                                vitoriaPlayer++;
                            }
                        }
                        log[rodada][29] = dano[0];
                    }                   // FIM Ataque Player
                    if(healthIA == 0)
                        flag = 0;
                    else if(flag == 2){     // Ataque IA
                        mostrarHP(healthPlayer, healthIA);
                        printf("Vez da IA atacar:\n\n");
                        opcaoInt = rand() % (2) + 1;
                        dado = rand() % (100 + 1);
                        if(opcaoInt == 1) {         // Arma Melee
                            log[rodada][19]++;
                            dano[0] = dano[1];
                            printf("A IA usou %s.\n", tipoArmaMelee[statsIA[2]]);
                            if(dado < (statsPlayer[5]) * 1.3){      // Crítico
                                log[rodada][21]++;
                                dano[0] *= 2;
                                printf("Ataque crítico, dará o dobro de dano.\n");
                            }
                        }
                        else if(opcaoInt == 2) {    // Arma Ranged
                            log[rodada][21]++;
                            dano[0] = dano[2];
                            printf("A IA usou %s.\n", tipoArmaRanged[statsIA[3]]);
                            if(dado < (statsPlayer[5])){      // Crítico
                                dano[0] *= 2;
                                printf("Ataque crítico, dará o dobro de dano.\n");
                            }
                        }
                        //Esquiva
                        if(opcaoInt == 1)
                            dado = rand() % (100 + 1);
                        else if(opcaoInt == 2)
                            dado = (rand() % (100 + 1)) * 1.5;
                        if(dado < statsPlayer[6]){
                            log[rodada][9]++;
                            dano[0] = 0;
                            printf("Você conseguiu se esquivar do ataque inimigo, que não teve efeito.\n");
                        }
                        else{
                            printf("O oponente te deu %i de dano.\n", dano[0]);
                            healthPlayer -= dano[0];
                        }
                        printf("\n");
                        system("pause");
                        system("cls");
                        flag = 1;       // Troca de lados
                        if(healthPlayer < 0){
                            healthPlayer = 0;
                            vitoriaIA++;
                        }
                        log[rodada][30] = dano[0];
                    }                   // FIM Ataque IA
                    if(healthPlayer == 0)
                        flag = 0;
                    log[rodada][12] = healthPlayer;
                    log[rodada][25] = healthIA;
                }while(flag != 0);                       // While
                log[rodada][5] = log[rodada][6] + log[rodada][7];
                log[rodada][18] = log[rodada][19] + log[rodada][20];
                system("cls");
                introducaoGame();
                printf("Resultado:\n\n");
                printf("Seu HP final: %i\n", healthPlayer);
                printf("HP final do oponente: %i", healthIA);
                printf("\n\n");
                system("pause");
                system("cls");
                introducaoGame();
                flag = 0;

                // Finalização da rodada
                if(vitoriaPlayer == 1){
                    log[rodada][26] = 1;
                    log[rodada][27]++;
                    vitoria();
                    printf("Parabéns, você venceu a rodada!");

                }
                else if(vitoriaIA == 1){
                    log[rodada][26] = 2;
                    log[rodada][28]++;
                    derrota();
                    printf("Infelizmente não foi dessa vez, quem sabe numa próxima!");
                }
                printf("\n\n");
                system("pause");
                system("cls");
                rodada++;
                if(rodada != numRodadas){
                    introducaoGame();
                    printf("Iniciando uma nova rodada...\n\n");
                    system("pause");
                    system("cls");
                }
                fimRodada = 1;
            }while(fimRodada == 0);
            if(rodada == numRodadas)
                fimJogo = 1;
        }   // FIM DO JOGO
        int i;
        for(i = 0; i < numRodadas; i++){
            introducaoGame();
            printf("Relatório rodada %i:\n\n", i + 1);
            printf("Player:\n\n");
            printf("Personagem: %s\n", tipoPersonagem[log[i][0]]);
            printf("Arma melee: %s\n", tipoArmaMelee[log[i][1]]);
            printf("Arma ranged: %s\n", tipoArmaRanged[log[i][2]]);
            printf("Chance de acerto crítico: %i%%\n", log[i][3]);
            printf("Chance de esquiva: %i%%\n", log[i][4]);
            printf("Quantidade de golpes total: %i\n", log[i][5]);
            printf("Quantidade de golpes com a arma melee: %i\n", log[i][6]);
            printf("Quantidade de golpes com a arma ranged: %i\n", log[i][7]);
            printf("Quantidade de acertos crítico: %i\n", log[i][8]);
            printf("Quantidadede esquivas: %i\n", log[i][9]);
            printf("HP inicial: %i\n", log[i][10]);
            printf("HP extra: %i\n", log[i][11]);
            printf("Resultado: ");
            if(log[i][26] == 1)
                printf("vitória");
            else
                printf("derrota");
            printf("\n\n");
            system("pause");
            system("cls");
            introducaoGame();
            printf("Relatório rodada %i:\n\n", i + 1);
            printf("IA:\n\n");
            printf("Personagem: %s\n", tipoPersonagem[log[i][13]]);
            printf("Arma melee: %s\n", tipoArmaMelee[log[i][14]]);
            printf("Arma ranged: %s\n", tipoArmaRanged[log[i][15]]);
            printf("Chance de acerto crítico: %i%%\n", log[i][16]);
            printf("Chance de esquiva: %i%%\n", log[i][17]);
            printf("Quantidade de golpes total: %i\n", log[i][18]);
            printf("Quantidade de golpes com a arma melee: %i\n", log[i][19]);
            printf("Quantidade de golpes com a arma ranged: %i\n", log[i][20]);
            printf("Quantidade de acertos crítico: %i\n", log[i][21]);
            printf("Quantidadede esquivas: %i\n", log[i][22]);
            printf("HP inicial: %i\n", log[i][23]);
            printf("HP extra: %i\n", log[i][24]);
            printf("Resultado: ");
            if(log[i][26] == 2)
                printf("vitória");
            else
                printf("derrota");
            printf("\n\n");
            system("pause");
            system("cls");
        }
        introducaoGame();
        printf("Obrigado por jogar nosso jogo :)\n");

    return 0;
}

void introducaoGame()
{
    FILE *fptr;
    char c;
    char filename[100] = "src/introducao.txt";
    fptr = fopen(filename, "r");
    c = fgetc(fptr);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    printf("\n\n");
}
void historiaGame()
{
    introducaoGame();
    FILE *fptr;
    char c;
    char filename[100] = "src/historia/principal.txt";
    fptr = fopen(filename, "r");
    c = fgetc(fptr);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    printf("\n\n");
    system("pause");
    system("cls");
}
void vitoria()
{
    FILE *fptr;
    char c;
    char filename[100] = "src/vitoria.txt";
    fptr = fopen(filename, "r");
    c = fgetc(fptr);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    printf("\n\n");
}
void derrota()
{
    FILE *fptr;
    char c;
    char filename[100] = "src/derrota.txt";
    fptr = fopen(filename, "r");
    c = fgetc(fptr);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    printf("\n\n");
}
void menuInicial(int opcaoInt)
{
    system("cls");
    introducaoGame();
    if(opcaoInt == 2){
        flag = 0;
        system("cls");
        while(flag == 0){
            introducaoGame();
            printf("[1] Menus de seleção.\n");
            printf("[2] Como jogar.\n");
            printf("[3] Sair.\n");
            printf("Resposta: ");
            scanf("%i", &opcaoInt);
            system("cls");
            introducaoGame();
            if(opcaoInt == 1){
                printf("Escolha de Rodadas:\n");
                printf("Nesse menu, você deve digitar a quantidade de rodadas que deseja jogar, sendo o mínimo 1 rodada.\n");
                printf("\n");
                printf("Menu de seleção de personagens:\n");
                printf("Nesse menu, você deverá escolher 1 dos 4 personagens disponíveis, sendo eles Braum, Kirito, Naruto e Sasuke, cada um com sua própria história.\n");
                printf("\n");
                printf("Seleção de arma melee:\n");
                printf("Nesse menu, você deve escolhar 1 das 4 armas melee disponíveis, sendo elas a adaga, a faca e o machado.\n");
                printf("A arma melee é uma arma de curto alcance. Ela dá de 3 a 12 de dano, pouco comparada à arma ranged, porém suas chances de acertar são maiores, e as de crítico são 20%% a mais que a sua atual.\n");
                printf("(Ex: 20%% a mais de 10%% de crítico é igual a 12%% de chance de crítico.\n");
                printf("\n");
                printf("Seleção de arma ranged:\n");
                printf("Nesse menu, você deve escolhar 1 das 5 armas ranged disponíveis, sendo elas o arco, a besta, o cajado mágico, a kunai e a shuriken.\n");
                printf("A arma ranged é uma arma de longo alcance. Ela dá de de 8 a 17 de dano, mais que a arma melee, porém suas chances de acertar são menores e sua chance de crítico é a mesma dos atributos normais.\n");
                printf("\n");
                printf("Verificando sua escolha:\n");
                printf("Nesse menu, você deverá confirmar suas seleções de personagem, arma melee e arma ranged.\n");
                printf("Caso digite 'n', você irá voltar para a seleção de personagens, e repetir todo o processo.\n");
                printf("\n");
                system("pause");
            }
            else if(opcaoInt == 2){
                printf("Após os menu de seleção, será pedido para você chutar um número de 1 a 20.\n");
                printf("Caso acerte esse número, você irá receber o triplo desse valor como vida extra.\n");
                printf("Caso acerte, você não irá receber nenhum HP extra.\n");
                printf("\n");
                printf("Após o menu de amostragem de dados, a rodada irá começar.\n");
                printf("O primeiro a começar atacando é selecionado de forma aleatória, podendo você ou a IA começar primeiro.\n");
                printf("\n");
                printf("Para jogar, você deverá escolher entre atacar com sua arma melee ou sua arma ranged.\n");
                printf("Mais detalhes sobre as armas você encontra no menu tutorial 'Menus de seleção'.\n");
                printf("\n");
                printf("Caso você acerte um ataque crítico, este dará o dobro do dano que daria se fosse um normal.\n");
                printf("Quanto maior o seu atributo de acerto crítico, mais chances você tem de acertar um.\n");
                printf("\n");
                printf("Há também a chance de você esquivar de um ataque inimigo, zerando o dano que você levaria se acertasse.\n");
                printf("Quanto maior o seu atributo de esquiva, mais chances você tem de se esquivar do ataque inimigo.\n");
                printf("\n");
                printf("A rodada acaba quando um dos dois personagens tem seu HP zerado.\n");
                printf("Após o fim da partida, que é após a finalização de todas as rodadas, será mostrado um relatório de todas as rodadas jogadas.\n");
                printf("Nesse relatório você verá seus dados e do oponente ao decorrer das rodadas.\n");
                printf("\n");
                system("pause");
            }
            else if(opcaoInt == 3)
                flag = 1;
            system("cls");
        }
    }
    else if(opcaoInt == 3){
        printf("Participantes do grupo:\n");
        printf("Alef Garcia Gaigher\n");
        printf("Isaque Spalenza Soares\n");
        printf("Otávio Theodoro de Bortoli\n");
        printf("Paulo Henrique Rodrigues Grund\n\n");
        system("pause");
        system("cls");
    }
}
void selecionarPersonagem(int opcaoPersonagem)
{
    introducaoGame();
    if(opcaoPersonagem == 0){
    FILE *fptr;
    char c;
    char filename[100] = "src/personagens/braum.txt";
    fptr = fopen(filename, "r");
    c = fgetc(fptr);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    }
    else if(opcaoPersonagem == 1){
    FILE *fptr;
    char c;
    char filename[100] = "src/personagens/kirito.txt";
    fptr = fopen(filename, "r");
    c = fgetc(fptr);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    }
    else if(opcaoPersonagem == 2){
    FILE *fptr;
    char c;
    char filename[100] = "src/personagens/naruto.txt";
    fptr = fopen(filename, "r");
    c = fgetc(fptr);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    }
    else if(opcaoPersonagem == 3){
    FILE *fptr;
    char c;
    char filename[100] = "src/personagens/sasuke.txt";
    fptr = fopen(filename, "r");
    c = fgetc(fptr);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    }
    printf("\n\n");
    system("pause");
    system("cls");
}
void selecionarPersonagemHistoria(int opcaoPersonagem)
{
    introducaoGame();
    if(opcaoPersonagem == 0){
    FILE *fptr;
    char c;
    char filename[100] = "src/historia/braum.txt";
    fptr = fopen(filename, "r");
    c = fgetc(fptr);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    }
    else if(opcaoPersonagem == 1){
    FILE *fptr;
    char c;
    char filename[100] = "src/historia/kirito.txt";
    fptr = fopen(filename, "r");
    c = fgetc(fptr);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    }
    else if(opcaoPersonagem == 2){
    FILE *fptr;
    char c;
    char filename[100] = "src/historia/naruto.txt";
    fptr = fopen(filename, "r");
    c = fgetc(fptr);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    }
    else if(opcaoPersonagem == 3){
    FILE *fptr;
    char c;
    char filename[100] = "src/historia/sasuke.txt";
    fptr = fopen(filename, "r");
    c = fgetc(fptr);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    }
    printf("\n\n");
    system("pause");
    system("cls");
}
void selecionarArmaMelee(int opcaoArmaMelee)
{
    if(opcaoArmaMelee == 0){
        FILE *fptr;
        char c;
        char filename[100] = "src/armasMelee/adaga.txt";
        fptr = fopen(filename, "r");
        c = fgetc(fptr);
        while(c != EOF){
            printf("%c", c);
            c = fgetc(fptr);
        }
        fclose(fptr);
    }
    else if(opcaoArmaMelee == 1){
        FILE *fptr;
        char c;
        char filename[100] = "src/armasMelee/espada.txt";
        fptr = fopen(filename, "r");
        c = fgetc(fptr);
        while(c != EOF){
            printf("%c", c);
            c = fgetc(fptr);
        }
        fclose(fptr);
    }
    else if(opcaoArmaMelee == 2){
        FILE *fptr;
        char c;
        char filename[100] = "src/armasMelee/machado.txt";
        fptr = fopen(filename, "r");
        c = fgetc(fptr);
        while(c != EOF){
            printf("%c", c);
            c = fgetc(fptr);
        }
        fclose(fptr);
    }
}
void selecionarArmaRanged(int opcaoArmaRanged)
{
    if(opcaoArmaRanged == 0){
        FILE *fptr;
        char c;
        char filename[100] = "src/armasRanged/arco.txt";
        fptr = fopen(filename, "r");
        c = fgetc(fptr);
        while(c != EOF){
            printf("%c", c);
            c = fgetc(fptr);
        }
        fclose(fptr);
    }
    else if(opcaoArmaRanged == 1){
        FILE *fptr;
        char c;
        char filename[100] = "src/armasRanged/besta.txt";
        fptr = fopen(filename, "r");
        c = fgetc(fptr);
        while(c != EOF){
            printf("%c", c);
            c = fgetc(fptr);
        }
        fclose(fptr);
    }
    else if(opcaoArmaRanged == 2){
        FILE *fptr;
        char c;
        char filename[100] = "src/armasRanged/cajado.txt";
        fptr = fopen(filename, "r");
        c = fgetc(fptr);
        while(c != EOF){
            printf("%c", c);
            c = fgetc(fptr);
        }
        fclose(fptr);
    }
    else if(opcaoArmaRanged == 3){
        FILE *fptr;
        char c;
        char filename[100] = "src/armasRanged/kunai.txt";
        fptr = fopen(filename, "r");
        c = fgetc(fptr);
        while(c != EOF){
            printf("%c", c);
            c = fgetc(fptr);
        }
        fclose(fptr);
    }
    else if(opcaoArmaRanged == 4){
        FILE *fptr;
        char c;
        char filename[100] = "src/armasRanged/shuriken.txt";
        fptr = fopen(filename, "r");
        c = fgetc(fptr);
        while(c != EOF){
            printf("%c", c);
            c = fgetc(fptr);
        }
        fclose(fptr);
    }
}
void mostrarHP(int healthPlayer, int healthIA)
{
    introducaoGame();
    printf("Seu HP: %i\n", healthPlayer);
    printf("HP do oponente: %i\n", healthIA);
    printf("\n");
}
