import cv2


def draw_piggy(image, piggy_image, face_location, top: bool, side: bool):
    x, y, w, h = face_location
    ratio = h / piggy_image.shape[0] * 0.9
    small = cv2.resize(piggy_image, (0, 0), None, ratio, ratio)
    r, c = small.shape[0], small.shape[1]
    start = (w - c) // 2
    if top:
        for i in range(c):
            for j in range(r):
                if y - r + j >= 0 and small[j, i][3] != 0:
                    for k in range(3):
                        image[y - r + j, x + start + i][k] = small[j, i][k]
    if side:
        for i in range(c):
            for j in range(r):
                if small[j, i][3] != 0:
                    if x + 0.9 * w + i < image.shape[1]:
                        for k in range(3):
                            image[y + j, x + int(0.9 * w) + i][k] = small[j, i][k]
                    if x + 0.1 * w - i > 0:
                        for k in range(3):
                            image[y + j, x + w // 10 - i][k] = small[j, i][k]


capture = cv2.VideoCapture(0)
width = int(capture.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(capture.get(cv2.CAP_PROP_FRAME_HEIGHT))

cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

piggy = cv2.imread('piggy.png', cv2.IMREAD_UNCHANGED)

while True:
    if capture.isOpened():
        ret, frame = capture.read()
        if ret:
            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            locations = cascade.detectMultiScale(gray, minSize=(64, 64))
            if len(locations):
                location = locations[0]
                draw_piggy(frame, piggy, location, True, True)

        cv2.imshow('Monitor', frame)
        if cv2.waitKey(33) & 0xFF == ord('q'):
            break

capture.release()
cv2.destroyAllWindows()
