#! /usr/bin/env python3

# Print unicode characters
def main():
    try:
        for i in range(256):
            print(chr(i), end='')
    except:
        print()
        exit(0)

if __name__ == '__main__':
    main()
