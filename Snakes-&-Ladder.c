// Snakes & Ladder
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ladders[5];

int clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
        return 0;
}

void snakes_board_draw(int player_pos, int ai_pos) {
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            int num;
            int is_ladder = 0;
            
            if (i%2==0){
                num=100-(i*10)-j;
            } else {
                num=100-(i*10)-(9-j);
            }

            for (int k=0;k<5;k++) {
                if (num==ladders[k]) {
                    is_ladder = 1;
                    break;
                }
            }

            if (num==player_pos && num==ai_pos) {
                printf("\033[1;33mPA\033[0m\t");
            } else if (num == player_pos) {
                printf("\033[0;32mP\033[0m\t");
            } else if (num == ai_pos) {
                printf("\033[0;31mA\033[0m\t");
            } else if (is_ladder) {
                printf("\033[0;34m%d\033[0m\t", num);
            } else {
                printf("%d\t", num);
            }
        }
        printf("\n\n");
    }
}

void ladders_create(){
    for (int i = 0; i < 5; i++) {
        int num, unique;
        do {
            num = rand() % 80 + 1;
            unique = 1;
            for (int j = 0; j < i; j++) {
                if (ladders[j] == num) {
                    unique = 0;
                    break;
                }
            }
        } while (!unique);
        ladders[i] = num;
    }
}

int check_ladder(int pos) {
    for (int i = 0; i < 5; i++) {
        if (pos == ladders[i]) {
            printf("🎉 Ladder found at %d! Climb to %d\n", pos, pos + 5);
            return 5;
        }
    }
    return 0;
}

int player_one_turn(){
    getchar();

    int player_random_num = rand()%(6-1+1)+1;
    return player_random_num;
}

int ai_turn(){
    int ai_random_num;
    ai_random_num = rand()%(6-1+1)+1;
    return ai_random_num;
}

int single_player_section(){
    int player_position=0,ai_position=0,choice;
    printf("Welcome To Single Player Snakes & Ladder Game\n\n");
    getchar();
    ladders_create();
    int single_match_flag=1;
    while(single_match_flag){
        clear_screen();
        snakes_board_draw(player_position, ai_position);
        printf("\nPlayer, Please Press Enter To Roll The Dice...");
        int player_one_move = player_one_turn();
        player_position = player_position + player_one_move;
        player_position = player_position + check_ladder(player_position);
        printf("You Rolled---> %d\nPlayer, is now at Square %d\n",player_one_move,player_position);
        int ai_move = ai_turn();
        ai_position = ai_position + ai_move;
        ai_position = ai_position + check_ladder(ai_position);
        printf("AI Rolled---> %d\nAI, is now at Square %d\n",ai_move,ai_position);

        if(player_position >= 100 || ai_position >= 100){
            clear_screen();
            if(player_position>=100){
                printf("Player Won!\n");
            }
            else{
                printf("AI Won\n");
            }
            break;
        }
        printf("\nPress Enter to continue...");
        getchar();
    }
    printf("\n1. Play Again\n2. Exit\nEnter Your Choice: ");
    scanf("%d",&choice);
    if(choice==1){
        return 0;
    }
    else if(choice==2){
        clear_screen();
        return 3;
    }
    else{
        printf("Wrong Input!\n");
        return 1;
    }
}

int play_menu(){
    int choice;
    printf("1. Single Player\n\n2. Local Multiplayer\n\n3. Back\n\n4. Exit\n\nEnter Your Choice: ");
    scanf("%d",&choice);
    if(choice==1){
        clear_screen();
        int single_player_flag=1;
        while(single_player_flag==1){
            single_player_flag = single_player_section();
        }
        if(single_player_flag==3){
            return 0;
        }
        return 2;
    }
    else if(choice==2){
        clear_screen();
    }
    else if(choice==3){
        clear_screen();
        return 2;
    }
    else if(choice==4){
        clear_screen();
        return 0;
    }
    else{
        clear_screen();
        printf("Wrong Input! Choose Between (1-4)\n");
        return 1;
    }
    return 0;
}

int about_section(){
    char choice;
    printf("Welcome To Snakes & Ladder Game About Section\n-----------------------------\n\nThis Game Is Made By Using C Programming Language\n\nOwner--> Siamur Rahman Sunny\n\nYou Can Play This Game As A Single Player Or As A Multiplayer\n\nIn Single Player You Will Play Against AI\n\nIn Multiplayer You Will Play Against Another Real Player Locally\n\nIts Local Multiplayer Not Global Multiplayer\n");
    printf("----------------------\n\nPress E for Exit\nPress B for Going Back\n-----------------------\nEnter Your Choice: ");
    scanf(" %c",&choice);
    switch(choice){
        case 'E':
        case 'e':{
            clear_screen();
            return 0;
        }
        case 'B':
        case 'b':{
            return 2;
        }
        default:{
            clear_screen();
            printf("Wrong Input! You Must Choose E/e or B/b\n");
            return 1;
        }
    }
}

int game_menu(){
    clear_screen();
    int choice;
    printf("Welcome To Snakes & Ladder Game\n--------------------------------\n1. Play\n2. About\n3. Exit\n--------------------------------\nEnter Your Choice: ");
    scanf("%d",&choice);
    if(choice==1){
        clear_screen();
        int game_menu_flag=1;
        while(game_menu_flag==1){
            game_menu_flag=play_menu();
        }
        if(game_menu_flag==0){
            printf("Program Exitted\n");
            return 0;
        }
        else if(game_menu_flag==2){
            return 1;
        }
        return 0;
    }
    else if(choice==2){
        clear_screen();
        int about_flag=1;
        while(about_flag==1){
            about_flag = about_section();
        }
        if(about_flag==0){
            printf("Program Exitted!\n");
            return 0;
        }
        else if(about_flag==2){
            return 1;
        }
        else{
            printf("Something Wrong Happened. Game Exitted\n");
            return 0;
        }
        return 0;
    }
    else if(choice==3){
        clear_screen();
        printf("Game Exitted\n");
        return 0;
    }
    else{
        printf("Wrong Input! Choose Between (1-3).\n");
        return 1;
    }
}

int main(){
    int screen_running_flag=1;
    srand(time(NULL));
    while(screen_running_flag){
        screen_running_flag=game_menu();
    }
}