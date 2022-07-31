//
// Created by DHL on 2022/7/31.
//

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        int len = 1001;
        int *result = new int[len]();
        int alen = arr1.size();
        for (int i = 0; i < alen; i++) {
            result[arr1[i]]++;
        }

        int index = 0;
        int blen = arr2.size();
        for (int i = 0; i < blen; i++) {
            int key = arr2[i];
            while (result[key] > 0) {
                arr1[index++] = key;
                result[key]--;
            }
        }

        for (int i = 0; i < len; i++) {
            while (result[i] > 0) {
                arr1[index++] = i;
                result[i]--;
            }
        }
        delete[] result;
        return arr1;
    }
};