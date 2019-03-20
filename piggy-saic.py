import cv2

from capture import Capture
from face import Face

if __name__ == '__main__':
    capture = Capture(0)

    print('Width', capture.width)
    print('Height', capture.height)
    print('FPS', capture.fps)

    face = Face()

    piggy = cv2.imread('piggy.png', cv2.IMREAD_UNCHANGED)
    rows, cols, channels = piggy.shape

    cv2.namedWindow('Camera', cv2.WINDOW_AUTOSIZE)

    while True:
        frame = capture.frame()
        # face location
        locations = face.locations(frame)
        # replace face to piggy
        if len(locations) > 0:
            x, y, w, h = locations[0]

            small = cv2.resize(piggy, (0, 0), fx=h / rows, fy=h / rows)
            r, c, _ = small.shape

            start_x = (w - c) // 2

            for i in range(r):
                for j in range(c):
                    if small[i, j][3] != 0:
                        for k in range(3):
                            frame[x + start_x + i, y + j][k] = small[i, j][k]

            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 1)

        cv2.imshow('Camera', frame)
        if cv2.waitKey(33) & 0xFF == ord('q'):
            break

    cv2.destroyAllWindows()
