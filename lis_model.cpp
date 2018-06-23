#include "lis_model.h"

std::string LIS_model::getname()
{
    return this->name;
}

int n_squared::run(std::vector<int> list)
{
    int length = 0;
    return length;
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


int n_log_n::run(std::vector<int> list)
{
    std::vector<int> retval(list.size(),0);
        int length = 1;
        retval[0] = list[0];
        for (auto i = 1; i < list.size(); i++) {
            if (list[i] < retval[0])
                retval[0] = list[i];
            else if (list[i] > retval[length-1])
                retval[length++] = list[i];
            else
                retval[binSearch(retval, -1, length-1, list[i])] = list[i];
        }
    return length;
}
