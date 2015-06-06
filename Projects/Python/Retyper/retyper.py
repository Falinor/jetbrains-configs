#! /usr/bin/python3

import time, sys

def main():
    if len(sys.argv) < 2:
        print('Usage: ./retyper.py FILE')
        exit(1)
    for arg in sys.argv:
        if str(arg) == str(sys.argv[0]):
            continue
        try:
            with open(arg) as f:
                for l in f:
                    for c in l:
                        sys.stdout.write(c)
                        sys.stdout.flush()
                        time.sleep(0.05)
        except KeyboardInterrupt as e:
            print('\nContinuing to next file!')
            continue
        except:
            print('retyper: no such file or directory')


if __name__ == "__main__":
    main()
