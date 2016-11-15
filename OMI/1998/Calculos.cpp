#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int Multiply, Divide, Target, Result, Mult, Div, N, Parent, Visited[10000];
queue<int> Queue;
queue<int> Times;

void Solve()
{
    Queue.push(1);
    Times.push(0);
    while(!Queue.empty())
    {
        N = Queue.front();
        Queue.pop();
        Parent = Times.front();
        Times.pop();
        if(N == Target)
        {
            Result = Parent;
            break;
        }
        Visited[N] = 1;
        Mult = N*Multiply;
        Div = N/Divide;
        if(Mult > 9999)
            Mult = 1;
        if(Div > 9999)
            Div = 1;
        if(!Visited[Mult])
        {
            Queue.push(Mult);
            Times.push(Parent+1);
            Visited[Mult] = 1;
        }
        if(!Visited[Div])
        {
            Queue.push(Div);
            Times.push(Parent+1);
            Visited[Div] = 1;
        }
    }
}

int main()
{
    optimizar_io;
    cin >> Multiply >> Divide >> Target;
    Solve();
    cout << Result;
    return 0;
}
