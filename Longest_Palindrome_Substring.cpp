/*********************************************************************************
*     File Name           :     Longest_Palindrome_Substring.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-26 00:31]
*     Last Modified       :     [2015-10-26 01:41]
*     Description         :
**********************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
    public:
        string longestPalindrome(string s) {
            int size = s.size();
            if (size == 0)
                return "";
            bool pa[size][size];  
            memset(pa, false, size*size*sizeof(bool));  

            int maxLen = 1;
            int start = 0;
            int end = 0;
            for (int j = 0; j < size; j ++) {
                for (int i = 0; i < j; i ++) {
                    if (i + 1 == j)
                        pa[i][j] = s[i] == s[j];
                    else {
                        pa[i][j] = s[i] == s[j] && pa[i + 1][j - 1];
                    }
                    if (pa[i][j] && maxLen < j - i + 1) {
                        maxLen = (j -i + 1);
                        start = i;
                        end = j;
                    }
                }
                pa[j][j] = true;
            }
            return s.substr(start, end - start + 1);
        }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("esbtzjaaijqkgmtaajpsdfiqtvxsgfvijpxrvxgfumsuprzlyvhclgkhccmcnquukivlpnjlfteljvykbddtrpmxzcrdqinsnlsteonhcegtkoszzonkwjevlasgjlcquzuhdmmkhfniozhuphcfkeobturbuoefhmtgcvhlsezvkpgfebbdbhiuwdcftenihseorykdguoqotqyscwymtjejpdzqepjkadtftzwebxwyuqwyeegwxhroaaymusddwnjkvsvrwwsmolmidoybsotaqufhepinkkxicvzrgbgsarmizugbvtzfxghkhthzpuetufqvigmyhmlsgfaaqmmlblxbqxpluhaawqkdluwfirfngbhdkjjyfsxglsnakskcbsyafqpwmwmoxjwlhjduayqyzmpkmrjhbqyhongfdxmuwaqgjkcpatgbrqdllbzodnrifvhcfvgbixbwywanivsdjnbrgskyifgvksadvgzzzuogzcukskjxbohofdimkmyqypyuexypwnjlrfpbtkqyngvxjcwvngmilgwbpcsseoywetatfjijsbcekaixvqreelnlmdonknmxerjjhvmqiztsgjkijjtcyetuygqgsikxctvpxrqtuhxreidhwcklkkjayvqdzqqapgdqaapefzjfngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugphhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvyarvaxmchtyrtkgekkmhejwvsuumhcfcyncgeqtltfmhtlsfswaqpmwpjwgvksvazhwyrzwhyjjdbphhjcmurdcgtbvpkhbkpirhysrpcrntetacyfvgjivhaxgpqhbjahruuejdmaghoaquhiafjqaionbrjbjksxaezosxqmncejjptcksnoq");
}
