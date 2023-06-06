#ifndef GOMOKU_H
#define GOMOKU_H
class Gomoku {

public:
	Gomoku(); 						//地圖初始化
	bool colWin(char, int, int);	//判斷直向棋子數  
	bool rowWin(char, int, int);	//判斷橫向棋子數 
	bool obliWinl(char, int, int);  //判斷斜向棋子數
	bool obliWin2(char, int, int);	//判斷斜向棋子數
	bool winner(char, int, int);	//上述四個判斷有一個成立,及獲勝
	bool tfSet(char, int, int);		//輸入棋子位置
	bool mapOver();					//搜尋是否滿盤,只要有一個是空的,地圖就不為滿
	void show() const;				//顯示棋盤
	void welcome() const;
private:
	char map[15][15];  // 地圖大小為15 * 15

};


	
#endif // GOMOKU_H
