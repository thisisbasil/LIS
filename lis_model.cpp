#include "lis_model.h"
#include <cmath>

std::string LIS_model::getname()
{
    return this->name;
}

double n_squared::getTheoretical(const int& n)
{
        return pow(n,2);
}

//log_10
double n_log_n::getTheoretical(const int & n)
{
    return n*log(n);
}

double patience::getTheoretical(const int & n)
{
    return n*log(n);
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

std::vector<int> patience::construct(const std::vector<std::vector<TUPLE> > &v)
{
    std::vector<int> retval;
    int x = v.size() - 1;
    int y = 0;
    while (x != -1)
    {
        retval.insert(retval.begin(), v[x][y].val);
        std::array<int,2> temp = v[x][y].back;
        x = temp[0];
        y = temp[1];
    }
    return retval;
}

int patience::getPosn(const std::vector<std::vector<TUPLE>>& v, int lo, int hi, int val)
{
    int loc = -1;
    while (hi - lo >= 1)
    {
        int mid = lo + (hi - lo) / 2;
        if (val < v[mid][v[mid].size()-1].val)
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
    std::vector<std::vector<TUPLE>> piles;
    for(auto i : list)
    {
        int loc = this->getPosn(piles,0,piles.size(),i);
        TUPLE t(i);
        if (loc == -1)
        {
            if (piles.size() >= 1)
            {
                int x = piles.size() - 1;
                int y = piles[x].size() - 1;
                t.back[0] = x;
                t.back[1] = y;
            }
            std::vector<TUPLE> pile(1,t);
            piles.push_back(pile);
        }
        else
        {
            int x = loc - 1;
            int y = piles[x].size() - 1;
            t.back[0] = x;
            t.back[1] = y;
            piles[loc].push_back(t);
        }
    }
    return this->construct(piles);
}
