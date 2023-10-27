#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define SIZE 10
int lefeff = NULL;
int player_board[SIZE][SIZE]; // 玩家的棋盤
int computer_board[SIZE][SIZE]; // 電腦的棋盤
int player_ships[5] = { 5, 4, 3, 3, 2 }; // 玩家的船隻數量
int computer_ships[5] = { 5, 4, 3, 3, 2 }; // 電腦的船隻數量
void initialize_board(int board[SIZE][SIZE]) {
    // 初始化棋盤
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
}
void print_board(int board[SIZE][SIZE], int show_ships) {
    // 輸出棋盤
    printf("  ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf(". ");
            }
            else if (board[i][j] == 1) {
                printf("O ");
            }
            else if (board[i][j] == 2) {
                if (show_ships) {
                    printf("X ");
                }
                else {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
}
void place_ships(int board[SIZE][SIZE], int ships[]) {
    // 放置船隻
    for (int i = 0; i < 5; i++) {
        int size = ships[i];
        int placed = 0;
        while (!placed) {
            int x = rand() % SIZE;
            int y = rand() % SIZE;
            int dir = rand() % 2;
            if (dir == 0) {
                // 水平方向
                if (x + size <= SIZE) {
                    int valid = 1;
                    for (int j = x; j < x + size; j++) {
                        if (board[y][j] != 0) {
                            valid = 0;
                            break;
                        }
                    }
                    if (valid) {
                        for (int j = x; j < x + size; j++) {
                            board[y][j] = 1;
                        }
                        placed = 1;
                    }
                }
            }
            else {
                // 垂直方向
                if (y + size <= SIZE) {
                    int valid = 1;
                    for (int j = y; j < y + size; j++) {
                        if (board[j][x] != 0) {
                            valid = 0;
                            break;
                        }
                    }
                    if (valid) {
                        for (int j = y; j < y + size; j++) {
                            board[j][x] = 1;
                        }
                        placed = 1;
                    }
                }
            }
        }
    }
}
int perform_attack(int board[SIZE][SIZE], int x, int y, int ships[]) {
    // 執行攻擊，返回結果
    if (board[y][x] == 0) {
        board[y][x] = 2; // 未命中
        return 0;
    }
    else if (board[y][x] == 1) {
        board[y][x] = 2; // 命中
        int ship_index = board[y][x] - 1;
        ships[ship_index]--;
        lefeff++;
        return 1;
    }
    else {
        return -1; // 已經攻擊過這個位置
    }
}
int check_game_over(int ships[]) {
    // 檢查遊戲是否結束
    for (int i = 0; i < 5; i++) {
        if (ships[i] > 0) {
            return 0;
        }
    }
    return 1;
}
void abcd() {
    int t;
    initialize_board(player_board);
    initialize_board(computer_board);
    printf("歡迎來到海戰棋遊戲！\n");
    printf("請放置您的船隻...");
    scanf_s("%d", &t);
    srand(t); // 初始化隨機數生成器
    place_ships(player_board, player_ships);
    printf("正在放置電腦的船隻...\n");
    place_ships(computer_board, computer_ships);
    int player_turn = 1;
    int game_over = 0;
    while (lefeff < 19) {
        printf("\n玩家的棋盤：\n");
        print_board(player_board, 1); // 顯示玩家的棋盤，包括船隻位置
        printf("\n電腦的棋盤：\n");
        print_board(computer_board, 0); // 隱藏電腦的船隻位置
        if (player_turn) {
            printf("\n輪到玩家攻擊！\n");
            printf("請輸入攻擊的座標（例如：00）：");
            char input[3];
            scanf_s("%s", input, 1000);
            int x = input[0] ^ 48;
            int y = input[1] ^ 48;
            int result = perform_attack(computer_board, x, y, player_ships);
            if (result == 0) {
                printf("玩家攻擊未命中！\n");
            }
            else if (result == 1) {
                printf("玩家攻擊命中！\n");
                computer_ships[result]--;
            }
            else {
                printf("您已經攻擊過這個位置！\n");
            }
            player_turn = false;
            game_over = check_game_over(computer_ships);
        }
        else {
            printf("\n輪到電腦攻擊！\n");
            int x = rand() % SIZE;
            int y = rand() % SIZE;
            int result = perform_attack(player_board, x, y, computer_ships);
            if (result == 0) {
                printf("電腦攻擊未命中！(%d.%d)\n", x, y);
            }
            else if (result == 1) {
                printf("電腦攻擊命中！(%d.%d)\n", x, y);
                player_ships[result]--;
            }
            game_over = check_game_over(player_ships);
            player_turn = true;
        }
    }
    if (check_game_over(player_ships) == 0) {
        printf("\n電腦贏得了遊戲！\n");
    }
    else {
        printf("\n玩家贏得了遊戲！\n");
    }
}
int main()
{
    abcd();
    return 0;
}
