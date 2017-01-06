#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums);

void sortv(vector<int> &vec);

vector<vector<int> > threeSum(vector<int>& nums) {
    vector< vector<int> >ret;

    if (nums.size() < 2) {
        return ret;
    }

    if (nums.size() == 3) {
        if (nums[1] + nums[2] + nums[0] == 0) {
            ret.push_back(nums);
        }

        return ret;
    }

    sortv(nums);

    int size = nums.size();
    int last_1;
    int last_2;
    int last_3;

    for (vector<int>::const_iterator it = nums.cbegin(); it != (nums.cend() - 2); it++) {
        int first = *it;
//        cout<<"first and last_1"<<first<<last_1<<endl;
        if (it != nums.cbegin()) {
            if (first == last_1) {
//                cout<<"same first"<<first<<endl;
                continue;
            }
        }

        last_1 = first;
        // 2rd Loop
        for (vector<int>::const_iterator it2 = it + 1; it2 != (nums.end() - 1); it2++) {
            int second = *it2;
//            cout<<"No.2 for loop: "<<(*it2)<<" last2: "<<last_2<<endl;
            if (it2 != it + 1) {
                if (second == last_2) {
//                    cout<<"same second"<<second<<endl;
                    continue;
                }
            }
            last_2 = second;
            // Third loop
            for (vector<int>::const_iterator it3 = it2 + 1; it3 != nums.end(); it3++) {
                int third = *it3;
                if (it3 != it2 + 1) {
                    if (third == last_3) {
//                        cout<<"same third"<<third<<endl;
                        continue;
                    }
                }
                last_3 = third;

                if (*it3 + second + first) {
                    continue;
                } else {
                    vector<int> tmp;
                    tmp.push_back(first);
                    tmp.push_back(second);
                    tmp.push_back(*it3);
                    ret.push_back(tmp);
//                    cout<< *it3 << second << first <<endl;
                }
            }

        }
    }

    return ret;
}

void sortv(vector<int> &vec) {
    for (int i = vec.size(); i > 0; --i) {
        for (int j = 0; j < i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                int t = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = t;
            }
        }    
    }
    
//    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
//        cout<<"Sort:"<<(*it)<<endl;
//    }
}

int main() {
cout<< "xxx" << endl;
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

vector< vector<int> > ret = threeSum(vec2);

for (int i = 0; i < ret.size(); ++i) {
    cout<<"start: "<<i<<endl;
    for (int j = 0; j < 3; ++j) {
        cout<<ret[i][j]<<endl;
    }
    cout<<"end."<<endl;
}
return 0;
}
