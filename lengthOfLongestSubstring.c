#include <stdio.h>

int ifDump(char *s, int index, int start);

int ifDump(char *s, int index, int start) {
    for (int j = start; j < index; ++j) {
        if (s[index] == s[j]) {
            return j;
        }
    }

    return -1;
}

int lengthOfLongestSubstring(char *s) {
    int len = 0;
    int tmpLen = 0;
    int startIndex = 0;
    for (int i = 0; ; ++i) {
        if (s[i] != '\0') {
            int dumpIndex = ifDump(s, i, startIndex);
            if (dumpIndex >= 0) {
                len = len > tmpLen ? len : tmpLen;
                tmpLen = i - dumpIndex;
                startIndex = dumpIndex + 1;
                printf("Dump index: %d value: %c, lenth: %d.\n", i, s[i], len);
            } else {
                ++tmpLen;
            }
        } else {
            break;
        }
    }
    return len > tmpLen ? len : tmpLen;
}

int main() {
  char *s = NULL;
  s = "dasflmjdiofjewojffdhosfeowjfsfdsafsfsafsaf";
  int ret = lengthOfLongestSubstring(s);
  printf("ret: %d.\n", ret);
  return 0;
}
