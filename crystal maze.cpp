//..............................................................trust the process..............................................................



/*..........................Do not go gentle into that good night. Rage, rage against the dying of the light......................................*/


/*............................."I put my heart and my soul into my work,.................................................................
.......................................And have actually lost my mind while doing so,".....................................................*/




/*.................................Can or can't, the path exists only when you choose to walk it...............................................*/



/*You see, power, real power, doesn't come to those who were born strongest
            or fastest or smartest. No, it comes to those who will do anything to achieve it"
                                                                                             — Silco*/

/* stuff you should really look for
    * "Keep your thought process clear!"
    * THINK FIRST!, THEN CODE!
    * List/write down the OBSERVATIONS and think in a DISCIPLINED way !
    * Observe/simulate the test cases properly
    * Re-read the question.
    * DON'T GET STUCK ON ONE APPROACH
    * int overflow, array bounds
    * special cases (n=1?), set assert, clear structure for next test case.
    * comparitive,||,==) execute first than bit operator(<<,>>,&,^,|).
    * do smth instead of nothing and stay organized
    * oeis.org
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;
void neighbourgenerator(vector<pair<int,int>> &neighbour){

for(int i=-1;i<=1;i++){
    for(int j=-1;j<=1;j++){

        if(abs(i)!=abs(j)){
            neighbour.emplace_back(i, j);
        }

    }

}


}

int bfs(int row,int col,vector<vector<char>> &maze,vector<pair<int,int>> &neighbours,vector<vector<int>> &visited){

int rows=maze.size();
int cols=maze[0].size();

queue<pair<int,int>> q;

q.push({row,col});
visited[row][col]=1;
int m=0;
while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
    visited[r][c]=1;
    if(maze[r][c]=='C') m++;
    q.pop();
    for(int i=0;i<4;i++){
         int validrow=r+neighbours[i].first;
         int validcol=c+neighbours[i].second;
         if(validrow<rows && validrow>=0 && validcol<cols && validcol>=0 && (maze[validrow][validcol]=='.' || maze[validrow][validcol]=='C') && visited[validrow][validcol]==0){

            visited[validrow][validcol]=1;
            q.push({validrow,validcol});


         }


    }






}


return m;

}




/// vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main(){
    int test,z=1;
    cin>>test;
    while(test--){

vector<pair<int,int>> neighbours;
neighbourgenerator(neighbours);

int n,m,q;
cin>>n>>m>>q;
vector<vector<int>> visited(n,vector<int>(m,0));


vector<vector<char>> maze(n,vector<char>(m));

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>maze[i][j];
    }
}
cout<<"Case "<<z<<":"<<endl;
for(int i=0;i<q;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;

    cout<<bfs(x,y,maze,neighbours,visited)<<endl;


}
z++;
   }

return 0;}
