#! /usr/bin/env python3

import sys
import subprocess

RED = '\033[91m'
GREEN = '\033[92m'
END = '\033[0m'

def test(host):
    retcode = subprocess.call('ping -c 1 ' + host, shell=True)
    if retcode == 0:
        print(GREEN + '[PASS] ' + host + END)
    else:
        print(RED + '[FAIL] ' + host + END)

def main():
    for arg in sys.argv:
        if len(sys.argv) < 2:
            print('Usage: ./testserver.py file [files...]\n')
            exit(1)
        if arg != sys.argv[0]:
            try:
                print('Opening file ' + arg + '...', end="")
                with open(arg) as f:
                    print('OK')
                    for l in f:
                        test(l)
            except:
                print("\ntestserver: could not open the requested file")
                continue

if __name__ == "__main__":
    main()
