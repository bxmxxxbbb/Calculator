#include<bits/stdc++.h>
using namespace std;

stack <char> sCh; //���ڴ�ŷ��ŵķ���ջ
stack <double> sNum;//���ڴ�����ݵ�����ջ
char num[105];
char str1[105];

void cal_1()//���ܼӼ��˳���ѭ�������ر�����
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
        sNum.push(n2);//���µĽ����ջ
        sCh.pop();//ɾ���ù��ķ���
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
    sCh.push('(');//�ֽ�������ȼ�����������ջ
    for(int i=0; str1[i]; ++i){
        if(str1[i]>='0' && str1[i]<='9' || str1[i]=='.'){
            num[k++]=str1[i];
            continue;
        }
        num[k]=0;//��β�������ĸ����atof������ȡ���� ע�����������0�浽����������ĸ��a���������Ϊ������־
        if(num[0]!=0){
            n=atof(num);
            num[0]=0;
            sNum.push(n);
        }
        k=0; //�±����
        switch(str1[i]){  //�õ��˺�ǿ���߼�
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
