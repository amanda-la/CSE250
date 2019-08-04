#ifndef A3_HPP
#define A3_HPP

#include <iostream>
#include <list>
#include "Maze.hpp"

class coor{
public:
	int x, y, d;
	coor(int, int, int);
};

coor::coor(int a, int b, int c){
	x = a;
	y = b;
	d = c;
}

// implement your function distance
int distance(Maze& maze, int sx, int sy, int fx, int fy) {

	std::list<coor> queue;
	queue.push_back(coor(sx, sy, 0));
	maze.mark(sx, sy);
	

	while(!queue.empty()){
		int posx = queue.front().x;
		int posy = queue.front().y;
		int posd = queue.front().d;

		//left check
		if(!maze.is_visited(posx - 1, posy) && maze.is_open(posx - 1, posy)){
			maze.mark(posx-1, posy);
			queue.push_back(coor(posx-1, posy, posd + 1));
		}

		//right check
		if(!maze.is_visited(posx + 1, posy) && maze.is_open(posx + 1, posy)){
			maze.mark(posx + 1, posy);
			queue.push_back(coor(posx + 1, posy, posd + 1));
		}

		//up check
		if(!maze.is_visited(posx, posy - 1) && maze.is_open(posx, posy - 1)){
			maze.mark(posx, posy -1);
			queue.push_back(coor(posx, posy - 1, posd + 1));
		}

		//down check
		if(!maze.is_visited(posx, posy + 1) && maze.is_open(posx, posy + 1)){
			maze.mark(posx, posy + 1);
			queue.push_back(coor(posx, posy + 1, posd + 1));
		}


		//neighbor dest check
		if((posx-1 == fx && posy == fy) || (posx + 1 == fx && posy == fy) || 
			(posx == fx && posy - 1 == fy) || (posx == fx && posy + 1 == fy)){
			break;
		}

		queue.pop_front();
		
	} // while loop
	
	return queue.front().d + 1;

} // distance

#endif // A3_HPP
