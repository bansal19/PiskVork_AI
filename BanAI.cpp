/*
BANSAL AI Version 1
methods to include:
public:
	void	Start(uint size);
	void	Restart();
	void 	Begin();
	void 	Play();
	void 	OpponentPlayedThere(uint x, uint y);
	void	PleaseDontbeStupid();
	int		Evaluate();
	void	Dump();
}
*/
#include <ctime>
#include "BanAI.h"

using namespace std;


void			BanAI::Start(int size){

	this->size = size;
	cout << "OK" << endl;
	cout << "MESSAGE : Board Size is " << size << endl;
	map.resize(size, std::vector<int>(size, 0));
	srand(time(NULL));
}

void			BanAI::Restart()
{
}

void			BanAI::Begin()
{
	x = rand() % 20;
	y = rand() % 20;

	if(map[x][y] == 0)
		{
			cout << x << "," << y << endl;
			// DEBUGGING LINE: cout << "MESSAGE : " << input << endl;
			map[x][y] = 1;
		}
}

void			BanAI::Play()
{
	int		score = 0;
	int		best_score = 0;
	int		best_x = 0;
	int		best_y = 0;

	for (int y = 0; y < this->size; ++y)
	{
		for (int x = 0; x < this->size; ++x)
		{
			if (this->map[y][x] == 0)
			{
				this->map[y][x] = 1;

				score = Evaluate();
				if (score > best_score)
				{
					best_score = score;
					best_x = x;
					best_y = y;
				}

				this->map[y][x] = 0;
			}
		}
	}
	this->map[best_y][best_x] = 1;
	cout << best_x << "," << best_y << endl;
	Dump();
}



void 			BanAI::OpponentPlayedThere(int x, int y)
{
	if((x < size) && (y < size))
	{
		map[x][y] = 2;
	}
}

void			BanAI::PleaseDontbeStupid()
{

}

int			BanAI::Evaluate()
{
	static const int	Directions[8][2] = {
		{-1, -1}, {0, -1}, {1, -1},
		{-1, 0}, {1, 0},
		{-1, 1}, {0, 1}, {1, 1}
	};

	int		score = 0;

	if (this->map[y][x] == 1)
	{
		for (int d = 0; d < 8; ++d)
		{
			if (y + Directions[d][1] < this->size && x + Directions[d][0] < this->size && 
				(y + Directions[d][1] > 0) && (x + Directions[d][0] > 0) && 
				this->map[y + Directions[d][1]][x + Directions[d][0]] == 1)
			{
				score += 20;
			}
		}
	}
	return (score);
}

void			BanAI::Dump()
{
  for(int i = 0; i < size; i++)
  {
  	for(int j = 0; j < size; j++)
  	{
  		cout << map[i][j] << " ";
  	}
  	cout << endl;
  }
}


