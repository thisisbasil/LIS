#include <iostream>
#include "lis.h"
#include "lis_model.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
int main()
{
    std::ofstream out;
    out.open("lis.csv");
    out << "n,n^2,n^2_theoretical,improved,patience,n_log_n_theoretical\n";
    for(auto n=50; n<=10000; n+=50)
    {
        std::cout << "starting n=" << n << "..." << std::endl;
        std::vector<int> v;
        for(auto i = 0; i < n; ++i)
        {
            int temp = rand()%1000 + 1;
            v.push_back(temp);
        }
        LIS model;
        std::shared_ptr<LIS_model> strat = std::make_shared<n_squared>();
        model.setModel(strat);
        LIS::infoTuple n2 = model.runModel(v);
        strat.reset();
        strat = std::make_shared<n_log_n>();
        model.setModel(strat);
        LIS::infoTuple nln = model.runModel(v);
        strat.reset();
        strat = std::make_shared<patience>();
        model.setModel(strat);
        LIS::infoTuple pat = model.runModel(v);
        out << std::setw(10)
            << n << ',' << n2.runtime << ','
            << n2.theoretical << nln.runtime << ','
            << pat.runtime << pat.theoretical
            << std::endl;
    }
    out.close();
    return 0;
}
