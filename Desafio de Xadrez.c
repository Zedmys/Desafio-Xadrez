#include <stdio.h>

// --- Funções Auxiliares para o Nível Mestre ---
// Em C, as funções precisam ser declaradas antes de serem usadas.
// Como o Nível Mestre pede por recursão, criamos estas funções aqui.
// Elas serão chamadas de dentro da seção "Mestre" na função main.

/**
 * @brief Move a Torre de forma recursiva (Nível Mestre).
 * @param passosRestantes O número de casas que ainda faltam para mover.
 */
void moverTorreRecursivo(int passosRestantes) {
    // Caso Base: a condição de parada. Se não há mais passos, a função encerra.
    if (passosRestantes <= 0) {
        return;
    }
    // Ação: executa um passo do movimento.
    printf("Direita\n");
    // Chamada Recursiva: a função chama a si mesma com um problema menor (passos - 1).
    moverTorreRecursivo(passosRestantes - 1);
}

/**
 * @brief Move o Bispo de forma recursiva (Nível Mestre).
 * @param passosRestantes O número de casas na diagonal que ainda faltam para mover.
 */
void moverBispoRecursivo(int passosRestantes) {
    if (passosRestantes <= 0) {
        return;
    }
    printf("Cima\n");
    printf("Direita\n");
    moverBispoRecursivo(passosRestantes - 1);
}

/**
 * @brief Move a Rainha de forma recursiva (Nível Mestre).
 * @param passosRestantes O número de casas que ainda faltam para mover.
 */
void moverRainhaRecursivo(int passosRestantes) {
    if (passosRestantes <= 0) {
        return;
    }
    printf("Esquerda\n");
    moverRainhaRecursivo(passosRestantes - 1);
}


// --- Função Principal ---
// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.
int main() {
    printf("Iniciando simulação de movimentos - MateCheck\n");

    // ======================================================================
    // Nível Novato - Movimentação das Peças
    // ======================================================================
    printf("\n--- Nível Novato: Movimentação com Loops Simples ---\n\n");
    
    // Declaração de variáveis constantes para o número de casas.
    // Usar constantes torna o código mais limpo e fácil de alterar no futuro.
    const int MOVIMENTOS_BISPO = 5;
    const int MOVIMENTOS_TORRE = 5;
    const int MOVIMENTOS_RAINHA = 8;

    // Implementação de Movimentação do Bispo
    // Para simular a diagonal "superior direita", o loop imprime "Cima" e "Direita" a cada passo.
    printf("Movimentando o Bispo (5 casas na diagonal superior direita):\n");
    for (int i = 0; i < MOVIMENTOS_BISPO; i++) {
        printf("Cima\n");
        printf("Direita\n");
    }
    printf("\n");

    // Implementação de Movimentação da Torre
    // Um loop 'for' simples é perfeito para repetir o movimento para a direita.
    printf("Movimentando a Torre (5 casas para a direita):\n");
    for (int i = 0; i < MOVIMENTOS_TORRE; i++) {
        printf("Direita\n");
    }
    printf("\n");

    // Implementação de Movimentação da Rainha
    // Similar à torre, mas movendo para a esquerda.
    printf("Movimentando a Rainha (8 casas para a esquerda):\n");
    for (int i = 0; i < MOVIMENTOS_RAINHA; i++) {
        printf("Esquerda\n");
    }
    printf("\n");

    // ======================================================================
    // Nível Aventureiro - Movimentação do Cavalo
    // ======================================================================
    printf("\n--- Nível Aventureiro: Movimento do Cavalo em L ---\n\n");
    
    // Utilizamos loops aninhados para o movimento em "L" (2 casas para baixo, 1 para a esquerda).
    // O loop externo 'for' controla as "fases" do movimento (vertical e horizontal).
    // O loop interno 'while' executa os passos de cada fase.
    printf("Movimentando o Cavalo em L (2 para baixo, 1 para a esquerda):\n");
    for (int fase = 1; fase <= 2; fase++) {
        if (fase == 1) { // Fase 1: Movimento vertical
            int passosVerticais = 2;
            while (passosVerticais > 0) {
                printf("Baixo\n");
                passosVerticais--;
            }
        } else { // Fase 2: Movimento horizontal
            int passosHorizontais = 1;
            while (passosHorizontais > 0) {
                printf("Esquerda\n");
                passosHorizontais--;
            }
        }
    }
    printf("\n");

    // ======================================================================
    // Nível Mestre - Funções Recursivas e Loops Avançados
    // ======================================================================
    printf("\n--- Nível Mestre: Recursão e Loops Avançados ---\n\n");
    
    // Aqui, em vez de reescrever a lógica, simplesmente chamamos as funções recursivas
    // que foram definidas no início do arquivo.
    printf("Movimentando a Torre com função recursiva:\n");
    moverTorreRecursivo(5);
    printf("\n");

    printf("Movimentando o Bispo com função recursiva:\n");
    moverBispoRecursivo(5);
    printf("\n");

    printf("Movimentando a Rainha com função recursiva:\n");
    moverRainhaRecursivo(8);
    printf("\n");

    // Movimentação do Cavalo (1 L para cima e à direita) com loop de múltiplas variáveis.
    printf("Movimentando o Cavalo em L (2 para cima, 1 para a direita) com loop avançado:\n");
    // Este loop 'for' tem duas variáveis de controle (passos_cima, passos_direita).
    // A condição de parada é quando a soma dos passos executados for 3.
    for (int passos_cima = 0, passos_direita = 0; (passos_cima + passos_direita) < 3; ) {
        
        // Primeiro, executa os dois movimentos para cima.
        if (passos_cima < 2) {
            printf("Cima\n");
            passos_cima++;
            // 'continue' pula o resto do loop e inicia a próxima iteração.
            // Isso garante que os 2 passos para cima sejam feitos antes do passo para a direita.
            continue; 
        }

        // Depois, executa o movimento para a direita.
        if (passos_direita < 1) {
            printf("Direita\n");
            passos_direita++;
        }

        // 'break' serve como uma segurança para sair do loop caso a condição principal falhe.
        // Neste caso, ele garante que o loop termine assim que o movimento completo for feito.
        if (passos_cima == 2 && passos_direita == 1) {
            break;
        }
    }
    printf("\nSimulação concluída.\n");

    return 0;
}