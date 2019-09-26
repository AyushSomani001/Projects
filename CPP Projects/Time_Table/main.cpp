// Author: "Ayush Somani"

#include<bits/stdc++.h>
using namespace std;
int n;
int r;
int ctr=0;
typedef struct
{
    int hr;
    int minute;
    float asp;
}tim;
typedef struct
{
    int id;
    vector<int>domain;
    tim strt;
    tim end1;
    int allot=-1;
    int mark=-1;
}clas;
void rem(clas ar[],int l,int m)
{
    for(int i=0;i<ar[l].domain.size();i++)
    {
        if(ar[l].domain[i]==m)
        {
            vector<int>::iterator it=ar[l].domain.begin();
            ar[l].domain.erase(it+i);
            return;
        }
    }
}
int selectd(clas ar[])
{
    int cla=-1;
    int min1=1000000;
    for(int j=1;j<=n;j++)
    {
        if(ar[j].allot==-1)
        {int rt=ar[j].domain.size();
        if(rt<min1)
        {
            min1=rt;
            cla=j;
        }
        }
    }
    return cla;
}
void update(clas ar[],int i,int j)
{
    for(int l=1;l<=n;l++)
    {
        if(ar[l].allot==-1)
        {
           if(ar[i].strt.asp<ar[l].strt.asp)
           {
               if(ar[i].end1.asp<ar[l].strt.asp);
               else
                {
                    rem(ar,l,j);
                    //cout<<l<<"   "<<ar[l].domain.size()<<endl;
                    ar[l].mark=1;
                }
           }
        else if(ar[l].strt.asp<ar[i].strt.asp)
        {
            if(ar[l].end1.asp<ar[i].strt.asp);
               else
                {
                    rem(ar,l,j);

                    ar[l].mark=1;
                }

        }
        else
             {
                 rem(ar,l,j);
                 //cout<<l<<"   "<<ar[l].domain.size()<<endl;
                 ar[l].mark=1;
             }
    }
}
}
void backtrack(clas ar[],int i,int j)
{
    for(int l=1;l<=n;l++)
    {
        if(l==i)
            continue;
        if(ar[l].allot==-1 && ar[l].mark==1)
        {
            ar[l].domain.push_back(j);
            ar[l].mark=-1;
        }
    }
}
void display(int soln[])
{
    cout<<endl<<endl<<endl;
    for(int i=1;i<=n;i++)
        cout<<"C"<<i<<" will have class in room no. R"<<soln[i]<<endl;
    cout<<endl<<endl<<endl;
}
void solve(vector<vector<int> > c,clas ar[],int soln[],int xc)
{
    if(xc==0)
    {
        if(ctr==0)
        display(soln);
        ctr=1;
        return;
    }
    if(ctr==0)
    {int choice=selectd(ar);
    //cout<<choice<<"   "<<ar[choice].domain.size()<<endl;
    if(choice!=-1)
    {for(int i=0;i<ar[choice].domain.size();i++)
    {
        xc--;
        ar[choice].allot=ar[choice].domain[i];
        soln[choice]=ar[choice].domain[i];
        update(ar,choice,ar[choice].domain[i]);
        solve(c,ar,soln,xc);
        backtrack(ar,choice,ar[choice].domain[i]);
        xc++;
    }
    ar[choice].allot=-1;
    }
    }
}
int main()
{
    vector<vector<int> > constraints(100);
    cout<<"Enter the number of classes....... ";
    cin>>n;
    cout<<"Enter the number of available rooms...... ";
    cin>>r;
    clas ar[n+1];
    for(int i=1;i<=n;i++)
    {
        cout<<"FOR CLASS "<<i<<endl;
        cout<<"Enter strt hour.....  ";
        cin>>ar[i].strt.hr;
        cout<<"Enter strt minute.....  ";
        cin>>ar[i].strt.minute;
        ar[i].strt.asp=ar[i].strt.hr+((float)(ar[i].strt.minute)/60);
        cout<<"Enter end hour.....  ";
        cin>>ar[i].end1.hr;
        cout<<"Enter end minute.....  ";
        cin>>ar[i].end1.minute;
        ar[i].end1.asp=ar[i].end1.hr+((float)(ar[i].end1.minute)/60);
        ar[i].id=i;
        for(int j=1;j<=r;j++)
            ar[i].domain.push_back(j);
        cout<<endl;
       // cout<<ar[i].strt.asp<<"----"<<ar[i].end1.asp<<endl;
    }
    cout<<"Enter the number of constraints..... ";
    int cq;
    cin>>cq;
    for(int i=0;i<cq;i++)
    {
        cout<<"Enter 2 integers i and j such that Rj cant accommodate Ci  ";
        int l,m;
        cin>>l>>m;
        constraints[l].push_back(m);
        rem(ar,l,m);
    }
    int soln[n+1];
    solve(constraints,ar,soln,n);
    return 0;
}
