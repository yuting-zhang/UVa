#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    string line;
    getline(cin, line);
    int N = stoi(line);
    while (N--) {
        getline(cin, line);
        istringstream sin(line);
        vector<int> nums;
        int num;
        while (sin >> num)
            nums.push_back(num);
        int solution = 1;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] > nums[j])
                    solution = max(solution, gcd(nums[i], nums[j]));
                else
                    solution = max(solution, gcd(nums[j], nums[i]));
        printf("%d\n", solution);
    }
    return 0;
}
