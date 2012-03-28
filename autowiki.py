import os
import re

def get_item_lists(filename):
    f = open(filename, "r")
    item_list = []
    while True:
        line = f.readline()
        if not line:
            break
        m = re.match(r'#\s+\[\[\./(.+)\|.+\]\]', line)
        if m is not None:
            item_list.append(m.group(1))
    f.close()
    return item_list

def add_links():
    item_list = get_item_lists("index.wiki")
    index_page = open("index.wiki", 'a')
    for item in os.listdir("."):
        if (os.path.isfile(item)) and (item != "index.wiki") and \
            (item.endswith(".wiki")) and (item[:-5] not in item_list):
            f = open(item, 'r')
            title = f.readline()
            m = re.match(r'=+([^=]+)=+', title)
            if m is None:
                continue
            print m.group(1)
            index_page.write('# [[./' + item[:-5] + '|' + m.group(1) + ']]\n')
            f.close()
    index_page.close()

if __name__ == "__main__":
    add_links()
