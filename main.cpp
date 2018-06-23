#include <iostream>
#include "lis.h"


int main()
{
    std::vector<int> v = {0, 8, 4, 12, 2,8};
    std::shared_ptr<LIS_model> strat(new n_log_n);
    LIS model(strat);
    model.runModel(v);
    return 0;
}
