#include <stack>
#include <vector>
#include <iostream>
#include "nQueen.h"

std::vector<std::vector<Queen>> soluRecord;

bool isQueenValid(std::stack<Queen> staQ, Queen q)
{
    while(!staQ.empty())
    {
        Queen tempQue = staQ.top();
        if(tempQue == q)
        {
            return false;
        }
        staQ.pop();
    }
    return true;
}

void record(std::stack<Queen> solu)
{
    std::vector<Queen> tempSolu;
    while(!solu.empty())
    {
        tempSolu.emplace_back(solu.top());
        solu.pop();
    }
    soluRecord.emplace_back(tempSolu);
}

void placeQueens(int N)
{
    std::stack<Queen> staQueens;
    Queen q(0, 0);
    while(q.x > 0 || q.y < N)
    {
        if(staQueens.size() >= N || q.y >= N)
        {
            q = staQueens.top();
            staQueens.pop();
            q.y++;
        }
        else
        {
            while(q.y < N && !isQueenValid(staQueens, q))
            {
                q.y++;
            }
            if(q.y < N)
            {
                staQueens.push(q);
                if(staQueens.size() >= N)
                {
                    record(staQueens);
                }
                q.x++;
                q.y = 0;
            }
        }
    }
}
void soluDisplay(std::vector<Queen> solu)
{
    int n = solu.size();
    std::vector<std::vector<char>> chessboard(n, std::vector<char>(n, '.'));
    for(Queen q : solu)
    {
        chessboard[q.x][q.y] = 'Q';
    }
    for(auto boardRow : chessboard)
    {
        for(char chess : boardRow)
        {
            std::cout << chess << "\t";
        }
        std::cout << std::endl;
    }
}

void testNQueens()
{
    int N = 0;
    std::cout << "Please input the num of queens:\t";
    std::cin >> N;
    
    placeQueens(N);
    int numSolus = soluRecord.size();

    for(auto solu : soluRecord)
    {
        soluDisplay(solu);
        std::cout << std::endl;
        std::cout << std::string(40, '-') << std::endl;
        std::cout << std::endl;
    }
    printf("%d queens have %d solutions.\n", N, numSolus);
}
