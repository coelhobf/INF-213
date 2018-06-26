#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string cpf;
        cin>> cpf;
        int nmr = 0;
        for (int i = 10; i > 1; i--)
        {
            int indice = -1 *(i - 10);
            nmr += i * (cpf[indice] - '0');
            //cout<< nmr << endl;
        }
        //cout<< nmr << endl;
        nmr = (10 * nmr)%11;
        nmr = nmr == 10 ? 0 : nmr;
        cpf += '0' + nmr;

        nmr = 0;
        for (int i = 11; i > 1; i--)
        {
            int indice = -1 *(i - 11);
            nmr += i * (cpf[indice] - '0');
            //cout<< nmr << endl;
        }
        //cout<< nmr << endl;
        nmr = (10 * nmr)%11;
        nmr = nmr == 10 ? 0 : nmr;
        cpf += '0' + nmr;

        cout<< cpf[9] << cpf[10] << endl;
    }
}