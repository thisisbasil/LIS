#ifndef LIS_MODEL_H
#define LIS_MODEL_H

#include <string>
#include <vector>

class LIS_model
{
public:
    std::string getname();
    virtual std::vector<int> run(std::vector<int>) = 0;
protected:
    std::string name;
};

class n_log_n : public LIS_model
{
public:
    n_log_n() { this->name = "n*log(n)"; }
    std::vector<int> run(std::vector<int>);
private:
    int binSearch(const std::vector<int>&,std::vector<int>&,int,int,int);
};

class n_squared : public LIS_model
{
public:
    n_squared() { this->name = "n^2"; }
    std::vector<int> run(std::vector<int>);
};

class exponential : public LIS_model
{
public:
    exponential() { this->name = "2^n"; }
    std::vector<int> run(std::vector<int>);
};

// possible alternate n log n implementation
class patience : public LIS_model
{
public:
    patience() { this->name = "patience"; }
    std::vector<int> run(std::vector<int>);
};

#endif // LIS_MODEL_H
