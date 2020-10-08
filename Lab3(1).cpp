#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
    int n,m;

    cout<<"Введите размер квадратной матрицы:\n";

    do{
        cin>>n>>m;

        if(n!=m)cout<<"Колличество строк и столбцов должны быть равны друг другу,чтобы матрица была квадратной,введите данные ещё раз:\n";

    }while(n!=m);

    float A[n][m];

    cout<<"Введите массив:\n";

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)cin>>A[i][j];
    }

    for(int i=0;i<n;++i){
        float sum=0;

        int k=0;

        for(int j=0;j<m;++j){
            if(A[i][j]<0){
                k=1;

                break;
            }
            sum+=A[i][j];
        }
        if(!k)cout<<"Сумма в элементов в "<<(i+1)<<" строке:"<<sum<<"\n";
    }
    float minSum=99999999;

    for(int i=0;i<n-2;++i){
        float sum=0;

        for(int j=0;j<m-i-1;++j){

            sum+=A[j+i+1][j];

        }
        if(minSum>sum)minSum=sum;

        int k=0;

        for(int j=1+i;j<m;++j){

            sum+=A[k++][j];

        }
        if(minSum>sum)minSum=sum;
    }
        cout<<"Минимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы:"<<minSum<<"\n";

    return 0;
}
