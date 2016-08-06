#include<string>
class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cow = 0;
        vector<int> s(10,0);
        vector<int> g(10,0);
        int sSize = secret.size();
        int sGuess = guess.size();
        if(sSize != sGuess || sSize <= 0 || sGuess <= 0)
            return "0A0B";
        for(int i = 0; i < sSize; i++)
        {
            char ch1 = secret[i];
            char ch2 = guess[i];
            if(ch1 == ch2)
                bull++;
            else{
                s[ch1-'0']++;
                g[ch2-'0']++;
            }
        }
        
        for(int i = 0; i < s.size(); i++)
        {
            cow += (s[i] <= g[i] ? s[i] : g[i]);
           // cout << endl << "s:" << s[i] << endl;
            //cout << endl << g[i] << endl;
            
        }
       // cout << cow;
        
        return to_string(bull) + 'A' + to_string(cow) + 'B';
        
    }
};
