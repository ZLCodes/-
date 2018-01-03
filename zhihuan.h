#include<iostream>
using namespace std;
#include<CString>
CString s,s1;
int count;
struct pageInfo
{
	int timer;//���ʱ��
	int No;//ҳ����
};
void blockInit(pageInfo* p,int bsize);//������ʼ������
void show(pageInfo*,int);//�������ʾ����
void FIFO(pageInfo*,int *,int,int);//FIFO�㷨,����Ϊ����飬ҳ�洮�����������ҳ����
int findExist(pageInfo*,int,int);//����ҳ���Ƿ��Ѿ������ڴ��У�����Ϊ����飬������ҳ���
void LRU(pageInfo*,int *,int,int);//LRU�㷨,����Ϊ����飬ҳ�洮�����������ҳ����
int findMax(pageInfo*,int);//�ҳ�����ʱ����õ�ҳ��
int findFuture(pageInfo*,int *,int,int,int);//����Ϊ����飬ҳ�洮�����������ҳ����,��ǰ����ҳ���±꣬�ҵ�����������δʹ�õ�ҳ���
void Optimal(pageInfo*,int *,int,int);//Optimal�㷨,����Ϊ����飬ҳ�洮�����������ҳ����
void blockInit(pageInfo* p,int bsize)
{
	int i;
	for(i=0;i<bsize;i++)//������ʼ��
	{
		p[i].No=-1;//��ų�ʼ��Ϊ-1
		p[i].timer=0;//���ʱ������Ϊ0
	}
}
void show(pageInfo* p,int bsize,bool b)//����������Ϣ
{
	int i;
	for(i=0;i<bsize;i++)
	{
		if(p[i].No!=-1)
		{
			char te = p[i].No+'0';
			s= s + te;
			s=s+" ";
		}
	}
	if(b)
		s=s+"\r\n";
}
int findExist(pageInfo* p,int bsize,int temp)//���ڷ����±꣬�����ڷ���-1
{
	int i;
	for(i=0;i<bsize;i++)
		if(p[i].No==temp)
			return i;
	return -1;

}
void FIFO(pageInfo* p,int *q,int bsize,int psize)
{
	count = 0;
	int i,j,max=0;
	int temp=0,t;
	int behind=0;// = bsize;//���ѭ������β�ڵ�
	int front=0;
	for(i=0;i<psize;i++)
	{
		if(findExist(p,bsize,q[i])==-1)
		{	
			temp=0;
			char ch;
			if(i<bsize)
			{
				p[i].No=q[i];
				p[i].timer++;
				behind++;
				show(p,bsize,true);
			}
			else
			{
				
				behind %= bsize;
				ch = p[front].No + '0';
				p[behind].No = q[i];
				p[behind].timer++;
				show(p,bsize,false);
				behind++;
				s = s+"  "+ch;
				ch = q[i]+'0';
				s = s+"��"+ch+"�滻\r\n";
				count++;
				//if(front!=0)
					front=(front+1)%bsize;
			//	else
				//front = 0;
				//
			}


			//char ch;
			//ch = p[behind].No + '0';
			/*behind = behind%bsize;
			p[behind].No=q[i];
			temp=p[0].No;
			ch = p[0].No + '0';
			behind++;
			//if(i<bsize)
				show(p,bsize,true);
		/*	else
				show(p,bsize,false);
			if(i>=bsize&&behind==bsize)
			{
				ch = p[0].No + '0';
				ch = temp + '0';
				s = s+"  "+ch;
				ch = q[i]+'0';
				s = s+"��"+ch+"�滻\r\n";
				count++;

			}*/
		}
		else
		{
			s=s+"��ȱҳ\r\n";
			for(j=0;j<bsize;j++)
			{
				p[i].timer++;
				if(max<p[i].timer)
					max=p[i].timer;
			}
			for(j=0;j<bsize;j++)
			{
				if(max==p[i].timer)
					front=i;
			}
		}
	}

	blockInit(p,bsize);//���������г�ʼ����������ֹӰ�������㷨

}
int findMax(pageInfo* p,int bsize)
{
	int max,i,temp = 0;
	for(i=0;i<bsize;i++)
	{
		if(p[i].timer>temp)
		{
			temp=p[i].timer;
			max=i;

		}
	}
	return max;
}
void LRU(pageInfo* p,int* q,int bsize,int psize)
{
	count = 0;
	int i,j;
	for(i=0;i<psize;i++)
	{
		if(i<bsize)
		{
			p[i].No = q[i];
			for(j=0;j<=i;j++)
				p[j].timer++;
			show(p,bsize,true);
		}
		else
		{
			int max = findExist(p,bsize,q[i]);
			if(max!=-1)
			{
				p[max].timer=0;
				s=s+"��ȱҳ\r\n";
			}
			else
			{
				max = findMax(p,bsize);
				char ch = p[max].No + '0';
				p[max].timer=0;
				p[max].No=q[i];
				show(p,bsize,false);
				s = s+ "   "+ch;
				ch = p[max].No + '0';
				s=s+"��"+ch+"�滻\r\n";
				count++;
			}
			for(j=0;j<=bsize;j++)
				p[j].timer++;
		}

	}
	blockInit(p,bsize);
}
int find(int* q, int temp, int psize, int k)
{
	int i, t = -1;
	for (i = k; i<psize; i++)
		if (q[i] == temp)
		{
			t = i;
			break;
		}
	return t;
}
//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
int findFuture(pageInfo* p, int* q, int bsize, int psize, int k)
{
	int j, max = 0;
	int temp[20];
	for (j = 0; j<bsize; j++)
	{
		temp[j] = find(q, p[j].No, psize, k);
		if (max < temp[j])
			max = temp[j];
		if (temp[j] == -1)
			return j;
	}
	for (j = 0; j < bsize; j++)
		if (max == temp[j])
		{
			max = j;
			break;
		}

	return max;

}
void Optimal(pageInfo* p,int* q,int bsize,int psize)
{
	count = 0;
	int i;
	for(i=0;i<psize;i++)
	{
		if(i<bsize)
		{
			p[i].No=q[i];
			show(p,bsize,true);
		}
		else
		{
			int max = findExist(p,bsize,q[i]);
			if(max!=-1)
			{
				s=s+"��ȱҳ\r\n";
			}
			else
			{
				 
				max = findFuture(p,q,bsize,psize,i);
				char ch = p[max].No+'0';
				p[max].No=q[i];
				show(p,bsize,false);
				s = s+ "   "+ch;
				ch = p[max].No + '0';
				s=s+"��"+ch+"�滻\r\n";
				count++;
			}
			
		}
	}
	blockInit(p,bsize);
}