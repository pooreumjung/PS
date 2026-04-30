#include <string>

using namespace std;

// 문자열 순자 변환 함수
char func(string s)
{
    if (s == "zero")
        return '0';
    else if (s == "one")
        return '1';
    else if (s == "two")
        return '2';
    else if (s == "three")
        return '3';
    else if (s == "four")
        return '4';
    else if (s == "five")
        return '5';
    else if (s == "six")
        return '6';
    else if (s == "seven")
        return '7';
    else if (s == "eight")
        return '8';
    else if (s == "nine")
        return '9';
    else
        return 'n';
}

// 문자열 판정 함수
string func2(string s)
{
    string temp = "", answer = "";

    // s 길이만큼 탐색
    for (int i = 0; i < s.length(); i++)
    {
        temp.push_back(s[i]);

        if (temp.length() >= 3)
        {
            // temp가 변경 가능한 문자열인지 확인하기
            char c = func(temp);
            if (c == 'n')
                continue;
            // 변경 가능하다면 answer에 넣고 temp 초기화
            else
            {
                answer.push_back(c);
                temp = "";
            }
        }
    }
    return answer;
}
int solution(string s)
{
    string temp = "", answer = "";

    for (int i = 0; i < s.length(); i++)
    {
        // 숫자를 만난 경우
        if (isdigit(s[i]))
        {
            // temp가 존재한다면
            if (temp.length())
            {
                answer += func2(temp);
                temp = "";
            }
            answer.push_back(s[i]);
        }
        // 그냥 문자인 경우 => temp를 쌓거나 정수 반환
        else
        {
            temp.push_back(s[i]);
            if (temp.length() >= 3)
            {
                if (func(temp) != 'n')
                {
                    answer += func2(temp);
                    temp = "";
                }
            }
        }
    }

    return stoi(answer);
}