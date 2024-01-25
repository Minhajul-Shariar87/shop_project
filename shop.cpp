#include<iostream>
#include<stdlib.h>

#include<string.h>
#include<fstream>

using namespace std;

//watch
class Gadgets{

public:

    string gadgets;
    int price;

    Gadgets(string gadgets,int price){
   this -> gadgets=gadgets;
   this -> price=price;

    }
virtual void tprice()=0;
};
class Accessories:public Gadgets{

public:
    Accessories(string gadgets,int price):Gadgets(gadgets,price){

    }
    int q;
    void tprice(){
    cout<<"The gadget name is: "<<gadgets<<endl;
    cout<<"The price of the gadget is: "<<price<<endl;
    cout<<"Quantity: ";
 cin>>q;
 int total=0;

 for(int i=1;i<=q;i++){
    total=total+price;
 }
 cout<<"Total price is: "<<total<<endl;

    }

};



Gadgets *g;
void accessories(){
int q,s;
string r,t;

cout<<"The name of the gadget is: ";
getline(cin>>ws,t);

cout<<"The price of the watch is: ";
cin>>s;
Accessories p(t,s);
g=&p;
g -> tprice();
cout<<"The name of the gadget is: ";
getline(cin>>ws,r);

cout<<"The price of the watch is: ";
cin>>q;
Accessories u(r,q);
g=&u;
g -> tprice();
}

void registration(){
string mail,password,name,cmail,cpassword;
int ncount;
ofstream nfile;
nfile.open("account.txt",ios::app);
cout<<"Enter mail: ";
cin>>mail;
cout<<"Enter password: ";
cin>>password;
cout<<"Enter name: ";

getline(cin>>ws,name);
nfile<<mail<<endl;
nfile<<password<<endl;
nfile.close();
}
void login(){
string cmail,cpassword,password,mail;
string line;
int ncount;
cout<<"Enter your mail: ";
cin>>cmail;
cout<<"Enter your password: ";
cin>>cpassword;
ifstream file("account.txt");
while(file>>mail>>password){
    if(cmail==mail&&cpassword==password){
       ncount=1;
    }
}
if(ncount==1){
    cout<<"Successfully login"<<endl;

}else{
cout<<"Login Suspection"<<endl;
}
file.close();
}





int main(){
int c,s;
cout<<"Products are:\n1)Products \n2)Registration \n 3)Login"<<endl;
cin>>c;
switch(c){
case 1:
cout<<"Products are:\n1)Accessories"<<endl;
cin>>s;
buy:
switch(s){
case 1:
    accessories();

    goto buy;
    break;


default:
    cout<<"Error Pressing"<<endl;
    goto buy;
}
break;


case 2:
registration();
main();
break;

case 3:
    login();
    main();
    break;

default:
    cout<<"Error pressing"<<endl;
    main();
}
cout<<endl;

}
