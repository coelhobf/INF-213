#include <bits/stdc++.h>
using namespace std;

double calcCRA1(const map<string, double> &cra)
{
    double med = 0.0;

    map<string, double>::const_iterator it = cra.cbegin();
    for(; it != cra.cend(); it++)
    {
        med+= (*it).second;
    }

    return med / cra.size();
}

double calcCRA2(const map<string, double> &cra)
{
    double med = 0.0;

    for(auto &x: cra)
    {
        med+= x.second;
    }

    return med / cra.size();
}

double calcCRA3(const map<string, double> &cra)
{
    double med = accumulate(cra.cbegin(), cra.cend(), 0.0,
    [] (double value, const std::map<string, double>::value_type& p)
                   { return value + p.second; });

    return med / cra.size();
}

void printNome(const map<string, double> &cra)
{
    for(auto &x: cra)
    {
        cout<< x.first << " " << x.second << "\n";
    }
}

void printCRA(const map<string, double> &cra)
{
    vector<pair<string, double>> v(cra.begin(), cra.end());

    sort(v.begin(), v.end(),
        [] (const pair<string, double> &a, const pair<string, double> &b)
        {
            if(a.second < b.second)
            {
                return true;
            }
            else if(a.second > b.second)
            {
                return false;
            }
            else
            {
                if(a.first <= b.first)
                {
                    return true;
                }
            }

            return false;
        });

    for(auto &x: v)
    {
        cout<< x.first << " " << x.second << "\n";
    }
}

int aprovados(const map<string, double> &cra)
{
    return count_if(cra.cbegin(), cra.cend(),
    [](const pair<string, double> &p){return p.second >= 60.0;});
}

int main()
{
    map<string, double> cra;

    cra["bruno1"] = 79.8;
    cra["bruno2"] = 77.5;
    cra["bruno3"] = 78.1;

    cout<< calcCRA1(cra) << "\n";
    cout<< calcCRA2(cra) << "\n";
    cout<< calcCRA3(cra) << "\n";
    cout<< "\n";
    printNome(cra);
    cout<< "\n";
    printCRA(cra);
    cout<< "\n";
    cout<< aprovados(cra) << "\n";
    cout<< "\n";
}