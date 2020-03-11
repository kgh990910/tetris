#include "header/main.h"

Block::Block(){}
int temp=0;

int main(){

    Block blck;

    drw_title();

    drw_bsc_ary(basic_ary,22,12);

    srand(time(NULL));

    slct_blck(blck);


    unsigned long nw_time=0;
    unsigned long prv_time=clock();

    while(1){
        if(scn_ky(blck)==1){
            mv_blck(blck);
            print();
        }

        // mv_blck(blck);
        // print();
        // cout<<clock()<<endl;
        // system("clear");
        // cout<<linux_getch()<<endl;

    }

    

    // while(1){
    //     cout<<clock()<<endl;
    // }
    
    

    // while(1){
    //     if(linux_getch()==91){
    //         cout<<linux_getch()<<endl;
    //     }
    // }
    
    
    // for(int i=0;i<22;i++){
    //     for(int j=0;j<12;j++){
    //         if(basic_array[i][j]!=test_array[i][j]){
    //             gotoxy(j+3,i+4);
    //             cout<<test_array[i][j];
    //         }
    //     }
    // }
    // gotoxy(5,5);
    // cout<<"1";
    // while(1){}

    // int i,j;
    // for(i=0;i<4;i++){
    //     for(j=0;j<4;j++){
    //         cout<<test.block[0][i][j];
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // test.block_spin();
    // for(i=0;i<4;i++){
    //     for(j=0;j<4;j++){
    //         cout<<test.block[0][i][j];
    //     }
    //     cout<<endl;
    // }

    return 0;
}