#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double nums[],int range,double result[] ){
    double sum =0;
    for(int i=0;i<range;i++) sum+=nums[i];
    
    double mean=sum/range;
    result[0]=mean;
    
    double a=0;
    for(int i=0;i<range;i++) a+=(nums[i]-mean)*(nums[i]-mean);
    
    double sd = sqrt(a/range);
    result[1]=sd;

    double b=1;
    for(int i=0;i<range;i++) b*=nums[i];

    double gm = pow(b,(1.0/range));
    result[2]=gm;

    double c=0;
    for(int i=0;i<range;i++) c+=(1.0/nums[i]);

    double hm = range/c;
    result[3]=hm;

    double min=nums[0],max=nums[0];
    
    for(int i=0;i<range;i++){ 
    if(nums[i]>max)max=nums[i];
    if(nums[i]<min)min=nums[i];
    }
    result[4]=max;
    result[5]=min;

}