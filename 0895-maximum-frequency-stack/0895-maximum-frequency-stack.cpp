class FreqStack {
public:
    unordered_map<int,int> freq; 
    unordered_map<int,stack<int>> freqStack;
    int maxFreq; 
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++; 
        maxFreq = max(maxFreq, freq[val]);
        freqStack[freq[val]].push(val); 
    }
    
    int pop() {
        int topElement = freqStack[maxFreq].top(); 
        freqStack[maxFreq].pop(); 
        freq[topElement]--; 
        if (freqStack[maxFreq].empty()) {
            maxFreq--;
        }
        return topElement; 
    }
};