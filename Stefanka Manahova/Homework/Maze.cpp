// Just perfect!!
// 25т.
#include <iostream>

using std::cout;
using std::cin;
using std::size_t;

const int N = 8;

const int NOT_VISITED = 0;
const int WALL = 1;
const int VISITED = 2;

/*създаваме структура square, 
в която имаме полета за координатите 
на квадратчето*/
struct square {
    int x;
    int y;
};


void print (int maze[N][N]) {
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cout << maze[i][j] << ' ';
        }
        
        cout << '\n';
    }
    
}

/*създаваме функция, която да принтира
намерения път*/
void print (square route[], const size_t &size) {
    cout << '(' << route[0].x << ", " << route[0].y << ')';

    for (size_t i = 1; i < size; i++)
    {
        cout << " -> (" << route[i].x << ", " << route[i].y << ')';
    }  
}
/*създаваме функция, която проверява дали дадено квадратче
е безопасно за посещение, т.е. е в рамките на лабиринта, 
не е стена и не е вече посетено*/
bool isSafe (int maze[N][N], int x, int y) {   
    if (x < 0 || x > N - 1 || y < 0 || y > N - 1) {
        return false;
    }

    if (maze[x][y] == WALL) {
        return false;
    }

    if (maze[x][y] == VISITED) {
        return false;
    }

    return true;
}

//създаваме рекурсивна функция, която да търси път в лабиринта

/*подаваме и масив от структурата square (route[]), в който ще запазваме пътя,
 както и на какво разстояние от началото се намираме (index), което би било 
 индекса на квадратчето в масива route, ако намерим път, и референция към 
 променливата, в която ще пазим дължината на пътя (size)*/

bool path (int maze[N][N], int start_x, int start_y, int end_x, int end_y, square route[], size_t index, size_t &size) {
    //ако квадратчето не е безопасно, връщаме false
    if (!isSafe(maze, start_x, start_y)) {
        return false;
    }
    /*ако сме достигнали желаното квардатче, го 
    добавяме към route, задаваме дължината на пътя и
    връщаме true*/
    if (start_x == end_x && start_y == end_y) {
        square end;
        end.x = end_x;
        end.y = end_y;

        // За по кратък запис можеш да направиш
        // route[index++] = {end_x, end_y};
        route[index++] = end;
        size = index;
        return true;
    }

    /*маркираме квадтарчето като посетено*/
    maze[start_x][start_y] = VISITED;

    /*рекурсивно търсим път във всички посоки*/
    bool result = path(maze, start_x, start_y + 1, end_x, end_y, route, index + 1, size) ||
                  path(maze, start_x + 1, start_y, end_x, end_y, route, index + 1, size) ||
                  path(maze, start_x, start_y - 1, end_x, end_y, route, index + 1, size) ||
                  path(maze, start_x - 1, start_y, end_x, end_y, route, index + 1, size);

    /*ако квадратчето е част от път, го добавяме
    към route на съответния индекс*/
    if (result) {
        square square;
        square.x = start_x;
        square.y = start_y;

        route[index] = square;
    }

    /*при рекурсивното връщане изчистваме лабиринта
    от нашите маркировки*/
    maze[start_x][start_y] = NOT_VISITED;

    //връщаме резултата от рекурсивното търсене на път
    return result;
}

int main () {
    int maze[8][8] = {
    {0, 1, 0, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 1},
    {0, 1, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 1, 1, 0},
    {0, 1, 0, 1, 0, 0, 1, 1},
    {0, 1, 0, 0, 1, 0, 0, 0}
    };

    square route[N*N];
    size_t size = 0;
    size_t index = 0;

    cout << std::boolalpha << path(maze, 0, 0, 0, 2, route, index, size) << '\n';

    print(maze);

    print(route, size);

    return 0;
}