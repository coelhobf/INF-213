#include <bits/stdc++.h>
#include "Mediana.h"

using namespace std;

void etapa1()
{
    stack<int> s;
    queue<int> q;

    for (int i = 0; i < 5; i++)
    {
        int a;
        cin >> a;
        s.push(a);
        q.push(a);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void etapa2()
{
    string str;
    cin >> str;

    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case '(':
        case '[':
        case '{':
            s.push(str[i]);
            break;
        case ')':
            if (s.empty() || s.top() != '(')
            {
                cout<< "Inconsistente" << endl;
                return;
            }
            s.pop();
            break;
        case ']':
            if (s.empty() || s.top() != '[')
            {
                cout << "Inconsistente" << endl;
                return;
            }
            s.pop();
            break;
        case '}':
            if (s.empty() || s.top() != '{')
            {
                cout << "Inconsistente" << endl;
                return;
            }
            s.pop();
            break;
        }
    }

    if (s.empty())
    {
        cout << "Consistente" << endl;
        return;
    }
    else
    {
        cout << "Inconsistente" << endl;
        return;
    }
}

void etapa3()
{
    Mediana med;
    int a;
    while(cin>> a)
    {
        med.insere(a);
        cout<< med << endl;
        cout<< med.getMediana() << " ";
    }
    cout<< endl;

}

int main()
{
    //etapa1();
    //etapa2();
    etapa3();
    return 0;
}
