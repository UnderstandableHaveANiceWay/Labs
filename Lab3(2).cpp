#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
    int n,m;

    cout<<"Введите колличество строк:";

    cin>>n;

    cout<<"Введите колличество столбцов:";

    cin>>m;

    int A[n][m],B[n][m];

    cout<<"Введите массив\n";

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
           cin>>A[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
           cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int k=0,a=0,b=0,c=0,d=0;
            if((i-1<n)&(i-1>=0)){
                a=A[i-1][j];
                ++k;
            }
            if(i+1<n){
                b=A[i+1][j];
                ++k;
            }
            if((j-1<n)&(j-1>=0)){
                c=A[i][j-1];
                ++k;
            }
            if(j+1<m){
                d=A[i][j+1];
                ++k;
            }
            B[i][j]=(a+b+c+d)/k;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
           cout<<B[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
