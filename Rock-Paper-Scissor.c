// Project-1 Rock Paper Scissor

// Declaration Of Library Function
#include<stdio.h>
#include<stdlib.h> // This Library Function For Using rand()
#include<time.h>  //  This Library Function For Using srand(time(NULL))
#include<string.h>

// This Function To Clear The Screen
void clear_screen(){
    printf("\033[2J\033[H");
}

// This Function Run The Round And Return Result As 1,2,3
int round_running(int round){
    int i,ai_choice,user_score=0,ai_score=0,result;
    char user_choice;
    clear_screen();
    printf("Game Started. Total %d Rounds Will Be Played\n",round);
    for(i=1;i<=round;i++){
        printf("\n\nPress s for Scissor r for Rock p for Paper: ");
        scanf(" %c",&user_choice);
        srand(time(NULL));
        ai_choice = rand()%(3-1+1)+1;
        printf("\nRound----> %d/%d",i,round);
        if(user_choice=='s' && ai_choice==1){
            clear_screen();
            printf("\nRound Draw\n");
            printf("You Choosed: Scissor\tAI Choosed: Scissor\n");
        }
        else if(user_choice=='s' && ai_choice==2){
            clear_screen();
            printf("\nAI Won This Round\n");
            printf("You Choosed: Scissor\tAI Choosed: Rock\n");
            ai_score+=1;
        }
        else if(user_choice=='s' && ai_choice==3){
            clear_screen();
            printf("\nYou Won This Round\n");
            printf("You Choosed: Scissor\tAI Choosed: Paper\n");
            user_score+=1;
        }
        else if(user_choice=='r' && ai_choice==1){
            clear_screen();
            printf("\nYou Won This Round\n");
            printf("You Choosed: Rock\tAI Choosed: Scissor\n");
            user_score+=1;
        }
        else if(user_choice=='r' && ai_choice==2){
            clear_screen();
            printf("\nRound Draw\n");
            printf("You Choosed: Rock\tAI Choosed: Rock\n");
        }
        else if(user_choice=='r' && ai_choice==3){
            clear_screen();
            printf("\nAI Won This Round\n");
            printf("You Choosed: Rock\tAI Choosed: Paper\n");
            ai_score+=1;
        }
        else if(user_choice=='p' && ai_choice==1){
            clear_screen();
            printf("\nAI Won This Round\n");
            printf("You Choosed: Paper\tAI Choosed: Scissor\n");
            ai_score+=1;
        }
        else if(user_choice=='p' && ai_choice==2){
            clear_screen();
            printf("\nYou Won This Round\n");
            printf("You Choosed: Paper\tAI Choosed: Rock\n");
            user_score+=1;
        }
        else if(user_choice=='p' && ai_choice==3){
            clear_screen();
            printf("\nRound Draw\n");
            printf("You Choosed: Paper\tAI Choosed: Paper\n");
        }
        else{
            clear_screen();
            printf("\nRound Skipped Because Of Your Wrong Input! AI Awarded 1 Point\n");
            ai_score+=1;
        }
        printf("\nYour-Score: %d\tAI-Score: %d\n",user_score,ai_score);
    }
    clear_screen();
    if(user_score>ai_score){
        result = 1;
        return result;
    }
    else if(ai_score>user_score){
        result = 2;
        return result;
    }
    else{
        result = 3;
        return result;
    }
}

// This Function Used To Take User Name And Round Number
int game_running(){
    int round_choice;
    char name[50];
    getchar();
    printf("Enter Your Name: ");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name, "\n")]='\0';
    clear_screen();
    printf("Welcome %s To Rock-Paper-Scissor\n-----------------\n\nHow Many Rounds You Want (1-10): ",name);
    scanf("%d",&round_choice);
    if(round_choice>10 || round_choice<1){
        printf("Sorry Wrong Input! You Must Need To Choose Between 1-10\nChoose Again: ");
        scanf("%d",&round_choice);
    }
    int round_screen = round_running(round_choice);
    if(round_screen==1){
        printf("\nCongratulations! You Won The Match\n");
        return 0;
    }
    else if(round_screen==2){
        printf("\nSorry You Lost. AI Won The Match. Better Luck Next Time!\n");
        return 0;
    }
    else{
        printf("\nDRAW\n");
        return 0;
    }
}

// This Function Behave Like Game Menu. Here Use Choose Play,About or Exit
int screen_running(){
    int choice,game_running_flag=1;
    char choice_about;
    printf("Welcome To Rock Paper Scissor\n-----------------------\n\n1. Play\n2. About\n3. Exit\nEnter Your Choice: ");
    scanf("%d",&choice);
    if(choice==1){
        clear_screen();
        while(game_running_flag){
            game_running_flag = game_running();
        }
        return 1;
    }
    else if(choice==2){
        clear_screen();
        printf("This is Rock Paper Scissor Game Made By Siamur Rahman Sunny\n\nC Programming Language Used To Make This\nPress b for Going Back\n");
        scanf(" %c",&choice_about);
        if(choice_about=='b'){
            clear_screen();
            return 1;
        }
        else{
            printf("Wrong Input! Only b allowed\n");
            printf("This is Rock Paper Scissor Game Made By Siamur Rahman Sunny\nC Programming Language Used To Make This\nPress b for Going Back\n");
            scanf(" %c",&choice_about);
        }
    }
    else if(choice==3){
        clear_screen();
        printf("Program Exitted! Thank You For Using Me\n");
        return 0;
    }
    else{
        clear_screen();
        printf("Sorry Wrong Input! Please Choose Between (1-3)\n");
        return 1;
    }
    return 0;
}

// This Is Main Function
int main(){
    int screen_flag = 1;
    while(screen_flag){
        screen_flag = screen_running();
    }
    return 0;
}