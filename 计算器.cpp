#include<bits/stdc++.h>
using namespace std;

stack <char> sCh; //用于存放符号的符号栈
stack <double> sNum;//用于存放数据的数据栈
char num[105];
char str1[105];

void cal_1()//接受加减乘除，循环条件特别巧妙
{
    double n1,n2;
    char ch;
    ch=sCh.top();
    while(ch!='('){
        n1=sNum.top();
        sNum.pop();
        n2=sNum.top();
        sNum.pop();
        switch(ch){
            case '+':
                n2+=n1;
                break;
            case '-':
                n2-=n1;
                break;
            case '*':
                n2*=n1;
                break;
            case '/':
                n2/=n1;
                break;
        }
        sNum.push(n2);//将新的结果入栈
        sCh.pop();//删除用过的符号
        ch=sCh.top();
    }
}

void cal_2()
{
    double n1,n2;
    char ch;
    ch=sCh.top();
    while(ch =='*' || ch =='/'){
        n1=sNum.top();
        sNum.pop();
        n2=sNum.top();
        sNum.pop();
        if(ch == '*'){
            n2*=n1;
        }else if(ch == '/'){
            n2/=n1;
        }
        sNum.push(n2);
        sCh.pop();
        ch=sCh.top();
    }

}
int main()
{
    int k=0;
    double n;
    gets(str1);
    char c[2]="=";
    strcat(str1,c);
    sCh.push('(');//现将最低优先级的左括号入栈
    for(int i=0; str1[i]; ++i){
        if(str1[i]>='0' && str1[i]<='9' || str1[i]=='.'){
            num[k++]=str1[i];
            continue;
        }
        num[k]=0;//在尾部添加字母用于atof函数读取数字 注意这里的数字0存到数组里是字母‘a’可以理解为结束标志
        if(num[0]!=0){
            n=atof(num);
            num[0]=0;
            sNum.push(n);
        }
        k=0; //下标归零
        switch(str1[i]){  //用到了很强的逻辑
            case '+' :
                cal_1();
                sCh.push('+');
                break;
            case '-' :
                cal_1();
                sCh.push('-');
                break;
            case '*' :
                cal_2();
                sCh.push('*');
                break;
            case '/' :
                cal_2();
                sCh.push('/');
                break;
            case '(' :
                sCh.push(str1[i]);
                break;
            case ')' :
                cal_1();
                sCh.pop();
                break;
            case '=' :
                cal_1();
                sCh.pop();
                break;

        }
    }
    printf("%.0lf",sNum.top());
    return 0;
}
