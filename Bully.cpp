#include<bits/stdc++.h>
using namespace std;
struct process{
   int id;
   int crash;
};
process P[10];

int total,coordinator;

int highest(){
   int max=0,i,loc; 
  for(i=1;i<=total;i++){
     if(P[i].id>max){
       if(P[i].crash==0){
        max=P[i].id;
        loc=i;
       }  
     }
  }
  return loc;
}

void election(int newco){
    int i,j,new1;
    int total1=0;
    for(j=1;j<=total;j++)
        if(P[j].crash!=1)
            total1++;
    while(newco<=total1){  
            for(i=newco+1;i<=total;i++)
                if(P[newco].id< P[i].id)
                  printf("Election message sent to Process %d by process %d\n",i,newco);
            printf("\n");
            for(i=newco+1;i<=total;i++)
                if(P[i].crash==0 && P[newco].id< P[i].id )
                  printf("OK message received from Process %d\n",i);
                else if(P[i].crash=1 && P[newco].id< P[i].id)
                  printf("Process %d is not responding..\n",i);
                newco=newco+1;
            if(newco<=total1)
                printf("process %d is taking over..\n",newco);
    }
    coordinator=newco-1;
    printf("New elected coordinator is Process %d\n\n",coordinator);  
}

void Crash(){
    int no,i,newco;
    printf("Enter the Process Number of the Process to be crashed: ");
    scanf("%d",&no);
    P[no].crash=1;
    printf("Process %d has crashed.. ",no); 
    for(i=1;i<=total;i++){
        if(P[i].crash==0)
          printf("Process %d is active\n",i);
        else 
          printf("Process %d is Inactive\n",i); 
   }
   if(no==coordinator){ 
        cout<<"Enter a process number which should start the election: ";
        cin>>newco;
        election(newco);
   }
}

void Recover(){
    int rec;
    cout<<"Enter the Process number of the process to be recovered: ";
    cin>>rec;
    P[rec].crash=0;
    election(rec);
}

void Bully(){
  int op;
  coordinator=highest(); 
  cout<<"Process "<<coordinator<<" is the Coordinator...\n";
  do{  
      printf("\n 1.Crash \n 2.Recover \n 3.Exit ");
      printf("\nEnter your choice: ");
      cin>>op;
      switch(op){
          case 1: Crash();
                break;
          case 2: Recover();
                break;
          case 3: 
                break; new
      }
    }while(op!=3);
}
int main(){ 
  int i,id;
  int ch;
  cout<<"Enter number of process : ";
  cin>>total;
  cout<<"Enter the id for the processes from low priority to high priority\n";
  for(i=1;i<=total;i++){  
       cout<<"Enter id for Process : "<<i<<" : ";
       cin>>id;new
       P[i].id=id;
       P[i].crash=0;
   }
  Bully();
  return 0;
}
