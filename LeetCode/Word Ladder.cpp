class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if (!dict.count(endWord))
            return 0;
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        int level=2;
        while (!q1.empty()&&!q2.empty()) {
            if (q1.size()>q2.size())
                swap(q1,q2);
            unordered_set<string> q;
            for (auto word:q1) {
                for (int i=0;i<word.size();i++) {
                    char c=word[i];
                    for (char j='a';j<='z';j++) {
                        word[i]=j;
                        if (q2.count(word))
                            return level;
                        if (!dict.count(word))
                            continue;
                        q.insert(word);
                        dict.erase(word);
                    }
                    word[i]=c;
                }
            }
            swap(q,q1);
            level++;
        }
        return 0;
    }
};