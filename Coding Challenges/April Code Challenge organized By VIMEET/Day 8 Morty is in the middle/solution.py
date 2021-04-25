"""
Solution By Ayush Chaudhari
Solution For Problem Morty is in the Middle
"""

def generate_pythagorean_triplets(till_this_num) :
    h, m = 0, 2
    vec=[]
    while h < till_this_num :
        for n in range(1, m) :
            p = m * m - n * n
            b = 2 * m * n
            h = m * m + n * n
  
            if h > till_this_num :
                break
            #this checks if the current triplet follow the rule z=x^2-y
            if(h==pow(p,2)-b):
                vec.append([p, b, h])
  
        m = m + 1
    return vec

def find_how_many(num):
    how_many=0
    satisfying_pythagorean_triplets=generate_pythagorean_triplets(num)     
    return len(satisfying_pythagorean_triplets)

if __name__=="__main__":
    test_case=int(input())
    numbers=[]
    for i in range(test_case):
        numbers.append((int)(input().strip()))
    for num in numbers:
        how_many=find_how_many(num)
        print(how_many)