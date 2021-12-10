#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool compare(vector<int> v1, vector<int> v2) {
      return v1[0] == v2[0] && v1[1] == v2[1];
    }

    void myqsort(vector<int> &vec, int start, int end) {
      if (end > vec.size() ) { return;}
      if (end - start <= 1) { return; }
      int mid = vec[start];
      int pivot_idx = start + 1;
      for (int i = start + 1; i < end; ++i) {
        if (vec[i] < mid) {
          int t = vec[i];
          vec[i] = vec[pivot_idx];
          vec[pivot_idx] = t;
          ++pivot_idx;
        }
      }
      vec[start] = vec[pivot_idx - 1];
      vec[pivot_idx - 1] = mid;

      myqsort(vec, start, pivot_idx);
      myqsort(vec, pivot_idx, end);
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
      vector< vector<int> >ret;

      if (nums.size() < 2) { return ret; }

      if (nums.size() == 3) {
        if (nums[1] + nums[2] + nums[0] == 0) {
          ret.push_back(nums);
        }
        return ret;
      }

      myqsort(nums, 0, nums.size());

      for (vector<int>::const_iterator it = nums.cbegin(); it != (nums.cend() - 2); it++) {
        int first = *it;
        cout << "first " << first << endl;
        if (!ret.empty()) { if(first == ret.back().front()) { continue; } }

        int tar = -*it;
        // 2rd Loop
        for (int j = it - nums.cbegin() + 1; j < nums.size() - 1; ++j) {
          if (!ret.empty()) {
            if(first == ret.back()[0] && second == ret.back()[1]) { continue; }
          }
          int second = nums[j];
          int third_tar = tar - second;
          cout << "2: " << second << " 3: " << third_tar << endl;
          bool found = false;
          if (third_tar >= second) {
            int search_start = j + 1;
            int search_end = nums.size();
            int idx;
            while(search_end > search_start) {
              idx = (search_start + search_end) / 2;
              cout << "idx " << idx << " num " << nums[idx] << endl;
              if (nums[idx] < third_tar) {
                search_start = idx;
              } else if (nums[idx] > third_tar) {
                search_end = idx;
                continue;
              } else { found = true; break; }
              if (search_start + 1 == search_end) { break; }
            }
          }

          if (found) {
            std::vector<int> oneret;
            oneret.push_back(first);
            oneret.push_back(second);
            oneret.push_back(third_tar);
            bool du = false;
            /*for (const auto &v : ret) {
              if (compare(v, oneret)) { du = true; break; }
            }*/
            if (!du) {
              ret.push_back(oneret);
              // cout << " found " << first << ", " << second << ", " << third_tar << endl;
            }
          }
        }
      }

      return ret;
    }
};

int main() {
  vector<int> vec;
  vec.push_back(-1);
  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(-1);
  vec.push_back(-4);

  vector<int> vec2;
  vec2.push_back(0);
  vec2.push_back(0);
  vec2.push_back(0);

  Solution s;
  vector< vector<int> > ret = s.threeSum(vec);

  for (int i = 0; i < ret.size(); ++i) {
    cout<<"start: "<<i<<endl;
    for (int j = 0; j < 3; ++j) {
      cout<<ret[i][j]<<endl;
    }
    cout<<"end."<<endl;
  }
  return 0;
}
