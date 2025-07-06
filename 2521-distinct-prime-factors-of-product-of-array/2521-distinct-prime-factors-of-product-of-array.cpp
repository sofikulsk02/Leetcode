class Solution {
public:
    void fillSeive(vector<bool>& seive) {
        int n = seive.size() - 1;
        for (int i = 2; i * i <= n; i++) {
            if (seive[i]) {
                for (int j = i * i; j <= n; j += i) {
                    seive[j] = 0;
                }
            }
        }
    }

    int distinctPrimeFactors(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<bool> seive(maxNum + 1, 1);  
        fillSeive(seive);
        seive[0] = seive[1] = 0;

        vector<int> primes;
        for (int i = 2; i <= maxNum; i++) {
            if (seive[i]) primes.push_back(i);
        }

        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int j = 0;
            while (n > 1 && j < primes.size()) {
                if (n % primes[j] == 0) {
                    s.insert(primes[j]);
                    while (n % primes[j] == 0) {
                        n /= primes[j];
                    }
                }
                j++;
            }
            if (n > 1) s.insert(n); 
        }

        return s.size();
    }
};
