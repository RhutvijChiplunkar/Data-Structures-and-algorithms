//============================================================================
// Name        : PALINDROME CHECK USING STACK.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
#include<stack>
#include<string>
using namespace std;


void isPalindrome(){
    //stack for pushing string elements
    stack<char> S1;

    //normal and reverse string
    string str,rev_str;

    cout<<"--------PALINDROME CHECK--------";
    cout<<"\nEnter a string::";
    cin>>str;
    int len=str.length();

    //push all characters in the stack
    for(int i=0;i<len;i++){
        S1.push(str[i]);
    }

    //the popped characters from stack are in reverse order of string
    while(!S1.empty()){
        rev_str+=S1.top();
        S1.pop();
    }

    //if both are equal then palindrome
    if(str==rev_str){
        cout<<"STRING IS A PALINDROME"<<endl;
    }
    else{
        cout<<"STRING IS NOT A PALINDROME"<<endl;
    }
    cout<<"--------------------------------"<<endl;
}
int main()
{
	isPalindrome();

	int opn=0;
	do{
		cout<<"Want to check more strings?"<<endl;
		cout<<"1)YES \n2)NO"<<endl;
		cout<<"Your choice::";
		cin>>opn;
	switch(opn){
	case 1:
		isPalindrome();
		break;
	case 2:
		cout<<"Thank You!!"<<endl;
		break;
	default:
		cout<<"Enter correct choice!"<<endl;
		break;
	}
	}while(opn!=2);
}
