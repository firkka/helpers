// every node will have certain amount of pointers (e.g. num of letters in aplhabet)
// all node pointers will be set to nullptr in the beginning

// insert function will add words starting from the 'root' node
// search function will check letter by letter starting from the given node that what are

/*
                       root
                    /   \    \
                    t   a     b
                    |   |     |
                    h   n     y
                    |   |  \  |
                    e   s  y  e
                 /  |   |
                 i  r   w
                 |  |   |
                 r  e   e
                        |
                        r

*/

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
