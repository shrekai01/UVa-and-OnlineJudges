class Solution {
public:
    // Two Pointers
    string reversePrefix(string word, char ch) {
        int idx = word.find(ch);
        if(idx == string::npos) return word;
        for(int l = 0, r = idx; l < r; l++, r--){
            swap(word[l], word[r]);
        }
        return word;
    }
    // O(n) time, O(1) extra-space, where n is word.length
};