#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int numberOfPairs(vector<pair< long long, int > >& arr) {
    int res = 0;
    sort(arr.begin(), arr.end());
    /* vector< pair < int, int > > logs; */
    /* logs.push_back(make_pair(i, j)); */
    /* for (int k = 0; k < logs.size(); k++ ) { */
    /*     cout << logs[k].first << " " << logs[k].second << endl; */
    /* } */

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (( arr[i].first * arr[j].first ) == ( arr[i].second + arr[j].second )) res++;
            if (( arr[i].first * arr[j].first ) > 2 * arr.size()) break;
        }
    }
    return res;
}

int main() {
    int numberTestCases;
    cin >> numberTestCases;
    vector<int> results;

    for (int i = 0; i < numberTestCases; i++) {
        int arrayLength;
        vector< pair < long long, int > > array;

        cin >> arrayLength;
        long long number;
        for (int j = 0; j < arrayLength; ++j) {
            cin >> number;
            array.push_back(make_pair(number, j + 1));
        }
        results.push_back(numberOfPairs(array));
    }

    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }
    return 0;
}
