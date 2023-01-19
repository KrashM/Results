// Супер е задачата. Единствено можем да срещнем проблем с паметта!
// 23т.
#include <iostream>

bool CanMove(bool **maze, const size_t &x, const size_t &y)
{
    return x < 8 && y < 8 && maze[x][y] == 0;
}

bool path(bool **maze, const size_t &_x, const size_t &_y, const size_t &end_x, const size_t &end_y)
{
    if(!CanMove(maze, _x, _y)) return false;
    if(_x == end_x && _y == end_y) return true;
    maze[_x][_y] = true;

    bool result = path(maze, _x + 1, _y, end_x, end_y)
        || path(maze, _x, _y + 1, end_x, end_y)
        || path(maze, _x - 1, _y, end_x, end_y)
        || path(maze, _x, _y - 1, end_x, end_y);
    
    maze[_x][_y] = false;
    return result;
}

int main()
{

    // Нямаш валидация за паметта!!
    bool **maze = new bool*[8];
    for(int i = 0; i < 8; ++i)
    {  
        maze[i] = new bool[8];
        for(int j = 0; j < 8; ++j)
        {
            std::cin >> maze[i][j];
        }
    }

    int _x, end_x, _y, end_y;
    std::cin >> _x >> _y >> end_x >> end_y;

    if(path(maze, _x, _y, end_x, end_y))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl; 
    }

    for(int i = 0; i < 8; ++i) 
    {
        delete[] maze[i];
    }
    delete[] maze;
    return 0;
}