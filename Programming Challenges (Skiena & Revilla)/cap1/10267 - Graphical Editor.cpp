#include <iostream>
#include <bits/stdc++.h> 

/*
 Ideia é implementar cada função separadamente.
Atenção para os índices que estão trocados do costume em programação
(x,y) img [y][x]
a função de região é facilmente implementada por recursividade, mas deve
ser estritamente limitado a recursão para não exceder tempo
*/

using namespace std;

char img[255][255];
int n, m;    
char op, c, nome[15];
int i,j;

void I(){
    cin >> n >> m;
    for (int i=0; i<=m; i++)
        for (int j=0; j<=n; j++)
            img[i][j] = 'O';
}

void C(){
    for (int i=0; i<=m; i++)
        for (int j=0; j<=n; j++)
            img[i][j] = 'O';
}

void L(){
    int x, y;
    cin >> x >> y >> c;
    img[y][x]=c;
}

void V(){
    int x, y1, y2;
    cin >> x >> y1 >>  y2 >> c;
    if (y1 > y2) swap(y1, y2);
    for(j=y1; j<=y2; j++)
        img[j][x] = c;
}
void H(){
    int y, x1, x2;
    cin >> x1 >> x2 >> y >> c;
    if (x1 > x2) swap(x1,x2);
    for(i=x1; i<=x2; i++)
        img[y][i] = c;
}

void K(){
    int  x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    for(i=y1; i<=y2; i++)
        for (j=x1;j<=x2;j++)
            img[i][j] = c;
}

void Frecursiva(int x, int y, char c, char o){
    
    if ( x<1 || x > n || y<1 || y > m) return;
    if (img[y][x]!=o)  return;
      
    img[y][x]=c;
    Frecursiva( x-1, y, c, o);
    Frecursiva( x+1, y, c, o);
    Frecursiva( x  , y-1, c, o);
    Frecursiva( x  , y+1, c, o);
}

void F(){
    int x, y;
    cin >> x >> y >> c;
    if (img[x][y] != c)
        Frecursiva(x, y, c,img[y][x]);
}

void S(){
    cin >> nome;
    cout << nome << endl;
    for(i=1; i<=m; i++){
        for (j=1; j<=n; j++)
            putchar(img[i][j]);
        puts("");
    }
}

int main(){
    
    while (true){
        cin >> op;
        switch(op){
            case 'I':
                I();
                break;
            case 'C':
                C();
                break;
            case 'L':
                L();
                break;
            case 'V':
                V();
                break;
            case 'H':
                H();
                break;
            case 'K':
                K();
                break;
            case 'F':
                F();
                break;
            case 'S':
                S();
                break;
            case 'X':
                return 0;
            default:
                do{
                    c = getchar();
                } while(c!='\n');
        }
    }
    return 0;
}
