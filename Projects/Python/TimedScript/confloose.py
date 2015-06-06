#! /usr/bin/python3

from time import sleep
import signal, os, atexit, subprocess, shutil

def main():
    # TODO Reopen a shell when the current one gets closed
    while True:
        subprocess.call('python3 confloose.py; bash', shell=True)
        sleep(10)

if __name__ == "__main__":
    while True:
        try:
            main()
        except:
            print('Nop')
