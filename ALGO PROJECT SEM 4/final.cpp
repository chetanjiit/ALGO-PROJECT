#include<bits/stdc++.h>

using namespace std;

int k=0;
int i=0;
int j=0;
int c=0;
int f;
int x;
int y;
struct profile
{
 char name[100];
 char religion[30];
 char gender[10];
 int age;
 float height;

 char location[100];
 char complexion[50];
 char profession[50];
 };
 struct expectation
 {
 char religion[30];
 int lage;
 int hage;
 float lheight;
 float uheight;
 char complexion[50];
 char profession[50];
 };
struct w
{
    int id;
    int sum;
};

  struct mat
  {
  struct profile p;
  struct expectation e;
 struct w wht[100];
  };
  void seeprofile(struct mat m[], int i)
  {
cout<<"******************************************************************************";
  cout<<"                                   PROFILE";
       cout<<"\nName :-   "<<m[i].p.name<<"\n";
       cout<<"Religion :-  "<<m[i].p.religion<<"\n";
       cout<<"Gender :-  "<<m[i].p.gender<<"\n";
       cout<<"Age :-  "<<m[i].p.age<<"\n";
       cout<<"Height :-  "<<m[i].p.height<<"feet\n";
       cout<<"Location :-  "<<m[i].p.location<<"\n";
       cout<<"Complexion :-  "<<m[i].p.complexion<<"\n";
       cout<<"Profession  :-  "<<m[i].p.profession<<"\n";

  }
  int searche(int N,struct mat m[], int b, int k)
  {

       for(i=0;i<N;i++)
       {

            if((m[b].wht[i].id==k)&&(m[b].wht[i].sum==0))
                return 1;
       }
       return 0;
  }

bool wPrefersM1OverM(int N,int *prefer, int w, int m, int m1)
{

    for (int i = 0; i < N; i++)
    {

        if (*((prefer+w*N)+i) == m1)
            return true;


        if (*((prefer+w*N)+i) == m)
           return false;
    }
}


void stableMarriage(int N,int *prefer, struct mat male[],struct mat female[], int z)
{
    int wPartner[N];

    bool mFree[N];


    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = N;

    while (freeCount > 0)
    {

        int m;
        for (m = 0; m < N; m++)
            if (mFree[m] == false)
                break;

        for (int i = 0; i < N && mFree[m] == false; i++)
        {
            int w = *((prefer+m*N)+i);


            if (wPartner[w-N] == -1)
            {
                wPartner[w-N] = m;
                mFree[m] = true;
                freeCount--;
            }

            else
            {

                int m1 = wPartner[w-N];


                if (wPrefersM1OverM(N,prefer, w, m, m1) == false)
                {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            }
        }
    }

int p;
    // Print the solution

    cout << "\n\n\n\n\n  Woman  Man" << endl;


 for (int i = 0; i < N; i++)
        {
            if(f==1&&wPartner[i]==z)
            {


                if(searche(N,male,z,i+N)==1)
                    cout<<" No match found \n";

                   else
                      {

                       cout<<"   "<<i+N<<"     "<<wPartner[i];
                       cout<<"\nPress 1 to see profile of your partner \n";
                       cin>>p;
                       if(p==1)
                      {
                              seeprofile(female,i);
                         }
                        break;
                      }
            }
       else  if(f==0&&i==z-N)
        {



                    cout<<i+N<<"  "<<wPartner[i];
                  cout<<"\nPress 1 to see profile of your partner \n";
                  cin>>p;
                  if(p==1)
                    {
                        seeprofile(male,wPartner[i]);
                        }
                  break;


        }

}
}



  int  main()
  {
 FILE * fp;

 int N;

    struct mat m;
    struct mat male[100];
    struct mat female[100];
    int s,t,l;
fp = fopen ("male.txt", "r");

         while(!feof(fp))
{  fscanf(fp,"%s %s %s %d %f %s %s %s %s %d %d %f %f %s %s\n", male[j].p.name,male[j].p.religion,male[j].p.gender ,&(male[j].p.age),&(male[j].p.height),male[j].p.location,male[j].p.complexion,male[j].p.profession,male[j].e.religion,&(male[j].e.lage),&(male[j].e.hage),&(male[j].e.lheight),&(male[j].e.uheight),male[j].e.complexion,male[j].e.profession);

      j++;
  }

  fclose(fp);
        fp = fopen ("female.txt", "r");
        while(!feof(fp))
        {
         fscanf(fp,"%s %s %s %d %f %s %s %s %s %d %d %f %f %s %s\n", female[k].p.name,female[k].p.religion,female[k].p.gender,&(female[k].p.age),&(female[k].p.height),female[k].p.location,female[k].p.complexion,female[k].p.profession,female[k].e.religion,&(female[k].e.lage),&(female[k].e.hage),&(female[k].e.lheight),&(female[k].e.uheight),female[k].e.complexion,female[k].e.profession);

          k++;
        }
        int v;
        fclose(fp);
cout<<"\nEnter 1 if u are a new user or 0 if u have tested earlier also \n";
cin>>v;
if(v==1)

{

  cout<<"***************ENTER PROFILE*********************\n";
       cout<<"enter name\n";
       cin>>m.p.name;
       cout<<"enter gender\n";
        cin>>m.p.gender;
        cout<<"enter religion\n";
    cin>>m.p.religion;
       cout<<"enter age\n";
       cin>>m.p.age;
       cout<<"enter height\n";
        cin>>m.p.height;

        cout<<"enter location\n";
         cin>>m.p.location;
         cout<<"enter complexion\n";
         cin>>m.p.complexion;
           cout<<"enter profession\n";
        cin>>m.p.profession;

        cout<<"*****************ENTER EXPECTATION******************\n";
        cout<<"religion\n";
        cin>>m.e.religion;
        cout<<"limits for age\n";
        cin>>m.e.lage;
        cin>>m.e.hage;
        cout<<"limits for height\n";
        cin>>m.e.lheight;
        cin>>m.e.uheight;
        cout<<"complexion\n";
        cin>>m.e.complexion;
        cout<<"profession\n";
        cin>>m.e.profession;

        if(strcmp(m.p.gender,"male")==0)
        {
           male[j]=m;
           cout<<male[j].p.name;
           f=1;
       fp = fopen ("male.txt", "a");
       fprintf(fp,"%s %s %s %d %f %s %s %s %s %d %d %f %f %s %s\n", male[j].p.name,male[j].p.religion,male[j].p.gender ,(male[j].p.age),(male[j].p.height),male[j].p.location,male[j].p.complexion,male[j].p.profession,male[j].e.religion,(male[j].e.lage),(male[j].e.hage),(male[j].e.lheight),(male[j].e.uheight),male[j].e.complexion,male[j].e.profession);
           j++;
            c++;
            fclose(fp);
        }
        else
        {
           female[k]=m;
      fp = fopen ("female.txt", "a");
      fscanf(fp,"%s %s %s %d %f %s %s %s %s %d %d %f %f %s %s\n", female[k].p.name,female[k].p.religion,female[k].p.gender,&(female[k].p.age),&(female[k].p.height),female[k].p.location,female[k].p.complexion,female[k].p.profession,female[k].e.religion,(female[k].e.lage),(female[k].e.hage),(female[k].e.lheight),(female[k].e.uheight),female[k].e.complexion,female[k].e.profession);
          fclose(fp);
           k++;
           f=0;
           c++;
           }
}

x=j;
y=k;


if(j>k)
{

    while(k!=j)
    {
       strcpy( female[k].p.name,"dumy");
         strcpy(female[k].p.religion,"rel");
        strcpy( female[k].p.gender,"female");
        female[k].p.age=50;
        female[k].p.height=7.8;
         strcpy(female[k].p.location,"ssd");
         strcpy(female[k].p.complexion,"toooodark");
         strcpy(female[k].p.profession,"work");
         strcpy(female[k].e.religion,"db");
        female[k].e.lage=52;
        female[k].e.hage=55;
        female[k].e.lheight=7.8;
        female[k].e.uheight=8.0;
         strcpy(female[k].e.complexion,"fair");
         strcpy(female[k].e.profession,"work");
        k++;

    }
}
else if(k>j)
{

    while(j!=k)
    {
       strcpy( male[j].p.name,"dumy");
         strcpy(male[j].p.religion,"rel");
        strcpy( male[j].p.gender,"female");
        male[j].p.age=50;
        male[j].p.height=7.8;
         strcpy(male[j].p.location,"ssd");
         strcpy(male[j].p.complexion,"toooodark");
         strcpy(male[j].p.profession,"work");
         strcpy(male[j].e.religion,"db");
        male[j].e.lage=52;
        male[j].e.hage=55;
        male[j].e.lheight=7.8;
        male[j].e.uheight=8.0;
         strcpy(male[j].e.complexion,"roodrk");
         strcpy(male[j].e.profession,"work");
        j++;

    }
}
s=j;
t=k;
int d;
int z;
if(v==0)
{
    cout<<"enter your id\n";
    cin>>z;
    cout<<"enter 0 for male 1 for female";
    cin>>d;
    if(((z>=x||z<0)&&d==0)||(((z-s)>=y||z<0||z<x)&&d==1))
    {
        cout<<"SORRY INVALID ID.\n";
        exit(0);
    }
    else if(d==0)
        f=1;
    else if(d==1)
        f=0;
}


  for(i=0;i<s;i++)
  {

      for(j=0;j<t;j++)
      {  male[i].wht[j].id=j+s;
          male[i].wht[j].sum=0;
          if(strcmp(male[i].e.religion,female[j].p.religion)==0)
          {
              male[i].wht[j].sum+=2;

          }
           if(strcmp(male[i].e.religion,female[j].p.religion)!=0)
          {
              male[i].wht[j].sum=0;

          }
          if( male[i].wht[j].sum>0)
          {

          if(female[j].p.age<=male[i].e.hage&&female[j].p.age>=male[i].e.lage)
          {
              male[i].wht[j].sum+=2;

          }
           if((female[j].p.height<=male[i].e.uheight)&&(female[j].p.height>=male[i].e.lheight))
          {
              male[i].wht[j].sum+=2;

          }
            if(strcmp(male[i].e.complexion,female[j].p.complexion)==0)
            {
                 male[i].wht[j].sum+=2;

            }
             if(strcmp(male[i].e.profession,female[j].p.profession)==0)
            {
                 male[i].wht[j].sum+=2;

            }
          }
       }


  }
  N=s;
  priority_queue<pair<int,int> >mle;
  int matri[2*N][N] ;
  for(i=0;i<s;i++)
  {
      for(j=0;j<s;j++)
        {
            mle.push(make_pair(male[i].wht[j].sum,male[i].wht[j].id));
        }
        j=0;
        while(!mle.empty())
        {
            matri[i][j]=mle.top().second;
            mle.pop();
                j++;
        }
  }
  /*checking for females now*/
  for(i=0;i<t;i++)
  {

      for(j=0;j<s;j++)
      {
           female[i].wht[j].id=j;
          female[i].wht[j].sum=0;
          if(strcmp(female[i].e.religion,male[j].p.religion)==0)
          {
              female[i].wht[j].sum+=2;

          }
          if(strcmp(female[i].e.religion,male[j].p.religion)!=0)
          {
              female[i].wht[j].sum=0;

          }
          if(female[i].wht[j].sum>0)

         {
             if(male[j].p.age<=female[i].e.hage&&male[j].p.age>=female[i].e.lage)
          {
              female[i].wht[j].sum+=2;

          }
           if((male[j].p.height<=female[i].e.uheight)&&(male[j].p.height>=female[i].e.lheight))
          {
              female[i].wht[j].sum+=2;

          }
            if(strcmp(female[i].e.complexion,male[j].p.complexion)==0)
            {
                 female[i].wht[j].sum+=2;

            }
             if(strcmp(female[i].e.profession,male[j].p.profession)==0)
            {
                 female[i].wht[j].sum+=2;

            }
         }
      }

    }

     for(i=s;i<2*s;i++)
  {
      for(j=0;j<s;j++)
        {
            mle.push(make_pair(female[i-s].wht[j].sum,female[i-s].wht[j].id));
        }
        j=0;
        while(!mle.empty())
        {
            matri[i][j]=mle.top().second;
            mle.pop();
            j++;
        }
  }


    if(v==1)
   {
       if(f==1)
        {
            cout<<"Your id is" <<k-1<<"  Your Best match \n";
            stableMarriage(N,(int *)matri, male,female,k-1);
        }
        else if(f==0)
             {
                 cout<<"Your id is" <<k+N-1<<"  Your Best match \n";
                stableMarriage(N,(int *)matri, male,female,k+N-1);
             }
   }
  else if(v==0)
  {

      cout <<"Your Id is "<<z<<" Your Best match is ";
      stableMarriage(N, (int *)matri,male,female,z);
  }

  return 0;
  }



