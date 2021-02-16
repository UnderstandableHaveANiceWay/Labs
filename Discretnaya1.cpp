#include <iostream>

void menu();
bool massInputList(int zv,int d,int**& mass);
bool massInputMassSmej(int zv,int d,int**& mass);
bool massInputMassInteden(int zv,int d,int**& mass);
int** intedInList(int zv,int d,int*** mass);
int** smInIntend(int zv,int d,int*** mass);
int** listInSm(int zv,int d,int*** mass);


int main(){
    bool isMassFull=false,fullList=false,fullMassSm=false,fullMassInted=false;
    int** A=nullptr;
    int*** ssilA=&A;
    int zvenia=0,dugi=0,choice=0;

    std::cout<<"Выберите один из пунктов меню\n";
    menu();

    while(1){

        do{
            std::cin>>choice;
            if(choice<1|choice>7){
                std::cout<<"Выбранного пункта меню нет, попробуйте ещё раз\n";
            }else if((choice==3||choice==4||choice==5)&&!isMassFull){
                std::cout<<"Сначала введите массив\n";
            }else if(choice==3&&fullMassInted){
                std::cout<<"И так введена матрица инцедентности\n";
            }else if(choice==4&&fullMassSm){
                std::cout<<"И так введён массив смежности\n";
            }else if(choice==5&&fullList){
                std::cout<<"И так введён список смежности\n";
            }else if(choice==6&&!isMassFull){
                std::cout<<"Нет матрицы,невозможно вывести\n";
            }else break;
        }while(1);

        if(choice==7)break;

        switch(choice){
            case 1: menu();
                    break;

            case 2: int ch;
                    std::cout<<"Что вы хотите ввести?\n\n1.Матрицу инцедентности\n2.Матрицу смежности\n3.Список смежности\n";
                    do{
                        std::cin>>ch;
                        if(ch>3||ch<1)std::cout<<"Такого пункта нет\n";
                    }while(ch>3||ch<1);

                    std::cout<<"Введите колличество звеньев: ";
                    std::cin>>zvenia;
                    std::cout<<"Введите колличество дуг: ";
                    std::cin>>dugi;

                    if(isMassFull){

                        fullMassInted=false;
                        fullMassSm=false;
                        fullList=false;
                        isMassFull=false;

                        for(int i=0;i<zvenia;++i)delete[] A[i];
                        delete[] A;
                    }

                    switch(ch){
                        case 1:massInputMassInteden(zvenia,dugi,A);
                                fullMassInted=true;
                                break;

                        case 2:massInputMassSmej(zvenia,dugi,A);
                                fullMassSm=true;     
                                break;

                        case 3:massInputList(zvenia,dugi,A);
                                fullList=true;
                                break;
                    }

                    isMassFull=true;
                    break;

            case 3: if(fullList){
                        A=listInSm(zvenia,dugi,ssilA);
                        A=smInIntend(zvenia,dugi,ssilA);
                        fullList=false;
                        fullMassInted=true;
                    }else if(fullMassSm){
                        A=smInIntend(zvenia,dugi,ssilA);
                        fullMassSm=false;
                        fullMassInted=true;
                    }

                    break;
            case 4: if(fullList){
                        A=listInSm(zvenia,dugi,ssilA);
                        fullList=false;
                        fullMassSm=true;
                    }else if(fullMassInted){
                        A=intedInList(zvenia,dugi,ssilA);
                        A=listInSm(zvenia,dugi,ssilA);
                        fullMassInted=false;
                        fullMassSm=true;
                    };

                    break;
            case 5: if(fullMassSm){
                        A=smInIntend(zvenia,dugi,ssilA);
                        A=intedInList(zvenia,dugi,ssilA);
                        fullMassSm=false;
                        fullList=true;
                    }else if(fullMassInted){
                        A=intedInList(zvenia,dugi,ssilA);
                        fullMassInted=false;
                        fullList=true;
                    }
                    break;

            case 6: if(fullList){
                        for(int i=0;i<zvenia;++i){
                            for(int j=0;j<=zvenia;++j){
                                std::cout<<A[i][j]<<" ";
                                if(A[i][j]==0)break;
                            }
                            std::cout<<"\n";
                        }
                    }else if(fullMassInted){
                            for(int i=0;i<dugi;++i){
                                for(int j=0;j<zvenia;++j){
                                    std::cout<<A[i][j]<<" ";
                                }
                            std::cout<<"\n";
                            }
                    }else if(fullMassSm){
                            for(int i=0;i<zvenia;++i){
                                for(int j=0;j<zvenia;++j){
                                    std::cout<<A[i][j]<<" ";
                                }
                            std::cout<<"\n";
                            }
                    }

                    break;
        }
    
    }

    for(int i=0;i<zvenia;++i)delete[] A[i];
    delete[] A;

    return 0;
}

void menu(){

    std::cout<<"1.Меню\n";
    std::cout<<"2.Ввести матрицу\n";
    std::cout<<"3.Переделать в матрицу инцедентности\n";
    std::cout<<"4.Переделать в матрицу смежности\n";
    std::cout<<"5.Переделать в список смежности\n";
    std::cout<<"6.Вывести на экран\n";
    std::cout<<"7.Закончить программу\n";

}

bool massInputList(int zv,int d,int**& mass){
    int colD=0;
    mass=new int*[zv];
    for(int i=0;i<zv;++i){

        mass[i]=new int[zv+1];
    }

    for(int i=0;i<zv;++i){
        for(int j=0;j<zv+1;++j){
            mass[i][j]=0;
        }
    }

    std::cout<<"Введите список\n";

    for(int i=0;i<zv;++i){
        std::cout<<i+1<<" звено\n";
        for(int j=0;j<zv+1;++j){
            
            do{

                std::cin>>mass[i][j];

                if(mass[i][j]>zv||mass[i][j]<0){

                    std::cout<<"Число не подходит для обработки, введите заново: \n";

                }
                
            }while(mass[i][j]>zv||mass[i][j]<0);
            if(mass[i][j]==0){

                break;

            }
            ++colD;
            if(colD>=d)break;
        }
        if(colD>=d)break;
    }

    std::cout<<"Список успешно введён\n";

    return true;

}

bool massInputMassSmej(int zv,int d,int**& mass){
    int colD=0;
    mass=new int*[zv];
    for(int i=0;i<zv;++i){

        mass[i]=new int[zv];
    }

    for(int i=0;i<zv;++i){
        for(int j=0;j<zv;++j){
            mass[i][j]=0;
        }
    }

    std::cout<<"Введите матрицу\n";

    for(int i=0;i<zv;++i){
        std::cout<<i+1<<" звено\n";
        for(int j=0;j<zv;++j){
            
            do{

                std::cin>>mass[i][j];

                if(mass[i][j]>2||mass[i][j]<0){

                    std::cout<<"Число не подходит для обработки, введите заново: \n";

                }
                
            }while(mass[i][j]>2||mass[i][j]<0);
            if(mass[i][j]==1)++colD;
            if(colD>=d)break;
        }
        if(colD>=d)break;
    }
    
    std::cout<<"Матрица успешно введена\n";

    return true;

}

bool massInputMassInteden(int zv,int d,int**& mass){
    mass=new int*[d];
    for(int i=0;i<d;++i){

        mass[i]=new int[zv];
    }

    for(int i=0;i<d;++i){
        for(int j=0;j<zv;++j){
            mass[i][j]=0;
        }
    }

    std::cout<<"Введите матрицу\n";

    for(int i=0;i<d;++i){
        std::cout<<i+1<<" дуга\n";
        for(int j=0;j<zv;++j){
            
            do{

                std::cin>>mass[i][j];

                for(int z=0;z<j;++z){
                    if((mass[i][j]==2||mass[i][j]==-1)&&(mass[i][z]==2||mass[i][z]==-1)){
                        if(mass[i][j]==2)std::cout<<"У дуги уже есть и начало и конец\n";
                        if(mass[i][j]==-1)std::cout<<"У этой дуги уже есть начало\n";
                        mass[i][j]=999999;
                        break;
                    }
                    if((mass[i][j]==2||mass[i][j]==1)&&(mass[i][z]==2||mass[i][z]==1)){
                        if(mass[i][j]==2)std::cout<<"У дуги уже есть и начало и конец\n";
                        if(mass[i][j]==1)std::cout<<"У этой дуги уже есть конец\n";
                        mass[i][j]=999999;
                        break;
                    }
                }

                if((mass[i][j]>2||mass[i][j]<-1)&&mass[i][j]!=999999){

                    std::cout<<"Число не подходит для обработки, введите заново: \n";

                }
                
            }while(mass[i][j]>2||mass[i][j]<-1);

        }
    }

    std::cout<<"Матрица успешно введена\n";

    return true;

}

int** intedInList(int zv,int d,int*** mass){

    int** massIn=*mass;

    int** B=new int*[zv];
    for(int i=0;i<zv;++i){

        B[i]=new int[zv+1];
    }
    int** start=B;

    for(int i=0;i<zv;++i){
        for(int j=0;j<zv+1;++j){
            B[i][j]=0;
        }
    }
    
    for(int i=0;i<d;++i){
        int pos=0;
        int start=-9999,end=-9999;
        for(int j=0;j<zv;++j){
            if(massIn[i][j]==0)continue;
            else if(massIn[i][j]==-1)start=j;
            else if(massIn[i][j]==1)end=j;
            else if(massIn[i][j]==2){
                start=end=j;
                break;
            }
        }
        while(start!=-9999&&end!=-9999){
            if(B[start][pos]<=zv&&B[start][pos]>=1){
                ++pos;

                continue;
            }
            B[start][pos]=end+1;
            break;
        }
    }
    for(int i=0;i<zv;++i){
        int intermidiate;
        for(int j=0;j<zv;++j){
            intermidiate=B[i][j];
            for(int l=0;l<zv;++l){
                if(intermidiate==B[i][l]&&j!=l){
                    B[i][l]=0;
                }
            }
        }for(int j=0;j<zv;++j){
            for(int l=0;l<zv;++l){
                if(B[i][j]>B[i][l]&&j!=l){
                    intermidiate=B[i][l];
                    B[i][l]=B[i][j];
                    B[i][j]=intermidiate;
                }
            }
        }for(int j=0;j<zv;++j){
            for(int l=0;l<zv;++l){
                if(B[i][j]==0||B[i][l]==0)break;
                if(B[i][j]<B[i][l]&&j!=l){
                    intermidiate=B[i][l];
                    B[i][l]=B[i][j];
                    B[i][j]=intermidiate;
                }
            }
        }
    }


    for(int i=0;i<zv;++i)delete[] massIn[i];

    delete[] *mass;

    return start;
}

int** smInIntend(int zv,int d,int*** mass){

    int** massIn=*mass;

    int** B=new int*[d];
    for(int i=0;i<d;++i){

        B[i]=new int[zv];
    }
    int** start=B;

    for(int i=0;i<d;++i){
        for(int j=0;j<zv;++j){
            B[i][j]=0;
        }
    }
    int lsda=0;

    for(int i=0;i<zv;++i){
        for(int j=0;j<zv;++j){
            if(massIn[i][j]==2){

                B[lsda++][i]=2;
                continue;

            }
            if(massIn[i][j]==1){

                B[lsda][i]=-1;

                B[lsda++][j]=1;
                
            }
            if(lsda>=d)break;
        }
        if(lsda>=d)break;
    }


    for(int i=0;i<zv;++i)delete[] massIn[i];

    delete[] *mass;

    return start;
}

int** listInSm(int zv,int d,int*** mass){

    int** massIn=*mass;

    int** B=new int*[zv];
    for(int i=0;i<zv;++i){

        B[i]=new int[zv];
    }

    for(int i=0;i<zv;++i){
        for(int j=0;j<zv;++j){
            B[i][j]=0;
        }
    }
    int** start=B;

    for(int i=0;i<zv;++i){
        for(int j=0;j<zv;++j){
            if(massIn[i][j]==0)break;
            if(i==massIn[i][j]-1){
                
                B[i][massIn[i][j]-1]=2;
            
            }else B[i][massIn[i][j]-1]=1;
        }
    }


    for(int i=0;i<zv;++i)delete[] massIn[i];

    delete[] *mass;
    
    return start;
}
