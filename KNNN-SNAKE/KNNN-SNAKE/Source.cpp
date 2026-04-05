#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;
#define MINX 2
#define MINY 2
#define MAXX 50
#define MAXY 20
void VeKhung();
void gotoxy(int column, int line);
struct Point {
    int x, y;
};
class CONRAN {
public:
    struct Point A[100];
    int DoDai;
    CONRAN() {
        DoDai = 3;
        A[0].x = 12; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 10; A[2].y = 10;
    }
    void Ve(Point Qua) {
        for (int i = 0; i < DoDai; i++) {
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
        gotoxy(Qua.x, Qua.y);
        cout << "*";
    }
    void DiChuyen(int Huong, Point &Qua) {
        for (int i = DoDai - 1; i > 0; i--)
            A[i] = A[i - 1];
        if (Huong == 0) A[0].x = A[0].x + 1;
        if (Huong == 1) A[0].y = A[0].y + 1;
        if (Huong == 2) A[0].x = A[0].x - 1;
        if (Huong == 3) A[0].y = A[0].y - 1;

        if((A[0].x==Qua.x) && (A[0].y==Qua.y)) {
            DoDai++;
            Qua.x = rand() % (MAXX - MINX) + MINX;
            Qua.y = rand() % (MAXY - MINY) + MINY;
        } 

    }
    bool IsChamKhung() {
        // Nếu đầu chạm vào các cạnh MIN hoặc MAX
        if (A[0].x <= MINX || A[0].x >= MAXX || A[0].y <= MINY || A[0].y >= MAXY) {
            return true;
        }

        for (int i = 1; i < DoDai; i++) {
            if (A[0].x == A[i].x && A[0].y == A[i].y) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    CONRAN r;
    int Huong = 0;
    char t;

    Point Qua;
    srand((int)time(0));
    Qua.x = rand() % (MAXX - MINX) + MINX;
    Qua.y = rand() % (MAXY - MINY) + MINY;

    while (1) {
        if (_kbhit()) {
            t = _getch();
            if (t == 'a') Huong = 2;
            if (t == 'w') Huong = 3;
            if (t == 'd') Huong = 0;
            if (t == 's') Huong = 1;
        }
        system("cls");
        VeKhung();
        r.Ve(Qua);
        r.DiChuyen(Huong, Qua);
        if (r.IsChamKhung()) {
            gotoxy(MAXX / 2, MAXY / 2);
            cout << "RAN DA CHET! GAME OVER!";
            break;
        }
        Sleep(100);
    }

    return 0;
}


void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void VeKhung() {
    for (int i = MINX; i <= MAXX; i++) {
        gotoxy(i, MINY); printf("-");
        gotoxy(i, MAXY); printf("-");
    }
    for (int j = MINY + 1; j <= MAXY - 1; j++) {
        gotoxy(MINX, j); printf("|");
        gotoxy(MAXX, j); printf("|");
    }
}
