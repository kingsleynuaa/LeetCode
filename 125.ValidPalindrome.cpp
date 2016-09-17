class Solution {
public:
//isalnum 存在与cctype头文件中，若为数字或字母，返回值非0，否则返回0

    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        for(int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            while(!isalnum(s[i]) && i < j) i++;
            while(!isalnum(s[j]) && i < j) j--;
            if(tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};
