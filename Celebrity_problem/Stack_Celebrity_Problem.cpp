
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
private:
    bool knows(vector<vector<int>> &M, int n, int a, int b)
    {
        if (M[a][b] == 1)
        {
            return true;
        }

        else
            return false;
    }

public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        while (s.size() != 1 && s.size() > 0)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (knows(M, n, a, b))
            {
                if (!knows(M, n, b, a))
                {
                    s.push(b);
                }
            }

            else if (knows(M, n, b, a))
            {
                if (!knows(M, n, a, b))
                {
                    s.push(a);
                }
            }
        }

        if (!s.empty())
        {
            int pot = s.top();

            for (int i = 0; i < n; i++)
            {
                if (!M[pot][i] == 0)
                {
                    return -1;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (!M[i][pot] == 1 && pot != i)
                {
                    return -1;
                }
            }

            return pot;
        }

        return -1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}
