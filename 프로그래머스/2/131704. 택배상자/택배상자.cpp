#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    stack<int> st;
    int answer = 0;

    // 주 컨테이너 벨트의 상자는 1번부터 순서대로 나옴
    for (int box = 1; box <= order.size(); box++) {
        st.push(box);

        // 현재 보조 벨트 맨 위 상자가 원하는 상자라면 트럭에 적재
        while (!st.empty() &&
               answer < order.size() &&
               st.top() == order[answer]) {
            st.pop();
            answer++;
        }
    }

    return answer;
}