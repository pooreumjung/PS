#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {

    vector<int> st;
    int answer = 0;

    for(int x : ingredient){

        st.push_back(x);

        int size = st.size();

        // 마지막 4개가 1 2 3 1인지 확인
        if(size >= 4 &&
           st[size - 4] == 1 &&
           st[size - 3] == 2 &&
           st[size - 2] == 3 &&
           st[size - 1] == 1){

            // 햄버거 제거
            st.pop_back();
            st.pop_back();
            st.pop_back();
            st.pop_back();

            answer++;
        }
    }

    return answer;
}