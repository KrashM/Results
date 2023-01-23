// Екстра е задачата.
// Отново много малки стилистични забележки.
// 30т.
#include <iostream>

//Функция за освобождаване на памет на динамична матрица
void deallocate(int** mat, unsigned size)
{
	for (unsigned i = 0; i < size; ++i)
	{
		delete[] mat[i];
	}
	delete[] mat;
	mat = nullptr;
}

//Функция за заделяне на памет за динамична матрица
int** allocate(unsigned size)
{
	int** mat = new (std::nothrow) int* [size];

	if (!mat)
		return nullptr;

	for (unsigned i = 0; i < size; ++i)
	{
		mat[i] = new (std::nothrow) int[size];
		if (!mat[i])
		{
			deallocate(mat, i);         //ако някой ред не се задели успешно, освобождаваме паметта за матрицата заделена до момента
			return nullptr;
		}
	}
	return mat;
}

//Функция, определяща дали дадена позиция е валидна спрямо целите на задачата
bool isNotValidPosition(int**& maze, int x, int y, unsigned size)
{
	// x >= size и y >= size.
	return (x < 0 || x == size || y < 0 || y == size || maze[x][y] == -1 || maze[x][y] == 1);
}

//Рекурсивна функция, отговаряща на въпроса дали съществува такъв път и го извежда по подходящ начин
bool path(int** maze, int start_x, int start_y, int end_x, int end_y, unsigned size)
{
	if (isNotValidPosition(maze, start_x, start_y, size))
		return false;

	if (start_x == end_x && start_y == end_y)
	{
		std::cout << "("<<start_x << " " << start_y<<")";
		return true;
	}

	maze[start_x][start_y] = -1;

	if (path(maze, start_x, start_y - 1, end_x, end_y, size))
	{
		std::cout <<" <- (" << start_x << " " << start_y << ")";
		return true;
	}

	if (path(maze, start_x - 1, start_y , end_x, end_y, size))
	{
		std::cout << " <- (" << start_x << " " << start_y << ")";
		return true;
	}
	if (path(maze, start_x + 1, start_y , end_x, end_y, size))
	{
		std::cout << " <- (" << start_x << " " << start_y << ")";
		return true;
	}
	if (path(maze, start_x, start_y + 1, end_x, end_y, size))
	{
		std::cout << " <- (" << start_x << " " << start_y << ")";
		return true;
	}

	return false;
}

//Функция, принтираща матрицата
void print(int** maze, unsigned size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int k = 0; k < size; ++k)
			std::cout << maze[i][0] << " ";
		std::cout << "\n";
	}
}

void output()
{
	// Попринцип по условие ти е дадено, че матрицата е 8х8.
	// Но ти си го направил динамично с NxN. Което е яко.
	// 2т. Бонус за това.
	std::cout << "Choose dimention:";
	unsigned dimentions;
	std::cin >> dimentions;
	if (!std::cin)                      //валидация на размерността на матрицата
	{
		std::cerr << "Invalid value for the dimentions!";
		return ;
	}

	int** maze = allocate(dimentions);  //динаммично заделяне на матрица

	if (!maze)               //ако не се задели успешно
	{
      std::cerr << "Couldn't allocate memory!\n";
	  return;
	}


	for (int i = 0; i < dimentions; ++i)
	{
		for (int k = 0; k < dimentions; ++k)   //инициализиране на матрицата
			std::cin >> maze[i][k];
	}

	//std::cout << "\nMaze:\n";
	//print(maze, dimentions);            //принтиране на матрицата

	// Можеше направо и тях unsigned да ги пишеш, избягваш проверките за < 0.
	int start_x, start_y;
	std::cout << "Choose starting point (x y):";
	std::cin >> start_x >> start_y;
	if (!std::cin || start_x<0 || start_x>=dimentions
		          || start_y<0 || start_y>=dimentions)
	{
		std::cerr << "Invalid values!";      //валидиране на началната позиция
		return ;
	}

	// Същото нещо тук.
	int end_x, end_y;
	std::cout << "Choose final position (x y):";
	std::cin >> end_x >> end_y;
	if (!std::cin || end_x < 0 || end_x >= dimentions
		          || end_y < 0 || end_y >= dimentions)
	{
		std::cerr << "Invalid values!";     //валидиране на крайната позиция
		return ;
	}

	std::cout << "Result:\n";
	std::cout << std::boolalpha << path(maze, start_x, start_y, end_x, end_y, dimentions);

	deallocate(maze, dimentions);       //освобождаване на паметта за матрицата
}

int main()
{
	output();
	return 0;
}

//Тестов пример:
//0 1 0 1 1 0 1 0 0 1 0 0 0 0 1 1 0 1 1 0 1 0 1 0 0 1 0 0 0 0 0 1 0 0 0 1 1 1 0 0 0 1 0 0 0 1 1 0 0 1 0 1 0 0 1 1 0 1 0 0 1 0 0 0
