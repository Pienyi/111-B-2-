#ifndef GOMOKU_H
#define GOMOKU_H
class Gomoku {

public:
	Gomoku(); 						//地圖初始化
	bool colWin(char, int, int);	//判斷直向棋子數  
	bool rowWin(char, int, int);	//判斷橫向棋子數 
	bool obliWinl(char, int, int);  //判斷斜向棋子數
	bool obliWin2(char, int, int);	//判斷斜向棋子數
	
private:
	char map[15][15];  // 地圖大小為15 * 15

};


	
#endif // GOMOKU_H
