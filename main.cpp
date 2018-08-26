#include <iostream>
#include <cstdlib>
#include<string>
#include<math.h>
#include<sstream>

using namespace std;
int a[8],b[8],c[8],d[8],e[8],h[8],l[8];
    int flag[8],sp[16];
int mem[65535][8];
void mvi( string reg,int oper);
void mov(string oper1, string oper2);
 void lda(string add16);
 void ldax(string rp);
 void lxi(string rp, string add16);
 void lhld(string add16);
void sta(string add16);
void stax (string rp);
void shld(string add16);
void xchg();
void sphl();
void xthl();









string hextobin(string s);
int stoint(string s);
int hextodec(string s);
string dectobin(string ne);
int bintodec(string n);
string intostr(int num);


int main()
{
   while(1)
  {
      string comm ;

label: cout<<endl<<" Ab kya karna hai?"<<endl;
       cin>>comm;
      if(comm == "medit")
      {
          cout<<"Address bata be!"<<endl;

         string ad;
         cin>>ad;
         if(ad[ad.size()-1] == 'h')
                {ad.erase(ad.size()-1);}
         int addr;
         addr = hextodec(ad);
        cout<<" Value bata"<<endl;
        string val ;
        cin>>val;


              if(val[val.size()-1] == 'h')
           {     val.erase(val.size()-1);

                 val = hextobin(val);
                 int value = stoint(val);

               for(int i=0;i<8;i++)
               {
                    int rem;
                 rem = value%10;
                 value /= 10;
                 mem[addr][7-i] = rem;

               }

                cout<<"Store ho gaya memory me!"<<endl;
           }
               else if(val[val.size()-1] == 'b')
             {     val.erase(val.size()-1);
               int value = stoint(val);
               for(int i=0;i<8;i++)
               {
                    int rem;
                 rem = value%10;
                 value /= 10;
                 mem[addr][7-i] = rem;
               }
             }

       }


  else if(comm == "mshow")
       {

      cout<<"Address bata dikhata hun!"<<endl;

         string ad;
         cin>>ad;
         if(ad[ad.size()-1] == 'h')
                {ad.erase(ad.size()-1);}
                int addr = hextodec(ad);
                  cout<< ad<< "h :";
                   for(int i=0;i<8;i++)
               {
                  cout<<" "<<mem[addr][i];
               }
           cout<<endl;
       }



    else if (comm == "inst")
     { cout<<endl<<"Chal be daal instruction..."<<endl<<endl;
      string s;

          cin>>s ;

          if(s == "mvi"){

          string reg,oper;
             cin>>reg>>oper;

             if(oper[oper.size()-1] == 'h')
           {     oper.erase(oper.size()-1);
               oper = hextobin(oper);
               int op = stoint(oper) ;
            mvi(reg,op);
              cout<< endl<<"Theek hai, hex value entered in moved!"<<endl;}

           else if(oper[oper.size()-1] =='b')
            {
                oper.erase(oper.size()-1);

                 int op = stoint(oper);
                 mvi(reg,op);
                 cout<< endl<<"Theek hai, bin value entered in moved!"<<endl;}


           else if((oper[oper.size()-1] >= '0') && (oper[oper.size()-1] <= '9'))
            {
                oper = dectobin(oper);
                int op = stoint(oper);

                mvi(reg,op);
             cout<< endl<<"Theek hai, dec value entered in moved!"<<endl;}


            else{cout<<" Arey! Value galat hai dekh"<<endl;}

         }

          else if(s == "mov"){
               string oper1, oper2;

               cin>> oper1>>oper2;

               mov(oper1,oper2);
               cout<<"Move ho gaya!"<<endl;
           }

          else if(s == "lda"){
              string add16;
              cin>>add16;
                 if(add16[add16.size()-1] == 'h')
                add16.erase(add16.size()-1);
              lda(add16);
              cout<<"Accumulator loaded"<<endl;
          }

          else if (s == "ldax"){

            string rp;
            cin>>rp;
            ldax(rp);
             cout<<"Accumulator loaded (using reg pair "<<rp<<")"<<endl;
          }

          else if( s == "lxi"){

            string rp,data16;
            cin>>rp>>data16;
              if(data16[data16.size()-1] == 'h')
                data16.erase(data16.size()-1);
            lxi(rp,data16);

            cout<<"Reg pair "<<rp<<" is loaded"<<endl;
          }

          else if(s == "lhld"){
            string add16;
            if(add16[add16.size()-1] == 'h')
            add16.erase(add16.size()-1);
            lhld(add16);

          }

          else if(s == "sta" ){
                string add16;
              cin>>add16;
                 if(add16[add16.size()-1] == 'h')
                add16.erase(add16.size()-1);
              sta(add16);
              cout<<" Contents of Accumulator stored!"<<endl;
          }

          else if(s == "stax"){

            string rp;
            cin>>rp;
            stax(rp);
             cout<<"Contents of accumulator stored (using reg pair "<<rp<<")"<<endl;

          }

          else if(s == "shld"){

            string add16;
            if(add16[add16.size()-1] == 'h')
            add16.erase(add16.size()-1);
            shld(add16);


          }

          else if(s == "xchg"){

            xchg();

            cout<<"contents of HL and DE are exchanged!"<<endl;
          }

          else if(s == "sphl"){

             sphl();
            cout<<"Stack pointer initialized with HL pair."<<endl;
          }

          else if(s == "xthl"){

            xthl();

            cout<<"Contents of HL exchanges with stack"<<endl;
          }













     }




     else if(comm == "showsp")
     {
         cout<<"SP: ";

         for(int i=0; i<16; i++)
         {
             cout<<sp[i]<<" ";

         }

         cout<<endl;

     }



       else if(comm == "exit")
        {  cout<<endl<<"Chal bye"<<endl;
            break;
        }

        else  if(comm == "dikhao")
         {   cout<< endl<< "Registers ke halat aise hain..."<<endl;

             cout<<"a= ";
              for(int i=0; i<8;i++)
            {
               cout<<a[i]<< " ";
            }
             cout<<endl;
             cout<<"b= ";
             for(int i=0; i<8;i++)
            {
               cout<<b[i]<< " ";
            }
             cout<<endl;
            cout<<"c= ";
              for(int i=0; i<8;i++)
            {
               cout<<c[i]<< " ";
            }
             cout<<endl;
             cout<<"d= ";
              for(int i=0; i<8;i++)
            {
               cout<<d[i]<< " ";
            }
             cout<<endl;
             cout<<"e= ";
              for(int i=0; i<8;i++)
            {
               cout<<e[i]<< " ";
            }
             cout<<endl;
            cout<<"h= ";
            for(int i=0; i<8;i++)
            {
               cout<<h[i]<< " ";
            }
             cout<<endl;
             cout<<"l= ";
           for(int i=0; i<8;i++)
            {
               cout<<l[i]<< " ";
            }
             cout<<endl;
         }

        else if(comm != "inst" || "dikhao" || "exit" || "medit")
         {
             cout<<"Kya? mai samja nahi!"<<endl;
         }

    goto label ;
    }

    return 0;
}

void mvi(string reg, int oper){

     if(reg == "m")
     {
         string str;
         for(int i=0; i<8; i++)
         {
             str += intostr(h[i]);
         }
         for(int i=0; i<8;i++)
         {
             str += intostr(l[i]);
         }
          int addr = bintodec(str);

         for(int i=0; i<8;i++)
       {    int rem;
           rem = oper%10;
           oper /= 10;
           mem[addr][7-i] = rem;
       }

     }


     else if(reg == "a")
    {
       for(int i=0; i<8;i++)
       {    int rem;
           rem = oper%10;
           oper /= 10;
           a[7-i] = rem;
       }
    }

    else if(reg == "b")
    {
       for(int i=0; i<8;i++)
       {    int rem;
           rem = oper%10;
           oper /= 10;
           b[7-i] = rem;
       }


    }

   else  if(reg == "c")
    {
       for(int i=0; i<8;i++)
       {    int rem;
           rem = oper%10;
           oper /= 10;
           c[7-i] = rem;
       }
    }

    else if(reg == "d")
    {
       for(int i=0; i<8;i++)
       {    int rem;
           rem = oper%10;
           oper /= 10;
           d[7-i] = rem;
       }
    }

     else if(reg == "e")
    {
       for(int i=0; i<8;i++)
       {    int rem;
           rem = oper%10;
           oper /= 10;
           e[7-i] = rem;
       }
    }

    else if(reg == "h")
    {
       for(int i=0; i<8;i++)
       {    int rem;
           rem = oper%10;
           oper /= 10;
           h[7-i] = rem;
       }
    }

    else if(reg == "l")
    {
       for(int i=0; i<8;i++)
       {    int rem;
           rem = oper%10;
           oper /= 10;
           l[7-i] = rem;
       }

    }
}


    void mov(string oper1, string oper2){
       if(oper1 == "m"){
            string str;
            for(int i=0; i<8; i++)
            {
                str += intostr(h[i]);
            }
            for(int i=0; i<8;i++)
            {
                str += intostr(l[i]);
            }
            int addr = bintodec(str);
            for(int i=0;i<8;i++)
            {
               mem[addr][i] = a[i];
            }


           if(oper2 == "a")
              {
                  for(int i=0;i<8;i++)
                  {
                     mem[addr][i] = a[i];
                  }
              }

              else if(oper2 =="b")
              {
                  for(int i=0;i<8;i++)
                  {
                      mem[addr][i] = b[i];
                  }
              }

               else if(oper2 =="c")
              {
                  for(int i=0;i<8;i++)
                  {
                     mem[addr][i] = c[i];
                  }
              }

               else if(oper2 =="d")
              {
                  for(int i=0;i<8;i++)
                  {
                     mem[addr][i] = d[i];
                  }
              }

               else if(oper2 =="e")
              {
                  for(int i=0;i<8;i++)
                  {
                     mem[addr][i] = e[i];
                  }
              }

                else if(oper2 =="h")
              {
                  for(int i=0;i<8;i++)
                  {
                    mem[addr][i] = h[i];
                  }
              }

                 else if(oper2 =="l")
              {
                  for(int i=0;i<8;i++)
                  {
                     mem[addr][i] = l[i];
                  }
              }



      }

         else if(oper1 == "a"){


             if(oper2 == "m")
             {
                 string str;
                 for(int i=0; i<8; i++)
                 {
                     str += intostr(h[i]);
                 }
                 for(int i=0; i<8;i++)
                 {
                     str += intostr(l[i]);
                 }
                  int addr = bintodec(str);
                  for(int i=0;i<8;i++)
                  {
                      a[i] = mem[addr][i];
                  }
             }

            else if(oper2 == "a")
              {
                  for(int i=0;i<8;i++)
                  {
                      a[i] = a[i];
                  }
              }

              else if(oper2 =="b")
              {
                  for(int i=0;i<8;i++)
                  {
                      a[i] = b[i];
                  }
              }

               else if(oper2 =="c")
              {
                  for(int i=0;i<8;i++)
                  {
                      a[i] = c[i];
                  }
              }

               else if(oper2 =="d")
              {
                  for(int i=0;i<8;i++)
                  {
                      a[i] = d[i];
                  }
              }

               else if(oper2 =="e")
              {
                  for(int i=0;i<8;i++)
                  {
                      a[i] = e[i];
                  }
              }

                else if(oper2 =="h")
              {
                  for(int i=0;i<8;i++)
                  {
                      a[i] = h[i];
                  }
              }

                 else if(oper2 =="l")
              {
                  for(int i=0;i<8;i++)
                  {
                      a[i] = l[i];
                  }
              }

          }

         else if(oper1 == "b"){

             if(oper2 == "m")
             {
                 string str;
                 for(int i=0; i<8; i++)
                 {
                     str += intostr(h[i]);
                 }
                 for(int i=0; i<8;i++)
                 {
                     str += intostr(l[i]);
                 }
                  int addr = bintodec(str);
                  for(int i=0;i<8;i++)
                  {
                      b[i] = mem[addr][i];
                  }
             }


            else if(oper2 == "a")
              {
                  for(int i=0;i<8;i++)
                  {
                      b[i] = a[i];
                  }
              }

              else if(oper2 =="b")
              {
                  for(int i=0;i<8;i++)
                  {
                      b[i] = b[i];
                  }
              }

               else if(oper2 =="c")
              {
                  for(int i=0;i<8;i++)
                  {
                      b[i] = c[i];
                  }
              }

               else if(oper2 =="d")
              {
                  for(int i=0;i<8;i++)
                  {
                      b[i] = d[i];
                  }
              }

               else if(oper2 =="e")
              {
                  for(int i=0;i<8;i++)
                  {
                      b[i] = e[i];
                  }
              }

                else if(oper2 =="h")
              {
                  for(int i=0;i<8;i++)
                  {
                      b[i] = h[i];
                  }
              }

                 else if(oper2 =="l")
              {
                  for(int i=0;i<8;i++)
                  {
                      b[i] = l[i];
                  }
              }



          }

         else if(oper1 == "c"){
             if(oper2 == "m")
             {
                 string str;
                 for(int i=0; i<8; i++)
                 {
                     str += intostr(h[i]);
                 }
                 for(int i=0; i<8;i++)
                 {
                     str += intostr(l[i]);
                 }
                  int addr = bintodec(str);
                  for(int i=0;i<8;i++)
                  {
                      c[i] = mem[addr][i];
                  }
             }


          else if(oper2 == "a")
              {
                  for(int i=0;i<8;i++)
                  {
                      c[i] = a[i];
                  }
              }

              else if(oper2 =="b")
              {
                  for(int i=0;i<8;i++)
                  {
                      c[i] = b[i];
                  }
              }

               else if(oper2 =="c")
              {
                  for(int i=0;i<8;i++)
                  {
                      c[i] = c[i];
                  }
              }

               else if(oper2 =="d")
              {
                  for(int i=0;i<8;i++)
                  {
                      c[i] = d[i];
                  }
              }

               else if(oper2 =="e")
              {
                  for(int i=0;i<8;i++)
                  {
                      c[i] = e[i];
                  }
              }

                else if(oper2 =="h")
              {
                  for(int i=0;i<8;i++)
                  {
                      c[i] = h[i];
                  }
              }

                 else if(oper2 =="l")
              {
                  for(int i=0;i<8;i++)
                  {
                      c[i] = l[i];
                  }
              }



          }

          else if(oper1 == "d"){
             if(oper2 == "m")
             {
                 string str;
                 for(int i=0; i<8; i++)
                 {
                     str += intostr(h[i]);
                 }
                 for(int i=0; i<8;i++)
                 {
                     str += intostr(l[i]);
                 }
                  int addr = bintodec(str);
                  for(int i=0;i<8;i++)
                  {
                      d[i] = mem[addr][i];
                  }
             }


          else if(oper2 == "a")
              {
                  for(int i=0;i<8;i++)
                  {
                      d[i] = a[i];
                  }
              }

              else if(oper2 =="b")
              {
                  for(int i=0;i<8;i++)
                  {
                      d[i] = b[i];
                  }
              }

               else if(oper2 =="c")
              {
                  for(int i=0;i<8;i++)
                  {
                      d[i] = c[i];
                  }
              }

               else if(oper2 =="d")
              {
                  for(int i=0;i<8;i++)
                  {
                      d[i] = d[i];
                  }
              }

               else if(oper2 =="e")
              {
                  for(int i=0;i<8;i++)
                  {
                      d[i] = e[i];
                  }
              }

                else if(oper2 =="h")
              {
                  for(int i=0;i<8;i++)
                  {
                      d[i] = h[i];
                  }
              }

                 else if(oper2 =="l")
              {
                  for(int i=0;i<8;i++)
                  {
                      d[i] = l[i];
                  }
              }



          }

          else if(oper1 == "e"){
             if(oper2 == "m")
             {
                 string str;
                 for(int i=0; i<8; i++)
                 {
                     str += intostr(h[i]);
                 }
                 for(int i=0; i<8;i++)
                 {
                     str += intostr(l[i]);
                 }
                  int addr = bintodec(str);
                  for(int i=0;i<8;i++)
                  {
                      e[i] = mem[addr][i];
                  }
             }


          else if(oper2 == "a")
              {
                  for(int i=0;i<8;i++)
                  {
                      e[i] = a[i];
                  }
              }

              else if(oper2 =="b")
              {
                  for(int i=0;i<8;i++)
                  {
                      e[i] = b[i];
                  }
              }

               else if(oper2 =="c")
              {
                  for(int i=0;i<8;i++)
                  {
                      e[i] = c[i];
                  }
              }

               else if(oper2 =="d")
              {
                  for(int i=0;i<8;i++)
                  {
                      e[i] = d[i];
                  }
              }

               else if(oper2 =="e")
              {
                  for(int i=0;i<8;i++)
                  {
                      e[i] = e[i];
                  }
              }

                else if(oper2 =="h")
              {
                  for(int i=0;i<8;i++)
                  {
                      e[i] = h[i];
                  }
              }

                 else if(oper2 =="l")
              {
                  for(int i=0;i<8;i++)
                  {
                      e[i] = l[i];
                  }
              }



          }

          else if(oper1 == "h"){
             if(oper2 == "m")
             {
                 string str;
                 for(int i=0; i<8; i++)
                 {
                     str += intostr(h[i]);
                 }
                 for(int i=0; i<8;i++)
                 {
                     str += intostr(l[i]);
                 }
                  int addr = bintodec(str);
                  for(int i=0;i<8;i++)
                  {
                      h[i] = mem[addr][i];
                  }
             }


          else if(oper2 == "a")
              {
                  for(int i=0;i<8;i++)
                  {
                      h[i] = a[i];
                  }
              }

              else if(oper2 =="b")
              {
                  for(int i=0;i<8;i++)
                  {
                      h[i] = b[i];
                  }
              }

               else if(oper2 =="c")
              {
                  for(int i=0;i<8;i++)
                  {
                      h[i] = c[i];
                  }
              }

               else if(oper2 =="d")
              {
                  for(int i=0;i<8;i++)
                  {
                      h[i] = d[i];
                  }
              }

               else if(oper2 =="e")
              {
                  for(int i=0;i<8;i++)
                  {
                      h[i] = e[i];
                  }
              }

                else if(oper2 =="h")
              {
                  for(int i=0;i<8;i++)
                  {
                      h[i] = h[i];
                  }
              }

                 else if(oper2 =="l")
              {
                  for(int i=0;i<8;i++)
                  {
                      h[i] = l[i];
                  }
              }

          }

           else if(oper1 == "l"){
             if(oper2 == "m")
             {
                 string str;
                 for(int i=0; i<8; i++)
                 {
                     str += intostr(h[i]);
                 }
                 for(int i=0; i<8;i++)
                 {
                     str += intostr(l[i]);
                 }
                  int addr = bintodec(str);
                  for(int i=0;i<8;i++)
                  {
                      l[i] = mem[addr][i];
                  }
             }


          else if(oper2 == "a")
              {
                  for(int i=0;i<8;i++)
                  {
                      l[i] = a[i];
                  }
              }

              else if(oper2 =="b")
              {
                  for(int i=0;i<8;i++)
                  {
                      l[i] = b[i];
                  }
              }

               else if(oper2 =="c")
              {
                  for(int i=0;i<8;i++)
                  {
                      l[i] = c[i];
                  }
              }

               else if(oper2 =="d")
              {
                  for(int i=0;i<8;i++)
                  {
                      l[i] = d[i];
                  }
              }

               else if(oper2 =="e")
              {
                  for(int i=0;i<8;i++)
                  {
                      l[i] = e[i];
                  }
              }

                else if(oper2 =="h")
              {
                  for(int i=0;i<8;i++)
                  {
                      l[i] = h[i];
                  }
              }

                 else if(oper2 =="l")
              {
                  for(int i=0;i<8;i++)
                  {
                      l[i] = l[i];
                  }
              }
          }

    }

  void lda(string add16){

      add16 = hextobin(add16);
      int addr16 = bintodec(add16);
      for(int i=0; i<8; i++)
      {
         a[i] = mem[addr16][i];
      }
  }

void ldax(string rp)
{
    if(rp =="b")
    {
                string str;
            for(int i=0; i<8; i++)
            {
                str += intostr(b[i]);
            }
            for(int i=0; i<8;i++)
            {
                str += intostr(c[i]);
            }
            int addr = bintodec(str);
            for(int i=0;i<8;i++)
            {
              a[i]= mem[addr][i];
            }
    }

       else if(rp =="d")
    {
                string str;
            for(int i=0; i<8; i++)
            {
                str += intostr(d[i]);
            }
            for(int i=0; i<8;i++)
            {
                str += intostr(e[i]);
            }
            int addr = bintodec(str);
            for(int i=0;i<8;i++)
            {
              a[i]= mem[addr][i];
            }
    }

    else if(rp != "b"||"d")
    {
        cout<<" Abe ye wale reg. pair not allowed hai!"<<endl;
    }


}

 void lxi( string rp, string data16)
{      string sec,fir;
            sec += data16[(data16.size()-2)];
             sec += data16[(data16.size()-1)];
            fir += data16[(data16.size()-4)];
            fir += data16[(data16.size()-3)];

     sec = hextobin(sec);
      fir = hextobin(fir);
      int se = stoint(sec);
      int fi = stoint(fir);
    if(rp =="b")
    {
      for(int i=0; i<8;i++)
       {    int rem;
           rem = fi%10;
           fi/= 10;
           b[7-i] = rem;
       }
        for(int i=0; i<8;i++)
       {    int rem;
           rem = se%10;
           se/= 10;
           c[7-i] = rem;
       }
    }

  else if(rp =="h")
    {
      for(int i=0; i<8;i++)
       {    int rem;
           rem = fi%10;
           fi/= 10;
           h[7-i] = rem;
       }
        for(int i=0; i<8;i++)
       {    int rem;
           rem = se%10;
           se/= 10;
           l[7-i] = rem;
       }

    }

   else if(rp =="d")
    {
      for(int i=0; i<8;i++)
       {    int rem;
           rem = fi%10;
           fi/= 10;
           d[7-i] = rem;
       }
        for(int i=0; i<8;i++)
       {    int rem;
           rem = se%10;
           se/= 10;
           e[7-i] = rem;
       }

    }

}


void lhld(string add16){

       add16 = hextobin(add16);
      int addr16 = bintodec(add16);
      for(int i=0; i<8; i++)
      {
         l[i] = mem[addr16][i];
         h[i] = mem[addr16 +1][i];
      }
}

void sta(string add16){
     add16 = hextobin(add16);
      int addr16 = bintodec(add16);
      for(int i=0; i<8; i++)
      {
       mem[addr16][i]  = a[i] ;
      }
}

void stax (string rp){

   if(rp =="b")
    {
                string str;
            for(int i=0; i<8; i++)
            {
                str += intostr(b[i]);
            }
            for(int i=0; i<8;i++)
            {
                str += intostr(c[i]);
            }
            int addr = bintodec(str);
            for(int i=0;i<8;i++)
            {
              mem[addr][i] = a[i];
            }
    }

       else if(rp =="d")
    {
                string str;
            for(int i=0; i<8; i++)
            {
                str += intostr(d[i]);
            }
            for(int i=0; i<8;i++)
            {
                str += intostr(e[i]);
            }
            int addr = bintodec(str);
            for(int i=0;i<8;i++)
            {
             mem[addr][i] = a[i];
            }
    }

       else if(rp =="h")
    {
                string str;
            for(int i=0; i<8; i++)
            {
                str += intostr(h[i]);
            }
            for(int i=0; i<8;i++)
            {
                str += intostr(l[i]);
            }
            int addr = bintodec(str);
            for(int i=0;i<8;i++)
            {
             mem[addr][i] = a[i];
            }
    }


 }

 void shld( string add16){

      add16 = hextobin(add16);
      int addr16 = bintodec(add16);
      for(int i=0; i<8; i++)
      {
         mem[addr16][i] = l[i] ;
         mem[addr16 +1][i] = h[i];


      }
 }

 void xchg(){

 for(int i=0; i<8; i++)
 {
     int temp =0;

     temp = h[i];
     h[i] = d[i];
     d[i] = temp;

 }

  for(int i=0; i<8; i++)
 {
     int temp =0;

     temp = l[i];
     l[i] = e[i];
     e[i] = temp;

 }

 }

 void sphl(){

  for(int i=0; i<8; i++)
  {
      sp[i] = h[i];
      sp[i+8] = l[i];
  }


 }

 void xthl(){

              string str;
            for(int i=0; i<8; i++)
            {
                str += intostr(sp[i]);
            }
            for(int i=0; i<8;i++)
            {
                str += intostr(sp[i+8]);
            }
            int addr = bintodec(str);


  for(int i=0; i<8; i++)
 {
     int temp =0;

     temp = l[i];
     l[i] = mem[addr][i];
      mem[addr][i] = temp;

 }

  for(int i=0; i<8; i++)
 {
     int temp =0;

     temp = h[i];
     h[i] = mem[addr + 1][i];
      mem[addr+1][i] = temp;

 }


 }











string hextobin(string s){
long int i=0;
	string binnum;
	while(s[i])
	{
		switch(s[i])
		{
			case '0' : binnum += "0000";;
				break;
			case '1' : binnum += "0001";
				break;
			case '2' : binnum += "0010";
				break;
			case '3' : binnum += "0011";
				break;
			case '4' : binnum += "0100";
				break;
			case '5' : binnum += "0101";
				break;
			case '6' : binnum +="0110";
				break;
			case '7' :binnum +="0111";
				break;
			case '8' : binnum += "1000";
				break;
			case '9' : binnum += "1001";
				break;
			case 'A' : binnum +="1010";
				break;
			case 'B' :binnum += "1011";
				break;
			case 'C' : binnum += "1100";
				break;
			case 'D' :binnum += "1101";
				break;
			case 'E' : binnum += "1110";
				break;
			case 'F' :binnum += "1111";
				break;
			case 'a' : binnum += "1010";
				break;
			case 'b' : binnum += "1011";
				break;
			case 'c' : binnum += "1100";
				break;
			case 'd' : binnum += "1101";
				break;
			case 'e' : binnum += "1110";
				break;
			case 'f' :binnum += "1111";
				break;
			default : cout<<"\nInvalid hexadecimal digit "<<s[i];
		}
		i++;
	}
    return binnum;
}

int stoint(string s){
    int op;
    std::stringstream convert;

    convert << s;
    convert >> op;

    convert.str("");
    convert.clear();
   return op;
}

int hextodec(string hexVal){
    int len = hexVal.size();

    int base = 1;
    int dec_val = 0;

    for (int i=len-1; i>=0; i--)
    {
        if (hexVal[i]>='0' && hexVal[i]<='9')
        {
            dec_val += (hexVal[i] - 48)*base;

            base = base * 16;
        }

        else if (hexVal[i]>='a' && hexVal[i]<='f')
        {
            dec_val += (hexVal[i] - 87)*base;


            base = base*16;
        }
    }

    return dec_val;
}

string dectobin(string ne){
          int n= stoint(ne);
          string final;
    for (int i = 7; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            final+= "1";
        else
            final+= "0";
    }

     return final;

}

int bintodec(string n){
    string num = n;
    int dec_value = 0;

    int base = 1;

    int len = num.length();
    for (int i=len-1;i>=0;i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

string intostr(int num) {
    std::ostringstream ss;
    ss << num;
   return ss.str();
}
