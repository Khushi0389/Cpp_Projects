#include <iostream>
#include <conio.h>
#include <windows.h>
#include <deque>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

bool gameOver;
int headX, headY;
int foodX, foodY;
int score;

deque<pair<int, int>> snake;

void Setup() {
    srand(time(0));
    gameOver = false;
    dir = STOP;
    headX = WIDTH / 2;
    headY = HEIGHT / 2;
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
    score = 0;
    snake.clear();
    snake.push_front({headX, headY});
}

void Draw() {
    system("cls");
    cout << "Score: " << score << endl;

    for (int i = 0; i < WIDTH + 2; i++) cout << "#";
    cout << endl;

    for (int y = 0; y < HEIGHT; y++) {
        cout << "#";
        for (int x = 0; x < WIDTH; x++) {
            if (x == foodX && y == foodY) {
                cout << "*";
            } else {
                bool printed = false;
                for (auto &s : snake) {
                    if (s.first == x && s.second == y) {
                        cout << "O";
                        printed = true;
                        break;
                    }
                }
                if (!printed) cout << " ";
            }
        }
        cout << "#\n";
    }

    for (int i = 0; i < WIDTH + 2; i++) cout << "#";
    cout << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                if (dir != RIGHT) dir = LEFT;
                break;
            case 'd':
                if (dir != LEFT) dir = RIGHT;
                break;
            case 'w':
                if (dir != DOWN) dir = UP;
                break;
            case 's':
                if (dir != UP) dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void Logic() {
    if (dir == STOP) return;

    pair<int, int> newHead = snake.front();

    switch (dir) {
        case LEFT:  newHead.first--; break;
        case RIGHT: newHead.first++; break;
        case UP:    newHead.second--; break;
        case DOWN:  newHead.second++; break;
    }

    // Wall collision
    if (newHead.first < 0 || newHead.first >= WIDTH || newHead.second < 0 || newHead.second >= HEIGHT) {
        gameOver = true;
        return;
    }

    // Self collision
    for (auto &s : snake) {
        if (s == newHead) {
            gameOver = true;
            return;
        }
    }

    // Move
    snake.push_front(newHead);

    // Eat food
    if (newHead.first == foodX && newHead.second == foodY) {
        score += 10;
        foodX = rand() % WIDTH;
        foodY = rand() % HEIGHT;
    } else {
        snake.pop_back(); // normal move
    }
}

int main() {
    Setup();

    cout << "Press W A S D to start moving. X to quit.\n";
    while (dir == STOP) {
        Input();
        Sleep(10);
    }

    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }

    system("cls");
    cout << "GAME OVER!\nFinal Score: " << score << endl;
    return 0;
}
