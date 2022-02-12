// Word Ladder: https://leetcode.com/problems/word-ladder/
//              https://leetcode.com/problems/word-ladder/discuss/898086/Easy-BFS-in-C%2B%2B-with-explanation-%3A-

/*
    We approach the problem using BFS with the following steps:
    1.  At the very first we check whether our endWord is present in the word list or not.
    2.  If present, then we need to form our graph, the first node will be beginWord and last word will be the endWord.
    3.  For each node's neighbour, we transform at most one character in the node's string and check whether it is present
        in our word list or not. Then, the transformed word forms the neighbour of the given node.

    Application of BFS to the constructed graph:
    1.  First we insert beginWord to queue.
    2.  Then for each level in the queue, we increase the depth variable as indicated by 'd'.
    3.  Then we replace each character at the top of the queue, and check with the endWord.
    4.  If present we return 'd' + 1 else we insert the transformed word in the queue and remove the transformed 
        word from the wordlist.
*/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        
        set<string> s;
        for(auto i: wordList)
            s.insert(i);
        
        queue<string> q;
        q.push(beginWord);
        int d = 0;

        while(!q.empty())
        {
            d++;
            int n = q.size();
            
            while(n--)
            {
                string curr = q.front();
                q.pop();

                for(int i = 0; i < curr.length(); i++)
                {
                    string temp = curr;

                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        temp[i] = c;

                        if(temp == curr)
                            continue;
                        
                        if(temp == endWord)
                            return d + 1;
                        
                        if(s.find(temp) != s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }

        return 0;
    }
};