#include <iostream>
using namespace std;
#define wordCount 12
#define wordSize 40
int main(){

    char sentence[wordCount][wordSize]={};

    cout<<"Введите предложение:\n";

    for(int i=0;i<wordCount;++i){

        cin>>sentence[i];

    }

    for(int i=0;i<wordCount;++i){

        int isDuplicate=0;

        for(int j=0;j<wordCount;++j){

            int duplicateWord=1;

            if(i==j){
                continue;
            }

            int l=0;

            while((sentence[i][l]!='\0')|(sentence[j][l]!='\0')){

                if(sentence[i][l]!=sentence[j][l]){

                    duplicateWord=0;

                    break;

                }

                ++l;

            }

            if(duplicateWord){

                for(int l=0;l<wordSize;++l){

                    sentence[j][l]='\0';

                    isDuplicate=1;

                }

            }

        }

        if(isDuplicate){

            for(int l=0;l<wordSize;++l){

                sentence[i][l]='\0';

            }

        }

    }

    cout<<"\n";

        for(int i=0;i<wordCount;++i){

        cout<<sentence[i];

        if(sentence[i][0]!='\0'){

            cout<<" ";

        }

    }

    return 0;
}
