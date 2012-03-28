
#this script is used for changing filename in large batch
import os
import sys
#fisrt set the work directory
work_dir = raw_input("input your work dir:")
os.chdir(work_dir)

#it only supports removing some prefix in filename
#then  set the prefix you wanto to remove
if sys.argv[1] == "-d":
    rm_str = raw_input("input the string you want to remove:")
    for filename in os.listdir(work_dir):
        if os.path.isfile(filename):
            old = filename
            new = filename.lstrip(rm_str)
            if old != new:
                os.rename(old, new)
#rename all the files by name 1,2,3...
elif sys.argv[1] == "-l":
    for filename in os.listdir(work_dir):
        if os.path.isfile(filename):
            old = filename
            new = "prefix"+filename
            os.rename(old, new)
    cnt = 0
    for filename in os.listdir(work_dir):
        if os.path.isfile(filename):
            old = filename
            new = str(cnt) + os.path.splitext(old)[1]
            cnt += 1
            os.rename(old, new)
        


