#include<windows.h>
#include<iostream>
#include<time.h>
#include<conio.h>
using namespace std;
void SetCapsLock(bool chk);
void SetNumLock(bool chk);
void SetScrollLock(bool chk);
void run1(void);//random
void run2(void);//run
void run3(void);//GAME
void star(void);

int main()
{
    system("color 0A");//set color
    char opt;//��� 
    int chk=GetKeyState('Y');//����
    int chk2=chk;

    
    do
    {
    SetNumLock(0);//�k�s(turn off the light)
    SetCapsLock(0);
    SetScrollLock(0);
    system("cls");
    cout<<"~~~~~~~~~~~~~~~~\n"
        <<" �п�ܼҦ��G\n\t(1)�H���{�{\n\t(2)���k�]��\n\t(3)�����{�{\n\t(4)����t�פp�C��"
        <<"\n\n\t(q)����\n:";
    
    cin>>opt;
    
    switch(opt)
    {
    case '1'://�H���{�{
         cout<<"�H���{�{�� ";
          run1();
         break;
    case '2'://���k�]��
         cout<<"�]���� ";
         run2();
         break;
    case '3'://�����{�{
         star();
         break;
    case '4'://����t�פp�C��
         cout<<"�W�h�G�s����U M ��(���ۤ���S����^.^)\nSpeed: 3.0->�@�ӿO"
         <<"\nSpeed: 4.0->��ӿO\nSpeed: 5.0->�T�ӿO(�ӧQ)\n";
         run3();
         break;
    case 'q':
         return 0;
         break;
    case 'Q':
         return 0;
         break;
    default:
         break;
    }
    SetNumLock(1);//�_�k 
    SetCapsLock(0);
    SetScrollLock(0);
    
    cout<<"\n�~�����H(y/other): \n";
    system("pause");
    }while((chk=GetKeyState('Y'))!=chk2);//���o�H�~�γo�Ӥ�k�A���M�i��cin 
     
    //}while((opt=='y')||(opt=='Y'));
    SetNumLock(1);//�_�k 
    SetCapsLock(0);
    SetScrollLock(0);
    return 0;
}

void run1(void)
{
int chk=GetKeyState('Q');//����
  do
  {
    
    SetNumLock(rand()%2);
    SetCapsLock(rand()%2);
    SetScrollLock(rand()%2);
    chk=GetKeyState('Q');
    Sleep(300);
  }while(chk==GetKeyState('Q'));    
}

void run2(void)
{
int chk=GetKeyState('Q');//����
int i=0;
  do
  {
    if((i%4)==0)
    {
    SetNumLock(1);
    SetCapsLock(0);
    SetScrollLock(0);
    cout<<"\b-";
    }else if((i%4)==1)
    {
    SetNumLock(0);
    SetCapsLock(1);
    SetScrollLock(0);
    cout<<"\b/";
    }else if((i%4)==2)
    {
    SetNumLock(0);
    SetCapsLock(0);
    SetScrollLock(1);
    cout<<"\b|";
    }else if((i%4)==3)
    {
    SetNumLock(0);
    SetCapsLock(1);
    SetScrollLock(0);
    cout<<"\b\\";
    }
    
    i++;
    chk=GetKeyState('Q');
    Sleep(200);
  }while(chk==GetKeyState('Q'));    
}

void run3(void)//speed game
{
  int chk=GetKeyState('Q');
  clock_t endwait;
  endwait = clock ();
  int b,m;
  double i=1;
  clock_t Tf,Tt;
  Tf = clock ();
  do
  {
  do
  {
  m=GetKeyState('M');
  }while(m<0);
      do
      {
      }while(m==GetKeyState('M'));
  
    do
  {
  m=GetKeyState('M');
  }while(m<0);
      do
      {
      }while(m==GetKeyState('M'));
  Tt=Tf;
  Tf=clock();
  i++;
  double temp=(1/((double)(Tf-Tt)/1000.0));
  cout<<"\rSpeed: "<<temp;
  
  if(temp>5.0)
  {
  SetNumLock(1);
  SetCapsLock(1);
  SetScrollLock(1);
  break;
  }else if(temp>4.0)
  {
  SetNumLock(1);
  SetCapsLock(1);
  SetScrollLock(0);
  }else if(temp>3.0)
  {
  SetNumLock(1);
  SetCapsLock(0);
  SetScrollLock(0);
  
  }
  }while(chk==GetKeyState('Q'));    
  
  star();
  //cout<<"\n�i�H���F�I";
  //Sleep(3000);
}

void star(void)
{
 for(int i=0;i<7;i++)
 {
  cout<<"\n\n*********You Win*********"; 
  SetNumLock(1);
  SetCapsLock(1);
  SetScrollLock(1);
  Sleep(500);
  cout<<"\r";
  SetNumLock(0);
  SetCapsLock(0);
  SetScrollLock(0);
  Sleep(500);
 }    


}   

void SetCapsLock(bool chk) //1,�O�G *******************
{

     if((GetKeyState(VK_CAPITAL)==1)^(chk))//1,�O�G 
     {
     // Simulate a key press 
     keybd_event(VK_CAPITAL, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 ); 
     // Simulate a key release 
     keybd_event(VK_CAPITAL, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
     
     }
} 
     
void SetNumLock(bool chk)//1,�O�G *********************
{
     if((GetKeyState(VK_NUMLOCK)==1)^(chk))
     {
     keybd_event(VK_NUMLOCK,0x45,KEYEVENTF_EXTENDEDKEY|   0,0   );   
     keybd_event(VK_NUMLOCK,0x45,KEYEVENTF_EXTENDEDKEY|KEYEVENTF_KEYUP,0);
     }   
}
     
void SetScrollLock(bool chk)//1,�O�G ******************
{
     if((GetKeyState(VK_SCROLL)==1)^(chk))
     {
     keybd_event(VK_SCROLL, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 );
     keybd_event(VK_SCROLL, 0x45, KEYEVENTF_EXTENDEDKEY|KEYEVENTF_KEYUP,0);
     }   
}
/*
If the high-order bit is 1, the key is down; otherwise, it is up.
If the low-order bit is 1, the key is toggled. 
A key, such as the CAPS LOCK key, is toggled if it is turned on. 
The key is off and untoggled if the low-order bit is 0. 
A toggle key's indicator light (if any) on the keyboard will be on when the key is toggled,
 and off when the key is untoggled.
*/