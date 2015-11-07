/*
 * python solution
from collections import deque
class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        table = set()
        result = []
        if len(s) == 0:
            return result

        d = deque()
        d.append(s)
        minStep = -1
        cnt = 1
        while len(d) != 0:
            if (minStep != -1 ) and (cnt > minStep):
                return result
            size = len(d)
            for i in range(0, size):
                tmp = d.popleft()
                if self.check(tmp) is True:
                    if tmp not in table:
                        table.add(tmp)
                        result.append(tmp)
                    minStep = cnt
                else:
                    for j in range(0, len(tmp)):
                        if tmp[j] is '(' or ')':
                            d.append(tmp[:j] + tmp[j + 1:])
            cnt = cnt + 1

        return result

    def check(self, sstr):
        ss = []
        for char in sstr:
            if char is '(':
                ss.append(char)
            elif char is ')':
                if len(ss) == 0:
                    return False
                ss.pop()

        return len(ss) == 0

if __name__ == "__main__":
    s = Solution()
    print s.removeInvalidParentheses("()())()")

*/

class Solution {
    public:
        vector<string> removeInvalidParentheses(string s) {
            vector<string>v;
            if (s.size() == 0) {
                v.push_back(s);
                return v;
            }

            map<string,bool>m;
            queue<string>q;
            q.push(s);

            int minStep = -1;
            int cnt = 1;
            while (!q.empty()) {
                if (minStep != -1 && cnt > minStep)
                    return v;
                int size = q.size();
                for (int i = 0; i < size; i ++) {
                    string tmp = q.front();
                    q.pop();
                    int left = 0;
                    int right = 0;
                    if (check(tmp, left, right)) {
                        v.push_back(tmp);
                        minStep = cnt;
                    } else {
                        bool flag = left > right;
                        for (int j = 0; j < tmp.size(); j ++) {
                            if (flag) {
                                if (tmp[j] == '(') {
                                	string newStr = tmp.substr(0, j) + tmp.substr(j + 1);
                                	if (m.find(newStr) == m.end()) {
                                		m[newStr] = true;
                                    	q.push(tmp.substr(0, j) + tmp.substr(j + 1));
                                    }
                                }
                            } else {
                                if (tmp[j] == ')') {
                                	string newStr = tmp.substr(0, j) + tmp.substr(j + 1);
                                	if (m.find(newStr) == m.end()) {
                                		m[newStr] = true;
                                    	q.push(tmp.substr(0, j) + tmp.substr(j + 1));
                                    }
                                }
                            }
                        }
                    }
                }
                cnt ++;
            }
            return v;

        }
        bool check(string s, int &left, int &right) {
            stack<char>stk;
            for (int i = 0; i < s.size(); i ++) {
                if (s[i] == '(') {
                    stk.push(s[i]);
                    left ++;
                } else if (s[i] == ')') {
                    if (stk.empty())
                        return false;
                    stk.pop();
                    right ++;
                }
            }

            return stk.empty();
        }
};





