#include "lis_model.h"

std::string LIS_model::getname()
{
    return this->name;
}

std::vector<int> n_squared::run(const std::vector<int>& list)
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

std::vector<int> n_log_n::run(const std::vector<int>& list)
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

std::vector<int> patience::construct(const std::vector<std::vector<int> > &v)
{
    std::vector<int> retval;
    int prev;
    for (auto i = v.end()-1; i >= v.begin(); i--)
    {
        if (i == v.end() - 1)
        {
            auto j = i[i->size()-1][0];
            retval.push_back(j);
            prev = j;
        }
        else
        {
            for (auto j = i->begin(); j < i->end(); j++)
            {
                if (prev > *j)
                {
                    retval.insert(retval.begin(),*j);
                    prev = *j;
                    break;
                }
            }
        }
    }
    return retval;
}

int patience::getPosn(const std::vector<std::vector<int>>& v, int lo, int hi, int val)
{
    int loc = -1;
    while (hi - lo >= 1)
    {
        int mid = lo + (hi-lo)/2;
        if (val < v[mid][v[mid].size()-1])
        {
            loc = mid;
            int temp = this->getPosn(v,lo,mid,val);
            if (temp != -1)
                loc = temp;
            return loc;
        }
        else
        {
            loc = this->getPosn(v,mid+1,hi,val);
            return loc;
        }
    }
    return loc;
}

std::vector<int> patience::run(const std::vector<int> &list)
{
    std::vector<std::vector<int>> piles;
    for(auto i :list)
    {
        int loc = this->getPosn(piles,0,piles.size(),i);
        if (loc == -1)
        {
            std::vector<int> pile(1,i);
            piles.push_back(pile);
        }
        else
        {
            piles[loc].push_back(i);
        }
    }
    return this->construct(piles);
}
