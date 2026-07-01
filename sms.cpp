#include<bits/stdc++.h>
using namespace std;
struct employee{
    char name[100];
    int salary;
    int id;
};
int main(){
    employee e[100] = {
        { "Amit ", 25000, 26110},
        {"Arun ", 30100, 26412 }
    };

    cout<<"1. Display employee \n"<<"2. Add employee \n"<<"3. Search employee \n"<< "4. Update salary \n"<<"5. calculate net salary \n"<<"6. Delete employee\n"<<endl;
    int choice,curr =2;
    cin>>choice;
    cout<<'\n';
    switch(choice){
        case 2 :{
            cout<<"Enter number of employee you want to add : ";
            int number;
            cin>>number;
            for(int i=curr;i<curr+number;i++){
              cout<<"Enter name : ";
              cin>>e[i].name ;
              cout<<"Enter salary : ";
              cin>>e[i].salary ;
              cout<<"Enter id : ";
              cin>>e[i].id;

            }
            curr+= number;
            cout<<"Record added successfully ";
            break;

        }
        
        case 1 :{
           cout<<"Name "<<"Salary "<<"Id "<<endl;
           for(int i=0;i<curr;i++){
    
              cout<<e[i].name <<" "<<e[i].salary<<" "<<e[i].id<<endl;

            }
            break;
        }
        
        case 3 :{
          cout<<"Enter employee id : ";
          int R;
          cin>>R;
          for(int i=0;i<curr;i++){
              if(e[i].id == R){
                 cout<<"Name "<<"Salary "<<"Id "<<endl;
                
                 cout<<e[i].name <<" "<<e[i].salary<<" "<<e[i].id<<endl;
                 break;
                }
            
            }
             break;
        }

        case 4 :{
           cout<<"Enter employee id : ";
           int p,pos =-1;
           cin>>p;
           for(int i=0;i<curr;i++){
              if(e[i].id == p){
                 pos = i;
                 break;
                }
            }
          if(pos == -1){
              cout<<"Employee id not found ";
            }
          else{
              
              cout<<"Enter new salary : ";
              cin>>e[pos].salary;
            
              cout<<"Records updated successfully ";
            }
            break;
        }


        case 5 : {
            cout<<"Enter employee id : ";
            int p,pos =-1,netsalary;
            cin>>p;
           for(int i=0;i<curr;i++){
              if(e[i].id == p){
                 pos = i;
                 break;
                }
            }
          if(pos == -1){
              cout<<"Employee id not found ";
            }
            else{
                netsalary = e[pos].salary + 0.2*e[pos].salary + 0.1*e[pos].salary - 0.05*e[pos].salary ; // netsalary = HRA + DA - PF
                cout<<"Basic salary is : " << e[pos].salary <<'\n'<<"Net salary is : "<<netsalary;
            }

        break;
        }
         

        case 6 :{

          cout<<"Enter employee id : ";
          int r,posi = -1;
          cin>>r;
          for(int i=0;i<curr;i++){
              if(e[i].id == r){
                  posi = i;
                  break;
                }
            }
          if(posi == -1){
              cout<<"Employee id not found ";
            }
          else{
              for(int i=posi;i<curr-1;i++){
                  e[i] = e[i+1] ;
                }
                curr--;
                cout<<"Records deleted successfully ";
            }
            break;
        }

        
    }
    return 0;

}
