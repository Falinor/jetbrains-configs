#! /usr/bin/python2

import cv2

def main():
    # 0 pour /dev/video0
    cap = cv2.VideoCapture(0)

    while True:
        ret, im = cap.read()

        cv2.imshow('Webcam', im)
        key = cv2.waitKey(40)

if __name__ == "__main__":
    main()
