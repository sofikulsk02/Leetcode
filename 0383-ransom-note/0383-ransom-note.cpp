class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {  
          unordered_map<char, int> charCount;  
        for (char ch : magazine) {  
            charCount[ch]++;  
        }   
        for (char ch : ransomNote) {  
            if (charCount[ch] == 0) {  
                return false;   
            }  
            charCount[ch]--; 
        }  

        return true; 
    }
};