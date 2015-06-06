#! /usr/bin/env python3

### Verify that logins are correct

import re
import sys

GREEN = '\033[92m'
RED = '\033[91m'
END = '\033[0m'

def parse(f):
    pattern = "^\* [a-z0-9]{1,6}_[a-z0-9]$"
    i = 1
    for l in f:
        if re.match(pattern, l):
            print(GREEN + '[PASS] ' + l + END, end="")
        else:
            print(RED + '[FAIL] line #' + str(i) + ' invalid login: ' + l + END, end="")
        i += 1

def main():
    if len(sys.argv) < 2:
        print('logins: need atleast one AUTHORS input file')
        exit(1)
    try:
        for i in range(1, len(sys.argv)):
            arg = sys.argv[i]
            with open(arg) as f:
                print('Reading into file ' + arg + '...')
                parse(f)
        print('Script is now over.')
    except:
        print('logins: error while trying to read')
        exit(2)

if __name__ == "__main__":
    main()
