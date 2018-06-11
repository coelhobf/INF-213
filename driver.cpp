#include <bits/stdc++.h>
using namespace std;

// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
//#include "MyStack.h"

void etapa1()
{
    stack<int> s;
    queue<int> q;

    for (int i = 0; i < 6; i++)
    {
        int a;
        cin >> a;
        s.push(a);
        q.push(a);
    }

    for (int i = 0; i < 6; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

void etapa2()
{
    string str;
    cin.ignore();
    getline(cin, str);

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
                cout << "Inconsistente" << endl;
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

//---------------------------------------

// Insira aqui o codigo para a etapa 3....

//#include "MedianaLenta.h" //use essa implementacao para fazer os primeiros testes (com o calculo lento da mediana...)
#include "Mediana.h" //descomente esta linha para utilizar sua classe mais eficiente!
void etapa3()
{
    //descomente o codigo abaixo ao fazer a etapa 3
    Mediana mediana;
    vector<int> v;

    int n, elem;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        mediana.insere(elem);
        
        cout<< mediana.getMediana() << " ";
    }
    cout << "\n";
}

//---------------------------------------

int main()
{
    int etapa;
    cin >> etapa;
    switch (etapa)
    {
    case 1:
        cout << "Etapa 1" << endl;
        etapa1();
        break;
    case 2:
        cout << "Etapa 2" << endl;
        etapa2();
        break;
    case 3:
        cout << "Etapa 3" << endl;
        etapa3();
        break;
    }
}
