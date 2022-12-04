#pragma once
#include <stack>
#include <vector>

//通过回溯法来解决N皇后问题

//N皇后类定义，x,y 表示在棋盘上的坐标，重载运算符 == 和 !=
//当皇后在攻击路径上时，判断为 == 
struct Queen{ 
    int x, y;
    Queen(int xx = 0, int yy = 0): x(xx), y(yy) {};
    bool operator== (const Queen &q) const {
        return  (x == q.x)
                || (y == q.y)
                || (x + y == q.x + q.y)
                || (x - y == q.x - q.y);
    }
    bool operator!= (const Queen &q) const {
        return !(*this == q);
    }
};

extern std::vector<std::vector<Queen>> soluRecord;  //用来记录所有的全局解
bool isQueenValid(std::stack<Queen> staQ, Queen q); //用来判断当前皇后是否与前面的皇后冲突
void record(std::stack<Queen> solu);                //用来将全局解进行记录    
void placeQueens(int N);                            //回溯程序
void soluDisplay(std::vector<Queen> solu);          //展示棋盘
void testNQueens();

