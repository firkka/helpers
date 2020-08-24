class TrieNode
{
public:
     TrieNode* branches[26];
     bool      isLeaf;

    TrieNode() : isLeaf(false)
    {
        for (int i = 0; i < 26; i++)
        {
            branches[i] = nullptr; 
        }
    }

    TrieNode *createNode(void) 
    { 
        struct TrieNode *node =  new TrieNode; 

        node->isLeaf = false; 

        for (int i = 0; i < 26; i++)
        {
            node->branches[i] = NULL; 
        }
        return node; 
    }

    void insert(TrieNode *root, string key) 
    { 
        TrieNode *r = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';

            if (not r->branches[index])
            {
                r->branches[index] = createNode();
            }
            r = r->branches[index];
        }
        r->isLeaf = true; 
    } 

    bool search(TrieNode *root, string key)
    {
        TrieNode *node = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (not node->branches[index])
            {
                return false;
            }

            node = node->branches[index];
        }

        return (node != nullptr && node->isLeaf);
    }
};


class StreamChecker
{
private:
    TrieNode* root;
public:
    StreamChecker(vector<string>& words)
    {
        root = new TrieNode();

        int n = sizeof(words)/sizeof(words[0]); 

        for (int i = 0; i < n; i++) 
        {
            root->insert(root, words[i]);
        }
    }
    
    bool query(char letter)
    {
        return root->search(root, letter);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

// Using Trie, we can search the key in O(M) time
