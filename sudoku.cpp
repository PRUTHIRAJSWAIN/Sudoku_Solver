#include<bits/stdc++.h>
using namespace std;
#define n 9
bool issafe(int arr[n][n],int i,int j,int value)
{
    for(int k=0;k<9;k++)
    {
        if(arr[i][k]==value || arr[k][j]==value)
            return false;
    }
    int iblock=i/3;
    int jblock=j/3;
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            if(arr[iblock*3+x][jblock*3+y]==value)
            {

                return false;
            }
        }
    }

    return true;
}
void printgrid(int arr[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

bool solve(vector<pair<int,int>> &pos,int arr[n][n],int depth)
{
    if(depth>=pos.size())
    {
        return true;
    }
    for(int i=1;i<=9;i++)
    {

        int x=pos[depth].first;
        int y=pos[depth].second;

        if(issafe(arr,x,y,i))
        {
            //cout<<x<<"  "<<y<<endl;
            arr[x][y]=i;
            if(solve(pos,arr,depth+1))
                return true;
            arr[x][y]=0;
        }
    }
    return false;

}

int main()
{
    int arr[n][n]=   { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    vector<pair<int,int>> pos;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0)
            {
                pair<int,int> temp;
                temp.first=i;
                temp.second=j;
                pos.push_back(temp);
            }
        }
    }
    if(solve(pos,arr,0))
        printgrid(arr);
}

