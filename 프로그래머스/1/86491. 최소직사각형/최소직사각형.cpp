#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxWidth = 0;
    int maxHeight = 0;

    for (int i = 0; i < sizes.size(); i++) {
        int w = max(sizes[i][0], sizes[i][1]);
        int h = min(sizes[i][0], sizes[i][1]);

        maxWidth = max(maxWidth, w);
        maxHeight = max(maxHeight, h);
    }

    return maxWidth * maxHeight;
}