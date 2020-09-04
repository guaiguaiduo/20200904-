using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#define random(a,b) (rand()%(b-a+1))+a
//���ȫ�ֱ���
int time=0;
int samount,bwamount,bamount; //ȥ��¼��ǰ��Ȧ�����������
int saleamount,sumprice;
int alldate[13];
int allweight[16];
int allspiece[4];
struct pig{
	int spiece=0;//spiece=1Ϊ����spiece=2��С����spiece=3�Ǵ���
	double weight=0;
	int days=0;
	pig *next=NULL; 
};
class pigcircle{
	private:
		int sum;//��¼��Ȧ�������
		pig *head;//һ����Ȧ�������ͷָ��
		int ifblack; //����Ǻ���Ȧ��ifblack=1
		int number;
	public:
		pigcircle();
		double searchweight(int i);
		int searchdate(int i);
		int searchspiece(int i);
		int pigcirclestatistics();
		void uppig() ;
	    void  sale();
	    int insert(pig *p);
		int initialaddpig(pig *p);
		int getnumber();
		int getsum();
		pig *gethead();
		void sendnumber(int i);
};
pigcircle::pigcircle()
{
	sum=0;
	head=NULL;
	ifblack=0;//δ��ע�Ǻ�����ֵĬ��Ϊ0 
}
//
int pigcircle::getsum()
{
	return sum;
 } 
int pigcircle::getnumber()
{
	return number;
}
pig* pigcircle::gethead()
{
	return head;
}
void pigcircle::sendnumber(int i)
{
	number=i;
}
int pigcircle::searchspiece(int i)
{
	int j=0;
	pig *p=head;
	if(p==NULL) return -1;
	for(;j<i&&p!=NULL;j++)
	p=p->next ;
	if(p==NULL)
	return -1;//-1��ʾ�������ų�������Ȧ���������
	else
	return p->spiece;
}
int pigcircle::searchdate(int i)
{
	int j=0;
	pig *p=head;
	if(p==NULL) return -1;
	for(;j<i&&p!=NULL;j++)
	p=p->next;
	if(p==NULL)
	return -1;//ͬ��
	else
	return p->days;
}
double pigcircle::searchweight(int i)
{
	int j=0;
	pig *p=head;
	if(p==NULL) return -1;
	for(;j<i&&p!=0;j++)
	p=p->next;
	if(p==NULL)
	return -1;//ͬ��
	else
	return p->weight; 
}
int pigcircle::pigcirclestatistics()
{
	int j;
	pig *p=head;
	samount=bwamount=bamount=0;
	if(ifblack==1)
	{
		bamount=sum;
		return 1;
	}
	else 
	{
		while(p!=NULL)
		{
			if(p->spiece==2)
			samount+=1;
			else
			bwamount+=1;
			p=p->next;
		}
		return 2;
	}
}
 //����������У�������ͳ��һ����Ȧ�����Ʒ�ֺ�������
 //���õ����������ݽ�������ȫ�ֱ����У������ز�ͬ�Ķ�Ӧֵ 
void pigcircle::uppig()
{
	pig *p=head;
	while(p!=NULL)
	{
		p->weight=((double)random(0,12))/10;
		p->days+=1;
		p=p->next;
	}
 }//���Ϊ���Ӻ�����Ŀ�����ڸı䵱ǰ��Ȧÿһֻ�������������
void pigcircle::sale()
 {
 	pig *p=head,*p1;
 	while(p!=NULL)
 	{
 		if(p->weight>75||p->days>360)
 		{
 		  if(p->spiece==1)
		   	sumprice+=p->weight*15;
		   else if(p->spiece==2)
		   sumprice+=p->weight*7;
		   else
		   sumprice+=p->weight*6;
		   p1->next=p->next;
		   p=p->next;
		   delete p;
		   saleamount++;
		}
		 p1=p;
		 p=p->next;
	 }
 }
  //������������棬��������¼��Ȧ�����ֵ���٣���ʵ�ֳ�Ȧ�����������ɾ����
void saleall(pigcircle pc[])
{
	int i;
	saleamount=sumprice=0;
	for(i=1;i<=100;i++)
	p[i].sale();
	ofstream destFile("buyandsale",ios::app);
	destFile<<"sale"<<endl<<time<<' '<<saleamount<<' '<<sumprice<<endl;
	destFile.close();
}
int pigcircle::insert(pig *p)
{
	if(sum==10) return 0;//������ԭ���Ļ����ϲ�������
	if(ifblack!=p->spiece) return 0;//ͬ��
	if(p==NULL)
	head=p;
	else
	{
		p->next=head;
		head=p;
	}
	return 1;//����ɹ� 
}
void initialnumber(pigcircle pc[])
{
	int i;
	for(i=1;i<=100;i++)
	{
		pc[i].sendnumber(i);
	}
}
void initial(pigcircle pc[])
{
	int count=200,i,pg1,pg2,t,sum,c,j;
	pig *p,*p1;
	pig pp;
	vector<pig> vb;
	vector<pig> ve;
	while(count--)
{
	p=new pig;
	p->spiece=random(1,3);
	p->weight=random(20,50);
	p->days=0;
	pp=*p;
	if(p->spiece==1)
	vb.push_back(pp);
	else
	ve.push_back(pp);
}
    sum=vb.size();
    j=0;
    for(c=1;c<=100;c++)
    {
    	p1=pc[c].gethead();
    	for(i=1;i<=2&&j<=sum;i++)
    	{
    		if(i==1)
    		p1=*vb[j];
    		else
    		{
    			p1->next=*vb[j];
    			p1=p1->next;
			}
			j++;
			if(j==sum&&c==100)
			{
				p1->next=*vb[j];
    			p1=p1->next;
    			break;
			}
		}
	}
    sum=ve.size();
    j=0;
    for(;c<=100;c++)
    {
    	p1=pc[c].gethead();
    	for(i=1;i<=t&&j<=sum;i++)
    	{
    		if(i==1)
    		p1=*ve[j];
    		else
    		{
    			p1->next=*ve[j];
    			p1=p1->next;
			}
			j++;
			if(j==sum&&c==100)
			{
				p1->next=*ve[j];
				p1=p1->next;
				break;
			}
		}
	}
}
void outFile(pigcircle pc[])
{
	ofstream destFile("pigsmessage",ios::out);
	int i,j,sum;
	pig *p,*p1; 
	for(i=1;i<=100;i++)
	{
		p=pc[i].gethead();
		sum=pc[i].getsum();
		destFile<<pc[i].getnumber()<<endl;
		for(j=1;j<=sum;j++)
		{
			destFile<<p->spiece<<' '<<p->weight<<' '<<p->days<<endl;
			p1=p;
			p=p->next; 
			delete p1;
		}
	}
	 destFile.close();
}
void inFile(pigcircle pc[])
{
	ifstream srcFile("pigsmessage",ios::in);
	pig *p,*p1;
	int i,j,sum,t;
	for(i=1;i<=100;i++)
	{
		sum=pc[i].getsum();
		srcFile>>t;
		pc[i].sendnumber(t);
		for(j=1;j<=sum;j++)
		{
			p1=new pig;
			srcFile>>p1->spiece>>p1->weight>>p1->days;
			if(j==1) p=p1;
			else
			{
				p->next=p1;
				p=p1;
			}
		}
	}
	srcFile.close();
}
void allmember(pigcircle pc[])
{
	int i,sum,j,t;
	for(i=1;i<=100;i++)
	{
		sum=pc[i].getsum();
		for(j=1;j<=sum;j++)
		{
			allspiece[pc[i].searchspiece(j)]++;
			alldate[pc[i].searchdate(j)/30]++;
			allweight[int(pc[i].searchweight(j)/10.0)]++;
		}
	}
}
void buypigs(pigcircle pc[],int bp,int wp,int sp)
{
	
}
int main()
{
	pigcircle pc[101];
	initialnumber(pc);
	initial(pc);
	inFile(pc);
	outFile(pc);
 } 
