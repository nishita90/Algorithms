/*
LeetCode
Given two strings representing two complex numbers.
You need to return a string representing their multiplication.
Note: i2 = -1 according to the definition.
Note:
The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b
will both belong to the range of [-100, 100]. And the output should be also in this form.
Example: Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert
it to the form of 0+2i.

*/
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, rb, ia, ib;
        char plus;
        std::stringstream aa(a);
        std::stringstream bb(b);
        aa >> ra >> plus >> ia;
        bb >> rb >> plus >> ib;
        std::string res = std::to_string((ra*rb) -1*ia*ib ) + "+" + std::to_string((ra*ib + rb*ia)) + "i";
        return(res);
    }
};
