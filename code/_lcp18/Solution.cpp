//
// Created by DHL on 2022/7/30.
//

class Solution {
public:
    int breakfastNumber(vector<int> &staple, vector<int> &drinks, int x) {
        int *arr = new int[x + 1]();
        int slen = staple.size();
        for (int i = 0; i < slen; i++) {
            if (staple[i] > x) continue;
            arr[staple[i]]++;
        }

        for (int i = 1; i <= x; i++) {
            arr[i] += arr[i - 1];
        }

        int dlen = drinks.size();
        int ans = 0;
        for (int i = 0; i < dlen; i++) {
            if (drinks[i] > x) continue;
            ans += arr[x - drinks[i]];
            ans = ans % 1000000007;
        }
        delete[] arr;
        return ans;
    }
};