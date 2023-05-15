#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>

#define MAX_PLAYER 100
#define MAX_USERNAME_LENGTH 21
#define MAX_PASSWORD_LENGTH 21

// COLORS
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[1;97m"
#define RES "\e[0m"

// Global Variable
int marker, marker_one;

// Structure Variable
typedef struct user
{
    int addScore;
    int subScore;
    int mulScore;
    int divScore;
    int totalScore;
    float aveScore;
    char u_name[MAX_USERNAME_LENGTH];
    char p_word[MAX_PASSWORD_LENGTH];
} REC;
REC P_USER[MAX_PLAYER];

// Game Function Declaration
void init();
void top10LB();
void delay();
void delay5();
void loading();
void game();
void current_scores();
void startMenu(); // LOG-IN & REGISTER
int gameMenu(); // THE ARITHMETIC OPERATIONS

// Login System Function Declaration
void Register();
void login();

// Game Operation Function Declaration
void addGameFunction();
void subGameFunction();
void mulGameFunction();
void divGameFunction();

// LeaderBoard Function Declaration
void leaderboard();
void add_leaderboard();
void sub_leaderboard();
void mul_leaderboard();
void div_leaderboard();

//File Handling
void save();
void retrieve();
void addRetrieve(REC b);

int main()
{
    init();
    retrieve();
    startMenu();

    return 0;
}

// Function Declaration
void init()
{
    marker = -1;
}

void current_scores()
{
    system("cls");
    printf("\e[1;37m ===============================================================\e[0m\n");
    printf("\e[1;37m                           YOUR SCORES                          \e[0m\n");
    printf("\e[1;37m ===============================================================\e[0m\n");

    int addScore = P_USER[marker_one].addScore;
    int subScore = P_USER[marker_one].subScore;
    int mulScore = P_USER[marker_one].mulScore;
    int divScore = P_USER[marker_one].divScore;

    printf("\n Welcome, \e[4;95m%s\e[0m" "! We're glad to see you. \n\n", P_USER[marker_one].u_name);
    printf(RES" Your scores are as follows:\n");
    printf(WHT" -> Addition: \e[1;96m%d\n", addScore);
    printf(WHT" -> Subtraction: \e[1;96m%d\n", subScore);
    printf(WHT" -> Multiplication: \e[1;96m%d\n", mulScore);
    printf(WHT" -> Division: \e[1;96m%d\n\n" RES, divScore);
}

void top10LB()
{
    REC sort;
    REC temp[MAX_PLAYER];
    memcpy(&temp, &P_USER, sizeof(P_USER));
    system("cls");
    printf("\e[1;37m ===============================================================================================\e[0m\n");
    printf("\e[1;37m                                      THE TOP 10 PLAYERS                                        \e[0m\n");
    printf("\e[1;37m ===============================================================================================\e[0m\n\n");
    printf(" Here are the current top players of our game.\n Let's play the game and see if you can beat them!\n\n");
    printf(" \e[1;37mRANK NAME\t\tADDITION\tSUBTRACTION\tMULTIPLICATION\tDIVISION\tAVERAGE\e[0m\n");
    if (marker > 9)
    {

    for (int x = 0; x <= 9; x++)
  {
    temp[x].aveScore = (temp[x].addScore + temp[x].subScore + temp[x].mulScore + temp[x].divScore) / 4.0;
  }
  for (int x = 0; x < 10; x++)
  {
    for (int y = 0; y < 10; y++)
    {
      if (temp[y].aveScore < temp[y + 1].aveScore)
      {
        sort = temp[y];
        temp[y] = temp[y + 1];
        temp[y + 1] = sort;
      }
    }
  }
  for (int a = 0; a < 10; a++)
    if (strcmp(temp[a].u_name, P_USER[marker_one].u_name) == 0)
  {
      printf( " \e[1;93m[%02d] %s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f\n" RES, a+1, temp[a].u_name, temp[a].addScore, temp[a].subScore, temp[a].mulScore, temp[a].divScore, temp[a].aveScore);
  }
  else
  {
    printf("\e[0m [%02d] %s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f\e[0m\n", a+1, temp[a].u_name, temp[a].addScore, temp[a].subScore, temp[a].mulScore, temp[a].divScore, temp[a].aveScore);
  }
    }
    else
    {
        for (int x = 0; x <= marker; x++)
  {
    temp[x].aveScore = (temp[x].addScore + temp[x].subScore + temp[x].mulScore + temp[x].divScore) / 4.0;
  }
  for (int x = 0; x <= marker; x++)
  {
    for (int y = 0; y < marker; y++)
    {
      if (temp[y].aveScore < temp[y + 1].aveScore)
      {
        sort = temp[y];
        temp[y] = temp[y + 1];
        temp[y + 1] = sort;
      }
    }
  }
  for (int a = 0; a <= marker; a++)
    if (strcmp(temp[a].u_name, P_USER[marker_one].u_name) == 0)
  {
      printf( " \e[1;93m[%02d] %s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f\n" RES, a+1, temp[a].u_name, temp[a].addScore, temp[a].subScore, temp[a].mulScore, temp[a].divScore, temp[a].aveScore);
  }
  else
  {
    printf(" [%02d] %s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f\n", a+1, temp[a].u_name, temp[a].addScore, temp[a].subScore, temp[a].mulScore, temp[a].divScore, temp[a].aveScore);
  }
}
}

//DELAY IN CODE
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void delay5()
{
    int i;
    for (i = 5; i > 0; i--)
    {
        delay(1);
        printf(" %d..", i);
    }
}

void loading()
{
    printf("\n\n");
    printf("\n\n\t\t\t\t\t\tLoading....\n\n");
    for(int i = 1; i <= 120; i++)
    {
        usleep(5000);
        printf("%c", 219);
    }
    printf("\n\n\t\t\t\t\t\tSuccessfully Loaded!");
}

void game()
{
    int a = 1, b = 1, choice, ch1;
    while(1)
    {
        switch(gameMenu())
        {
        case '1': //PLAY
            srand(time(NULL));
            while(b)
            {
                system("cls");
                printf("\e[1;37m ===============================================================\e[0m\n");
                printf("\e[1;37m                             GAME MODE                          \e[0m\n");
                printf("\e[1;37m ===============================================================\e[0m\n\n");
                printf("\e[1;92m [1] - Addition\e[0m\n");
                printf("\e[1;93m [2] - Subtraction\e[0m\n");
                printf("\e[1;94m [3] - Multiplication\e[0m\n");
                printf("\e[1;95m [4] - Division\e[0m\n");
                printf("\e[0;91m [5] - Back\e[0m\n");
                printf("\n \e[1;37mChoose an option \e[0m");

                ch1 = getche();
                switch(ch1)
                    {
                        case '1': //ADDITION
                            while(a)
                            {
                                system("cls");
                                printf("\e[1;37m ===============================================================\e[0m\n");
                                printf("\e[1;37m                          ADDITION MENU                         \e[0m\n");
                                printf("\e[1;37m ===============================================================\e[0m\n\n");
                                printf("\e[1;92m [1] - Start the Game\e[0m\n");
                                printf("\e[1;93m [2] - Leaderboards\e[0m\n");
                                printf("\e[1;91m [3] - Back to Game Menu\e[0m\n");
                                printf("\n Choose an option ");

                                choice = getche();
                                switch(choice)
                                {
                                    case '1':
                                        addGameFunction();
                                        break;
                                    case '2':
                                        add_leaderboard();
                                        break;
                                    case '3':
                                        a = 0;
                                        break;
                                    default:
                                        fflush(stdin);
                                        break;
                                }
                            }
                            a = 1;
                            break;
                        case '2': //SUBTRACTION
                            while (a)
                            {
                            system("cls");
                            printf("\e[1;37m ===============================================================\e[0m\n");
                            printf("\e[1;37m                       SUBTRACTION MENU                         \e[0m\n");
                            printf("\e[1;37m ===============================================================\e[0m\n\n");
                            printf("\e[1;92m [1] - Start the Game\e[0m\n");
                            printf("\e[1;93m [2] - Leaderboards\e[0m\n");
                            printf("\e[1;91m [3] - Back to Game Menu\e[0m\n");
                            printf("\n Choose an option ");

                            choice = getche();
                                switch(choice)
                                {
                                    case '1':
                                        subGameFunction();
                                        break;
                                    case '2':
                                        sub_leaderboard();
                                        break;
                                    case '3':
                                        a = 0;
                                        break;
                                    default:
                                        fflush(stdin);
                                        break;
                                }
                            }
                            a = 1;
                            break;
                        case '3': //MULTIPLICATION
                            while(a)
                            {
                            system("cls");
                            printf("\e[1;37m ===============================================================\e[0m\n");
                            printf("\e[1;37m                      MULTIPLICATION MENU                       \e[0m\n");
                            printf("\e[1;37m ===============================================================\e[0m\n\n");
                            printf("\e[1;92m [1] - Start the Game\e[0m\n");
                            printf("\e[1;93m [2] - Leaderboards\e[0m\n");
                            printf("\e[1;91m [3] - Back to Game Menu\e[0m\n");
                            printf("\n Choose an option ");

                            choice = getche();
                                switch(choice)
                                {
                                    case '1':
                                        mulGameFunction();
                                        break;
                                    case '2':
                                        mul_leaderboard();
                                        break;
                                    case '3':
                                        a = 0;
                                        break;
                                    default:
                                        fflush(stdin);
                                        break;
                                }
                            }
                            a = 1;
                            break;
                        case '4': //DIVISION
                            while(a)
                            {
                            system("cls");
                            printf("\e[1;37m ===============================================================\e[0m\n");
                            printf("\e[1;37m                          DIVISION MENU                         \e[0m\n");
                            printf("\e[1;37m ===============================================================\e[0m\n\n");
                            printf("\e[1;92m [1] - Start the Game\e[0m\n");
                            printf("\e[1;93m [2] - Leaderboards\e[0m\n");
                            printf("\e[1;91m [3] - Back to Game Menu\e[0m\n");
                            printf("\n Choose an option ");

                            choice = getche();
                                switch(choice)
                                {
                                    case '1':
                                        divGameFunction();
                                        break;
                                    case '2':
                                        div_leaderboard();
                                        break;
                                    case '3':
                                        a = 0;
                                        break;
                                    default:
                                        fflush(stdin);
                                        break;
                                }
                            }
                            a = 1;
                            break;
                        case '5': //BACK
                            b = 0;
                            break;
                        default:
                            fflush(stdin);
                            break;
                    }
            }
            b = 1;
            break;
        case '2': //OVERALL LEADERBOARDS
            system("cls");
            leaderboard();
            break;
        case '3': //LOGOUT
            system("cls");
            save(0);
            startMenu();
            break;
        case '4': //EXIT
            save();
            exit(0);
            break;
        default:
            fflush(stdin);
            break;
        }
    }
}


// START MENU
void startMenu()
{
    int choice;
    system("cls");
    printf("\e[1;37m ===============================================================\e[0m\n\n");
    printf("\e[1;37m  Welcome to the\e[0m \e[1;94mArithmetic Practice Game!\e[0m\n\n");
    printf("\e[1;37m  If you are a new player choose\e[0m \e[1;33mRegister\e[0m.\n  \e[1;37mIf you are an existing player choose\e[0m \e[1;32mLog-in\e[0m.\n\n");
    printf("\e[1;37m ===============================================================\e[0m\n\n");
    printf("\e[1;32m [1] - LOGIN\e[0m\n");
    printf("\e[1;33m [2] - REGISTER\e[0m\n");
    printf("\e[1;31m [3] - EXIT GAME\e[0m\n\n");
    printf("\e[1;37m Choose an option \e[0m");

    choice = getche();

    switch(choice)
    {
        case '1': login(); break;
        case '2': Register(); break;
        case '3': save(); exit(0); break;
        default: printf("\n Please try again...\n"); system("pause");
                 startMenu(); break;
    }
    getche();
}

int gameMenu()
{
    int choice;
    system("cls");
    printf("\e[1;37m ===============================================================\e[0m\n");
    printf("\e[1;37m                             GAME MENU                          \e[0m\n");
    printf("\e[1;37m ===============================================================\e[0m\n\n");
    printf("\e[1;92m [1] - Play\e[0m\n");
    printf("\e[0;93m [2] - Overall Leaderboard\e[0m\n");
    printf("\e[0;94m [3] - Logout\e[0m\n");
    printf("\e[0;91m [4] - Exit Game\e[0m\n");
    printf("\n \e[1;37mChoose an option \e[0m");

    choice = getche();

    return choice;
}

void Register()
{
    int check;
    check = 0;
    marker++;
    char username[20];
    char password[20];
    system("cls");
    printf("\e[1;37m ===============================================================\e[0m\n");
    printf("\e[1;33m                      REGISTER YOUR ACCOUNT                     \e[0m\n");
    printf("\e[1;37m ===============================================================\e[0m\n\n");
    printf(WHT" ENTER USERNAME: \e[0m");
    scanf(" %[^\n]s", &username);

    for(int x = 0; x <= marker; x++)
    {
        if(strcmp(username, P_USER[x].u_name) == 0)
        {
            printf("\n \e[1;31mUsername already taken...\e[0m\n\n");
            system("pause");
            check = 1;
        }
    }
    if (check != 1)
    {
        strcpy(P_USER[marker].u_name, username);
        printf(WHT" ENTER PASSWORD: \e[0m");
        scanf(" %[^\n]s", &password);
        strcpy(P_USER[marker].p_word, password);

        printf("\n \e[1;32mSuccessfully Registered!\n Please proceed to Log-in.\e[0m\n\n");
        loading();
        startMenu();
    }
    else
    {
        marker--;
        Register();
    }
}

void login()
{
    int check = 0;
    int i = 0;
    char username[20];
    char password[20];
    char ch;
    system("cls");
    printf("\e[1;37m ===============================================================\e[0m\n");
    printf("\e[1;32m                     LOG-IN TO YOUR ACCOUNT                     \e[0m\n");
    printf("\e[1;37m ===============================================================\e[0m\n\n");
    printf(WHT" ENTER USERNAME: \e[0m");
    scanf(" %[^\n]s", &username);
    printf(WHT" ENTER PASSWORD: \e[0m");
    while ((ch = _getch()) != 13)
    {
        password[i] = ch;
        i++;
        printf("*");
    }
    for(int x = 0; x <= marker; x++)
    {
        if(strcmp(username, P_USER[x].u_name) == 0)
        {
            if(strcmp(password, P_USER[x].p_word) == 0)
            {
                marker_one = x;
                check = 1;
                printf("\n\n \e[1;32mLog-in Success!\e[0m\n\n");
                loading();
                system("cls");
                current_scores();
                printf("\n\n The page will proceed to the Top 10 Leaderboard...\n");
                delay5();
                top10LB();
                printf("\n\n The page will proceed to the Game...\n");
                delay5();
                game();
            }
        }
    }
    if(!check)
    {
        printf("\n\n \e[1;31mNo match found.\n Please register first...\e[0m\n\n");
        system("pause");
        startMenu();
    }
    getch();
}

// ADDITION
void addGameFunction()
{
    system("cls");
    int correct = 0;
    int p_answer = 0;
    int answer = 0;
    int a = 0;
    int b = 0;
    srand(time(0));

    while (1)
    {
        a = rand() % 101;
        b = rand() % 101;
        answer = a + b;
        system("cls");
        printf(" ============================================\n");
        printf("                 QUESTION %02d               \n", correct+1);
        printf(" ============================================\n");
        printf("\n What is %d + %d? :  ", a, b);
        scanf("%d", &p_answer);

        if (p_answer != answer)
        {
            printf("\n Your answer is INCORRECT.\n The correct answer is %d.\n\n", answer);
            break;
        }
        correct++;
    }
    if (correct > P_USER[marker_one].addScore)
    {
        P_USER[marker_one].addScore = correct;
        printf("\n Congratulations! Your updated high score is: %d\n", P_USER[marker_one].addScore);
        system("pause");
    }
    else
    {
        printf(" Your score: %d\n", correct);
        system("pause");
    }
}

// SUBTRACTION GAME
void subGameFunction()
{
    system("cls");
    int correct = 0;
    int p_answer = 0;
    int answer = 0;
    int a = 0;
    int b = 0;
    srand(time(0));

    while (1)
    {
        a = rand() % 101;
        b = rand() % 101;
        system("cls");
        printf(" ============================================\n");
        printf("                 QUESTION %02d               \n", correct+1);
        printf(" ============================================\n");
        if (b > a)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        answer = a - b;
        printf("\n What is %d - %d? :  ", a, b);
        scanf("%d", &p_answer);
        if (p_answer != answer)
        {
            printf("\n Your answer is INCORRECT.\n The correct answer is %d.\n\n", answer);
            break;
        }
        correct++;
    }
    if (correct > P_USER[marker_one].subScore)
    {
        P_USER[marker_one].subScore = correct;
        printf("\n Congratulations! Your updated high score is: %d\n", P_USER[marker_one].subScore);
        system("pause");
    }
    else
    {
        printf(" Your score: %d\n", correct);
        system("pause");
    }
}

// MULTIPLICATION GAME
void mulGameFunction()
{
    system("cls");
    int correct = 0;
    int p_answer = 0;
    int answer = 0;
    int a = 0;
    int b = 0;
    srand(time(0));

    while (1)
    {
        a = rand() % 13;
        b = rand() % 13;
        answer = a * b;
        system("cls");
        printf(" ============================================\n");
        printf("                 QUESTION %02d               \n", correct+1);
        printf(" ============================================\n");
        printf("\n What is %d x %d? : ", a, b);
        scanf("%d", &p_answer);

        if (p_answer != answer)
        {
            printf("\n Your answer is INCORRECT.\n The correct answer is %d.\n\n", answer);
            break;
        }
        correct++;
    }
    if (correct > P_USER[marker_one].mulScore)
    {
        P_USER[marker_one].mulScore = correct;
        printf("\n Congratulations! Your updated high score is: %d\n", P_USER[marker_one].mulScore);
        system("pause");
    } else {
        printf(" Your score: %d\n", correct);
        system("pause");
    }
}

// DIVISION GAME
void divGameFunction()
{
    system("cls");
    int correct = 0;
    int p_answer = 0;
    int answer = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    srand(time(0));

    while (1)
    {
        a = rand() % 13;
        b = rand() % 13;
        c = a * b;
        system("cls");
        printf(" ============================================\n");
        printf("                 QUESTION %02d               \n", correct+1);
        printf(" ============================================\n");
        printf("\n What is %d / %d? : ", c, a);
        scanf("%d", &p_answer);
    if (p_answer != b)
    {
        printf("\n Your answer is INCORRECT.\n The correct answer is %d.\n\n", b);
        break;
    }
    correct++;
    }
    if (correct > P_USER[marker_one].divScore)
    {
        P_USER[marker_one].divScore = correct;
        printf("\n Congratulations! Your updated high score is: %d\n", P_USER[marker_one].divScore);
        system("pause");
    } else {
        printf(" Your score: %d\n", correct);
        system("pause");
    }
}

// OVERALL LEADERBOARD
void leaderboard()
{
    REC sort;
    REC temp[MAX_PLAYER];
    memcpy(&temp, &P_USER, sizeof(P_USER));
    system("cls");
    printf("\e[1;37m ===============================================================================================\e[0m\n");
    printf("\e[1;37m                                      OVERALL LEADERBOARDS                                      \e[0m\n");
    printf("\e[1;37m ===============================================================================================\e[0m\n\n");
    printf(WHT " RANK  NAME\t\tADDITION\tSUBTRACTION\tMULTIPLICATION\tDIVISION\tAVERAGE\n" RES);
    for (int x = 0; x <= marker; x++)
    {
        temp[x].aveScore = (temp[x].addScore + temp[x].subScore + temp[x].mulScore + temp[x].divScore) / 4.0;
    }
    for (int x = 0; x <= marker; x++)
    {
        for (int y = 0; y < marker; y++)
        {
            if (temp[y].aveScore < temp[y + 1].aveScore)
            {
                sort = temp[y];
                temp[y] = temp[y + 1];
                temp[y + 1] = sort;
            }
        }
    }
        for (int a = 0; a <= marker; a++)
        if (strcmp(temp[a].u_name, P_USER[marker_one].u_name) == 0)
        {
            printf(" \e[1;93m[%02d] %s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f\n" RES, a+1, temp[a].u_name, temp[a].addScore, temp[a].subScore, temp[a].mulScore, temp[a].divScore, temp[a].aveScore);
        }
        else
        {
            printf(" [%02d] %s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f\n", a+1, temp[a].u_name, temp[a].addScore, temp[a].subScore, temp[a].mulScore, temp[a].divScore, temp[a].aveScore);
        }
        system("pause");
}

// ADDITION LEADERBOARD
void add_leaderboard()
{
    system("cls");
    REC sort;
    REC temp[MAX_PLAYER];
    memcpy(&temp, &P_USER, sizeof(P_USER));
    printf("\e[1;37m ===============================================================\e[0m\n");
    printf("\e[1;37m                      ADDITION LEADERBOARDS                     \e[0m\n");
    printf("\e[1;37m ===============================================================\e[0m\n\n");
    printf(WHT " RANK NAME\t\t\tScore\n" RES);
    for(int x = 0; x <= marker; x++)
    {
        for(int y = 0; y < marker; y++)
        {
            if (temp[y].addScore < temp[y + 1].addScore)
            {
                sort = temp[y];
                temp[y] = temp[y + 1];
                temp[y + 1] = sort;
            }
        }
    }
    for(int z = 0; z <= marker; z++)
    {
        if (strcmp(temp[z].u_name, P_USER[marker_one].u_name) == 0)
        {
            printf("\e[1;93m [%02d] %s\t\t\t%d\n" RES, z+1, temp[z].u_name, temp[z].addScore);
        }
        else
        {
            printf(" [%02d] %s\t\t\t%d\n", z+1, temp[z].u_name, temp[z].addScore);
        }
    }
    system("pause");
}

// SUBTRACTION LEADERBOARD
void sub_leaderboard()
{
    system("cls");
    REC sort;
    REC temp[MAX_PLAYER];
    memcpy(&temp, &P_USER, sizeof(P_USER));
    printf("\e[1;37m ===============================================================\e[0m\n");
    printf("\e[1;37m                     SUBTRACTION LEADERBOARDS                   \e[0m\n");
    printf("\e[1;37m ===============================================================\e[0m\n\n");
    printf(WHT " RANK NAME\t\t\tScore\n" RES);
    for(int x = 0; x <= marker; x++)
    {
        for(int y = 0; y < marker; y++)
        {
            if (temp[y].subScore < temp[y + 1].subScore)
            {
                sort = temp[y];
                temp[y] = temp[y + 1];
                temp[y + 1] = sort;
            }
        }
    }
    for(int z = 0; z <= marker; z++)
        if (strcmp(temp[z].u_name, P_USER[marker_one].u_name) == 0)
    {
        printf("\e[1;93m [%02d] %s\t\t\t%d\n" RES, z+1, temp[z].u_name, temp[z].subScore);
    }
    else
    {
        printf(" [%02d] %s\t\t\t%d\n", z+1, temp[z].u_name, temp[z].subScore);
    }
    system("pause");
}

// MULTIPLICATION LEADERBOARD
void mul_leaderboard()
{
    system("cls");
    REC sort;
    REC temp[MAX_PLAYER];
    memcpy(&temp, &P_USER, sizeof(P_USER));
    printf("\e[1;37m ===============================================================\e[0m\n");
    printf("\e[1;37m                     MULTIPLICATION LEADERBOARDS                \e[0m\n");
    printf("\e[1;37m ===============================================================\e[0m\n\n");
    printf(WHT " RANK NAME\t\t\tScore\n" RES);
    for(int x = 0; x <= marker; x++)
    {
        for(int y = 0; y < marker; y++)
        {
            if (temp[y].mulScore < temp[y + 1].mulScore)
            {
                sort = temp[y];
                temp[y] = temp[y + 1];
                temp[y + 1] = sort;
            }
        }
    }
    for(int z = 0; z <= marker; z++)
        if (strcmp(temp[z].u_name, P_USER[marker_one].u_name) == 0)
    {
        printf("\e[1;93m [%02d] %s\t\t\t%d\n" RES, z+1, temp[z].u_name, temp[z].mulScore);
    }
    else
    {
        printf(" [%02d] %s\t\t\t%d\n", z+1, temp[z].u_name, temp[z].mulScore);
    }
    system("pause");
}

// DIVISION LEADERBOARD
void div_leaderboard()
{
    system("cls");
    REC sort;
    REC temp[MAX_PLAYER];
    memcpy(&temp, &P_USER, sizeof(P_USER));
    printf("\e[1;37m ===============================================================\e[0m\n");
    printf("\e[1;37m                       DIVISION LEADERBOARDS                    \e[0m\n");
    printf("\e[1;37m ===============================================================\e[0m\n\n");
    printf(WHT " RANK NAME\t\t\tScore\n" RES);
    for(int x = 0; x <= marker; x++)
    {
        for(int y = 0; y < marker; y++)
        {
            if (temp[y].divScore < temp[y + 1].divScore)
            {
                sort = temp[y];
                temp[y] = temp[y + 1];
                temp[y + 1] = sort;
            }
        }
    }
    for(int z = 0; z <= marker; z++)
        if (strcmp(temp[z].u_name, P_USER[marker_one].u_name) == 0)
    {
        printf("\e[1;93m [%02d] %s\t\t\t%d\n" RES, z+1, temp[z].u_name, temp[z].divScore);
    }
    else
    {
        printf(" [%02d] %s\t\t\t%d\n", z+1, temp[z].u_name, temp[z].divScore);
    }
    system("pause");
}

void save()
{
    REC sort;
    REC temp[MAX_PLAYER];
    memcpy(&temp, &P_USER, sizeof(P_USER));
    FILE *fp;
    fp = fopen("PlayerDetail.txt", "w+");
    if (fp == NULL)
    {
        printf("\n File not found...\n\n");
        system("pause");
    }
    else
    {
            for (int x = 0; x <= marker; x++)
    {
        temp[x].aveScore = (temp[x].addScore + temp[x].subScore + temp[x].mulScore + temp[x].divScore) / 4.0;
    }
    for (int x = 0; x <= marker; x++)
    {
        for (int y = 0; y < marker; y++)
        {
            if (temp[y].aveScore < temp[y + 1].aveScore)
            {
                sort = temp[y];
                temp[y] = temp[y + 1];
                temp[y + 1] = sort;
            }
        }
    }
        for (int z = 0; z <= marker; z++)
        {
            fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\n",
                    temp[z].u_name, temp[z].p_word,
                    temp[z].addScore, temp[z].subScore, temp[z].mulScore, temp[z].divScore,
                    temp[z].aveScore);
        }
    }
    fclose(fp);
}

void retrieve()
{
    FILE *fp;
    REC scr;
    fp = fopen("PlayerDetail.txt", "r+");
    if (fp == NULL)
    {
        printf("\n File not found...\n\n");
        system("pause");
    }
    else
    {
        while(!feof(fp))
        {
            fscanf(fp, " %[^\t]s",scr.u_name);
            fscanf(fp, " %[^\t]s",scr.p_word);
            fscanf(fp, "%d\t%d\t%d\t\%d\n",
                   &scr.addScore, &scr.subScore, &scr.mulScore, &scr.divScore);
            addRetrieve(scr);
        }
    }
    fclose(fp);
}

void addRetrieve(REC b)
{
    if (marker == MAX_PLAYER - 1)
    {
        printf("\n Array is full...\n\n");
        system("pause");
    }
    else
    {
        marker++;
        P_USER[marker] = b;
    }
}
