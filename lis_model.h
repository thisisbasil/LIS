#ifndef LIS_MODEL_H
#define LIS_MODEL_H

#include <string>
#include <vector>
#include <array>

class LIS_model
{
public:
    std::string getname();
    virtual std::vector<int> run(const std::vector<int>&) = 0;
    virtual double getTheoretical(const int&) = 0;
protected:
    std::string name;
};

class n_log_n : public LIS_model
{
public:
    n_log_n() { this->name = "n*log(n)"; }
    std::vector<int> run(const std::vector<int>&);
    double getTheoretical(const int&);
private:
    int binSearch(const std::vector<int>&,std::vector<int>&,int,int,int);
};

class n_squared : public LIS_model
{
public:
    n_squared() { this->name = "n^2"; }
    std::vector<int> run(const std::vector<int>&);
    double getTheoretical(const int&);
};

// possible alternate n log n implementation
class patience : public LIS_model
{
public:
    patience() { this->name = "patience"; }
    std::vector<int> run(const std::vector<int>&);
    double getTheoretical(const int&);
private:
    struct TUPLE
    {
        int val;
        std::array<int,2> back;
        TUPLE(int _val = -1, int x = -1, int y = -1)
        {
            val = _val;
            back[0] = x;
            back[1] = y;
        };
    };
    int getPosn(const std::vector<std::vector<TUPLE>>&,int,int,int);
    std::vector<int> construct(const std::vector<std::vector<TUPLE>>&);

};

#endif // LIS_MODEL_H
