// Erect the fence: https://leetcode.com/problems/erect-the-fence/

// Jarvis Algorithm 
class Solution {
public:

    int getRotationAngle(vector<int> A, vector<int> B, vector<int> C) {
        return (B[1] - A[1]) * (C[0] - B[0]) - (B[0] - A[0]) * (C[1] - B[1]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        set<vector<int>> set; 
        int leftMostIndex = 0;
        int n = trees.size(); 

        if(n < 4)
            return trees; 
        
        for(int i = 0; i < n; i++) {
            if(trees[i][0] < trees[leftMostIndex][0])
                leftMostIndex = i;
        }

        // We start from the leftMostIndex 
        // and then try to pick the next point
        // from the available points which is more clockwise
        // from the current point and we stop
        // when we come to the same point.
        int currPoint = leftMostIndex; 
        while(true) {
            int candidate = (currPoint + 1) % n; 

            // Try to pick the next point which is more clockwise to the current point 
            for(int i = 0; i < n; i++) {
                if(getRotationAngle(trees[currPoint], trees[candidate], trees[i]) > 0)
                    candidate = i;
            }

            // Pick all the points from the space which are co-linear with the candidate 
            for(int i = 0; i < n; i++) {
                if(getRotationAngle(trees[currPoint], trees[candidate], trees[i]) == 0) {
                    set.insert(trees[i]);
                }
            }

            currPoint = candidate; 
            if(currPoint == leftMostIndex || set.size() == n)
                break; 
        }

        vector<vector<int>> result; 
        for(const auto &node: set) {
            result.push_back(node);
        }

        return result;
    }
};

// Optimal Solution
class Solution {
public:

    using tree = vector<int> ;

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        auto cross = [](tree &B, tree &A, tree &T) -> int {
            return (T[1] - B[1])*(B[0]-A[0]) - (B[1]-A[1])*(T[0]-B[0]);
        };

        sort(trees.begin(), trees.end()); 

        deque<tree> F; 

        for(tree T: trees) {
            while(F.size() >= 2 && cross(F[F.size() - 1], F[F.size() - 2], T) < 0)
                F.pop_back(); 
            F.push_back(T);

            while(F.size() >= 2 && cross(F[0], F[1], T) > 0)
                F.pop_front(); 
            F.push_front(T);
        }

        set<tree> unique(F.begin(), F.end()); 
        return vector<tree> (unique.begin(), unique.end());
    }
};
