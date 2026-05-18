#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;

    for (int height = 1; height * height <= total; height++) {
        if (total % height != 0) continue;

        int width = total / height;

        if ((width - 2) * (height - 2) == yellow) {
            return {width, height};
        }
    }

    return {};
}