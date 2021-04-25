"""
Solution By Ayush Chaudhari
Solution For Problem Morty has a exam
"""

def swap(arr,index1,index2):
    arr[index1],arr[index2]=arr[index2],arr[index1]
    return arr


def check_already_sorted(input_list):
    if(input_list==sorted(input_list)):
        return 0
    else:
        return 1

def swapping_operation1(length_arr,arr):#swapping adjacent element{m0->m1,m2->m3,m4->m5......}
    for i in range(0,length_arr//2):
            arr=swap(arr,i,i+length_arr//2)
    return arr

def swapping_operation2(length_arr,arr):
    for i in range(0,length_arr,2):
        arr=swap(arr,i,i+1)
    return arr 

def calc_minimal_operation1(arr):
    ops1=0
    length_arr=len(arr)
    
    while ops1<length_arr:
        arr=swapping_operation1(length_arr,arr)
        ops1+=1
        if check_already_sorted(arr) == 0:
            return ops1
            
        arr=swapping_operation2(length_arr,arr)
        ops1+=1
        if check_already_sorted(arr) == 0:
            return ops1
            
    if(ops1>length_arr-1):
        return -1
    
def calc_minimal_operation2(arr_copy):
    ops2=0
    length_arr=len(arr_copy)
    while ops2<length_arr:
        arr_copy=swapping_operation2(length_arr,arr_copy)
        ops2+=1
        if check_already_sorted(arr_copy) == 0:
            return ops2
            
        arr_copy=swapping_operation1(length_arr,arr_copy)
        ops2+=1
        if check_already_sorted(arr_copy) == 0:
            return ops2
    
    if(ops2>length_arr-1):
        return -1
    
if __name__=='__main__':
    num=int(input())
    lst=[int(n) for n in input().split()]
    # print(lst)
    lst_copy=[]
    # lst_copy=lst
    for ele in lst:
        lst_copy.append(ele)
        
    if(check_already_sorted(lst)==0):
       print(0)
    else:
        ops1=calc_minimal_operation1(lst)
        ops2=calc_minimal_operation2(lst_copy)

        if(ops1==-1 and ops2==-1):
            print(-1)
        elif(ops1==-1 and ops2!=-1):
            print(ops2)
        elif(ops1!=-1 and ops2==-1):
            print(ops1)
        else:
            print(min(ops1,ops2))