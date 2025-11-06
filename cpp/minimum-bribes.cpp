#include<iostream>
#include<vector>
void minimumBribes(std::vector<int> q) {
    int nBribes = 0;
    for (int idx = q.size()-1; idx >= 0; --idx) {
        //if (q.at(idx) == (idx+1)) continue;
        if ((q.at(idx) - (idx + 1)) > 2) {
            std::cout << "Too chaotic\n";
            return;
        }
        for (int j = std::max(0, q[idx]-2); j < idx; ++j) {
            if (q[j] > q[idx]) ++nBribes;
        }
    }
    std::cout << nBribes << "\n";
}

int main() {
    //minimumBribes({2,1,5,3,4});
    minimumBribes({1,2,5,3,7,8,6,4});
    return 0;
}
