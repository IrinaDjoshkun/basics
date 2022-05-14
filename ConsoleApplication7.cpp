#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>

using namespace std;

//========================================================================================

enum Cell : char
{
    CROSS = 'X',
    ZERO = '0',
    EMPTY = '_'
};

enum GameProgress
{
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW,

};

struct Coord
{
    size_t y = 0;
    size_t x = 0;
};

#pragma pack(push, 1)
struct Game
{
    Cell** ppField = nullptr;
    const size_t SIZE = 3;
    Cell human;
    Cell ai;
    size_t turn = 0;
    GameProgress progress = IN_PROGRESS;

};
#pragma pack(pop)

//========================================================================================

void clearScr()
{
    system("cls");
    //std::cout << "\x1B[2J\x1B[H";
}

int32_t __fastcall getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

//========================================================================================

void __fastcall InitGame(Game& g)
{
    g.ppField = new Cell * [g.SIZE];
    for (size_t i = 0; i < g.SIZE; i++)
    {
        g.ppField[i] = new Cell [g.SIZE];
    }

    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            g.ppField[y][x] = EMPTY;

        }
    }

    if (getRandomNum(0, 1000) > 500)
    {
        g.human = CROSS;
        g.ai = ZERO;
        g.turn = 0;
    }
    else
    {
        g.human = ZERO;
        g.ai = CROSS;
        g.turn = 1;
    }
}


void __fastcall DeinitGame(Game& g)
{
    for (size_t i = 0; i < g.SIZE; i++)
    {
        delete[] g.ppField[i];
    }
    delete[] g.ppField;
    g.ppField = nullptr;
}

void __fastcall Drawgame(const Game& g)
{
    cout << endl << "     ";
    for (size_t x = 0; x < g.SIZE; x++)
    {
        cout << x + 1 << "   ";

    }
    cout << endl;
    for (size_t y = 0; y < g.SIZE; y++)
    {
        cout << " " << y + 1 << " | ";
        for (size_t x = 0; x < g.SIZE; x++)
        {
            cout << g.ppField[y][x] << " | ";

        }
        cout << endl;
    }
    cout << endl << "Human: " << g.human << endl << "Computer: " << g.ai << endl;
}

GameProgress __fastcall getwon(const Game& g)
{
    for (size_t y = 0; y < g.SIZE; y++)
    {
        if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][0] == g.ppField[y][2])
        {
            if (g.ppField[y][0] == g.human)
                return WON_HUMAN;

            if (g.ppField[y][0] == g.ai)
                return WON_AI;
        }
    }
    for (size_t x = 0; x < g.SIZE; x++)
    {
        if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[0][x] == g.ppField[2][x])
        {
            if (g.ppField[0][x] == g.human)
                return WON_HUMAN;

            if (g.ppField[0][x] == g.ai)
                return WON_AI;
        }
    }
    if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
    {
        if (g.ppField[1][1] == g.human)
            return WON_HUMAN;

        if (g.ppField[1][1] == g.ai)
            return WON_AI;
    }
    if (g.ppField[2][0] == g.ppField[1][1] && g.ppField[2][0] == g.ppField[0][2])
    {
        if (g.ppField[1][1] == g.human)
            return WON_HUMAN;

        if (g.ppField[1][1] == g.ai)
            return WON_AI;
    }

    bool draw = true;
    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] != EMPTY)
            {
                draw = false;
                break;
            }
        }
        if (!draw)
            break;
    }

    if (draw)
        return DRAW;

    return IN_PROGRESS;
}

Coord __fastcall getHumanCoord(const Game& g)
{
    Coord c;
    do
    {
        cout << "Enter x (1..3): ";
        cin >> c.x;
        cout << "Enter y (1..3): ";
        cin >> c.y;
        c.x--;
        c.y--;

    } while (c.x > 2 || c.y > 2 || g.ppField[c.x][c.y] != EMPTY);

    return c;
}

Coord __fastcall getAiCoord(Game& g)
{
    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.ai;
                if (getwon(g) == WON_AI)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] = EMPTY;
            }
        }
    }

    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.human;
                if (getwon(g) == WON_HUMAN)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] = EMPTY;
            }
        }
    }
    
    if (g.ppField[1][1] == EMPTY)
        return{ 1,1 };
    Coord arr[4];
    size_t num = 0;
    if (g.ppField[0][0] == EMPTY)
    {
        arr[num++] = { 0,0 };
    }
    if (g.ppField[2][2] == EMPTY)
    {
        arr[num++] = { 2,2 };
    }
    if (g.ppField[2][0] == EMPTY)
    {
        arr[num++] = { 2,0 };
    }
    if (g.ppField[0][2] == EMPTY)
    {
        arr[num++] = { 0,2 };
    }
    if (num > 0)
    {
        const size_t index = getRandomNum(0, 1000) % num;
        return arr[index];
    }

    num = 0;
    if (g.ppField[0][1] == EMPTY)
    {
        arr[num++] = { 0,1 };
    }
    if (g.ppField[2][1] == EMPTY)
    {
        arr[num++] = { 2,1 };
    }
    if (g.ppField[1][0] == EMPTY)
    {
        arr[num++] = { 1,0 };
    }
    if (g.ppField[1][2] == EMPTY)
    {
        arr[num++] = { 1,2 };
    }
    if (num > 0)
    {
        const size_t index = getRandomNum(0, 1000) % num;
        return arr[index];
    }
}

void __fastcall Congrats(const Game& g)
{
    if (g.progress == WON_HUMAN)
        cout << "Human won!" << endl;
    else if (g.progress == WON_AI)
        cout << "Computer won!" << endl;
    else if (g.progress == DRAW)
        cout << "Draw!" << endl;
}

//========================================================================================

int main()
{
    Game g;
    InitGame(g);
    clearScr();
    Drawgame(g);

    do
    {
        if (g.turn % 2 == 0)
        {
            Coord c = getHumanCoord(g);
            g.ppField[c.y][c.x] = g.human;
        }
        else
        {
            Coord c = getAiCoord(g);
            g.ppField[c.y][c.x] = g.ai;
        }
        clearScr();
        Drawgame(g);
        g.turn++;
        g.progress = getwon(g);

    } while (g.progress == IN_PROGRESS);

    Congrats(g);
    DeinitGame(g);
    return 0;
}
