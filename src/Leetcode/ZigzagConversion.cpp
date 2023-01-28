
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
*/

#include <iostream>
#include <string>

std::string convert(std::string s, int numRows)
{
    if (numRows == 1) return s;

    std::string result = "";
    int n = s.length();
    int cycle_len = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j + i < n; j += cycle_len)
        {
            result += s[j + i];
            if (i != 0 && i != numRows - 1 && j + cycle_len - i < n)
                result += s[j + cycle_len - i];
        }
    }
    return result;
}

int main()
{
    std::string s = "PAYPALISHIRING";
    int numRows = 3;
    std::cout << convert(s, numRows) << std::endl;
    return 0;
}


