#include "Gomoku.h" 
#include<iostream>
using namespace std;

int main() {

    Gomoku game;
    game.welcome();
    system("CLS");
    game.show();
    int x, y;
    char player = '0';

    while (1)
    {
        cout << " (Y: 直 X: 橫    X、Y都按0時, 結束遊戲)  " << endl;

        //輸入座標
        cout << "X:";
        cin >> x;
        cout << "Y:";
        cin >> y;

        if (x == 0 && y == 0)
        {
            //如果X、Y都輸入0,結束迴圈 
            cout << "\n結束遊戲!\n";
            break;
        }
        else
        {
            x--;
            y--;
            //因為陣列起始為0,所以輸入的值需要-1
        }
        system("CLS"); //清除螢幕畫面
        bool TFset = game.tfSet(player, x, y); // 判斷有效輸入
        game.show(); //更新地圖顯示

        if (game.winner(player, x, y))
        {
            //判斷頭飾,若有玩家獲勝,輸出提示後結束迴圈 
            cout << endl << player << "玩家獲勝\n";
            break;
        }

        if (game.mapOver())
        { // 滿圖，不分勝負
            cout << endl << "不分勝負" << endl;
            break;
        }

        if (TFset)
        {
            //若為有效輸入即更換棋子 player:
            if (player == '0')
                player = '@';
            else
                player = '0';
        }
    }
}

