/*********************************************************************************
*     File Name           :     Valid_Number.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-11-01 22:35]
*     Last Modified       :     [2015-11-01 22:36]
*     Description         :
**********************************************************************************/
//reference:http://www.cnblogs.com/chasuner/p/validNumber.html
class Solution
{
public:
    bool isNumber(string s)
    {
        enum InputType
        {
            INVALID,    // 0
            SPACE,      // 1
            SIGN,       // 2
            DIGIT,      // 3
            DOT,        // 4
            EXPONENT,   // 5
            NUM_INPUTS  // 6
        };
        
        int transitionTable[][NUM_INPUTS] =
        {
            -1,  0,  3,  1,  2, -1,     // next states for state 0
            -1,  8, -1,  1,  4,  5,     // next states for state 1
            -1, -1, -1,  4, -1, -1,     // next states for state 2
            -1, -1, -1,  1,  2, -1,     // next states for state 3
            -1,  8, -1,  4, -1,  5,     // next states for state 4
            -1, -1,  6,  7, -1, -1,     // next states for state 5
            -1, -1, -1,  7, -1, -1,     // next states for state 6
            -1,  8, -1,  7, -1, -1,     // next states for state 7
            -1,  8, -1, -1, -1, -1,     // next states for state 8
        };
        
        int state = 0;
        int i = 0;
        while (i < s.size() && s[i] != '\0')
        {
            InputType inputType = INVALID;
            if (isspace(s[i]))
                inputType = SPACE;
            else if (s[i] == '+' || s[i] == '-')
                inputType = SIGN;
            else if (isdigit(s[i]))
                inputType = DIGIT;
            else if (s[i] == '.')
                inputType = DOT;
            else if (s[i] == 'e' || s[i] == 'E')
                inputType = EXPONENT;
            
            state = transitionTable[state][inputType];
            
            if (state == -1)
                return false;
            else
                ++i;
        }
        
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};