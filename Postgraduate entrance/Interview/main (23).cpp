
#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef  struct                     
{ KeyType  key;                                             
} ElemType;  

typedef  struct
{ ElemType  *R; 
  int  length;
} SSTable;                      

void  Create(SSTable &T)
{ int i;
  T.R=new ElemType[MAXSIZE+1];
  cin>>T.length;
  for(i=1;i<=T.length;i++)
     cin>>T.R[i].key;   
}

int  Search_Bin(SSTable T, KeyType k);

int main () 
{  SSTable T;  KeyType k;
   Create(T);
   cin>>k;
   int pos=Search_Bin(T,k);
   if(pos==0) cout<<"NOT FOUND"<<endl;
   else cout<<pos<<endl;
   return 0;
}

/* ����������д�� */
int  Search_Bin(SSTable T, KeyType k){

	int low_num = 1;
	int hig_num = T.length;
	int mid =low_num;

	if(k==T.R[hig_num].key){
			return T.R[hig_num].key;
		}
	if(k==T.R[low_num].key){
			return T.R[low_num].key;
		}
	if(k<T.R[low_num].key||k>T.R[hig_num].key){
			return 0;
	}	
	while(low_num<hig_num){
		mid =(low_num+hig_num)/2;
		if(T.R[mid].key>k){
			hig_num = mid;
		}
		else
			if(T.R[mid].key<k){
				low_num = mid;
			}
			else{
				return mid;
			}
	}
}
