#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;



class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.length(), b.length());
        int carry = 0;
        string res = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < n; i++)
        {
            cout << "a[i]: " << a[i] << " b[i]: " << b[i] << endl;
            
            if (i < a.length() && i < b.length()) {
                if (a[i] == '1' && b[i] == '0' || a[i] == '0' && b[i] == '1') {
                    if (carry == 1)
                        res.insert(0, "0");
                    else
                        res.insert(0, "1");
                }
                else if (a[i] == '0' && b[i] == '0') {
                    if (carry == 1) {
                        res.insert(0, "1");
                        carry = 0;
                    }
                    else
                        res.insert(0, "0");
                }
                else if (a[i] == '1' && b[i] == '1') {
                    if (carry == 1) {
                        res = "1" + res;
                         cout << "res: " << res << endl;
                    }
                    else {
                        res = "0" + res;
                        cout << "res: " << res << endl;
                        carry = 1;
                    }
                }
            }
            else if (i >= a.length())
            {
                 cout << "else if works";
                if (b[i] == '0') {
                    if (carry == 1) {
                        res = "1" + res;
                        carry = 0;
                    }
                    else
                        res = "0" + res;
                }
                else if (b[i] == '1') {
                    if (carry == 1)
                        res = "0" + res;
                    else
                        res = "1" + res;
                }
            }
            else if (i >= b.length())
            {
                 cout << "else if works";
                if (a[i] == '0') {
                    if (carry == 1) {
                        res = "1" + res;
                        carry = 0;
                    }
                    else
                        res = "0" + res;
                }
                else if (a[i] == '1') {
                    if (carry == 1)
                        res = "0" + res;
                    else
                        res = "1" + res;
                }
            }
             cout << "res: " << res << endl;
        }
        if (carry == 1)
            res = "1" + res;
        return res;
    }
};



int main()
{
    string a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    string b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";

    Solution solution = Solution();

    string answer = solution.addBinary(a, b);


    return 0;
}