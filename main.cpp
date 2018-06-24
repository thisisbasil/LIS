#include <iostream>
#include "lis.h"
#include <cstdlib>

int main()
{
    std::cout << "n,n_log_n,n_squared\n";
    for(auto n = 1000; n <= 20000; n+=1000)
    {
        std::vector<int> v;
        for(auto i = 0; i < n; ++i)
        {
            int temp = rand()%1000 + 1;
            v.push_back(temp);
        }
        LIS model;
        std::shared_ptr<LIS_model> strat(new n_log_n);
        model.setModel(strat);
        auto nln = model.runModel(v).runtime;
        strat.reset(new n_squared);
        model.setModel(strat);
        auto ns = model.runModel(v).runtime;
        std::cout << n << ',' << nln << ',' << ns << '\n';
    }
    return 0;
}
