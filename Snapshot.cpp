#include<bits/stdc++.h>
using namespace std;
const int N=4;
vector<int> PS[N];
int main(){
    for(int i=0;i<N;i++){
        PS[i].clear();
    }
    int Events;
    cout<<"No of Events : ";
    cin>>Events;
    int src,dest;
    bool f;
    for(int i=0;i<Events;i++){
        cout<<"Press 1 to check status of all the processes at this time : ";
        cin>>f;
        if(f){
            for(int j=0;j<N;j++){
                cout<<"Process : "<<j+1<<" \t";
                for(int s=0;s<PS[j].size(); s++)
                    cout<<"e"<<j+1<<"^"<<s+1<<", ";
                cout<<endl;
            }
        }
        src=rand()%N;
        dest=rand()%N;
        cout<<src+1<<" "<<dest+1<<"\n";
        PS[dest].push_back(1); 
        PS[src].push_back(1);
    }
    return 0;
}
