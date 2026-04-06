
//  gcc rebota2.c -o rebota2 -lncurses

#include <ncurses.h>
#include <unistd.h>

#define DELAY 50000

int main(int argc, char *argv[]) {
 int x = 5, y = 0;
 int max_y = 20, max_x = 80;
 int next_x = 0;
 int directionx = 1;
 int next_y = 0;
 int directiony = 1;

 int x_p1 = 1, y_p1 = 10, x_p2 = max_x - 2, y_p2 = 10;
 int ch = 0;

 int score_p1 = 0, score_p2 = 0;

 initscr();
 noecho();
 cbreak();
 curs_set(FALSE);
 nodelay(stdscr, FALSE);

 mvprintw(max_y/2, (max_x/2) - 5, "PONG GAME");
 mvprintw((max_y/2) + 1, (max_x/2) - 15, "Player 1: W/Q to move");
 mvprintw((max_y/2) + 2, (max_x/2) - 15, "Player 2: O/P to move");
 mvprintw((max_y/2) + 3, (max_x/2) - 15, "First to 5 points wins");
 mvprintw((max_y/2) + 4, (max_x/2) - 15, "Press any key to start");
 refresh();
 getch();
 nodelay(stdscr, TRUE);

 
 while(1) {
 	clear();
 	mvprintw(y, x, "o");
for (int i = 0; i < 4; i++)
 	mvprintw(y_p1 + i, x_p1, "|");
for (int i = 0; i < 4; i++)
 	mvprintw(y_p2 + i, x_p2, "|");
	mvprintw(0, 2, "Player 1: %d", score_p1);
	mvprintw(0, 20, "Player 2: %d", score_p2);
 	refresh();


    ch = getch();
    if (ch == 'q')
           y_p1 -= 1;
    else if (ch == 'w')
           y_p1 += 1;
	else if (ch == 'o')
		   y_p2 -= 1;
	else if (ch == 'p')
		   y_p2 += 1;
 	
 	usleep(DELAY);

 	next_x = x + directionx;
 	next_y = y + directiony;


	if (next_x == x_p2 && y >= y_p2 && y <= y_p2 + 4) {
		directionx*= -1;
	}
	else if (next_x == x_p1 && y >= y_p1 && y <= y_p1 + 4) {
		directionx*= -1;
	}
	else if (next_x >= max_x) {
		score_p1++;
		clear();
		mvprintw(max_y/2, (max_x/2) - 7, "Player 1 Scores!");
		refresh();
		sleep(1);
		x = 5;
		y = 0;
	} else if (next_x < 0) {
		score_p2++;
		clear();
		mvprintw(max_y/2, (max_x/2) - 7, "Player 2 Scores!");
		refresh();
		sleep(1);
		x = max_x - 6;
		y = 0;
	} else {
		x+= directionx;
	}


 	if (next_y >= max_y || next_y < 0) {
 		directiony*= -1;
 	} else {
 		y+= directiony;
 	}
	if(score_p1 == 5 || score_p2 == 5) {
		clear();
		if(score_p1 == 5) {
			mvprintw(max_y/2, (max_x/2) - 7, "Player 1 Wins!");
		} else {
			mvprintw(max_y/2, (max_x/2) - 7, "Player 2 Wins!");
		}
		refresh();
		sleep(3);
		break;
	}
 }

 endwin();
}
