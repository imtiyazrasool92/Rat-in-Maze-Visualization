#include <bits/stdc++.h>
#include <thread>         
#include <chrono>
#define n 5 // size of maze

using namespace std;

int path[n][n];
void visual(){
    for(int row=0;row<n;row++){
        for(int column=0;column<n;column++){
            cout << path[row][column] << " ";
        }
        cout << endl;
    }
}

bool ratInMaze(int maze[n][n],int r,int c){
        if(r==n-1&&c==n-1){
            path[r][c] = 1;
            return true;
        }
        if(maze[r][c]==0){
            path[r][c] = 1;
            system("clear");
            visual();
             this_thread::sleep_for (std::chrono::seconds(1));
            if(ratInMaze(maze,r,c+1)){
                return true;
            }
            if(ratInMaze(maze,r+1,c)){
                return true;
            }
            system("clear");
            visual();
             this_thread::sleep_for (std::chrono::seconds(1));
            path[r][c] = 0;
        }
        return false;
}

int main(){
    int maze[n][n] = {
                    {0,0,0,0,0},
                    {-1,0,-1,-1,-1},
                    {0,0,-1,0,0},
                    {-1,0,0,0,0},
                    {-1,0,-1,-1,0},
                    };
    memset(path,0,sizeof(path));        
    ratInMaze(maze,0,0);
       system("clear");
            visual();

}