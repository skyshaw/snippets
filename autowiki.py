import os
import re

def get_item_lists(index_page):
    item_list = []
    while True:
        line = index_page.readline()
        if not line:
            break
        m = re.match(r'\[\[\./(.+)\.html\|.+\]\]', line)
        item_list.append(m.group(1))
    return item_list

def add_links():
    index_page = open("index.wiki", 'w+')
    item_list = get_item_lists(index_page)
    for item in os.listdir("."):
        if (not os.path.isdir(item)) and (item != "index.wiki") and \
            (item.endswith(".wiki")) and (item[:-5] not in item_list):
            f = open(item, 'r')
            title = f.readline()
            m = re.match(r'=+([^=]+)=+', title)
            print m.group(1)
            index_page.write('# [[./' + item[:-5] + '.html|' + m.group(1) + ']]\n')
            f.close()
    index_page.close()

if __name__ == "__main__":
    add_links()
