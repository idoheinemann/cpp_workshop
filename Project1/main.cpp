
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <vector>
#include <array>
#include <iostream>
#include <functional>
#include <iterator>

using namespace std;


int main() {
    vector<int> v = { 1,2,3,4,5,6,7,8,9,10,12,12,3,6,2,45,3,4,3,2 };
    cout << count(v.begin(), v.end(), 4) << endl;
    cout << count_if(v.begin(), v.end(), [](int i) {return i > 4; }) << endl;
    v.erase(remove_if(v.begin(), v.end(), [](int x) {return x < 8; }), v.end());
    for_each(v.begin(), v.end(), [](int i) {cout << i << " "; });
    cout << endl;
    vector<int> v2 = {};
    adjacent_difference(next(v.begin()), v.end(), back_inserter(v2));
    for_each(v2.begin(), v2.end(), [](int i) {cout << i << " "; });
    cout << endl;
    cout << accumulate(v2.begin(), v2.end(), 0);
}