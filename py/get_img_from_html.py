#-*- coding:utf-8 -*-
import urllib2
import sys
import re
import urllib

def get_page(url):
    try:
        file_handle = urllib2.urlopen(url)
        string = file_handle.read()
        file_handle.close()
    except IOError:
        print 'Cannot open URL %s for reading' % url
        string = ''
    return string

def get_file_name(url):
    return url[url.rfind('/') + 1:]

def get_extension_name(url):
    return url[url.rfind('.'):]

def get_images(url):
    string = get_page(url)
    regular = r'<img([ ]*)src="(.*?)"(.*)/>'
    links = re.findall(regular, string)
    num = 0
    for img_link in links:
        try:
            urllib.urlretrieve(
                img_link[1], str(num) + get_extension_name(img_link[1]))
            print  "%s --> %s finished" % (
                img_link[1], str(num) + get_extension_name(img_link[1]))
            num += 1
        except IOError:
            print "%s download failed" % img_link[1]

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print 'format error, input an url!'
    else:
        get_images(sys.argv[1])
        
