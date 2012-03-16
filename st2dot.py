#!/usr/bin/python
import sys
'''
typedef [struct|union] name {
    marco1 //
    type1 val1 ; /**/
    macro2
    type2 val2 ;
    macro3
    type3 val3 ;
} name;

[struct|union] name {
    ...
};
'''

def remove_comment(string):
    '''simple remove'''
    pos = string.find('//')
    if pos != -1:
        string = string[:pos]
    while True:
        s = string.find('/*')
        e = string.find('*/')
        if s == -1:
            break
        string = string[:s] + string[e + 2:]
    return string


def st2dot(lines):
    for i in range(len(lines)):
        lines[i] = remove_comment(lines[i]).strip()
    begin, end = lines[0], lines[-1]
    pos = begin.find('typedef')
    if pos == -1:
        header = begin.rstrip('{').strip()
    else:
        header = begin[pos + len('typedef'):].strip('{').strip()

    end = end.lstrip('}').rstrip(';').strip()
    if end:
        header = end + '(' + header + ')'
    label = '"' + header + ' |'
    cnt = 0
    for line in lines[1:-1]:
        line = line.strip(';').strip('{').strip('')
        if line:
            label += ' f<%d> %s\\l |' % (cnt, line)
            cnt += 1
    return label + '"'
    

if __name__ == "__main__":
   print st2dot(sys.stdin.readlines()) 
