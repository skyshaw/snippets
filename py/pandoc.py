import sys
import subprocess
import os

def main():
    if len(sys.argv) != 2:
        return
    infile = sys.argv[1]
    tmpfile = infile + '.tmp.html'
    extension = infile.split('.')[-1]
    if extension == 'md' or extension == 'markdown':
        destFileType = 'markdown'
    elif extension == 'rst':
        destFileType = 'rst'
    runPandoc = 'pandoc -o {0} -t html -f {1} {2}'.format(tmpfile, destFileType, infile)
    runBrowser = r'C:\Users\skyshaw\AppData\Local\Google\Chrome\Application\chrome.exe {0}'.format(os.path.abspath(tmpfile))
    subprocess.call(runPandoc)
    subprocess.call(runBrowser)
    os.remove(tmpfile)


if __name__ == '__main__':
    main()


    
