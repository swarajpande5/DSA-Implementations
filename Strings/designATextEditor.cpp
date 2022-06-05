// Design a text editor: https://leetcode.com/problems/design-a-text-editor/
// https://leetcode.com/problems/design-a-text-editor/discuss/2111861/Using-Two-Stacks-or-C%2B%2B

class TextEditor 
{
public:
    
    stack<char> left;
    stack<char> right;
    
    TextEditor() 
    {
        
    }
    
    void addText(string text) 
    {
        for(auto &c: text)
            left.push(c);
    }
    
    int deleteText(int k) 
    {
        int cnt = 0;
        while(!left.empty() && k > 0)
        {
            left.pop();
            cnt++;
            k--;
        }
        
        return cnt;
    }
    
    string cursorLeft(int k) 
    {
        while(!left.empty() && k > 0)
        {
            char c = left.top();
            left.pop();
            right.push(c);
            k--;
        }
        
        string rtn = "";
        int cnt = 10;
        while(!left.empty() and cnt > 0)
        {
            char c = left.top();
            left.pop();
            rtn += c;
            cnt--;
        }
        
        reverse(rtn.begin(), rtn.end());
        
        for(int i = 0; i < rtn.size(); i++)
            left.push(rtn[i]);
        return rtn;
    }
    
    string cursorRight(int k) 
    {
        while(!right.empty() && k > 0)
        {
            char c = right.top();
            right.pop();
            left.push(c);
            k--;
        }    
            
        string rtn = "";
        int cnt = 10;
        while(!left.empty() and cnt > 0)
        {
            char c = left.top();
            left.pop();
            rtn += c;
            cnt--;
        }
        
        reverse(rtn.begin(), rtn.end());
        
        for(int i = 0; i < rtn.size(); i++)
            left.push(rtn[i]);
        return rtn;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */