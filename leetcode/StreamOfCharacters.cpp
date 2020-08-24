/*
Implement the StreamChecker class as follows:

    StreamChecker(words): Constructor, init the data structure with the given words.
    query(letter): returns true if and only if for some k >= 1, the last k characters
    queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.

    Hint create a Trie!
*/

class StreamChecker
{
private:
    vector<string> words;
public:
    StreamChecker(vector<string>& words) : words(words)
    {
        
    }
    
    bool query(char letter)
    {
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
