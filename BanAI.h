/*
Bansal Gomoku AI: Version 1
EMPTY = 0
BanAI = 1
OPPONENT = 2
*/
#include <map>
#include <iostream>
#include <vector>
#include <ctime>

typedef	std::vector<std::vector<int> >	Map;

class BanAI
{

private:
	Map 	map;
	int		size;
	int		x;
	int		y;
	int		opponentX;
	int		opponentY;

public:
	void	Start(int size);
	void	Restart();
	void 	Begin();
	void 	Play();
	void 	OpponentPlayedThere(int x, int y);
	void	PleaseDontbeStupid();
	void	Simulate(int x, int y);
	int		Evaluate();
	void	Dump();
};