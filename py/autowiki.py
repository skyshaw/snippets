import os
import re

def get_item_lists(filename):
#    file_ = open(filename, "r")
#    item_list = []
#    while True:
#        line = file_.readline()
#        if not line:
#            break
#        title = re.match(r'#\s+\[\[\./(.+)\|.+\]\]', line)
#        if title is not None:
#            item_list.append(title.group(1))
#    file_.close()
#    return item_list

    #It's safe, __exit__ of file object will close the file
    with open(filename, "r") as f: 
        item_list = []
        for line in f:
            title = re.match(r'#\s+\[\[\./(.+)\|.+\]\]', line)
            if title is not None:
                item_list.append(title.group(1))
    return item_list


def add_links():
    item_list = get_item_lists("index.wiki")
    index_page = open("index.wiki", 'a')
    for item in os.listdir("."):
        if (os.path.isfile(item)) and (item != "index.wiki") and \
            (item.endswith(".wiki")) and (item[:-5] not in item_list):
            file_ = open(item, 'r')
            line = file_.readline()
            title = re.match(r'=+\s*([^=\s]+)\s*=+', line)
            if title is None:
                continue
            print title.group(1)
            index_page.write('# [[./' + item[:-5] + '|'
                             + title.group(1) + ']]\n')
            file_.close()
    index_page.close()

if __name__ == "__main__":
    add_links()
