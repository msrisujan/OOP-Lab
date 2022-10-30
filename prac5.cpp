// C++ program to find the index
// of an element in a vector
#include <bits/stdc++.h>
using namespace std;

template<typename T>
    vector<int> findItems(std::vector<T> const &v, int target) {
    std::vector<int> indices;
    auto it = v.begin();
    while ((it = std::find_if(it, v.end(), [&] (T const &e) { return e == target; }))
        != v.end())
    {
        indices.push_back(std::distance(v.begin(), it));
        it++;
    }
    return indices;
}
    int destroyTargets(vector<int>& nums, int space) {
        vector<int>x;
        for(int i=0;i<nums.size();i++)
        {
            int c=0;
            for(int j=0;j<nums.size();j++)
            {
                if((nums[j]-nums[i]>=0)&&((nums[j]-nums[i])%space==0))
                    c++;
            }
            x.push_back(c);
        }
        int y=*max_element(x.begin(),x.end());
        int k=0;
        for(int i=0;i<x.size();i++)
        {
            if(y==x[i])
                k++;
        }
        if(k==1)
        {
            int t=distance(x.begin(),max_element(x.begin(),x.end()));
            return nums[t];
        }
        else
        {
            vector<int>e=findItems(x,y);
            int r=e.size();
            int b[r];
            for(int i=0;i<e.size();i++)
            {
                b[i]=nums[e[i]];
            }
            return *min_element(b,b+r);
        }
    }
    int main()
    {
        int n;
        cin>>n;
        vector<int>a;
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            a.push_back(x);
        }
        int s;
        cin>>s;
        int y=destroyTargets(a,s);
        cout<<y;
    }