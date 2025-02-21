#include <stdlib.h>
#include <stdio.h>

int player = 1, contador = 0, resultado = 0, answer = 0;
void startBoard();
void showBoard();
int checkBoard();
int play();
char tablero[3][3];

//main
int main(){
    startBoard();
    do{
        player = 1, contador = 0, resultado = 0;
        startBoard();
        play();
        printf("\nQuieres jugar nuevamente? 1. si 2. no: ");
        scanf("%d", &answer);
    }while(answer != 2);
    return 0;
}
//fin main

startBoard(){
    tablero[0][0] = '1';
    tablero[0][1] = '2';
    tablero[0][2] = '3';
    tablero[1][0] = '4';
    tablero[1][1] = '5';
    tablero[1][2] = '6';
    tablero[2][0] = '7';
    tablero[2][1] = '8';
    tablero[2][2] = '9';
}

showBoard(){
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            printf("%c", tablero[i][j]);
            if(j < 2){
            printf(" | ");
            }
        }
        if(i < 2){
        printf("\n----------\n");
        }
    }
}

checkBoard(){
    //check diagonals
    if(tablero[0][0] == 'X' && tablero[1][1] == 'X'&& tablero[2][2] == 'X'){
        printf(" \nJugador 1 gana!");
        return 0;
    }
    else if(tablero[0][2] == 'X' && tablero[1][1] == 'X'&& tablero[2][0] == 'X'){
        printf(" \nJugador 1 gana!");
        return 0;
    }
    else if(tablero[0][0] == 'O' && tablero[1][1] == 'O'&& tablero[2][2] == 'O'){
        printf(" \nJugador 2 gana!");
        return 0;
    }
    else if(tablero[0][2] == 'O' && tablero[1][1] == 'O'&& tablero[2][0] == 'O'){
        printf(" \nJugador 2 gana!");
        return 0;
    }
    //check rows
    for(int i = 0; i <= 2; i++){
        int x = 0;
        int o = 0;
        for(int j = 0; j <= 2; j++){
            switch(tablero[i][j]){
            case 'X':
                x++;
                break;
            case 'O':
                o++;
                break;
            }
        }
        if(x == 3){
            printf(" \njugador 1 gana!");
            return 0;
        }
        else if(o == 3){
            printf(" \njugador 2 gana!");
            return 0;
        }
    }
    //check columns
    for(int i = 0; i <= 2; i++){
        int x = 0;
        int o = 0;
        for(int j = 0; j <= 2; j++){
            switch(tablero[j][i]){
            case 'X':
                x++;
                break;
            case 'O':
                o++;
                break;
            }
        }
        if(x == 3){
            printf(" \njugador 1 gana!");
            return 0;
        }
        else if(o == 3){
            printf(" \njugador 2 gana!");
            return 0;
        }
    }
}

play(){
    char a;
    printf("Bienvenido a tic tac toe!\n");
    showBoard();
    do{
    printf("\njugador %d, introduzca donde quiere se quiere colocar: \n", player);
    scanf(" %c", &a);
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            if(tablero[i][j] == a){
                    switch(player){
                    case 1:
                        tablero[i][j] = 'X';
                        player = 2;
                        break;
                    case 2:
                        tablero[i][j] = 'O';
                        player = 1;
                        break;
                }
                break;
            }
        }
    }
    showBoard();
    resultado = checkBoard();
    contador++;
    if(contador == 9 && resultado != 0){
        printf("\nEmpate!");
        break;
    }
    }while(resultado != 0);
}
