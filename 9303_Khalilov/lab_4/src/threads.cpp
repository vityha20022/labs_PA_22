#include "./utils.cpp"
#include "./strassen.cpp"
#include <thread>
#include <ctime>
#include <math.h> /* pow */

using namespace std;

int main(int argc, const char **argv)
{
    srand(time(0));

    int power = 4, n = pow(2, power), m = pow(2, power);

    auto A = MATRIX::generate(n, m);
    auto B = MATRIX::generate(n, m);

    cout << "matrices size = " << n << "x" << m << "\n";

    clock_t timer = clock();

    MATRIX::Matrix<int> C1 = MATRIX::parallelSimpleMultiply(A, B);

    clock_t duration = clock() - timer;
    cout << "Simple Parallel Multiply:   ";
    cout << duration / (double)CLOCKS_PER_SEC << "s" << endl;

    MATRIX::Matrix<int> C2;

    timer = clock();

    STRASSEN::multiply(A, B, C2, n);

    cout << "\n"
         << A << "\n"
         << B << "\n"
         << C1 << "\n"
         << C2 << "\n";

    duration = clock() - timer;
    cout << "Strassen Parallel Multiply: ";
    cout << duration / (double)CLOCKS_PER_SEC << "s" << endl;

    return 0;
}


0 # 4 # 6 # 4 # 7 # 6 # 9 # 1 # 5 # 9 # 5 # 9 # 4 # 1 # 2 # 3 ##  
0 # 9 # 0 # 2 # 4 # 2 # 2 # 9 # 6 # 5 # 6 # 7 # 6 # 1 # 4 # 2 ##  
9 # 0 # 5 # 2 # 0 # 4 # 3 # 8 # 1 # 7 # 8 # 0 # 3 # 3 # 8 # 9 ##  
4 # 8 # 7 # 0 # 5 # 4 # 4 # 3 # 9 # 1 # 9 # 2 # 3 # 3 # 2 # 8 ##  
9 # 4 # 8 # 6 # 5 # 2 # 4 # 9 # 3 # 0 # 9 # 0 # 0 # 5 # 5 # 0 ##  
6 # 4 # 9 # 0 # 0 # 8 # 5 # 5 # 0 # 0 # 1 # 4 # 9 # 8 # 7 # 7 ##  
1 # 5 # 7 # 2 # 2 # 4 # 9 # 3 # 3 # 2 # 3 # 2 # 9 # 5 # 8 # 4 ##  
0 # 1 # 4 # 0 # 4 # 0 # 2 # 1 # 2 # 8 # 4 # 2 # 4 # 3 # 4 # 8 ##  
6 # 3 # 9 # 6 # 8 # 9 # 9 # 6 # 5 # 2 # 4 # 6 # 9 # 5 # 5 # 9 ##  
8 # 6 # 6 # 1 # 3 # 1 # 2 # 0 # 2 # 1 # 8 # 7 # 6 # 0 # 2 # 0 ##  
8 # 7 # 1 # 4 # 1 # 5 # 7 # 7 # 4 # 5 # 7 # 2 # 1 # 4 # 1 # 4 ##  
5 # 2 # 7 # 5 # 5 # 6 # 0 # 4 # 1 # 8 # 5 # 0 # 7 # 4 # 5 # 6 ##  
5 # 9 # 5 # 7 # 9 # 8 # 6 # 5 # 1 # 2 # 8 # 7 # 0 # 7 # 5 # 4 ##  
7 # 3 # 3 # 5 # 3 # 3 # 7 # 1 # 0 # 7 # 4 # 7 # 3 # 4 # 2 # 3 ##  
2 # 1 # 2 # 6 # 7 # 1 # 3 # 2 # 7 # 5 # 0 # 8 # 8 # 9 # 7 # 2 ##  
5 # 1 # 2 # 3 # 3 # 6 # 4 # 5 # 2 # 7 # 9 # 4 # 1 # 3 # 6 # 6 ## 


0 # 4 # 0 # 9 # 8 # 0 # 1 # 0 # 3 # 5 # 4 # 1 # 1 # 9 # 9 # 4 ## 
2 # 7 # 0 # 5 # 3 # 8 # 4 # 1 # 7 # 8 # 6 # 6 # 1 # 9 # 1 # 5 ## 
1 # 9 # 2 # 0 # 5 # 6 # 4 # 6 # 3 # 8 # 9 # 9 # 7 # 9 # 3 # 5 ## 
5 # 7 # 2 # 5 # 0 # 2 # 8 # 8 # 6 # 6 # 3 # 6 # 8 # 0 # 0 # 5 ## 
2 # 6 # 2 # 0 # 5 # 5 # 3 # 9 # 7 # 3 # 5 # 8 # 9 # 1 # 5 # 9 ## 
9 # 5 # 2 # 7 # 8 # 6 # 0 # 5 # 9 # 2 # 5 # 0 # 4 # 2 # 7 # 1 ## 
0 # 5 # 1 # 0 # 5 # 9 # 4 # 2 # 6 # 9 # 7 # 3 # 2 # 4 # 6 # 8 ## 
7 # 5 # 3 # 7 # 5 # 4 # 8 # 2 # 1 # 7 # 3 # 4 # 6 # 3 # 6 # 1 ## 
1 # 5 # 8 # 6 # 3 # 1 # 2 # 2 # 6 # 3 # 5 # 0 # 8 # 1 # 2 # 8 ## 
3 # 9 # 4 # 3 # 0 # 7 # 5 # 1 # 9 # 0 # 2 # 9 # 5 # 7 # 0 # 4 ## 
3 # 3 # 2 # 8 # 9 # 7 # 1 # 9 # 5 # 5 # 1 # 1 # 2 # 3 # 3 # 2 ## 
7 # 1 # 3 # 3 # 3 # 4 # 4 # 8 # 8 # 7 # 6 # 8 # 5 # 9 # 1 # 1 ## 
5 # 5 # 8 # 1 # 2 # 4 # 0 # 1 # 9 # 8 # 7 # 5 # 9 # 1 # 3 # 9 ## 
2 # 5 # 0 # 5 # 5 # 8 # 0 # 6 # 2 # 6 # 3 # 4 # 1 # 5 # 3 # 4 ## 
5 # 7 # 4 # 8 # 6 # 7 # 5 # 1 # 2 # 1 # 6 # 2 # 0 # 2 # 6 # 8 ## 
8 # 5 # 3 # 3 # 1 # 2 # 2 # 4 # 0 # 1 # 2 # 1 # 2 # 4 # 5 # 0