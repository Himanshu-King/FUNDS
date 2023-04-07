#include <iostream>
using namespace std;

void disclamier()
{
    cout<<"----------------------------------------DISCLAIMER----------------------------------------\nYou are responsible for your own money.\nPlease don't come to me after fucking it all your funds.\nBut I noticed if we loss 2 bet conssectutivly then the next one we can win.\n\n";
}

void invest(int a, float b, int &first, int &second, int &third, int flag2, int a2);

void profit(int &first, int &second, int &third, int &pt, int &flag, int &a, float &b, int a2)
{
    float first1, first2, second1, second2, third1, third2;
    up:
    first1 = ((first - (float(first)/40)*2)*2)-first;
    first2 = ((first - (float(first)/40)*2)*1.5)-first;
    second1 = ((second - (float(second)/40)*2)*2)-(first+second);
    second2 = ((second - (float(second)/40)*2)*1.5)-(first+second);
    third1 = ((third - (float(third)/40)*2)*2)-(first+second+third);
    third2 = ((third - (float(third)/40)*2)*1.5)-(first+second+third);
    // first1 = -1;
    if((first1<0 || first2<0) || (second1<0 || second2<0) || (third1<0 || third2<0) || flag==3)
    {
        bool flag3=0;
        flag = 0;
        a = a - 10;
        b = float(1140)/a;
        invest(a, b, first, second, third, flag3, a2);
        goto up;
    }

    if((first1<0 || first2<0) || (second1<0 || second2<0) || (third1<0 || third2<0) )
    {
        pt=1;
    }
    else
    {
        if(flag==1)
        {
            cout<<"************************************************************************************\n";
            cout<<"If 1 color win in bid 1 then you will get: "<< first1 <<", Net Balance:- "<< a2+first1 <<", Profit %:- " << float(first1)/a2*100 << endl;
            cout<<"If 2 color win in bid 1 then you will get: "<< first2 <<", Net Balance:- "<< a2+first2 <<", Profit %:- " << float(first2)/a2*100<< endl;
            cout<<"\n----------------------------------------------------\n";
            cout<<"If 1 color win in bid 2 then you will get: "<< second1 <<", Net Balance:- "<< a2+second1 <<", Profit %:- " << float(second1)/a2*100<< endl;
            cout<<"If 2 color win in bid 2 then you will get: "<< second2 <<", Net Balance:- "<< a2+second2 <<", Profit %:- " << float(second2)/a2*100<< endl;
            cout<<"\n----------------------------------------------------\n";
            cout<<"If 1 color win in bid 3 then you will get: "<< third1 <<", Net Balance:- "<< a2+third1 <<", Profit %:- " << float(third1)/a2*100<< endl;
            cout<<"If 2 color win in bid 3 then you will get: "<< third2 <<", Net Balance:- "<< a2+third2 <<", Profit %:- " << float(third2)/a2*100<< endl;
            cout<<"************************************************************************************\n";
        }
    }
}

void invest(int a, float b, int &first, int &second, int &third, int flag2, int a2)
{
    int pt = 0;
    int flag = 0;
    // cout<<"Value of b is: " << b << endl;
    // cout<<"Value of a is: " << a <<endl;

    // Storing and converting in 10 multiples.
    first = (100/b) - (int(100/b)%10);
    second = (240/b) - (int(240/b)%10);
    third = (800/b) - (int(800/b)%10);
    // cout<< "Value is:"<< first <<endl;
    // cout<< "Value is:"<< second <<endl;
    // cout<< "Value is:"<< third <<endl;

    proup:
    if(first+second+third>a2)
    {
        flag=3;
    }

    profit(first, second, third, pt, flag, a, b, a2);

    if(first+second+third>a2)
    {
        goto proup;
    }

    if (flag2==1)
    {
        if(first+second+third<=a2 )
        {
            cout<<"************************************************************************************\n";
            cout<<"Play your first bid at: "<<first<<endl;
            cout<<"\nIf you lose BID 1 then use BID 2 otherwise go on with BID 1.\n";
            cout<<"Play your second bid at: "<<second<<endl;
            cout<<"\nIf you lose BID 2 then use BID 3.\n";
            cout<<"Play your third bid at: "<<third<<endl;
            cout<<"************************************************************************************\n";
        }
        else
        {
            cout<<"Contact program creater.\nName = Himanshu Soni \nInsta ID:- 8king_soni8\n";
        }
    }
}


void pro(int first, int second, int third, int &a, float &b, int a2)
{
    int p=2,pt=0;
    int flag = 1;
    while(1)
    {
        cout<<"If you want to see profit in every bid press 1 otherwise 0: ";
        cin >> p;
        if(p!=1 && p!=0)
        {
            cout<<"Enter valid input: ";
        }
        else
        {
            break;
        }
    }
    if(p==1)
    {
        profit(first, second , third, pt, flag, a, b, a2);
    }
}

int main()
{
    int a , first, second , third ,a2;
    float b;
    bool flag2=1;
    disclamier();
    cout<<"Enter your funds $$$(not decimal): ";
    cin>>a2;
    a = a2+10;
    b = float(1140)/a;
    invest(a, b, first, second, third, flag2, a2);

    pro(first, second, third, a, b, a2);

    for (int i = 0; 1 ; i++)
    {
        if (i==0)
        {
            cout<<"Press Ctrl + C for exit the terminal.";
        }
    }
    

    return 0;
}