#include <iostream>
using namespace std;
int main(){

    int n;

    cout<<"Введите размер массива:";

    cin>>n;

    float A[n],prois=1,max=-99999999;

    int maxI=0;

    cout<<"Введите массив\n";

    for(int i=0;i<n;++i){

        cin>>A[i];

        if(A[i]<0){
            prois*=A[i];
        }
        if(A[i]>max){

            max=A[i];

            maxI=i;

        }
    }
    cout<<"Произведение отрицательных элементов массива:"<<prois<<"\n";

    float sum=0;

    for(int i=0;i<maxI;++i){

        if(A[i]>0){

            sum+=A[i];

        }
    }
    cout<<"Сумма положительных чисел до максимального элемента:"<<sum<<"\n";

    for(int i=0;i<(n/2);++i){

        float intermediateValue=A[i];

        A[i]=A[n-(i+1)];

        A[n-(i+1)]=intermediateValue;

    }
    cout<<"Модифицированный массив:\n";

    for(int i=0;i<n;++i)cout<<A[i]<<"\t";

    return 0;
}
