class Solution {
    int n;
public:
    int helper(int i, vector<string>& words, vector<int>& score, unordered_map<char, int> &umpp){
        if(i == n) return 0;
        int take = 0, score_of_s = 0;
        string s = words[i];
        bool canTake = true;
        unordered_map<char, int> tmp = umpp;
        for(char &c: s){
            tmp[c]--;
            score_of_s += score[c-'a'];
            if(tmp[c] < 0){
                canTake = false;
                score_of_s = 0;
                break;
            }
        }
        if(canTake){
            umpp = tmp;
            take = helper(i+1, words, score, umpp) + score_of_s;
            for(char &c: s) umpp[c]++; // backtrack;
        }
        int notTake = helper(i+1, words, score, umpp);

        return max(take, notTake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        unordered_map<char, int> umpp;
        for(char &c: letters) umpp[c]++;

        /*
        return helper(0, words, score, umpp);
        */
        
        int ans = 0;
        for(int i = 1; i < (1 << n); i++){
            int val = 0;
            unordered_map<char, int> tmp = umpp;
            for(int j = 0; j < n; j++){
                if(i&(1 << j)){
                    unordered_map<char, int> prev = tmp;
                    string s = words[j];
                    bool canTake = true;
                    int s_score = 0;
                    for(char &c: s){
                        s_score += score[c-'a'];
                        tmp[c]--;
                        if(tmp[c] < 0){
                            s_score = 0;
                            canTake = false;
                            break;
                        }
                    }
                    if(!canTake) tmp = prev;
                    else val += s_score;
                }
            }
            ans = max(ans, val);
        }
        return ans;
    }
};