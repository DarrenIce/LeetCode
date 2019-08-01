// 本题做了很久，一开始数据结构想的有偏差，没有想到直接用下标去指示字母
// 明白了Trie树
// 带有.匹配符的搜索，一开始想用队列去模拟bfs，但是不太可行，不如递归效果来的更好，而且更加直观清楚
class TrieNode {
public:
  bool flag;
  TrieNode* next[26];
  TrieNode() {
    flag = false;
    for (int i = 0; i < 26; i++)
      next[i] = NULL;
  }
};

class WordDictionary {
 public:
  TrieNode* head;
  WordDictionary() {
    head = new TrieNode();
    head->flag = false;
  }
  /** Adds a word into the data structure. */
  void addWord(string word) {
    TrieNode* cur = head;
    for (int i = 0; i < word.size(); i++) {
      if (cur->next[word[i] - 'a'] == NULL) {
        cur->next[word[i] - 'a'] = new TrieNode();
      }
      cur = cur->next[word[i] - 'a'];
    }
    cur->flag = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool bfs(TrieNode* tn, string word, int i) {
    if (i == word.size())
      return tn->flag;
    if (word[i] != '.') {
      if (tn->next[word[i] - 'a'] && bfs(tn->next[word[i] - 'a'], word, i + 1))
        return true;
      return false;
    } 
    else {
      for (int k = 0; k < 26; k++) {
        if (tn->next[k] && bfs(tn->next[k], word, i + 1))
          return true;
      }
      return false;
    }
  }
  bool search(string word) {
    return bfs(head, word, 0);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */