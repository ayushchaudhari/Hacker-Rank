"""
Solution By Ayush Chaudhari
Solution For Problem Fora and Laura
"""

def apply_query(arr,query):
    arr[query[0]-1]*=query[1];
    return arr;
  
def get_gcd(a, b):
    while(b):
        a , b = b , a % b
    return a
    
if __name__=="__main__":
    lengthNquery=[int(x) for x in input().split()]
    arr=[int(x) for x in input().split()]
    for i in range(lengthNquery[1]):
        query=[int(x) for x in input().split()]
        
        arr=apply_query(arr,query)
        #print(arr)
        gcd=get_gcd(arr[0],arr[1])
        for i in range(2,len(arr)):
            gcd=get_gcd(gcd,arr[i])
        print(gcd % (10**9+7))