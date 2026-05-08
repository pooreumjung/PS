#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int>s;
int solution(vector<vector<int>> board, vector<int> moves) {
    int count = 0;
    for(int i=0;i<moves.size();i++){
        int move = moves[i];
        for(int j=0;j<board.size();j++){
            if(board[j][move-1] != 0){
                int temp = board[j][move-1];
                board[j][move-1]=0;
                if(s.empty())
                    s.push(temp);
                else{
                    if(s.top()==temp){
                        s.pop();
                        count+=2;
                    }
                    else
                        s.push(temp);
                }
                break;
            }
        }
    }
    return count;
}

// 첫 번째 보드가 가장 상단이다
// 즉 moves가 걸리면 board의 x좌표를 증가시키면서 찾는다
// 찾으면 stack에 넣고, s.top()이랑 같으면 삭제시킨다