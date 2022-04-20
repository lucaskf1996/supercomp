#include <omp.h>
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
// #include 
#pragma omp construct [params]

int main(){
    std::time_t start, end;
    int n = 1000000000;
    float result = 0;
    double time_taken;
    time(&start);
    for (int i = 0; i < n; i++){
        result += pow(-1.0, i)/(2.0*i+1.0);
    }
    time(&end);
    result *= 4;
    time_taken = double(end - start);
    std::cout << "resultado: " << result << std::endl << "tempo: " << time_taken << std::endl;

    result = 0;
    time(&start);
    #pragma omp parallel for reduction(+:result)
    for (int i = 0; i < n; i++){
        result += pow(-1.0, i)/(2.0*i+1.0);
    }
    time(&end);
    result *= 4;
    // {
    // }
    time_taken = double(end - start);
    std::cout << "resultado: " << result << std::endl << "tempo: " << time_taken << std::endl;
    return 1;
}
