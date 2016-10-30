#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int Rooms, Edges, Time, RoomA, RoomB, Visited[105], Node, TimeTaken, Result;
queue<int> Queue;
queue<int> Times;
vector<int> Submarine[105];

void Breadth(int InitialNode)
{
    Queue.push(InitialNode);
    Times.push(0);
    while(!Queue.empty())
    {
        Node = Queue.front();
        Queue.pop();
        TimeTaken = Times.front();
        Times.pop();
        Visited[Node] = 1;
        for(int i=0; i<Submarine[Node].size(); i++)
        {
            if(!Visited[Submarine[Node][i]])
            {
                Queue.push(Submarine[Node][i]);
                Times.push(TimeTaken+1);
                Visited[Submarine[Node][i]] = 1;
                if(TimeTaken+1 < Time)
                    Result++;
            }
        }
    }
}

int main()
{
    optimizar_io;
    cin >> Rooms >> Edges >> Time;
    for(int i=0; i<Edges; i++)
    {
        cin >> RoomA >> RoomB;
        Submarine[RoomA].push_back(RoomB);
        Submarine[RoomB].push_back(RoomA);
    }
    Breadth(Rooms);
    cout << Result;
    return 0;
}
