// Encrypt and decrypt strings: https://leetcode.com/problems/encrypt-and-decrypt-strings/

class Encrypter 
{
public:
    
    unordered_map<char, string> mp;
    unordered_map<string, int> dict;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) 
    {   
        // We store the key value pairs in an unordered_map 'mp',
        // so that encryption of a character takes O(1)
        for(int i = 0; i < keys.size(); i++)
            mp[keys[i]] = values[i];
        
        // We encrypt the strings in vector 'dictionary' and
        // store its count in unordered_map 'dict'. 
        // Such that we can directly say the cound of decryptions for a string in O(1). 
        for(int i = 0; i < dictionary.size(); i++)
        {
            string p = encrypt(dictionary[i]);
            dict[p]++;
        }
    }
    
    string encrypt(string word1) 
    {
        // Encrypting the string using key value pairs in unordered_map 'mp'
        string p = "";
        for(int i = 0; i < word1.size(); i++)
            p += mp[word1[i]];
        
        return p;
    }
    
    int decrypt(string word2) 
    {
        // If word2 not present in dict, we return 0
        if(dict.find(word2) == dict.end())
            return 0;
        
        return dict[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */