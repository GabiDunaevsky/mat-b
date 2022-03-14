#include <string>
#include <vector>
using namespace std;

const short bLimit = 33; // Depends on the limit(check for part b)
const short hLimit = 126; // Depends on the limit(check for part b)

namespace ariel{
    string mat(int columns, int rows , char c , char d);
    vector<vector<char>> fillingCarpet(int columns , int rows , char a , char b);
    }