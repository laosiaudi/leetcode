// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Integer_To_Roman.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-11 16:59:17
// MODIFIED: 2015-05-11 17:32:38
#include <iostream>
using namespace std;


//classfiy digit of every bit 
//1:1,2,3
//2:4
//3:5
//4:6,7,8
//5:9
class Solution {
    public:
        string intToRoman(int num) {
            char symbos[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
            string roman;
            int scale = 1000;
            int i = 6;
            while (1) {
                if (i < 0)
                    break;
                int digit = num / scale;
                if (digit != 0) {
                    if (digit <= 3 && digit >= 1) {
                        roman.append(digit, symbos[i]);
                    } else if (digit == 4) {
                        roman.append(1, symbos[i]);
                        roman.append(1, symbos[i + 1]);
                    } else if (digit == 5) {
                        roman.append(1, symbos[i + 1]);
                    } else if (digit <= 8 && digit >= 6) {
                        roman.append(1, symbos[i + 1]);
                        roman.append(digit - 5, symbos[i]);
                    } else {
                        roman.append(1, symbos[i]);
                        roman.append(1, symbos[i + 2]);
                    }
                }
                i -= 2;
                num = num % scale;
                scale /= 10;
            }
            return roman;
        }
};
