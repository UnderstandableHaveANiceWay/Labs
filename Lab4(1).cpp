#include <iostream>
#define tovCount 8
    struct Price{
        char Tovar[255];
        char Mag[255];
        float Stoim;
    };
using namespace std;
int main(int argc,char* argv[]){
    Price Spisok[tovCount];
    for(int i=0;i<tovCount;++i){
        cout<<"Введите название товара\n";
        cin>>Spisok[i].Tovar;
        cout<<"Введите название магазина\n";
        cin>>Spisok[i].Mag;
        cout<<"Введите цену товара\n";
        cin>>Spisok[i].Stoim;
    }
    char preSearchName[255];
    int count=-1;
    cout<<"Введите по буквам название магазина,товары которого вам нужны,в конце поставьте точку.\n";
    for(int i=0;i+1;++i){
        cin>>preSearchName[i];
        ++count;
        if(preSearchName[i]=='.')break;
    }
    char searchName[count];
    for(int i=0;i<count;++i){
        searchName[i]=preSearchName[i];
    }
    for(int i=0;i<tovCount;++i){
        Price SpisokIntermedeate;
        for(int j=0;j<=i;++j){
            int l=0;
            do{
                if(Spisok[i].Mag[l]<Spisok[j].Mag[l]){
                    SpisokIntermedeate=Spisok[i];
                    Spisok[i]=Spisok[j];
                    Spisok[j]=SpisokIntermedeate;
                }
                ++l;
            }while((Spisok[i].Mag[l]>=Spisok[j].Mag[l])&((int)Spisok[j].Mag[l]>65)&((int)Spisok[i].Mag[l]<122));
        }
    }
    int noMag=1;
    for(int i=0;i<tovCount;++i){
        int vivod=1;
        for(int j=0;j<count;++j){
            if(!(searchName[j]==Spisok[i].Mag[j])){
                vivod=0;
                break;
            }
        }   
        if(vivod){
            cout<<"Данные товара:\n";
            cout<<Spisok[i].Tovar<<"\n";
            cout<<Spisok[i].Mag<<"\n";
            cout<<Spisok[i].Stoim<<"\n\n";
            noMag=0;
        }
    }
    if(noMag)cout<<"Такого магазина нет\n";
    cout<<"\n\nВсе товары:\n";
    for(int i=0;i<tovCount;++i){
        cout<<"Данные товара:\n";
        cout<<Spisok[i].Tovar<<"\n";
        cout<<Spisok[i].Mag<<"\n";
        cout<<Spisok[i].Stoim<<"\n\n";
    }
    return 0;
}
