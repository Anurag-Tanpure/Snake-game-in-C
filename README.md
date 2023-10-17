Snake Game in C


Description:
This is a simple Snake game written in the C programming language. The game allows the player to control a snake represented by the character '8' using arrow keys or the 'W', 'A', 'S', 'D' keys. The objective is to eat the food ('*') to increase the player's score while avoiding collisions with the walls and the snake itself.

Features:

1.	Control the snake's movement using arrow keys or 'W', 'A', 'S', 'D'.
2.	The snake's position is represented by '8'.
3.	Collect food ('*') to increase your score.
4.	Prevent collisions with the walls or the snake's body to continue playing.
5.	A "GAME OVER" screen is displayed when the game ends.
6.	Beep sound effects to enhance the gaming experience.
7.	Score tracking and restart option.

How to Play:

1.	Press 'Y' to start the game or 'N' to quit.
2.	Use arrow keys or 'W', 'A', 'S', 'D' keys to control the snake's movement.
3.	Collect food to increase your score.
4.	Avoid collisions with walls and the snake's body.
5.	When the game ends, press 'Y' to play again or any other key to exit.

Project Structure:

snake_game.c: The main source code file for the game.
README.txt: A readme file with project details (you are encouraged to add more information).
snake_game.exe: The compiled executable file (not included in this code snippet).
g[]: A 2D array containing the "GAME OVER" screen.
Various functions to handle game logic, rendering, and user input.

Compile and Run:

You can compile the code using a C compiler, such as GCC:
gcc snake_game.c -o snake_game.exe

Run the compiled executable:
snake_game.exe

Notes:
The code uses functions like _kbhit() and getch() to detect keyboard input.
The game logic handles the snake's movement, food generation, and collision detection.
The game ends when the snake collides with walls or itself, displaying the "GAME OVER" screen.
Feel free to customize and improve the game, add more features, or make it your own. Happy coding and enjoy your time on GitHub!
