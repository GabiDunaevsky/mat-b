/** 
 * Author: Gabriel Dunaevsky
 * Since : 2022-03
 */

#include "mat.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>
#include <string>


using namespace std;

int main(){
    cout << ariel::mat(9,7,'@','-') << endl;
    cout << ariel::mat(13,5,'@','-') << endl;
    cout << ariel::mat(33,19,'@','-') << endl;
    cout << ariel::mat(1,1,'%','$') << endl;
    cout << ariel::mat(9,3,'@','@') << endl;
    try
    {
        cout << ariel::mat(35,-3,'@','-') << endl;
    }
    catch(exception& e)
    {
        cout <<"caught exp :"  << e.what() << '\n' << endl;
    }


    cout << ariel::mat(1,9,'%','$') << endl;
    cout << ariel::mat(9,1,'%','$') << endl;


    try
    {
    cout << ariel::mat(9,3,'@','\n') << endl;
    }
    catch(exception& e)
    {
        cout <<"caught exp :"  << e.what() << '\n' << endl;
    }
    try
    {
    cout << ariel::mat(9,3,'@',2) << endl;
    }
    catch(exception& e)
    {
        cout <<"caught exp :"  << e.what() << '\n' << endl;
    }
    try{
    cout << ariel::mat(0,43,'@','-') << endl;
    }
    catch(exception& e)
    {
        cout <<"caught exp :"  << e.what() << '\n' << endl;
    }
    try{
    cout << ariel::mat(-2,43,'@','-') << endl;
    }
    catch(exception& e)
    {
        cout <<"caught exp :"  << e.what() << '\n' << endl;
    }
    try{
    cout << ariel::mat(13,4,'@','-') << endl;
    }
    catch(exception& e)
    {
        cout <<"caught exp :"  << e.what() << '\n' << endl;
    }

int param = 1;
int num = 1;
while( param == 1){
    string userAns = "";
    cout <<"Would you like to try your "  << num << " try (your answer sould be only yes or no): " << endl;
    cin >> userAns;
    if(userAns == "yes"){
        int rows;
        int columns;
        char firstOne;
        char secondOne;
        cout << "Please enter the columns Number:"<< endl;
        cin >> columns;
        cout << "Please enter the rows Number:"<< endl;
        cin >> rows;
        cout << "Please enter the first char:"<< endl;
        cin >> firstOne;
        cout << "Please enter the second char:"<< endl;
        cin >> secondOne;
        try{
    
            cout << ariel::mat(columns,rows,firstOne,secondOne) << endl;
        }
        catch(exception& e)
    {
        cout <<"caught exp :"  << e.what() << '\n' << endl;
    }
    num++;
    }else if(userAns == "no"){
        param = 0;
    }
    else{
        cout << "You Entered a wrong number please try again!";
    } 
 }
}