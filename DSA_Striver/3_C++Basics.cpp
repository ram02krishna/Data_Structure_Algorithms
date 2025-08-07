// Note: It will not work if your default terminal is Powershell. Make it "cmd" then it will work.To change default terminal : Hit clt+shift+p->write:default terminal->change it to cmd.
// ctrl+shift+B -> to run the inputs

#include <bits/stdc++.h>
using namespace std;

// Functions are assigned outside the int main

void printName()
{
    cout<<"hey Striver!"<<endl;
}

void printName(string name)
{
    cout<<"hey"<<" "<<name<<endl;
}

void sum(int num1,int num2)
{
    int num3 = num1+num2;
    cout<<num3<<endl;
}

int Add(int num1,int num2)
{
    int num3 = num1+num2;
    cout<<num3<<endl;
    return num3; // here return will work because we have used int instead of void as a data type.
    // return means that it will store the result.
}

  // Pass by value 
    void dosomething(int num)
    {
        cout<<num<<endl;
        num += 5;
        cout<<num<<endl;
        num += 5;
        cout<<num<<endl;
    }

  // Pass by reference 
    void dosomething(string &s)
    {
        s[0] = 't';
        cout<< s<<endl;
    }

int main()
{
    // int, long, long long, float, double, char
    // string and getline
    /*
    string s;
    cin>>s;
    cout<<s;
    */
    // we have taken input hey striver.On running the code  we will get hey only as a output.the basckspace between two words will be consider as two different strings so to uget both of them in the output need to assign different strings s1 and s2.
    // here is the solution for the above problem
    /*
    string str;
    getline(cin, str); //this getline will take the entire line as input.Nxt line will not be picked by it
    cout<<str;
    */

    //if else 
    // switch 
    // arrays -> The indexes of the array will be stored consecutively one after the other in the memory once the first index of the array is stored anywhere in the memory
    
    /*
    // 2D array 
    int arr[4][5]; //arr[rows][columns]
    arr[2][3] = 45;
    cout<<arr[2][3]<<endl;
    cout<<arr[1][4]<<endl<<arr[3][5];
    */
    //as no value is assigned to these indexes so this will print garbage values.
    
    /*
    string s = "Striver";
    cout<<s[0]<<" "<<s[1]<<" "<<s[4]<<endl; //so basically string can be used as array of characters starting from index 0 to the string_length-1
    int len = s.size();
    s[len-1] = 'z';
    cout<<s[len-1]<<endl;
    */
    
    // for loop
    // while and do while
    // Functions (Pass by refernce and pass by value)
    // Functions are set of code which performs for you
    // Functions are used to modularise code
    // Functions are use to increase readability
    // Functions are used to use same code multiple times
    // void 
    // return 
    // parameterised
    // non parameterised

    printName();

    string name;
    cin>>name;
    printName(name);

    sum(45,36);
    Add(12,15);
    
    // Pass by value
    int num = 10;
    dosomething(num);
    cout<<num<<endl;

    // when u call function and u pass value that is number then it's copy goes,not the original number.
    // that's why after calling the function wen we tried to cout<<num; then the output is 10 not 20.

    // Pass by reference
    string s = "Raj";
    dosomething(s);
    cout<< s <<endl;
    // in this it takes the address of the original.actually it deals with the original data with the help of address.

    return 0;
}
