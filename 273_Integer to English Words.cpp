// Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

// For example,
// 123 -> "One Hundred Twenty Three"
// 12345 -> "Twelve Thousand Three Hundred Forty Five"
// 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"


// corner cases: 1,000,000  1,000,010  12,345  0  1,023
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)  return "Zero";
        string ans = "";
        int k = 0; // index of units array
        while (num > 0) {
            if (num % 1000 != 0) {
                if (ans != "")  ans = " " + ans;
                ans = lessThanThousand(num % 1000) + units[k++] + ans;
            } else {
                k++;
            }
            num = num / 1000;
        }
        return ans;
    }
    
    string lessThanThousand(int num) {
        if (num == 0)  return "";
        int d100 = num / 100, d10 = num / 10 % 10, d1 = num % 10;
        string ans = "";
        if (d100 > 0)  ans += digits[d100] + " Hundred";
        if (d10 >= 2) { // >= 20
            ans += (ans == "") ? tens[d10] : " " + tens[d10];
            ans += (d1 == 0) ? "" : " " + digits[d1];
        } else if (d10 == 1) { // 10 ~ 19
            ans += (ans == "") ? decade[d1] : " " + decade[d1];
        } else { // 0 ~ 9
            ans += (d1 == 0) ? "" : (ans == "") ? digits[d1] : " " + digits[d1];
        }
        return ans;
    }
    
private:
    vector<string> units = {"", " Thousand", " Million", " Billion"};
    vector<string> digits = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> decade = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", 
                             "Seventeen", "Eighteen", "Nineteen"};
};