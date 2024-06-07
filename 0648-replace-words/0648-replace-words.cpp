class TrieNode{
    public:
        unordered_map<char, TrieNode*> ch;
        string word = "";
};

class Trie{
    public:
        TrieNode *root;
        Trie(){ root = new TrieNode(); }

        void insert(string &word){
            TrieNode *node = root;
            for(char &c: word){
                if(node->ch.find(c) == node->ch.end())
                    node->ch[c] = new TrieNode();
                node = node->ch[c];
            }
            node->word = word;
        }

        string findRoot(string &word){
            TrieNode *node = root;
            for(char &c: word){
                if(node->ch.find(c) == node->ch.end()){
                    return word;
                }
                node = node->ch[c];
                if(node->word.empty() == false){
                    return node->word;
                }
            }
            return word;
        }
};

class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        /*
        sort(dictionary.begin(), dictionary.end());
        vector<string> arr; 
        stringstream ss(sentence); 
        string word; 
        sentence = "";
        while (getline(ss, word, ' ')) {
            for (const auto& root : dictionary) {
                if (word.find(root) == 0) { 
                    word = root;
                    break;
                }
            }
            sentence += word + ' ';
        }
        if (!sentence.empty()) sentence.pop_back();
        return sentence;
        */

        Trie trie;
        for(auto &str: dictionary) trie.insert(str);
        string word; stringstream ss(sentence); sentence = "";
        while(getline(ss, word, ' ')) sentence += trie.findRoot(word) + ' ';
        sentence.pop_back();
        return sentence;
    }
};