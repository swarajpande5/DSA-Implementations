// Prime counters: https://innoskrit.in/blog/tcs-codevita/prime-counters-codevita-2017-round-2/

vector<int> primeCounters(vector<pair<int, int>> &ranges, int size)
{
    vector<bool> primeSieve(size + 1, true);
    vector<int> cp(size + 1, 0);
    vector<int> pc(size + 1, 0);

    primeSieve[0] = false;
    primeSieve[1] = false;

    for(int number = 2; number <= size; number++)
    {
        if(primeSieve[number])
            cp[number] = cp[number - 1] + 1;
        else 
            cp[number] = cp[number - 1];

        if(primeSieve[cp[number]])
            pc[number] = pc[number - 1] + 1;
        else 
            pc[number] = pc[number - 1];
        
        if(primeSieve[number])
            for(int multiple = number * number; multiple <= size; multiple += number)
                primeSieve[multiple] = false;
    }

    vector<int> ans;

    for(auto range: ranges)
    {
        int diff = pc[range.second] - pc[range.first - 1];
        ans.push_back(diff);
    }

    return ans;
}