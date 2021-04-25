"""
Solution/Algorithm By Ayush Chaudhari
"""

test_cases=int(input())

for i in range(test_cases):
 output=99999999999999999999
 x,y=input().split()
 int_x=int(x)
 int_y=int(y)
 till=int_x;
 if(int_y<int_x):
    till=int_y
 #itr=0
 for i in range(till,0,-1):
    # print(i)
    bitwise_xor=(int_x ^ i)+(int_y ^ i)
    if(output>bitwise_xor):
        #itr=i
        output=bitwise_xor
 if(output==99999999999999999999):
   print("0")
 else:
   print(output)
   