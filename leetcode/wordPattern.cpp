class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        
        istringstream iss(str);
        string word;
        
        map<char, string> m;        
        map<string, char> n;        

        // read pattern
        for (int i = 0; i < pattern.size(); i++)
        {
            iss >> word;

            if (m.count(pattern[i]) == 0 && n.count(word) == 0)
            {
                m.insert(std::make_pair(pattern[i], word));
                n.insert(std::make_pair(word, pattern[i]));
            }
            else
            {
               
                if (m[pattern[i]].compare(word) or m[pattern[i]].empty())
                {
                    return false;
                }
            }
        }
        
        if(iss>>word)
            return false;
        
        return true;
    }
};
