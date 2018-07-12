#include <iostream>
#include <string>
#include <stdlib.h>     
#include <vector>
#include <climits>
#include <ctime>

#include		"BanAI.h"

using namespace std;

typedef unsigned int uint;
/*
To save the gamestate, I am creating a vector-by-vector map that initialises.
EMPTY : 0
BANAI: 1
OPPONENT: 2 
*/

int main()
{
	int 		size;
	int 		x;
	int 		y;
	int			opponentx;
	int 		opponenty;
	string 		input;
	BanAI 		gameplayer;

	std::vector<std::vector<int> >	Map;

	while (1)
	{
		getline(cin, input);
		if(input.compare(0, 6, "START ") == 0)
		{
			size = atoi(input.c_str() + 6);
			gameplayer.Start(size);

		} else if (input.compare(0, 5, "TURN ") == 0)
		{
			opponentx = atoi(input.c_str() + 5);
			opponenty = atoi(input.c_str() + input.find_first_of(',') + 1);

			gameplayer.OpponentPlayedThere(opponentx, opponenty);
			gameplayer.Play();
			
		} else if (input == "BEGIN") {

			gameplayer.Begin();
		}
	}
}

