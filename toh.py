def TOH(n,src,dst,tmp):
    if(n==1):
        print("Move disk ",n,"from ",src," to ",dst)
    else:
        TOH(n-1,src,tmp,dst)
        print("Move disk ",n,"from" ,src," to ",dst)
        TOH(n-1,tmp,dst,src)

n = int(input("Enter number of discs "))
TOH(n,'A','C','B')