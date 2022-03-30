#include<bits/stdc++.h>
int main()
{
    std::time_t start, end;
  
    time(&start);
    time(&end);
  
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    std::cout << "Time taken by program is : " << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;
    return 0;
}