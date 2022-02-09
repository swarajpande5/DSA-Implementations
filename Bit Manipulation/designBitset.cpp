// Design bitset: https://leetcode.com/problems/design-bitset/

class Bitset
{
private:
    string s = "";
    string flipped = "";
    int cnt = 0;
    int size = 0;

public:
    Bitset(int size)
    {
        for(int i = 0; i < size; i++)
        {
            s.push_back('0');
            flipped.push_back('1');
        }

        this -> size = size;
    }

    void fix(int idx)
    {
        if(s[idx] == '0')
            cnt++;
        
        s[idx] = '1';
        flipped[idx] = '0';
    }

    void unfix(int idx)
    {
        if(s[idx] == '1')
            cnt--;
        
        s[idx] = '0';
        flipped[idx] = '1';
    }

    void flip()
    {
        swap(s, flipped);
        cnt = size - cnt;
    }

    bool all()
    {
        return cnt == size;
    }

    bool one()
    {
        return cnt > 0;
    }

    int count()
    {
        return cnt;
    }

    string toString()
    {
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */