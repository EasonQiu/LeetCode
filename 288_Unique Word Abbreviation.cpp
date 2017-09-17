// An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

// a) it                      --> it    (no abbreviation)

//      1
// b) d|o|g                   --> d1g

//               1    1  1
//      1---5----0----5--8
// c) i|nternationalizatio|n  --> i18n

//               1
//      1---5----0
// d) l|ocalizatio|n          --> l10n
// Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

// Example: 
// Given dictionary = [ "deer", "door", "cake", "card" ]

// isUnique("dear") -> 
// false

// isUnique("cart") -> 
// true

// isUnique("cane") -> 
// false

// isUnique("make") -> 
// true

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (string &word : dictionary) {
            dict[word.front() + to_string(word.size() - 2) + word.back()].insert(word);
        }
    }
    
    bool isUnique(string word) {
        string abbr = word.front() + to_string(word.size() - 2) + word.back();
        auto pos = dict.find(abbr);
        return (pos == dict.end()) || 
               (pos->second.size() == 1 && *pos->second.begin() == word);
    }
    
private:
    unordered_map<string, unordered_set<string> > dict; // abbr, words with the same abbr
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */