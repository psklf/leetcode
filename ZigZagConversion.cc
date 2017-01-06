#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
       string convert(string s, int numRows) {
            if (numRows == 1) {
                return s;
            }

            int length = s.length();
            int every = 2 * (numRows -1);
            int num = length / every;

            string str;
            string *str_list = new string[num + 1];
            for (int i = 0; i < num; ++i) {
                int start = i * every;
                string tmp(s, start, every);
                cout<<tmp<<endl;
                str_list[i] = tmp;
            }
            int mm = length % every;
            if (mm) {
                str_list[num] = string(s, length - mm, mm);
            }

            // split finish

            for (int j = 0; j < numRows; ++j) {
                for (int i = 0; i < num + 1; ++i) {
                    if (i == num) {
                        int char_length = str_list[i].length();
                        if (j < char_length) {
                            str += str_list[i][j];

                            if (j != 0 && j != numRows - 1 && (every - j) < char_length) {
                                str += str_list[i][every - j];
                            }
                        }

                    } else {
                        str += str_list[i][j];
                        if (j != 0 && j != numRows - 1) {
                            str += str_list[i][every - j];
                        }
                    }

                }
            }

            delete [] str_list;
            return str;
        }

};


int main() {
    Solution so = Solution();
    string s("abcdefghijklmnopqrstuvwxyz");
    string s1("PAYPALISHIRING");
    // so.convert(s, 3);
    cout<<so.convert(s1, 2)<<endl;
    return 0;
}
