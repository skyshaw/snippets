import os
import sys


def count_lines(filename):#abs path
    f = open(filename, 'r')
    num = len(f.readlines())
    #print filename, num
    f.close()
    return num
    

def traversal(dirname):#abs path
    res = 0
    if os.path.isdir(dirname):
        for p in os.listdir(dirname):
            res += traversal(os.path.join(dirname, p))
    else:
        res = count_lines(dirname)
    return res


if __name__ == "__main__":
    string, name = "%d lines in %s", os.getcwd()
    if len(sys.argv) == 2:
        if not os.path.isabs(sys.argv[1]):
            name = os.path.join(os.getcwd(), sys.argv[1])
    elif len(sys.argv) > 2:
        print 'format error, input directory name or file anme'
    print string %(traversal(name), name)
