// Hand Cricket Project

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// Declaring Necessary Global Variables
char user_name[15],opponent_name[15];
int user_score,user_wicket,ai_score,ai_wicket,target,result,ball,target_flag;

// Declaring Functions
int clear_screen();         // This is to clear the whole screen
void reset_game();          // This is to reset every variable
void taking_team_name();    // This is to Take User and AI team
void batting();             // This is for Batting
void bowling();             // This is for Bowling
int toss();                 // This is for Toss
void over();                // This is for selecting Balls per match
int play_menu();            // This is play section
int about();                // This is about section
int menu();                 // This is Main_Menu

int clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
        return 0;
}

void reset_game(){
    user_score = 0;
    user_wicket = 0;
    ai_score = 0;
    ai_wicket = 0;
    target = 0;
    result = 0;
    ball = 0;
    target_flag = 0;
}

void taking_team_name(){
    int choice,ai_choice;
    clear_screen();
    do{
        printf("Welcome To Team Selection\n------------------\n");
        printf("1.  Afghanistan\n2.  Australia\n3.  Bangladesh\n4.  England\n5.  India\n6.  Ireland\n7.  New-Zealand\n");
        printf("8.  Pakistan\n9.  South-Africa\n10.  Sri-Lanka\n11.  West-Indies\n12.  Zimbabwe\nSelect Your Team: ");
        scanf("%d",&choice);
        if(choice<1 || choice>12){
            printf("Wrong Input! Choose Between (1-12)\n");
        }
    }while(choice<1 || choice>12);
    ai_choice = rand()%(12-1+1)+1;
    if(choice==ai_choice){
        ai_choice = rand()%(12-1+1)+1;
    }
    if(choice==1){
        strcpy(user_name, "Afghanistan");
    }
    else if(choice==2){
        strcpy(user_name, "Australia");
    }
    else if(choice==3){
        strcpy(user_name, "Bangladesh");
    }
    else if(choice==4){
        strcpy(user_name, "England");
    }
    else if(choice==5){
        strcpy(user_name, "India");
    }
    else if(choice==6){
        strcpy(user_name, "Ireland");
    }
    else if(choice==7){
        strcpy(user_name, "New-Zealand");
    }
    else if(choice==8){
        strcpy(user_name, "Pakistan");
    }
    else if(choice==9){
        strcpy(user_name, "South-Africa");
    }
    else if(choice==10){
        strcpy(user_name, "Sri-Lanka");
    }
    else if(choice==11){
        strcpy(user_name, "West-Indies");
    }
    else if(choice==12){
        strcpy(user_name, "Zimbabwe");
    }
    if(ai_choice==1){
        strcpy(opponent_name, "Afghanistan");
    }
    else if(ai_choice==2){
        strcpy(opponent_name, "Australia");
    }
    else if(ai_choice==3){
        strcpy(opponent_name, "Bangladesh");
    }
    else if(ai_choice==4){
        strcpy(opponent_name, "England");
    }
    else if(ai_choice==5){
        strcpy(opponent_name, "India");
    }
    else if(ai_choice==6){
        strcpy(opponent_name, "Ireland");
    }
    else if(ai_choice==7){
        strcpy(opponent_name, "New-Zealand");
    }
    else if(ai_choice==8){
        strcpy(opponent_name, "Pakistan");
    }
    else if(ai_choice==9){
        strcpy(opponent_name, "South-Africa");
    }
    else if(ai_choice==10){
        strcpy(opponent_name, "Sri-Lanka");
    }
    else if(ai_choice==11){
        strcpy(opponent_name, "West-Indies");
    }
    else if(ai_choice==12){
        strcpy(opponent_name, "Zimbabwe");
    }
}

void batting(){
    int user_point,balls_bowled=0,ai_point;
    clear_screen();
    printf("%s Are Now Batting\n-------------\n",user_name);
    do{
        do{
            printf("Enter Your Choice (1-6): ");
            scanf("%d",&user_point);
            if(user_point<1 || user_point>6){
                printf("Wrong Input! Choose Between (1-6)\n");
            }
        }while(user_point<1 || user_point>6);
        ai_point = rand()%(6-1+1)+1;
        if(user_point==ai_point){
            user_wicket+=1;
        }
        if(user_point!=ai_point){
            user_score+=user_point;
        }
        balls_bowled+=1;
        clear_screen();
        printf("%s Choosed %d\n",user_name,user_point);
        printf("%s Choosed %d\n",opponent_name,ai_point);
        if(target_flag==1){
            printf("Score: %d\nWicket: %d\nBall: %d\nTarget: %d\n",user_score,user_wicket,balls_bowled,target);
        }
        else{
            printf("Score: %d\nWicket: %d\nBall: %d\n",user_score,user_wicket,balls_bowled);
        }
        printf("Press Enter To Continue........");
        getchar();
        getchar();
        if(user_wicket==10){
            break;
        }
        if(target_flag==1){
            if(user_score>target){
                break;
            }
        }
    }while(balls_bowled<ball);
    if(target_flag==0){
        target = target + user_score + 1;
        target_flag = 1;
        bowling();
    }
    else{
        if(user_score>target){
            printf("%s beat %s by %d Wickets!\n",user_name,opponent_name,10-user_wicket);
            reset_game();
            printf("Press Enter To Continue...");
            getchar();
        }
        else{
            printf("%s beat %s by %d Runs!\n",opponent_name,user_name,target-user_score);
            reset_game();
            printf("Press Enter To Continue...");
            getchar();
        }
    }
}

void bowling(){
    int user_point,balls_bowled=0,ai_point;
    clear_screen();
    printf("%s Are Now Bowling\n-------------\n",user_name);
    do{
        do{
            printf("Enter Your Choice (1-6): ");
            scanf("%d",&user_point);
            if(user_point<1 || user_point>6){
                printf("Wrong Input! Choose Between (1-6)\n");
            }
        }while(user_point<1 || user_point>6);
        ai_point = rand()%(6-1+1)+1;
        if(user_point==ai_point){
            ai_wicket+=1;
        }
        if(ai_point!=user_point){
            ai_score+=ai_point;
        }
        balls_bowled+=1;
        clear_screen();
        printf("%s Choosed %d\n",user_name,user_point);
        printf("%s Choosed %d\n",opponent_name,ai_point);
        if(target_flag==1){
            printf("Score: %d\nWicket: %d\nBall: %d\nTarget: %d\n",ai_score,ai_wicket,balls_bowled,target);
        }
        else{
            printf("Score: %d\nWicket: %d\nBall: %d\n",ai_score,ai_wicket,balls_bowled);
        }
        printf("Press Enter To Continue........");
        getchar();
        getchar();
        if(ai_wicket==10){
            break;
        }
        if(target_flag==1){
            if(ai_score>target){
                break;
            }
        }
    }while(balls_bowled<ball);
    if(target_flag==0){
        target = target + ai_score + 1;
        target_flag = 1;
        batting();
    }
    else{
        if(ai_score>target){
            printf("%s beat %s by %d Wickets!\n",opponent_name,user_name,10-ai_wicket);
            reset_game();
            printf("Press Enter To Continue...");
            getchar();
        }
        else{
            printf("%s beat %s by %d Runs!\n",user_name,opponent_name,target-ai_score);
            reset_game();
            printf("Press Enter To Continue...");
            getchar();
        }
    }
}

int toss(){
    int user_toss_choice,ai_toss_choice,ai_choice,user_choice;
    clear_screen();
    do{
        printf("Welcome to Toss Selection\n---------------\n1. Head\n2. Tail\nEnter Your Choice: ");
        scanf("%d",&user_toss_choice);
        if(user_toss_choice<1 || user_toss_choice>2){
            printf("Wrong Input! Choose Between (1-2)\n");
        }
    }while(user_toss_choice<1 || user_toss_choice>2);
    ai_toss_choice = rand()%(2-1+1)+1;
    if(user_toss_choice==ai_toss_choice){
        clear_screen();
        printf("%s Won The Toss!\n",user_name);
        do{
            printf("1. Batting\n2. Bowling\nEnter Your Choice: ");
            scanf("%d",&user_choice);
        }while(user_choice<1 || user_choice>2);
        clear_screen();
        if(user_choice==1){
            printf("%s Selected Batting\n",user_name);
            printf("Press Enter To Continue...");
            getchar();
            getchar();
            return 1;
        }
        else if(user_choice==2){
            printf("%s Selected Bowling\n",user_name);
            printf("Press Enter To Continue...");
            getchar();
            getchar();
            return 2;
        }
        else{
            printf("Unexpected Things Happened\n");
            return 0;
        }
    }
    else{
        clear_screen();
        printf("You Lost\n");
        ai_choice = rand()%(2-1+1)+1;
        if(ai_choice==1){
            printf("%s Selected Batting\n",opponent_name);
            printf("Press Enter To Continue...");
            getchar();
            getchar();
            return 2;
        }
        else if(ai_choice==2){
            printf("%s Selected Bowling\n",opponent_name);
            printf("Press Enter To Continue...");
            getchar();
            getchar();
            return 1;
        }
        else{
            printf("Unexpected Things Happened\n");
            return 0;
        }
    }
}

void over(){
    int choice;
    clear_screen();
    do{
        printf("1. 2 Over\n2. 5 Over\n3. 10 Over\nEnter Your Choice: ");
        scanf("%d",&choice);
        if(choice<1 || choice>3){
            printf("Wrong Input! Choose Between (1-3)\n");
        }
    }while(choice<1 || choice>3);
    if(choice==1){
        ball = 12;
    }
    else if(choice==2){
        ball = 30;
    }
    else if(choice==3){
        ball = 60;
    }
    else{
        printf("Unexpected Things Happened!\n");
    }
}

int play_menu(){
    clear_screen();
    taking_team_name();
    over();
    int toss_result = toss();
    if(toss_result==1){
        batting();
    }
    else if(toss_result==2){
        bowling();
    }
    else{
        return 0;
    }
    return 0;
}

int about(){
    char choice;
    clear_screen();
    printf("Welcome To The About Section Of Hand Cricket\n-----------------\n");
    printf("1 -> This Game Is Made By Siamur Rahman Sunny\n2 -> C Programming Language Used To Make This\n");
    printf("Features Of This Game\n------------\n1 -> When You Click On Play First You Will Need To Choose A Team\n");
    printf("2 -> Then You Have To Choose Overs\n3 -> Then You Have To Choose Head Or Tail For The Toss\n");
    printf("4 -> Then You Have To Select Bat or Ball If You Won Otherwise AI Will Choose\n");
    printf("5 -> Then Play The Game And At The End Result Will Show\n");
    printf("Press B for going back\nPress E to exit the game\nEnter Your Choice: ");
    scanf(" %c",&choice);
    if(choice=='B' || choice=='b'){
        return 2;
    }
    else if(choice=='E' || choice=='e'){
        return 0;
    }
    else{
        printf("Wrong Input! You Must Have To Write B/b or E/e\nPress Enter........");
        getchar();
        getchar();
        return 1;
    }
    return 0;
}

int menu(){
    int choice,menu_flag = 1,choicess;
    clear_screen();
    do{
        printf("Welcome To The Hand Cricket\n---------------\n1. Play\n2. About\n3. Exit\nEnter Your Choice: ");
        scanf("%d",&choice);
        if(choice<1 || choice>3){
            printf("Wrong Input! Choose Between (1-3)\n");
        }
    }while(choice<1 || choice>3);
    if(choice==1){
        clear_screen();
        menu_flag = play_menu();
        if(menu_flag==0){
            do{
                printf("Do You Want To Continue Or Exit\nPress 1 for Continue, Press 2 for Exit\nEnter Your Choice: ");
                scanf("%d",&choicess);
                if(choicess<1 || choicess>2){
                    printf("Wrong Input! Choose Again Between (1-2)\n");
                }
            }while(choicess<1 || choicess>2);
            if(choicess==1){
                return 1;
            }
            else if(choicess==2){
                clear_screen();
                printf("Program Exitted!\n");
                return 0;
            }
            else{
                clear_screen();
                printf("Unexpected Things Happened! Sorry For That.\n");
                return 0;
            }
        }
    }
    else if(choice==2){
        clear_screen();
        while(menu_flag==1){
            menu_flag = about();
        }
        if(menu_flag==0){
            clear_screen();
            printf("Program Exitted!\n");
            return 0;
        }
        else if(menu_flag==2){
            return 1;
        }
        else{
            clear_screen();
            printf("Unexpected Things Happened! Sorry For That.\n");
            return 0;
        }
    }
    else if(choice==3){
        clear_screen();
        printf("Program Exitted!\n");
        return 0;
    }
    else{
        printf("Unexpected Things Happened! Sorry For That.\n");
        return 0;
    }
    return 0;
}

int main(){
    int game_running_flag = 1;
    srand(time(NULL));
    clear_screen();
    while(game_running_flag){
        game_running_flag = menu();
    }
    return 0;
}