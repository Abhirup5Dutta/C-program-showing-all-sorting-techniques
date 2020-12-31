#include<stdio.h>
#include<stdlib.h>
void heaper(int arr[], int n, int i)
{
	int swap,largest = i,l = 2 * i + 1,r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
	largest = l;
	if (r < n && arr[r] > arr[largest])
	largest = r;
	if (largest != i) 
	{
		swap = arr[i];
		arr[i] = arr[largest];
		arr[largest] = swap;
		heaper(arr, n, largest);
	}
}
void heapify(int arr[], int n, int i)
{
	int swap,smallest = i,l = 2 * i + 1,r = 2 * i + 2;
	if (l < n && arr[l] < arr[smallest])
	smallest = l;
	if (r < n && arr[r] < arr[smallest])
	smallest = r;
	if (smallest != i) 
	{
		swap = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = swap;
		heaper(arr, n, smallest);
	}
}
void heapascendsort(int arr[],int num)
{
	int i,temp,n=num;
	for (i = n / 2 - 1; i >= 0; i--)
	heaper(arr, n, i);
	for (i = n - 1; i > 0; i--) {
		temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heaper(arr, i, 0);
    }   
}
void heapdescendsort(int arr[],int num)
{
	int i,temp,n=num;
	for (i = n / 2 - 1; i >= 0; i--)
	heapify(arr, n, i);
	for (i = n - 1; i > 0; i--) {
		temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }   
}
int getMax(int arr[], int n) 
{
	int i,mx = arr[0]; 
	for (i = 1; i < n; i++) 
	if (arr[i] > mx) 
	mx = arr[i]; 
	return mx;  
}  
void countSort(int arr[], int n, int exp)
{
	int i,output[100],count[10]={0};
	for (i = 0; i < n; i++) 
	count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++) 
	count[i] += count[i-1];
	for (i = n - 1; i >= 0; i--) { 
	output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
	count[(arr[i] / exp) % 10]--; 
	}
	for (i = 0; i < n; i++) 
	arr[i] = output[i];
}
void countdesSort(int arr[], int n, int exp)
{
	int i,output[100],count[10]={0};
	for (i = 0; i < n; i++) 
	count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++) 
	count[i] += count[i-1];
	for (i = n - 1; i >= 0; i--) { 
	output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
	count[(arr[i] / exp) % 10]--; 
	}
	for (i = 0; i < n; i++) 
	arr[n-1-i] = output[i];
}
void radixascendsort(int arr[], int n)
{
	int exp,m = getMax(arr, n);
	for (exp = 1; m / exp > 0; exp *= 10) 
	countSort(arr, n, exp);
}
void radixdescendsort(int arr[], int n)
{
	int exp,m = getMax(arr, n);
	for (exp = 1; m / exp > 0; exp *= 10) 
	countdesSort(arr, n, exp);
}
void merge(int a[], int f, int mid, int l)
{
	int i=f,j=mid+1,ind=f,t[100],k=f;
	while(i<=mid && j<=l)
	{
		if(a[i]<a[j])
		t[ind++]=a[i++];
		else if(a[i]>a[j])
		t[ind++]=a[j++];
		else
		{
			t[ind++]=a[i++];
			t[ind++]=a[j++];
		}
	}
	if(i>mid)
	{
		while(j<=l)
		t[ind++]=a[j++];
	}
	else
	{
		while(i<=mid)
		t[ind++]=a[i++];
	}
	while(k<ind)
	a[k]=t[k++];
}
void mergeascendsort(int a[], int f, int l)
{
	int mid;
	if(f<l)
	{
		mid=(f+l)/2;
		mergeascendsort(a,f,mid);
		mergeascendsort(a,mid+1,l);
		merge(a,f,mid,l);
	}
}
void mergedes(int a[], int f, int mid, int l)
{
	int i=f,j=mid+1,ind=f,t[100],k=f;
	while(i<=mid && j<=l)
	{
		if(a[i]>a[j])
		t[ind++]=a[i++];
		else if(a[i]<a[j])
		t[ind++]=a[j++];
		else
		{
			t[ind++]=a[i++];
			t[ind++]=a[j++];
		}
	}
	if(i>mid)
	{
		while(j<=l)
		t[ind++]=a[j++];
	}
	else
	{
		while(i<=mid)
		t[ind++]=a[i++];
	}
	while(k<ind)
	a[k]=t[k++];
}
void mergedescendsort(int a[], int f, int l)
{
	int mid;
	if(f<l)
	{
		mid=(f+l)/2;
		mergedescendsort(a,f,mid);
		mergedescendsort(a,mid+1,l);
		mergedes(a,f,mid,l);
	}
}
void quickascendsort(int a[], int f, int l)
{
	int i,j,pivot,t;
	if(f<l)
	{
		i=f;
		j=l;
		pivot=a[f];
		while(i<j)
		{
			while(i<=j && pivot>=a[i])
			 i++;
			 
			while(pivot<a[j])
			 j--;
			 
			if(i<j)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		t=a[j];
		a[j]=a[f];
		a[f]=t;
		quickascendsort(a,f,j-1);
		quickascendsort(a,j+1,l);
	}
}
void quickdescendsort(int a[], int f, int l)
{
	int i,j,pivot,t;
	if(f<l)
	{
		i=f;
		j=l;
		pivot=a[f];
		while(i<j)
		{
			while(i<=j && pivot<=a[i])
			 i++;
			 
			while(pivot>a[j])
			 j--;
			 
			if(i<j)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		t=a[j];
		a[j]=a[f];
		a[f]=t;
		quickdescendsort(a,f,j-1);
		quickdescendsort(a,j+1,l);
	}
}
void selectascendsort(int a[], int n)
{
	int i,j,temp,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			min=j;
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
}
void selectdescendsort(int a[], int n)
{
	int i,j,temp,max;
	for(i=0;i<n-1;i++)
	{
		max=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[max])
			max=j;
		}
		temp=a[max];
		a[max]=a[i];
		a[i]=temp;
	}
}
void bubbleascendsort(int a[],int N)
{
	int i,j,temp;
	for(i=0;i<N-1;i++)
	{
		for(j=0;j<N-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void bubbledescendsort(int a[],int N)
{
	int i,j,temp;
	for(i=0;i<N-1;i++)
	{
		for(j=0;j<N-1-i;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void insertascendsort(int arr[],int N)
{
	int i,j,temp;
	for(i=1;i<=N-1;i++)
	{
		temp=arr[i];
		j=i-1;
		while(temp<arr[j] && j>=0)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}
void insertdescendsort(int arr[],int N)
{
	int i,j,temp;
	for(i=1;i<=N-1;i++)
	{
		temp=arr[i];
		j=i-1;
		while(temp>arr[j] && j>=0)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}
void display(int arr[],int size)
{
	int i;
	printf("\nArray : ");
	for(i=0;i<size;i++)
	printf("%d ",arr[i]);
}
int main(){
	int i,n,a[100],ch;
	printf("Enter number of elements to be entered in array : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the number : ");
		scanf("%d",&a[i]);
	}
	display(a,n);
	while(1)
	{
		printf("\n\n1.To sort array in ascending order using bubble sort.");
		printf("\n2.To sort array in descending order using bubble sort.");
		printf("\n3.To sort array in ascending order using insertion sort.");
		printf("\n4.To sort array in descending order using insertion sort.");
		printf("\n5.To sort array in ascending order using selection sort.");
		printf("\n6.To sort array in descending order using selection sort.");
		printf("\n7.To sort array in ascending order using quick sort.");
		printf("\n8.To sort array in descending order using quick sort.");
		printf("\n9.To sort array in ascending order using merge sort.");
		printf("\n10.To sort array in descending order using merge sort.");
		printf("\n11.To sort array in ascending order using radix sort.");
		printf("\n12.To sort array in descending order using radix sort.");
		printf("\n13.To sort array in ascending order using heap sort.");
		printf("\n14.To sort array in descending order using heap sort.");
		printf("\n15.To exit.");
		printf("\n\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				bubbleascendsort(a,n);
				display(a,n);	
				break;
				
			case 2:
				bubbledescendsort(a,n);
				display(a,n);
				break;
				
			case 3:
				insertascendsort(a,n);
				display(a,n);
				break;
				
			case 4:
				insertdescendsort(a,n);
				display(a,n);
				break;
			
			case 5:
				selectascendsort(a,n);
				display(a,n);
				break;
				
			case 6:
				selectdescendsort(a,n);
				display(a,n);
				break;
				
			case 7:
				quickascendsort(a,0,n-1);
				display(a,n);
				break;
			
			case 8:
				quickdescendsort(a,0,n-1);
				display(a,n);
				break;
				
			case 9:
				mergeascendsort(a,0,n-1);
				display(a,n);
				break;
				
			case 10:
				mergedescendsort(a,0,n-1);
				display(a,n);
				break;
				
			case 11:
				radixascendsort(a, n);
				display(a,n);
				break;
				
			case 12:
				radixdescendsort(a, n);
				display(a,n);
				break;
				
			case 13:
				heapascendsort(a, n);
				display(a,n);
				break;
				
			case 14:
				heapdescendsort(a, n);
				display(a,n);
				break;
				
			case 15:
			exit(1);
				
			default:
				printf("\nWrong Choice!");
		}		
	}
	return 0;
}
