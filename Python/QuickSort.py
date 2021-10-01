import random
import time

def quick(arr,l,r):
   if(l<r):
       pivot=median(arr,l,r)
       i=l
       j=r-2
       while(True):
           while(arr[i]<pivot):
               i+=1
           while(arr[j]>pivot):
               j-=1
           if(i<j):
               t=arr[i]
               arr[i]=arr[j]
               arr[j]=t
           else:
               break
       t=arr[i]
       arr[i]=arr[r-1]
       arr[r-1]=t
       quick(arr,l,i-1)
       quick(arr,i+1,r)

def median(arr,l,r):
    mid=(l+r)//2
    if(arr[l]>arr[mid]):
        t=arr[l]
        arr[l]=arr[mid]
        arr[mid]=t
    if(arr[l]>arr[r]):
        t=arr[l]
        arr[l]=arr[r]
        arr[r]=t
    if(arr[mid]>arr[r]):
        t=arr[mid]
        arr[mid]=arr[r]
        arr[r]=t
    t=arr[mid]
    arr[mid]=arr[r-1]
    arr[r-1]=t
    return arr[r-1]

time1=time.time()
arr=[]
f=open("Quicksort1.txt","a")
for i in range(0,1000):
    arr.insert(i,i)
random.shuffle(arr)
l=0
r=999
print("Unsorted Array: ")
print(arr)
f.write(str(arr))
quick(arr,l,r)
print("Sorted Array: ")
print(arr)
f.write("\n\n\n"+str(arr))
time2=time.time()
time2-time1
print("Execution Time is: "+str(time2-time1)+"sec")
f.write("\n\n\nExecution Time is: "+str(time2-time1)+"sec")
f.close()

