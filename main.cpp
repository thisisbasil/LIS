#include <iostream>
#include "lis.h"
#include <cstdlib>
#include <cmath>

int main()
{
    std::cout << "n,exp,theo\n";

    std::vector<int> input =
    {
        100,200,300,400,500,600,700,800,900,1000,
        1100,1200,1300,1400,1500,1600,1700,1800,1900,2000
    };

    for(auto n : input) //= 100; n <= 10000; n+=100)
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
        //auto ns = log10(n);
        std::cout << n << ',' << nln << ',' << ns << '\n';
    }
    return 0;
}
