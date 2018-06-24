#include "lis_model.h"

std::string LIS_model::getname()
{
    return this->name;
}

std::vector<int> n_squared::run(std::vector<int> list)
{
    std::vector<int> L(list.size(),1);
    for(auto i = 0; i < list.size(); ++i)
    {
        for(auto j = i + 1; j < list.size(); ++j)
        {
            if (list[j] > list[i])
            {
                if (L[j] < L[i] + 1)
                    L[j] = L[i] + 1;
            }
        }
    }
    int len=0;
    for(auto i=0; i<list.size(); ++i)
    {
        if (len < L[i])
            len = L[i];
    }

    std::vector<int> retval(len);

    int i=0;
    for(auto j=i; j<list.size(); ++j)
        if (L[j] > L[i])
            i=j;

    int top = L[i] - 1;
    retval[top] = list[i];
    --top;

    for (auto j = i - 1; j >= 0; --j)
    {
        if (list[j] < list[i] && L[j] == L[i] - 1)
        {
            i = j;
            retval[top] = list[i];
            --top;
        }
    }
    return retval;
}


int n_log_n::binSearch(const std::vector<int>& v, std::vector<int>& tail,
                       int lo, int hi, int val)
{
    while (hi - lo > 1)
    {
        int mid = lo + (hi - lo)/2;
        if (v[tail[mid]] >= val)
            hi = mid;
        else
            lo = mid;
    }

    return hi;
}

std::vector<int> n_log_n::run(std::vector<int> list)
{
    std::vector<int> tail(list.size(),0),
                     prev(list.size(),-1), retval;
    int len=1;
    for (auto i = 1; i < list.size(); ++i)
    {
        if (list[i] < list[tail[0]])
            tail[0] = i;
        else if (list[i] > list[tail[len-1]])
        {
            prev[i] = tail[len-1];
            tail[len++] = i;
        }
        else
        {
            int idx = this->binSearch(list,tail,-1,len-1,list[i]);
            prev[i] = tail[idx-1];
            tail[idx] = i;
        }
    }
    for(auto i = tail[len-1]; i >= 0; i = prev[i])
        retval.insert(retval.begin(),list[i]);
    return retval;
}
