#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "mat.hpp"


using namespace std;
using namespace ariel;

bool checkInputFunc(int columns , int rows,char a , char b){
    if(rows <= 0 || columns <= 0 ){ return false;}
    if(rows % 2 == 0 || columns % 2 == 0 ){ return false;}
    if(a > hLimit || a < bLimit || b > hLimit || b < bLimit ){ return false;} // Depends on the limit(check for part b)
    return true;
}

namespace ariel{

     vector<vector<char>> fillingCarpet(int columns , int rows , char a , char b){
        int columnFromEnd = columns - 1;
        int columnFromBeg = 0;
        int rowFromEnd = rows - 1;
        int rowFromBeg = 0;

       
        vector<vector<char>> matrix(rows, vector<char> (columns, 0)); // initiating the matrix.
        while(columnFromEnd >= columnFromBeg && rowFromEnd >= rowFromBeg){// update the stop point before filling the matrix.
               for(int h = columnFromBeg; h <= columnFromEnd ;h++){// starting to fill the columns , doing it by for loop. 
                   if (columnFromEnd % 2 == 0 && columnFromBeg % 2 == 0) // Even bigger than 0.
                   {
                       matrix[rowFromEnd][h] = a;
                       matrix[rowFromBeg][h] = a;
                   }else{                                                // if the columns are odd so filling them with the second char.
                       matrix[rowFromEnd][h] = b;
                       matrix[rowFromBeg][h] = b;
                   }
              }

            /*
            Note: we need the separetion because the matrix is not necessarily squrt.
            */
               for (int i = rowFromBeg; i <= rowFromEnd; i++) // starting to fill the rows , doing it by for loop.
               {
                   if (rowFromEnd % 2 == 0 && rowFromBeg % 2 == 0) // Even bigger than 0.
                   {
                     matrix[i][columnFromEnd] = a;
                     matrix[i][columnFromBeg] = a;
                   } else{
                       matrix[i][columnFromEnd] = b;
                       matrix[i][columnFromBeg] = b;
                   } 
               }
                columnFromEnd--;
                columnFromBeg++;
                rowFromEnd--;
                rowFromBeg++;
        }
        return matrix;
    }
        
    string mat(int columns , int rows , char c , char d){
        if(!(checkInputFunc(columns , rows , c, d))){
            throw invalid_argument("Mat size is always odd"); // checkink the limits on the ,matrix if return false so throwing an error.
        }
        vector<vector<char>> carpetMat;
        carpetMat = fillingCarpet(columns , rows ,c,d); // getting the matrix by the helper func.
        string carpet ;
        for (int i = 0; i < rows; i++) // creating a string from the matrix by for loop.
        {
            for (int j = 0; j < columns; j++)
            {
                carpet += carpetMat[i][j];
            }
            carpet += "\n"; 
        }
        return carpet;
    }

}




/*
Just main for Testing , Ignore!!!!!!
*/
// int main(){
//     cout << ariel::mat(9,7,'@','-') << endl;
//     cout << ariel::mat(13,5,'@','-') << endl;
//     cout << ariel::mat(33,19,'@','-') << endl;
//     cout << ariel::mat(1,1,'%','$') << endl;
//     cout << ariel::mat(9,3,'@','@') << endl;
//     try
//     {
//         cout << ariel::mat(35,-3,'@','-') << endl;$(CXX) $(CXXFLAGS) --compile $< -o $@
//     }
//     catch(exception& e)
//     {
//         cout <<"caught exp :"  << e.what() << '\n' << endl;
//     }


//     cout << ariel::mat(1,9,'%','$') << endl;
//     cout << ariel::mat(9,1,'%','$') << endl;


//     try
//     {
//     cout << ariel::mat(9,3,'@','\n') << endl;
//     }
//     catch(exception& e)
//     {
//         cout <<"caught exp :"  << e.what() << '\n' << endl;
//     }
//     try
//     {
//     cout << ariel::mat(9,3,'@',2) << endl;
//     }
//     catch(exception& e)
//     {
//         cout <<"caught exp :"  << e.what() << '\n' << endl;
//     }
//     try{
//     cout << ariel::mat(0,43,'@','-') << endl;
//     }
//     catch(exception& e)
//     {
//         cout <<"caught exp :"  << e.what() << '\n' << endl;
//     }
//     try{
//     cout << ariel::mat(-2,43,'@','-') << endl;
//     }
//     catch(exception& e)
//     {
//         cout <<"caught exp :"  << e.what() << '\n' << endl;
//     }
//     try{
//     cout << ariel::mat(13,4,'@','-') << endl;
//     }
//     catch(exception& e)
//     {
//         cout <<"caught exp :"  << e.what() << '\n' << endl;
//     }

// int param = 1;
// int num = 1;
// while( param == 1){
//     string userAns = "";
//     cout <<"Would you like to try your "  << num << " try (your answer sould be only yes or no)" << endl;
//     cin >> userAns;
//     if(userAns == "yes"){
//         int rows;
//         int columns;
//         char firstOne;
//         char secondOne;
//         cout << "Please enter the columns Number:"<< endl;
//         cin >> columns;
//         cout << "Please enter the rows Number:"<< endl;
//         cin >> rows;
//         cout << "Please enter the first char:"<< endl;
//         cin >> firstOne;
//         cout << "Please enter the second char:"<< endl;
//         cin >> secondOne;
//         try{
    
//             cout << ariel::mat(columns,rows,firstOne,secondOne) << endl;
//         }
//         catch(exception& e)
//     {
//         cout <<"caught exp :"  << e.what() << '\n' << endl;
//     }
//     num++;
//     }else if(userAns == "no"){
//         param = 0;
//     }
//     else{
//         cout << "You Entered a wrong number please try again!";
//     } 
//  }
// }