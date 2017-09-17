// Given a List of words, return the words that can be typed using letters of alphabet 
// on only one row's of American keyboard like the image below.


// Example 1:
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
// Note:
// You may use one character in the keyboard more than once.
// You may assume the input string will only contain letters of alphabet.


class Solution {
public:
  vector<string> findWords(vector<string>& words) {
  	// init the hashmap rows
  	int rows[128] = {};
  	char row1[20] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
  									 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
  	char row2[18] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
  									'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
  	char row3[14] = {'z', 'x', 'c', 'v', 'b', 'n', 'm',
  									'Z', 'X', 'C', 'V', 'B', 'N', 'M',};
  	for (int i = 0; i < 18; ++i)  rows[row2[i]] = 1;
  	for (int i = 0; i < 14; ++i)  rows[row3[i]] = 2;
  	// test every word
  	vector<string> ans;
  	for (string word : words) {
  		int row_num = rows[word[0]];
  		bool is_valid = true;
  		for (char letter : word) {
  			if (rows[letter] != row_num) {
  				is_valid = false;  break;
  			}
  		}
  		if (is_valid)  ans.push_back(word);
  	}
  	return ans;
  }
};