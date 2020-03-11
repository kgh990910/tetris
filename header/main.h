#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include "linux.h"
#include "class.h"

using namespace std;

//방향키 91
#define LEFT 68
#define RIGHT 67
#define UP 65
#define DOWN 66
#define SPACE 32
#define p 112
#define ESC 27

int basic_ary[22][12]={
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,2,2,2,2,2,2,2,2,2,2,2}
};

int buf_ary[22][12]={
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,2},
    {2,2,2,2,2,2,2,2,2,2,2,2}
};

void slct_blck(Block& block){

    int blckshp;

    blckshp=rand()%7;
    int i,j;
    for(i=0;i<4;i++){
        gotoxy(5,3+i);
        for(j=0;j<4;j++){
            if(block.block[blckshp][i][j]==0){
                cout<<" ";
            }
            else{
                cout<<"◼︎";
            }
            block.buf_blck[i][j]=block.block[blckshp][i][j];
        }
    }
    // gotoxy(1,1);    
}

void drw_title(){

    cout<<endl<<endl;
    cout<<"  □□□□□□□□□□□□□□□□□□□□"<<endl;
    cout<<"  □□□□   Tetris   □□□□"<<endl;
    cout<<"  □□□□□□□□□□□□□□□□□□□□"<<endl<<endl;
    cout<<"  Please Entet Any Key To Start..."<<endl<<endl;
    cout<<"    △   : Shift"<<endl;
    cout<<"  ◁   ▷ : Left / Right"<<endl;
    cout<<"    ▽   : Soft Drop"<<endl;
    cout<<"  Space : Hard Drop"<<endl;
    cout<<"     P  : Pause"<<endl;
    cout<<"    ESC : Quit"<<endl;

    while(!linux_kbhit()){}
    system("clear");
}

void drw_bsc_ary(int (*ary)[12],int row,int col){

    cout<<"  ##NEXT##"<<endl;
    cout<<"  #      #"<<endl;
    cout<<"  #      #"<<endl;
    cout<<"  #      #"<<endl;
    cout<<"  #      #"<<endl;
    cout<<"  #      #"<<endl;
    cout<<"  #      #"<<endl;
    cout<<"  ########"<<endl<<endl<<endl;

    int i,j;
    for(i=0;i<row;i++){
        cout<<"  ";
        for(j=0;j<col;j++){
            if(ary[i][j]==2){
                cout<<"☒";
            }
            else if(ary[i][j]==0){
                cout<<" ";
            }
            else{
                cout<<"◼︎";
            }
        }
        cout<<endl;
    }
}

void mv_blck(Block& block){
    for(int i=0;i<21;i++){
        for(int j=1;j<11;j++){
            buf_ary[i][j]=0;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            buf_ary[block.y+i][block.x+j]=block.buf_blck[i][j];
        }
    }
    
}

void print(){
    for(int i=0;i<25;i++){
        for(int j=0;j<12;j++){
            if(basic_ary[i][j]!=buf_ary[i][j]){
                gotoxy(j+3,i+12);
                if(buf_ary[i][j]==1){
                    cout<<"◼︎";
                }
                else{
                    cout<<" ";
                }
                basic_ary[i][j]=buf_ary[i][j];
            }
        }
    }
    gotoxy(1,1);
    // system("clear");
    // for(int i=0;i<22;i++){
    //     for(int j=0;j<12;j++){
    //         cout<<buf_ary[i][j];
    //     }
    //     cout<<endl;
    // }

}

int scn_ky(Block& block){
    // if(linux_kbhit()){
    // if(linux_getch()==91){
        int i=linux_getch();
        
        if(i==67){
            block.x++;
            // cout<<"1"<<endl;
            return 1;
        }
        if(i==68){
            block.x--;
            // cout<<"2"<<endl;
            return 1;
        }
        if(i==65){
            block.block_spin();
            // cout<<"spin"<<endl;
            return 1;
        }
        if(i==66){
            block.y++;
            // cout<<"3"<<endl;
            return 1;
        }
        // system("clear");
        
        // return 1;
    // }
    if(i==32){
        //내리는 함수
        return 1;
    }
    if(i==27){
        //종료함수
        return 1;
    }
    if(i==112){
        //정지함수
        return 1;
    }

    
    // }
    return 0;
}

#endif