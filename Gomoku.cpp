#include "Gomoku.h" 
#include <iostream> 
using namespace std;

Gomoku::Gomoku() {
	//地圖初始化
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			map[i][j] = ' ';
		}
	}
}

bool Gomoku::winner(char player, int x, int y)
{
	//上述四個判斷有一個成立,及獲勝
	if (colWin(player, x, y) || rowWin(player, x, y) || obliWinl(player, x, y) || obliWin2(player, x, y))
		return true;
	else
		return false;
}

bool Gomoku::tfSet(char player, int x, int y)
{
	//輸入棋子位置
	if (x >= 0 && x < 15 && y >= 0 && y < 15 && map[y][x] == ' ') {
		map[x][y] = player;
		return true;
	}
	else
	{
		cout << "無效的輸入, 請重新輸入。" << endl;
		system("pause");
		system("CLS");
		return false;
	}
}

bool Gomoku::mapOver()
{
	//搜尋是否滿盤,只要有一個是空的,地圖就不為滿
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			if (map[i][j] == ' ')
				return false;

	return true;
}

void Gomoku::show() const
{
	//顯示棋盤
	cout << "   01  02  03  04  05  06  07  08  09  10  11  12  13  14  15" << endl; //X座標提示
	for (int i = 14, j=0;i >= 0; i--,j++)
	{
		//地區要倒過來顯示,座標才會接近一般數學使用
		cout << "  一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一" << endl;
		
		if (i + 1 < 10)		
			cout<<"0" << i + 1; //Y座標提示 
		else
			cout << i + 1;

		for (int j = 0; j < 15; j++)
		{
			cout << "| " << map[i][j] << " ";
		}
		cout << "|";

		if (i + 1 >= 10)
			cout << i + 1 << endl;
		else
			cout << "0" << i + 1 << endl; //
	
	}

	cout << "  一一一一一一一一一一一一一一一一一一一一一一一一一一一一一一" << endl;
	cout << "   01  02  03  04  05  06  07  08  09  10  11  12  13  14  15" << endl; //X座標提示

}

void Gomoku::welcome() const
{
	cout << "  ----------------" << endl;
	cout << "| --歡迎遊玩五子棋------|" << endl;
	cout << "  ----------------" << endl;
	cout << "遊戲說明:\n\n" 
		<< " 棋盤為15 * 15大小\n"
		<< " '0'代表白棋, '@'代表黑棋 \n"
		<< " 遊戲由白棋先手, 先達連續五顆棋子者(包含斜著)即獲勝\n"
		<< " 若滿盤(棋盤已滿且無獲勝者)則平手\n"
		<< " X和Y同時輸入0結束遊戲\n\n";

	system("pause");
}

