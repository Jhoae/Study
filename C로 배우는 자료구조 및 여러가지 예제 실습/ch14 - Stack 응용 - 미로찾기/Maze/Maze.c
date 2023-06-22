#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "pos.h"
#include "pos.c"

#define MAX 100 
#define PATH 0	// 지나갈 수 있는 위치
#define WALL 1	// 지나갈 수 없는 위치
#define VISITED 2	// 이미 방문한 위치	
#define BACKTRACKED 3	// 방문했다가 되돌아 나온 위치

int maze[MAX][MAX];
int n; // 미로의 크기

void read_maze();
void print_maze();
bool movable(Position pos, int dir);

int main()
{
	read_maze();

	Stack s = create();
	Position cur;
	cur.x = 0;
	cur.y = 0;

	int init_dir = 0; // 어떤 위치에 도달했을때, 처음 시도해볼 이동 방향

	while (1) {
		maze[cur.x][cur.y] = VISITED;
		if (cur.x == n - 1 && cur.y == n - 1) {
			printf("Found the path.\n");
			break;
		}
	
		bool forwarded = false;
		for (int dir = init_dir; dir < 4; dir++) {
			if (moveable(cur, dir)) {
				push(s, dir);
				cur = move_to(cur, dir);
				forwarded = true;
				init_dir = 0;
				break;
			}
		}

		if (!forwarded) { // 4방향중 어느곳으로도 가지 못했다면
			maze[cur.x][cur.y] = BACKTRACKED; // 왔다가 되돌아간 위치임을 표시
			if (is_empty(s)) { // 되돌아갈 위치가 없다면 원래 길이 없는 미로
				printf("No path exists.\n");
				break;
			}

			int d = pop(s);
			cur = move_to(cur, (d + 2) % 4); // 남(2) <-> 북(0) , 동(1) <-> 서(3)

			init_dir = d + 1; // 되돌아간 위치에서는 d+1번 방향부터 시도
		}
	}
	print_maze();
	}