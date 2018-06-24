#include <iostream>
#include "lis.h"
#include <cstdlib>

const int n = 1000;

int main()
{
    std::vector<int> v;
    for(auto i = 0; i < n; ++i)
    {
        int temp = rand()%1000 + 1;
        v.push_back(temp);
    }
    std::shared_ptr<LIS_model> strat(new n_squared);
    LIS model;//strat);
    model.setModel(strat);
    std::cout << model.runModel(v) << std::endl;
    strat.reset(new n_log_n);
    model.setModel(strat);
    std::cout << model.runModel(v) << std::endl;
    return 0;
}
