#define WD   15 /* 정사각형의 한 변의 길이를 15로 */
#define X    300
#define Y    40 /* 화면 위치 (300,40)에서 정사각형을 그리기 시작 */
#define DX   45
#define STX  49

void base_block(void);

void test_board(int ny);
void back_screen(void); /* 배경을 그리는 함수 */
void clear_board(void);  /* 테트리스 board를 초기화하는 함수 */
void comp_board(int num, int m, int nx, int ny, int *test); /* 테트리스 board와 벽돌을 비교하는 함수 */
void set_board (int num, int m, int nx, int ny); /* board에 1을 써넣는 함수 */

void erase(int num, int m, int nx, int ny);
void draw (int num, int m, int nx, int ny);

int  Pause(void);
void sound1(void);
void sound2(void);
void sound3(void);
void sound4(void);
void sound5(void);
void highscr(void);
void display_score(void);

void gprintf(const int xpos, const int ypos, char *format, ... );
void OpenScreen(void);
void CloseScreen(void);



unsigned char board[21][12]; /* 테트리스 화면과 1대 1로 대응하는 board 배열 선언  */

/* 배열의 확장-회전한 모양까지 배열에 저장 */
/* 테트리스의 7가지 모양을 배열에 저장시킴 */
const static char block[7][4][4][4] = {
	{ /* #1 Begin */
		{
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		}
	}, /* #1 End */

	{  /* #2 Begin */
		{
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		}
	}, /* #2 End */

	{  /* #3 Begin */
		{
			{0,1,0,0},
			{1,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{1,1,0,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,1,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,1,0},
			{0,1,0,0},
			{0,0,0,0}
		}
	}, /* #3 End */

	{  /* #4 Begin */
		{
			{0,0,1,0},
			{1,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{1,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		{
			{1,1,1,0},
			{1,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{1,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,0,0,0}
		}
	}, /* #4 End */

	{  /* #5 Begin */
		{
			{1,0,0,0},
			{1,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{1,1,1,0},
			{0,0,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{1,1,0,0},
			{1,0,0,0},
			{1,0,0,0},
			{0,0,0,0}
		}
	}, /* #5 End */

	{ /* #6 Begin */
		{
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{1,1,0,0},
			{1,0,0,0},
			{0,0,0,0}
		},
		{
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{1,1,0,0},
			{1,0,0,0},
			{0,0,0,0}
		}
	}, /* #6 End */

	{  /* #7 Begin */
		{
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		{
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0},
			{0,0,0,0}
		}
	} /* #7 End */

};

const static int color[8] = { 0,1,2,3,4,5,6,7 }; /* 색깔을 배열에 저장 */
static unsigned long newscr; /* 점수를 저장할 변수 선언 */

void InitGR(void);
void gprintf_XY( int xloc, int yloc, const int fc, const int bc, char *fmt, ... );