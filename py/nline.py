import os
import sys


def count_lines(filename):  #abs path
    file_ = open(filename, 'r')
    num = len(file_.readlines())
    #print filename, num
    file_.close()
    return num
    
def traversal(dirname):  #abs path
    res = 0
    if os.path.isdir(dirname):
        for subdir in os.listdir(dirname):
            res += traversal(os.path.join(dirname, subdir))
    else:
        res = count_lines(dirname)
    return res

if __name__ == "__main__":
    PROMPT, ROOT = "%d lines in %s", os.getcwd()
    if len(sys.argv) == 2:
        if not os.path.isabs(sys.argv[1]):
            ROOT = os.path.join(os.getcwd(), sys.argv[1])
    elif len(sys.argv) > 2:
        print 'format error, input directory name or file anme'
    print PROMPT % (traversal(ROOT), ROOT)
