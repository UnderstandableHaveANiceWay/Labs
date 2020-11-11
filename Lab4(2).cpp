#include <ctime>
#include <iostream>
using namespace std;
void Menu();
bool massMemo(int**& array,const int N,const int M);
bool massInputKeyboard(int**& array,int N,int M);
bool massInputRand(int**& array,int N,int M);
void massOutput(int**& array,int N,int M);
void massSort(int**& array,int N,int M);
void massDelete(int**& array,const int N);
int main(){
    int choice;
    int** A = nullptr;
    int N,M;
    bool isMemo=false,isMassFull=false;
    do{
        Menu();
        do{
            cin>>choice;
            if(choice<1|choice>7){
                cout<<"Выбранного пункта меню нет, попробуйте ещё раз\n";
            }else if(choice==1&isMemo){
                cout<<"Память уже выделена\n";
            }else if((choice==2|choice==3)&isMassFull){
                cout<<"Массив уже заполнен\n";
            }else if((choice==2|choice==3)&!isMemo){
                cout<<"Память не была выделена,не куда вставлять значения\n";
            }else if(choice==4&!isMassFull){
                cout<<"Невозможно отсортировать,заполните массив\n";
            }else if(choice==5&!isMassFull){
                cout<<"Перед тем как выводить массив на экран,заполните его\n";
            }else if(choice==6&!isMemo){
                cout<<"Память не выделена, или уже была освобождена\n";
            }else break;
        }while(1);
        switch(choice){
            case 1:
                cout<<"Введите размер массива:\n";
                cin>>N>>M;
                while(N<0|M<0){
                    cout<<"Массив с такими размерами не может быть создан,попробуйте заново\n";
                    cin>>N>>M;
                }
                A=new int* [N];
                isMemo=massMemo(A,N,M);
            break;
            case 2:
                isMassFull=massInputKeyboard(A,N,M);
            break;
            case 3:
                isMassFull=massInputRand(A,N,M);
            break;
            case 4:
                massSort(A,N,M);
            break;
            case 5:
                massOutput(A,N,M);
            break;
            case 6:
                massDelete(A,N);
                isMemo=false;
                isMassFull=false;
            break;
        }
    }while(choice!=7);
    if(isMemo){
        massDelete(A,N);
    }
    return 0;
}
void Menu(){
    cout<<"Выберите один из пунктов меню\n\n";
    cout<<"1.Динамическое выделение памяти для Массива\n";
    cout<<"2.Ввод элементов массива с клавиатуры\n";
    cout<<"3.Заполнение массива случайными числами\n";
    cout<<"4.Сортировка элементов массива линейным методом\n";
    cout<<"5.Вывод элементов массива на экран\n";
    cout<<"6.Освобождение памяти, выделенной для массива\n";
    cout<<"7.Окончание работы программы\n";
};
bool massMemo(int**& array,const int N,const int M){
    for(int i=0;i<N;++i){
        array[i]=new int[M];
    }
    return true;
};
bool massInputKeyboard(int**& array,const int N,const int M){
    cout<<"Введите массив:\n";
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>array[i][j];
        }
    }
    cout<<"Массив введён\n";
    return true;
};
bool massInputRand(int**& array,const int N,const int M){
    srand(time(NULL));
    cout<<"Укажите диапазон случайных чисел\nот ";
    int  bR,eR;
    cin>>bR;
    cout<<"до ";
    cin>>eR;
    while(bR>eR){
        cout<<"Начало диапазона меньше конца диапазона,хотите поменять их местами или ввести заново диапазон?\n";
        cout<<"1.Поменять местами\n";
        cout<<"2.Ввести диапазон занового\n";
        int ch;
        cin>>ch;
        while(ch!=1&ch!=2){
            cout<<"Нет такого пункта,выберите ещё раз\n";
            cin>>ch;
        }
        if(ch==1){
            int intermediateValue=bR;
            bR=eR;
            eR=intermediateValue;
        }else if(ch==2){
            cout<<"от\n";
            cin>>bR;
            cout<<"до\n";
            cin>>eR;
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            array[i][j]=bR+rand()%(eR-bR+1);
        }
    }
    return true;
};
void massOutput(int**& array,const int N,const int M){
    for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                cout<<array[i][j]<<"\t";
        }
        cout<<"\n";
    }
};
void massSort(int**& array,const int N,const int M){
    int k=1,d=0,B[N*M];
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            B[d++]=array[i][j];
        }
    }
    while(k!=0){
        k=0;
        int intermediateValue;
        for(int i=0;i+1<N*M;++i){
            if(B[i]>B[i+1]){
                intermediateValue=B[i];
                B[i]=B[i+1];
                B[i+1]=intermediateValue;
                k=1;
            }
        }
    }
    d=0;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            array[i][j]=B[d++];
        }
    }
};
void massDelete(int**& array,const int N){
    for(int i=0;i<N;++i){
        delete[] array[i];
    }
    delete[] array;
};
