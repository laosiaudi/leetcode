/*********************************************************************************
*     File Name           :     Bulls_And_Cows.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-11-11 20:05]
*     Last Modified       :     [2015-11-11 20:51]
*     Description         :
**********************************************************************************/
class Solution {
    public:
        string getHint(string secret, string guess) {
            int A = 0;
            int B = 0;

            int m[256]={0};

            for (int i = 0; i < secret.size(); i ++) {
                if (secret[i] == guess[i])
                    A ++;
                else {
                    m[secret[i]] ++;
                }
            }

            for (int i = 0; i < secret.size(); i ++) {
                if (secret[i] != guess[i] && m[guess[i]]) {
                    m[guess[i]] --;
                    B ++;
                }
            }

            string result = to_string(A) + "A" + to_string(B) + "B";
            return result;
        }
};


