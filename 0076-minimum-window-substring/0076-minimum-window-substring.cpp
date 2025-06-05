class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return ""; // Added: Handle empty t string

        int total = t.size();
        unordered_map<char, int> m;  //characters need in string

        for(int i = 0; i < t.size(); i++){
            m[t[i]]++;
        }

        // Moved initialization outside the loop
        int start = 0, end = 0, ans = INT_MAX, index = -1;

        while(end < s.size()){
            // Decrease the count of character if it's relevant to 't'
            if (m.count(s[end])) { // Added: Check if s[end] is in map 'm'
                m[s[end]]--;
                if(m[s[end]] >= 0) { // if count is not negative decrease the total
                    total--;
                }
            }

            // can we increase the window
            while(total == 0 && start <= end){ // Modified: total == 0 for a valid window
                //update the length of substring
                if(ans > end - start + 1){
                    ans = end - start + 1;
                    index = start;
                }

                // Increase the count of character if it's relevant to 't'
                if (m.count(s[start])) { // Added: Check if s[start] is in map 'm'
                    m[s[start]]++; // increase the count of character
                    if(m[s[start]] > 0){ // if count is positive
                        total++;     // increase the total
                    }
                }
                start++;  //move the start; decrease the size;
            }
            //increase the size of window
            end++;
        }

        if(index == -1) return "";

        // Modified: Use substr for string extraction
        return s.substr(index, ans);
    }
};