lines=[]
with open("date.in","r") as fileIn:
    lines=fileIn.readlines()
sum=0

# do multithreading on this shit
def do_line(line):
    line=line[:-1]
    mnum=int(0)
    for i in range(2**len(line)):
        if i.bit_count()!=12:continue
        p10=100000000000
        num=0
        for bit in range(len(line)):
            if (2**bit)&i!=0:
                num+=p10*int(line[bit])
                p10//=10
        mnum=max(mnum,num)
    return mnum

for line in lines:
    sum+=do_line(line)

with open("date.out","w") as fileOut:
    fileOut.write(str(sum))