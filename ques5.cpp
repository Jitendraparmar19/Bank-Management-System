#include <iostream>

using namespace std;

float arr[100][3]={0}; //initialized an array in which 1st column is denoting account number, 2nd denotes pin, 3rd denotes amount
int index1=0;
 int PIN;  // Manager pin is 4562

//function for opening a new account,asks for your pin(whatever you want) and initial deposit and gives you your account number.
void Open_Account(void){    
    int b=0;
    for(;b<100;b++){
        if(arr[b][0]==0){
            cout<<"Enter Your Pin (Must be in 4 digits) ";  
            cin>>arr[b][1];
            if(arr[b][1]<=9999 && arr[b][1]>=1000){
                cout<<endl<<"Enter Your Initial Deposit ";
                cin>>arr[b][2];
                arr[b][0]=1001+b;
                cout<<endl<<"Your Account Number is "<<1001+b<<endl; 
                break;
            }
            else{
                cout<<"PIN Criteria Did Not Meet"<<endl;
                break;
            }
            
        }
       else{continue;}
    }
    if (b==100){cout<<"Account cannot be opened";}
    
}  

//verification function verifies that account number and pin entered are right
bool Verification(int A,int P){   
    cout<<"Enter Your Account No. ";
    cin>>A;
    for(int b=0;b<100;b++){
       if(arr[b][0]==A) {
           cout<<"Enter Your Pin ";
           cin>>P;
           if(arr[b][1]==P){
               index1=b;
               return true;
           }
           else{
               return false;
           }
       }
    }
    return false;
   
}

int main()
{
    int A,P;
    char Transaction_type;
    cout<<"Enter Your Transaction_type ";
    cin>>Transaction_type;
    if(Transaction_type=='S'){                  //For opening the bank and enabling all the transaction function
        cout<<"Enter Pin (Should be entered by manager) ";
        cin>>PIN;
        if(PIN==4562){
            while(1>0){
                cout<<"Enter Your Transaction_type ";
                cin>>Transaction_type;
                switch (Transaction_type){
                    case 'I':  
                            cout<<"Enter Pin for I (Should be entered by manager) ";
                            cin>>PIN;
                            if(PIN==4562){
                              for(int z=0;z<100;z++){
                                  if(arr[z][2]!=0){
                                      cout<<"Enter Your % Rate " ;
                                       int Interest_Rate;
                                       cin>>Interest_Rate;
                                      float Interest= (arr[z][2]*Interest_Rate)/100; //Time Taken is 1 Year
                                      arr[z][2]+=Interest;
                                  }
                              }
                              
                            }
                            else{cout<<"Access Denied"<<endl;}
                            break; 
                            
                    case 'P':  
                            cout<<"Enter Pin for P (Should be entered by manager) ";
                            cin>>PIN;
                            if(PIN==4562){
                                int p=0;
                              for(int z=0;z<100;z++){
                                  if(arr[z][0]!=0){
                                      cout<<arr[z][0]<<"  "<<arr[z][2]<<endl;
                                      p++;
                                    }
                                } 
                                if(p==0){cout<<"No Account has been created"<<endl;}
                            }
                            else{cout<<"Access Denied"<<endl;}
                            break; 
                            
                    case 'E':  
                            cout<<"Enter Pin for E (Should be entered by manager) ";
                            cin>>PIN;
                            if(PIN==4562){
                                for(int y=0;y<100;y++){
                                    arr[y][0]=0;}
                              cout<<"All accounts closed"<<endl;
                              exit(0);
                            }
                            else{cout<<"Access Denied"<<endl;}
                            break; 
                    
                    case 'O':  
                            Open_Account(); 
                            break; 
            
                    case 'B':  
                            if(Verification(A,P)){
                                cout<<"Account No. "<<arr[index1][0]<<endl;
                                cout<<"Balance "<<arr[index1][2]<<endl ;
                            }
                            else{
                                cout<<"Account Details Incorrect"<<endl;
                                 }
                            break; 
            
                    case 'D':  
                           if(Verification(A,P)){
                                int New_Deposit;
                                cout<<"Enter your new deposit ";
                                cin>>New_Deposit;
                                arr[index1][2]=arr[index1][2]+New_Deposit;
                                cout<<"Account No. "<<arr[index1][0]<<endl;
                                cout<<"New Balance "<<arr[index1][2]<<endl ;
                            }
                            else{
                                 cout<<"Account Details Incorrect"<<endl;
                               }
                            break;
            
                    case 'W':  
                            if(Verification(A,P)){
                                int Withdrawal;
                                cout<<"Amount needs to be withdrawn ";
                                cin>>Withdrawal;
                                if(arr[index1][2]>=Withdrawal){
                                    arr[index1][2]=arr[index1][2]-Withdrawal;
                                    cout<<"Account No. "<<arr[index1][0]<<endl;
                                    cout<<"Balance "<<arr[index1][2]<<endl ;
                                }
                                else{cout<<"Not Enough Money"<<endl;}
                            }
                            else{
                                cout<<"Account Details Incorrect"<<endl;
                            }
                            break;
            
                    case 'C':  
                            if(Verification(A,P)){
                                 arr[index1][0]=0;
                                 arr[index1][1]=0;
                                 arr[index1][2]=0;
                                 cout<<"Account Closed"<<endl;
                            }
                            else{
                                 cout<<"Account Details Incorrect"<<endl;
                            }
                            break;
            
                    default:  
                            cout << "Invalid Transaction_type"; 
                            break; 
                }
            }
        }
        else{
            cout<<"Access Denied"<<endl;
        }
    }
    else{
        cout << "Invalid Transaction_type";
    }
    return 0;
}
