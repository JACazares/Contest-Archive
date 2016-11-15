#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int Row, Col, World[50][50], RowA, RowB, ColA, ColB, Result, Distance[50][50], R, C, Parent, Visited[50][50];
queue<int> Distances;
struct coord
{
    int X, Y;
};
coord Coord, Coord1;
queue<coord> Queue;

void Solve(int x1, int y1)
{
    Coord.X = x1;
    Coord.Y = y1;
    Queue.push(Coord);
    Distances.push(1);
    while(!Queue.empty())
    {
        Coord = Queue.front();
        Queue.pop();
        Parent = Distances.front();
        Distances.pop();
        R = Coord.X;
        C = Coord.Y;
        Visited[R][C] = 1;
        Distance[R][C] = Parent;
        if(R > 0)
        {
            Coord1.X = R-1;
            Coord1.Y = C;
            if(World[Coord1.X][Coord1.Y] == 0 && !Visited[Coord1.X][Coord1.Y])
            {
                Queue.push(Coord1);
                Distances.push(Parent+1);
                Visited[Coord1.X][Coord1.Y] = 1;
            }
        }
        if(R < Row-1)
        {
            Coord1.X = R+1;
            Coord1.Y = C;
            if(World[Coord1.X][Coord1.Y] == 0 && !Visited[Coord1.X][Coord1.Y])
            {
                Queue.push(Coord1);
                Distances.push(Parent+1);
                Visited[Coord1.X][Coord1.Y] = 1;
            }
        }
        if(C > 0)
        {
            Coord1.X = R;
            Coord1.Y = C-1;
            if(World[Coord1.X][Coord1.Y] == 0 && !Visited[Coord1.X][Coord1.Y])
            {
                Queue.push(Coord1);
                Distances.push(Parent+1);
                Visited[Coord1.X][Coord1.Y] = 1;
            }
        }
        if(C < Col-1)
        {
            Coord1.X = R;
            Coord1.Y = C+1;
            if(World[Coord1.X][Coord1.Y] == 0 && !Visited[Coord1.X][Coord1.Y])
            {
                Queue.push(Coord1);
                Distances.push(Parent+1);
                Visited[Coord1.X][Coord1.Y] = 1;
            }
        }
    }
}

int main()
{
    optimizar_io;
    cin >> Row >> Col;
    for(int i=0; i<Row; i++)
        for(int j=0; j<Col; j++)
            cin >> World[i][j];
    cin >> RowA >> ColA;
    cin >> RowB >> ColB;
    Solve(RowA, ColA);
    Result = Distance[RowB][ColB];
    cout << Result;
    return 0;
}
