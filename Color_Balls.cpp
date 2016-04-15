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
        x=rand()%480+10;           //���ͤ@��10~489���ü�
        y=rand()%480+10;           //���ͤ@��10~489���ü�
        r=10 ;
        angle=rand()%360;
        vx=5*cos(angle*3.14/180);   //�ϼu��x���q
        vy=5*sin(angle*3.14/180);   //�ϼu��y���q
        color = rand()%15+1;
    }

    void move_object(int v){
        x= x + vx * v ;         //���ʫ᪺��m
        y= y + vy * v ;
        if(x>=489)
         {
            x = 489;                //�p�G�W�L��ثh=489
            vx=-vx;                 //�ϦV
            change_color();   //�ܴ��C��
         }

         else if(x<=0)
            {
            x=10;                   //�p�G�W�L��ثh=10
            vx=-vx;
            change_color ();
            }
                    if(y>=489)      //�p�G�W�L��ثh=489
                    {
                    y = 489;
                    vy=-vy;
                    change_color ();
                    }

                    else if(y<=0)
                        {
                        y=10;       //�p�G�W�L��ثh=10
                        vy=-vy;
                        change_color();
                        }
    }

    void draw_object(){
        setfillstyle(1,color);      //�񺡪�"�˦�"�H��"�C��"
        fillellipse(x,y,r,r);   //�Hx���_�I�V�~r�񺡡A�Hy���_�I�V�~r��
        circle(x, y, r);           //�Hxy����ߨå�r�e��
    }

    void change_color (){
        color = rand()%15+1;     //�o��index �N���D�O���@���y �����⨺�@�Ӱ}�C�ȥN�� �N�O���C��
    }
};

int number_circles = 0;
int main()
{
    cout << "�q���| 101323055 �����T\n" << endl;
    cout << "UP: Faster, Down: Slower, LEFT: Delete, RIGHT: Add \n" << endl;

    int t=50,i;
    char ch;
    int v = 1;
    /// If you want to creata object array, you can use pointer !!!
    Ball* balls[100];

    initwindow(600,600);    ///��l�Ƶ���

    int poly[8]={0,0,0,500,500,500,500,0};  ///�ŧi �@�ӥ���Τ��

    srand(time(NULL));

    while(1)
    {
        setfillstyle(0,15);     ///�]�w�񺡼˦����C��
        fillpoly(4,poly);       ///�e�����

        /// ���ʨõe�C���y
        for(i=0;i<number_circles;i++){
            balls[i]->move_object(v);
            balls[i]->draw_object();
        }
        delay(t);
        cleardevice();  ///�e����ӲM��

        if (kbhit()!=0){
            if ((ch=getch()) == 0){
                ch=getch();
                if (ch==72)     //�W(�[�t)
                    v++;
                if(ch==80)     //�U(��t)
                    if(v>1)
                        v--;
                if(ch==75)     //��(�֤@��)
                    if(number_circles > 0)
                        number_circles--;
                if(ch==77)     //�k(�h�@��
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
