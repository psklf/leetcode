#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
  public:
    bool checkWord(unsigned long &mask, string &word) {
      for (auto c : word) {
        unsigned long v = pow(2, static_cast<int>(c - 'a') );
        if (mask & v) { return false;}
        mask |= v;
      }
      return true;
    }

    int maxLength(vector<string>& arr) {
      unsigned int len = arr.size();
      unsigned long combine_mask = pow(2, len) - 1;
      int max = 0;
      cout << " combine mask " << std::hex <<  combine_mask << " upper size " << pow(2, len)<< endl;
      while (combine_mask > 0x0){
        cout << " combine mask " << combine_mask << endl;
        // get string
        int each_len = 0;
        unsigned long word_mask = 0x0;
        for (int i = 0;i < len; ++i) {
          unsigned long m = pow(2,i);
          if (m & combine_mask) {
            // cout << "m " << m << " i "<<i << endl;
            std::cout << "check word " << arr[i] << endl;
            if (checkWord(word_mask, arr[i])) {
              each_len += arr[i].size();
            } else {
              each_len = 0; break;
            }
          }
        }
        cout << "this length is  " << each_len << endl;
        if (max < each_len) { max = each_len; }
        combine_mask = combine_mask - 0x1;
      }
      return max;
    }
};


int main() {
  std::vector<string> testcase{"abc", "def", "dcj"};
  Solution so;
  std::cout << "result "<< so.maxLength(testcase) << endl;

  return 0;
}
