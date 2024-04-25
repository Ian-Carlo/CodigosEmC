#include <stdio.h>
#include <stdlib.h>

// Declara��o dos prot�tipos das fun��es
int *queue; // Ponteiro para a fila
 // Vari�vel para rastrear a cabe�a da fila
int tail = 0; // Vari�vel para rastrear a cauda da fila

// Fun��o para mostrar a fila
void show_queue(){
    printf("\n--Queue--\n");
    // Verifica se a fila est� vazia
    if (tail == 0) {
        printf("Fila vazia\n");
        return; // Retorna se a fila estiver vazia
    }
    // Loop para imprimir os elementos da fila
    for(int i = 0; i < tail; i++){
        printf("[%d]", queue[i]);
        printf("-");
    }
    // Imprime a cauda da fila
    printf("\nTail: %d" , tail);
}

// Fun��o para enfileirar um elemento
void enqueue(){
    int val;
    // Realoca mem�ria para aumentar o tamanho da fila

    queue = (int*) realloc(queue, (tail + 1) * sizeof(int));
    //Verificacao de erro de aloca��o de mem�ria
    if (queue == NULL) {
        printf("Erro: Falha ao realocar mem�ria\n");
        exit(EXIT_FAILURE); // Encerra o programa com c�digo de erro
    }
    // Solicita ao usu�rio para inserir um elemento
    printf("Informe um elemento: ");
    scanf("%d", &val);
    //Verifica se valor � Inteiro
    if (scanf("%d", &val) != 1) {
        printf("Erro: Entrada inv�lida\n");
        exit(EXIT_FAILURE);
    }
    // Insere o elemento na fila e atualiza a cauda
    queue[tail] = val;
    tail = tail + 1;
    // Mostra a fila atualizada
    show_queue();
}

// Fun��o para desenfileirar um elemento
void dequeue(){
    // Verifica se h� elementos na fila para desenfileirar
    if(0 < tail){
        // Move os elementos da fila para frente
        for(int i = 1; i < tail; i++ ){
            queue[i-1] = queue[i];
        }
        // Atualiza a cauda e mostra a fila atualizada
        tail = tail - 1;
        show_queue();
    }
    else{
        // Imprime mensagem se a fila estiver vazia
        printf("Fila Vazia - ");
    }
}

// Fun��o para limpar a fila
void clear(){
    // Verifica se a fila est� vazia
    if(tail == 0){
        printf("\nFila Vazia\n");
    }
    // Limpa os elementos da fila e redefine a cabe�a e a cauda
    for(int i = 0 ; i < tail; i++){
        queue[i] = 0;
    }

    tail = 0 ;
}

// Fun��o principal
int main(){
    int opcao;
    // Loop para exibir o menu e processar a escolha do usu�rio
    do{
        printf("\nSelecione uma opcao: \n");
        printf("[1] - Enqueue: \n");
        printf("[2] - desqueue: \n");
        printf("[3] - Show Queue: \n");
        printf("[4] - clear: \n");
        printf("[5] - exit: \n");
        printf("ESCOLHA: ");
        scanf("%d" , &opcao);

        switch(opcao){
        case 1:
            enqueue(); // Chama a fun��o para enfileirar um elemento
            break;

        case 2:
            dequeue(); // Chama a fun��o para desenfileirar um elemento
            break;
        case 3:
            show_queue(); // Chama a fun��o para mostrar a fila
            break;
        case 4:
            clear(); // Chama a fun��o para limpar a fila
            break;
        case 5:
            return 0; // Sai do programa
            break;
        default:
            printf("Digite um numero correto: "); // Mensagem de erro para entrada inv�lida
        }
    } while(1); // Loop infinito para continuar exibindo o menu
}
