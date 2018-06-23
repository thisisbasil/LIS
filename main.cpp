#include <iostream>
#include "lis.h"


int main()
{
    std::vector<int> v = {50,40,70,30,40, 39,38,37,20};
    std::shared_ptr<LIS_model> strat(new n_log_n);
    LIS model(strat);

    std::cout << "list: ";
    for (auto i : v)
        std::cout << i << ' ';
    std::cout << std::endl;

    model.runModel(v);
    return 0;
}
