#include "lis_model.h"

std::string LIS_model::getname()
{
    return this->name;
}

std::vector<int> n_squared::run(std::vector<int> list)
{
    std::vector<int> retval;
    return retval;
}

int n_log_n::binSearch(const std::vector<int>& v,int lo, int hi, int val)
{
    while (hi-lo > 1) {
        int mid = lo + (hi-lo)/2;
        if (v[mid] >= val)
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}


std::vector<int> n_log_n::run(std::vector<int> list)
{
    std::vector<int> retval(list.size(),0);
    int len = 0;
    for (auto elem : list)
    {
        int i = this->binSearch(retval,0,len,elem);
        if (i < 0)
            i = (i + 1) * -1;
        retval[i] = elem;
        if (i == len)
            ++len;
    }
    return retval;
}
