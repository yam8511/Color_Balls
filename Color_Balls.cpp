#include <iostream>
#include <graphics.h>
#include <time.h>
#include <math.h>

using namespace std;


class Ball{
private:
    int x;
    int y;
    int r;
    int vx;
    int vy;
    int angle;
    int color;
public:
    Ball(){
        x=rand()%480+10;           //產生一個10~489的亂數
        y=rand()%480+10;           //產生一個10~489的亂數
        r=10 ;
        angle=rand()%360;
        vx=5*cos(angle*3.14/180);   //反彈的x分量
        vy=5*sin(angle*3.14/180);   //反彈的y分量
        color = rand()%15+1;
    }

    void move_object(int v){
        x= x + vx * v ;         //移動後的位置
        y= y + vy * v ;
        if(x>=489)
         {
            x = 489;                //如果超過邊框則=489
            vx=-vx;                 //反向
            change_color();   //變換顏色
         }

         else if(x<=0)
            {
            x=10;                   //如果超過邊框則=10
            vx=-vx;
            change_color ();
            }
                    if(y>=489)      //如果超過邊框則=489
                    {
                    y = 489;
                    vy=-vy;
                    change_color ();
                    }

                    else if(y<=0)
                        {
                        y=10;       //如果超過邊框則=10
                        vy=-vy;
                        change_color();
                        }
    }

    void draw_object(){
        setfillstyle(1,color);      //填滿的"樣式"以及"顏色"
        fillellipse(x,y,r,r);   //以x為起點向外r填滿，以y為起點向外r填滿
        circle(x, y, r);           //以xy為圓心並用r畫圓
    }

    void change_color (){
        color = rand()%15+1;     //得到index 就知道是哪一顆球 直接把那一個陣列值代換 就是換顏色
    }
};

int number_circles = 0;
int main()
{
    cout << "電機四 101323055 李明俊\n" << endl;
    cout << "UP: Faster, Down: Slower, LEFT: Delete, RIGHT: Add \n" << endl;

    int t=50,i;
    char ch;
    int v = 1;
    /// If you want to creata object array, you can use pointer !!!
    Ball* balls[100];

    initwindow(600,600);    ///初始化視窗

    int poly[8]={0,0,0,500,500,500,500,0};  ///宣告 一個正方形方框

    srand(time(NULL));

    while(1)
    {
        setfillstyle(0,15);     ///設定填滿樣式及顏色
        fillpoly(4,poly);       ///畫正方形

        /// 移動並畫每顆球
        for(i=0;i<number_circles;i++){
            balls[i]->move_object(v);
            balls[i]->draw_object();
        }
        delay(t);
        cleardevice();  ///畫面整個清掉

        if (kbhit()!=0){
            if ((ch=getch()) == 0){
                ch=getch();
                if (ch==72)     //上(加速)
                    v++;
                if(ch==80)     //下(減速)
                    if(v>1)
                        v--;
                if(ch==75)     //左(少一顆)
                    if(number_circles > 0)
                        number_circles--;
                if(ch==77)     //右(多一顆
                    if(number_circles < 100 ){
                        balls[number_circles] = new Ball();
                        number_circles++;
                    }
            }
            if (ch==27)          //Ese
                break;
        }
    }

    return 0;
}
