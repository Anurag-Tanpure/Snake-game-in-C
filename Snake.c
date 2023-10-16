/*
 * Snake Game in C
 * Created by Anurag Tanpure
 * GitHub: https://github.com/anuragtanpure
 *
 * Description:
 * This is a simple Snake game written in C language. 
 * Use the arrow keys or 'W', 'A', 'S', 'D' to control the snake.
 * The snake is represented by the character '8'.
 * Try to eat the food ('*') to increase your score and avoid collision with the walls and yourself.
 */

#include <stdio.h> 
#include <conio.h>     // For _kbhit() and getch() functions
#include <windows.h>   // For the Beep() function and Sleep() function
#include <time.h>      // For generating random numbers  rand()

char g[9][500] = {
    // Define a 2D array for the "GAME OVER" screen
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n',
    ' ', '0', '0', '0', ' ', ' ', ' ', ' ', '0', '0', ' ', ' ', ' ', '0', '0', '0', '0', '0', '0', '0', ' ', ' ', '0', '0', '0', ' ', ' ', ' ', ' ', ' ', '0', '0', '0', ' ', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', '0', '0', '0', ' ', '0', '0', '0', ' ', ' ', '\n',
    ' ', '0', ' ', ' ', ' ', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', ' ', ' ', ' ', ' ', '0', ' ', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', ' ', '\n',
    ' ', '0', ' ', ' ', ' ', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', ' ', ' ', ' ', ' ', '0', ' ', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', ' ', '\n',
    ' ', '0', ' ', ' ', ' ', ' ', ' ', '0', '0', '0', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', '0', '0', ' ', ' ', ' ', ' ', '0', ' ', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', '0', '0', ' ', ' ', '0', '0', '0', ' ', ' ', ' ', ' ', '\n',
    ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', ' ', ' ', ' ', ' ', '0', ' ', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', ' ', ' ', '0', '0', ' ', ' ', ' ', ' ', '\n',
    ' ', '0', '0', '0', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', ' ', ' ', ' ', ' ', '0', ' ', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', ' ', ' ', '0', ' ', '0', ' ', ' ', ' ', '\n',
    ' ', ' ', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', ' ', ' ', '0', '0', '0', ' ', ' ', ' ', ' ', ' ', '0', '0', '0', ' ', ' ', ' ', ' ', '0', '0', ' ', ' ', ' ', '0', '0', '0', ' ', ' ', '0', ' ', ' ', '0', '\n'};

// Define initial position of the snake
int x = 15, y = 15; 
char arr[40][40]; // 2D character array to store the elements of the Snake game's play area.

int h = 20, w = 30;  // Defining Height and Width of paly area;
int i, j;
char ch = 'w'; // Initial direction of the snake
int score = 0;
int foodi = 10, foodj = 10; // define initial position of the food
int speed = 30;// speed of snake
int tailX[100], tailY[100];
int tailLength = 1;

// Function to generate food for the snake
void generateFood()
{
    foodi = 1 + rand() % (h - 2);
    foodj = 1 + rand() % (w - 2);
    arr[foodi][foodj] = '*';
}

// Function to update the snake's position and check for collisions
void change()
{
    // using this for storing previous position os snake
    int prx, pry, prx2, pry2;
    prx = tailX[0];
    pry = tailY[0];
    tailX[0] = x; 
    tailY[0] = y; 

    for (int k = 1; k < tailLength; k++)// using this for updating snake position in tailX and tailY array
    {
        prx2 = tailX[k];
        pry2 = tailY[k];
        tailX[k] = prx;
        tailY[k] = pry;
        prx = prx2;
        pry = pry2;
    }

    for(int k = 2 ; k< tailLength; k++)// For check for snake collision
    {
        if(x == tailX[k] && y == tailY[k])// For check for snake collision
        {
            printf("Snake collision\n");
            game_over();
            exit(0);
        }
    }

    if (x == foodi && y == foodj) // Check whether snake eat food or not
    {
        score++;
        tailLength++;
        generateFood();
        arr[foodi][foodj] = '*';
    }
    else// if snake doesn't eat food so insert space
    {
        arr[tailX[tailLength - 1]][tailY[tailLength - 1]] = ' ';
    }

    switch (ch) // use for direction
    {
    case 'a':
    case 'A':
    case 75:
        if (score == 0)
            arr[x][y] = ' ';
        y--;
        break;
    case 'w':
    case 'W':
    case 72:
        if (score == 0)
            arr[x][y] = ' ';
        x--;
        break;
    case 'd':
    case 'D':
    case 77:
        if (score == 0)
            arr[x][y] = ' ';
        y++;
        break;
    case 's':
    case 'S':
    case 80:
        if (score == 0)
            arr[x][y] = ' ';
        x++;
        break;

    default:
        break;
    }

    arr[x][y] = '8';
}

// Function to play the game logic
void logic()
{
    while (ch != 'n' || ch != 'N')
    {
        print();
        Sleep(speed);
        if (x == 0 || y == 0 || x == h - 1 || y == w - 1)
        {
            game_over();
            break;
        }

        printf("current score %d\n", score);

        if (_kbhit())// use this for check user hit the keyboard if yes so scan the key that use hit
        {
            char c = ' ';

            c = getch();
            if (c == 'w' || c == 'a' || c == 'd' || c == 's' || ch == 'W' || ch == 'A' || ch == 'S' || ch == 'D' || ch == 75 || ch == 72 || 77 || ch == 80) 
            {
                Beep(600, 100);

                ch = c;
            }
        }
        change();
        system("cls");
    }
}

// Function to display game over screen with sound
void game_over_sound()
{
    Beep(500, 120);
    Beep(300, 100);
    Beep(500, 50);
    Beep(1000, 200);
    Beep(1000, 200);
}

// Function to display game over screen and play sound
void game_over()
{
    for (int i = 0; i < 7; i++)
    {
        printf("%s", g[i]);
    }

    game_over_sound();
}

// Function to print the game board
void print()
{
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the game board with boundaries
void boundary()
{
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (i == 0 || j == 0 || i == h - 1 || j == w - 1)
                arr[i][j] = '|';
            else
                arr[i][j] = ' ';
        }
    }

    arr[x][y] = '8'; // Initialize the snake's position
    arr[foodi][foodj] = '*'; // Initialize the food's position
}

// Function to display game rules and start the game
void rules()
{
    printf("Game Rules:\n");
    printf("Press 'W' or 'w' to go UP.\n");
    printf("Press 'A' or 'a' to go left.\n");
    printf("Press 'D' or 'd' to go right.\n");
    printf("Press 'S' or 's' to go down.\n");
    printf("You can also use the arrow keys.\n");

    printf("\n");

    printf("Press C for continue\n");
    printf("Press any key for stop game");
    char c = getche();
    Beep(250, 200);
    if (c == 'c' || c == 'C')
    {
        for (int u = 3; u >= 1; u--)
        {
            system("cls");

            printf("\n \n \n \n \n \n \n \n\n \n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
            printf("GAME is Starting in %d", u);
            Beep(250, 200);
            Sleep(1000);
        }
    }
    else
    {
        exit(0);
    }

    Beep(500, 120);
    Beep(300, 100);
}

int main()
{
    printf("Press Y for start game\n");
    printf("Press N and any key for stop game\n");
    ch = getch();
    if (ch == 'y' || ch == 'Y')  // check if use enter y so start game 
    {
        Beep(250, 200);
        system("cls");
        rules();
        system("cls");
    label:
        tailX[0] = x; // Initialize snake's starting position
        tailY[0] = y;
        boundary();
        logic();
    }
    else
        return 0;
    char z;
    printf("Total Score = %d\n", score);
    printf("PRESS [Y] for play again\n");
    z = getche();
    Beep(250, 200);
    Sleep(1000);
    if (z == 'y' || z == 'Y')
    {
        x = 15, y = 15; // Reset snake's position
        foodi = 10, foodj = 10;
        score = 0;
        ch = ' ';
        tailLength = 1;
        system("cls");
        goto label;
    }
    system("cls");
    printf("\n \n \n \n \n \n \n \n\n \n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
    printf("Thanks for playing");
    Sleep(2000);
    return 0;
}


