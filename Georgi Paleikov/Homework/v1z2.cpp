// Без забележки. Задачата е топ!!!
// 25т.
#include <iostream>
const int size = 8;

bool CanBeVisited (int maze[8][8], int row, int col)
{
    if(maze[row][col] == 0 && row >=0 && col >= 0 && row < size && col < size)
    return true;
    return false;
}

// Po ideq na Kalin Goergiev ot lekciite za rekursiq (AlreadyVisited)
// Izpolzvam opisanieto na algorituma v Wikipedia 
// za rekursivna implementaciq na DFS - https://en.wikipedia.org/wiki/Depth-first_search

void AlreadyVisited (int maze[8][8], int row, int col)
{
    maze[row][col] = 69;
}

bool path(int maze[8][8], int start_x, int start_y, int end_x, int end_y)
{
    if (start_x == end_x && start_y == end_y)
    {
    std::cout << "Krainata destinaciq e dostijima" << std::endl;
    std::cout << "(" << start_x << " , " << start_y << ")" << std::endl;
    return true;
    }
    
    AlreadyVisited(maze, start_x, start_y);

    if (CanBeVisited(maze, start_x+1, start_y) &&
    path(maze,start_x+1,start_y,end_x, end_y))
    {
    std::cout << "(" << start_x << " , " << start_y << ")" << std::endl;
    return true;
    }

    if (CanBeVisited(maze, start_x, start_y+1) &&
    path(maze,start_x,start_y+1,end_x, end_y))
    {
    std::cout << "(" << start_x << " , " << start_y << ")" << std::endl;
    return true;
    }

    if (CanBeVisited(maze, start_x-1, start_y) &&
    path(maze,start_x-1,start_y,end_x, end_y))
    {
    std::cout << "(" << start_x << " , " << start_y << ")" << std::endl;
    return true;
    }

    if (CanBeVisited(maze, start_x, start_y-1) &&
    path(maze,start_x,start_y-1,end_x, end_y))
    {
    std::cout << "(" << start_x << " , " << start_y << ")" << std::endl;
    return true;
    }

    return false;
}

int main()
{
    int maze[size][size] =
    {
        {0, 1, 0, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 1},
        {0, 1, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 0, 0},
        {0, 1, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 1, 1},
        {0, 1, 0, 0, 1, 0, 0, 0}
    };

    int start_x;
    int start_y;
    int end_x;
    int end_y;
    std::cin >> start_x >> start_y >> end_x >> end_y;
   
    if(!CanBeVisited (maze, start_x, start_y) || !CanBeVisited (maze, end_x, end_y))
    {
        std::cout << "Nevalidni nachalni/kraini koordinati";
        return 0;
    }

    if(!path(maze, end_x, end_y, start_x, start_y))
    std::cout << "Krainata destinaciq NE e dostijima";
    
    return 0;
}
