#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "Tetris.h"

using namespace std;

void exibeJogo(const Tetris &jogoComPecaCaindo,int larguraJogo,int alturaMaximaJogo)
{
    for(int j=0; j<larguraJogo+2; j++)
    {
        cout<< '-';
    }
    cout<< endl;
	for(int i=0;i<alturaMaximaJogo;i++)
	{
        cout<< '|';
		for(int j=0;j<larguraJogo;j++)
		{   
            cout<< jogoComPecaCaindo.get(j, alturaMaximaJogo-i-1);
		}
		cout<< '|' << endl;
	}
    for(int j=0; j<larguraJogo+2; j++)
    {
        cout<< '-';
    }
    cout<< endl;
    cout<< ' ';
	for(int j=0;j<larguraJogo;j++)
    {
        cout<< jogoComPecaCaindo.getAltura(j)/10;
	}
    cout<< endl;
    cout<< ' ';
    for(int j=0; j<larguraJogo; j++)
    {
        cout<< jogoComPecaCaindo.getAltura(j)%10;
    }
    cout<< endl;
}

int main()
{
    Tetris jogo(20);

    //inicio

    cout<< jogo.adicionaForma(0, 5, 'I', 0) << endl;
    cout<< jogo.adicionaForma(5, 5, 'I', 90) << endl;
    cout<< jogo.adicionaForma(10, 5, 'I', 180) << endl;
    cout<< jogo.adicionaForma(15, 5, 'I', 270) << endl;

    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());

    cout<< jogo.adicionaForma(0, 10, 'J', 0) << endl;
    cout<< jogo.adicionaForma(5, 10, 'J', 90) << endl;
    cout<< jogo.adicionaForma(10, 10, 'J', 180) << endl;
    cout<< jogo.adicionaForma(15, 10, 'J', 270) << endl;

    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());

    cout<< jogo.adicionaForma(0, 15, 'L', 0) << endl;
    cout<< jogo.adicionaForma(5, 15, 'L', 90) << endl;
    cout<< jogo.adicionaForma(10, 15, 'L', 180) << endl;
    cout<< jogo.adicionaForma(15, 15, 'L', 270) << endl;

    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());

    cout<< jogo.adicionaForma(0, 20, 'O', 0) << endl;
    cout<< jogo.adicionaForma(5, 20, 'O', 90) << endl;
    cout<< jogo.adicionaForma(10, 20, 'O', 180) << endl;
    cout<< jogo.adicionaForma(15, 20, 'O', 270) << endl;

    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());

    cout<< jogo.adicionaForma(0, 25, 'S', 0) << endl;
    cout<< jogo.adicionaForma(5, 25, 'S', 90) << endl;
    cout<< jogo.adicionaForma(10, 25, 'S', 180) << endl;
    cout<< jogo.adicionaForma(15, 25, 'S', 270) << endl;

    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());

    cout<< jogo.adicionaForma(0, 30, 'T', 0) << endl;
    cout<< jogo.adicionaForma(5, 30, 'T', 90) << endl;
    cout<< jogo.adicionaForma(10, 30, 'T', 180) << endl;
    cout<< jogo.adicionaForma(15, 30, 'T', 270) << endl;

    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());

    cout<< jogo.adicionaForma(0, 35, 'Z', 0) << endl;
    cout<< jogo.adicionaForma(5, 35, 'Z', 90) << endl;
    cout<< jogo.adicionaForma(10, 35, 'Z', 180) << endl;
    cout<< jogo.adicionaForma(15, 35, 'Z', 270) << endl;

    exibeJogo(jogo,jogo.getNumColunas(),jogo.getAltura());
}
/*
1Adicionando forma I ; (l,c): (,0) ; rotacao: 0 ; resultado: 1
2--------------------
3Adicionando forma I ; (l,c): (5,5) ; rotacao: 90 ; resultado: 1
4--------------------
5Adicionando forma I ; (l,c): (5,10) ; rotacao: 180 ; resultado: 1
6--------------------
7Adicionando forma I ; (l,c): (5,15) ; rotacao: 270 ; resultado: 1
8--------------------
9Imprimindo jogo, altura: 6 ; colunas: 20
10 --------------------
11|I    IIII I    IIII |
12|I         I         |
13|I         I         |
14|I         I         |
15|                    |
16|                    |
17 --------------------
18 00000000000000000000
19 60000666606000066660
20
21--------------------
22Adicionando forma J ; (l,c): (10,0) ; rotacao: 0 ; resultado: 1
23--------------------
24Adicionando forma J ; (l,c): (10,5) ; rotacao: 90 ; resultado: 1
25--------------------
26Adicionando forma J ; (l,c): (10,10) ; rotacao: 180 ; resultado: 1
27--------------------
28Adicionando forma J ; (l,c): (10,15) ; rotacao: 270 ; resultado: 1
29--------------------
30Imprimindo jogo, altura: 11 ; colunas: 20
31 --------------------
32|JJJJ  J   J    JJ   |
33|   J  J   JJJJ J    |
34|      J        J    |
35|     JJ        J    |
36|                    |
37|I    IIII I    IIII |
38|I         I         |
39|I         I         |
40|I         I         |
41|                    |
42|                    |
43 --------------------
44 11110010001111011000
45 11110816601000011660
46
47--------------------
48Adicionando forma L ; (l,c): (15,0) ; rotacao: 0 ; resultado: 1
49--------------------
50Adicionando forma L ; (l,c): (15,5) ; rotacao: 90 ; resultado: 1
51--------------------
52Adicionando forma L ; (l,c): (15,10) ; rotacao: 180 ; resultado: 1
53--------------------
54Adicionando forma L ; (l,c): (15,15) ; rotacao: 270 ; resultado: 1
55--------------------
56Imprimindo jogo, altura: 16 ; colunas: 20
57 --------------------
58|LLLL LL      L L    |
59|L     L   LLLL L    |
60|      L        L    |
61|      L        LL   |
62|                    |
63|JJJJ  J   J    JJ   |
64|   J  J   JJJJ J    |
65|      J        J    |
66|     JJ        J    |
67|                    |
68|I    IIII I    IIII |
69|I         I         |
70|I         I         |
71|I         I         |
72|                    |
73|                    |
74 --------------------
75 11110110001111011000
76 66660666605556063660
77
78--------------------
79Adicionando forma O ; (l,c): (20,0) ; rotacao: 0 ; resultado: 1
80--------------------
81Adicionando forma O ; (l,c): (20,5) ; rotacao: 90 ; resultado: 1
82--------------------
83Adicionando forma O ; (l,c): (20,10) ; rotacao: 180 ; resultado: 1
84--------------------
85Adicionando forma O ; (l,c): (20,15) ; rotacao: 270 ; resultado: 1
86--------------------
87Imprimindo jogo, altura: 21 ; colunas: 20
88 --------------------
89|OO   OO   OO   OO   |
90|OO   OO   OO   OO   |
91|                    |
92|                    |
93|                    |
94|LLLL LL      L L    |
95|L     L   LLLL L    |
96|      L        L    |
97|      L        LL   |
98|                    |
99|JJJJ  J   J    JJ   |
100|   J  J   JJJJ J    |
101|      J        J    |
102|     JJ        J    |
103|                    |
104|I    IIII I    IIII |
105|I         I         |
106|I         I         |
107|I         I         |
108|                    |
109|                    |
110 --------------------
111 22110220002211022000
112 11660116601156011660
113
114--------------------
115Adicionando forma S ; (l,c): (25,0) ; rotacao: 0 ; resultado: 1
116--------------------
117Adicionando forma S ; (l,c): (25,5) ; rotacao: 90 ; resultado: 1
118--------------------
119Adicionando forma S ; (l,c): (25,10) ; rotacao: 180 ; resultado: 1
120--------------------
121Adicionando forma S ; (l,c): (25,15) ; rotacao: 270 ; resultado: 1
122--------------------
123Imprimindo jogo, altura: 26 ; colunas: 20
124 --------------------
125| SS  S     SS  S    |
126|SS   SS   SS   SS   |
127|      S         S   |
128|                    |
129|                    |
130|OO   OO   OO   OO   |
131|OO   OO   OO   OO   |
132|                    |
133|                    |
134|                    |
135|LLLL LL      L L    |
136|L     L   LLLL L    |
137|      L        L    |
138|      L        LL   |
139|                    |
140|JJJJ  J   J    JJ   |
141|   J  J   JJJJ J    |
142|      J        J    |
143|     JJ        J    |
144|                    |
145|I    IIII I    IIII |
146|I         I         |
147|I         I         |
148|I         I         |
149|                    |
150|                    |
151 --------------------
152 22210220002221022000
153 56660656605666065660
154
155--------------------
156Adicionando forma T ; (l,c): (30,0) ; rotacao: 0 ; resultado: 1
157--------------------
158Adicionando forma T ; (l,c): (30,5) ; rotacao: 90 ; resultado: 1
159--------------------
160Adicionando forma T ; (l,c): (30,10) ; rotacao: 180 ; resultado: 1
161--------------------
162Adicionando forma T ; (l,c): (30,15) ; rotacao: 270 ; resultado: 1
163--------------------
164Imprimindo jogo, altura: 31 ; colunas: 20
165 --------------------
166|TTT   T    T   T    |
167| T   TT   TTT  TT   |
168|      T        T    |
169|                    |
170|                    |
171| SS  S     SS  S    |
172|SS   SS   SS   SS   |
173|      S         S   |
174|                    |
175|                    |
176|OO   OO   OO   OO   |
177|OO   OO   OO   OO   |
178|                    |
179|                    |
180|                    |
181|LLLL LL      L L    |
182|L     L   LLLL L    |
183|      L        L    |
184|      L        LL   |
185|                    |
186|JJJJ  J   J    JJ   |
187|   J  J   JJJJ J    |
188|      J        J    |
189|     JJ        J    |
190|                    |
191|I    IIII I    IIII |
192|I         I         |
193|I         I         |
194|I         I         |
195|                    |
196|                    |
197 --------------------
198 33310330003331033000
199 11160016600106010660
200
201--------------------
202Adicionando forma Z ; (l,c): (35,0) ; rotacao: 0 ; resultado: 1
203--------------------
204Adicionando forma Z ; (l,c): (35,5) ; rotacao: 90 ; resultado: 1
205--------------------
206Adicionando forma Z ; (l,c): (35,10) ; rotacao: 180 ; resultado: 1
207--------------------
208Adicionando forma Z ; (l,c): (35,15) ; rotacao: 270 ; resultado: 1
209--------------------
210Imprimindo jogo, altura: 36 ; colunas: 20
211 --------------------
212|ZZ    Z   ZZ    Z   |
213| ZZ  ZZ    ZZ  ZZ   |
214|     Z         Z    |
215|                    |
216|                    |
217|TTT   T    T   T    |
218| T   TT   TTT  TT   |
219|      T        T    |
220|                    |
221|                    |
222| SS  S     SS  S    |
223|SS   SS   SS   SS   |
224|      S         S   |
225|                    |
226|                    |
227|OO   OO   OO   OO   |
228|OO   OO   OO   OO   |
229|                    |
230|                    |
231|                    |
232|LLLL LL      L L    |
233|L     L   LLLL L    |
234|      L        L    |
235|      L        LL   |
236|                    |
237|JJJJ  J   J    JJ   |
238|   J  J   JJJJ J    |
239|      J        J    |
240|     JJ        J    |
241|                    |
242|I    IIII I    IIII |
243|I         I         |
244|I         I         |
245|I         I         |
246|                    |
247|                    |
248 --------------------
249 33310330003331033000
250 66560566606656056660


----------------------
|ZZ    Z   ZZ    Z   |
| ZZ  ZZ    ZZ  ZZ   |
|     Z         Z    |
|                    |
|                    |
|TTT   T    T   T    |
| T   TT   TTT  TT   |
|      T        T    |
|                    |
|                    |
| SS  S     SS  S    |
|SS   SS   SS   SS   |
|      S         S   |
|                    |
|                    |
|OO   OO   OO   OO   |
|OO   OO   OO   OO   |
|                    |
|                    |
|                    |
|LLLL LL      L L    |
|L     L   LLLL L    |
|      L        L    |
|      L        LL   |
|                    |
|JJJJ  J   J    JJ   |
|   J  J   JJJJ J    |
|      J        J    |
|     JJ        J    |
|                    |
|I    IIII I    IIII |
|I         I         |
|I         I         |
|I         I         |
|                    |
|                    |
----------------------
 33310330003331033000
 66560566606656056660
251
252--------------------*/