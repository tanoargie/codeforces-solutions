#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

bool comp(pair< long long, long long > firstPair, pair< long long, long long > secondPair) {
    return firstPair.first > secondPair.first;
}

int main() {
    int numberOfProducts;
    long long res = 0;
    vector < pair < long long, long long > > orderedByMax;
    cin >> numberOfProducts;
    for (int i = 0; i < numberOfProducts; ++i) {
        long long numberToBuy;
        long long minToHaveDiscount;
        cin >> numberToBuy >> minToHaveDiscount;
        pair < long long, long long > product = make_pair(minToHaveDiscount, numberToBuy);
        orderedByMax.push_back(product);
        /* int begin = 0; */
        /* int end = orderedByMax.size(); */
        /* while(begin + 1 < end) { */
        /*     int middle = ( begin + end ) / 2; */
        /*     if (minToHaveDiscount < orderedByMax[middle].first) { */
        /*         begin = middle; */
        /*     } else { */
        /*         end = middle; */
        /*     } */
        /* } */
        /* if (begin < orderedByMax.size() && ( minToHaveDiscount < orderedByMax[begin].first)) { */
        /*     orderedByMax.insert(orderedByMax.begin() + begin + 1, product); */
        /* } else { */
        /*     orderedByMax.insert(orderedByMax.begin() + begin, product); */
        /* } */
    }
    sort(orderedByMax.begin(), orderedByMax.end(), comp);

    /* for (int i = 0; i < orderedByMax.size(); i++) { */
    /*     cout << i << " " << orderedByMax[i].first << " " << orderedByMax[i].second  << endl; */
    /* } */

    int begin = 0;
    int end = orderedByMax.size() - 1;

    long long boughtItemsAtTheMoment = 0;
    while(begin <= end) {
        if (boughtItemsAtTheMoment >= orderedByMax[end].first) {
            res += orderedByMax[end].second;
            boughtItemsAtTheMoment += orderedByMax[end].second;
            end--;
        } else {
            long long req = min(orderedByMax[end].first - boughtItemsAtTheMoment, orderedByMax[begin].second);
            boughtItemsAtTheMoment += req;
            orderedByMax[begin].second -= req;
            res += 2 * req;
            if (orderedByMax[begin].second == 0) {
                begin++;
            }
        }
    }

    cout << res << endl;

    return 0;
}
