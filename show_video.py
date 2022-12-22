import tensorflow as tf
import os
from tensorflow.python.client import device_lib
import numpy as np

print(device_lib.list_local_devices())
from SORT.sort import Sort
import torch
import sys
import cv2
from projectCApp.analysisService.analysisModule.analysis import AnalysisCore


labels = ['Van', 'bus', 'compact', 'sedan', 'suv', 'truck']
colors = ['beige', 'black', 'blue', 'brown', 'red', 'silver', 'white', 'yellow']
colors2 = ['beige', 'black', 'blue', 'brown', 'red', 'silver', 'yellow']
colors3 = ['black','white']
colors4 = ['black','other','silver','white']

save_directory = "C:/Users/ygl/Desktop/projectC/projectC-main/test_data/car_set"
sys.path.insert(0, 'C:/Users/ygl/Desktop\projectC/projectC-main/resource')
device = torch.device("cuda")
model = torch.load("C:/Users/ygl/Desktop/tempt_projectC-main/resource/yolov5l.pth")
model.to(device)
colorModel = tf.keras.models.load_model('C:/Users/ygl/Desktop/tempt_projectC-main/resource/blackandwhite.h5')

# colorClassifier = Classifier()

tracker = Sort()
label = "car"
label_num = 2
analysisCore = AnalysisCore(tracker, model, label_num)

video = cv2.VideoCapture("C:/Users/ygl/Desktop/tempt_projectC-main/userVideos/hankug/25735a7ea32f1f66952e1e75b19cbbf1a724fe9bTestVideo.mp4")
if video.isOpened():
    fps = video.get(cv2.CAP_PROP_FPS)
    f_count = video.get(cv2.CAP_PROP_FRAME_COUNT)
    print("fps:" + str(fps) + "  " + "frame:" + str(f_count))
else:
    print("cant open")
    sys.exit()

while video.isOpened():
    ret, frame = video.read()
    if not ret:
        break
    key = cv2.waitKey(1)
    if key == ord('q'):
        break
    """    
    result = model([frame]).pandas().xyxy[0]
    locations = result.to_numpy()
    locations = locations[locations[:,5] == label_num][:,:-2]
    objects = tracker.update(locations)
    """
    objects = analysisCore.excuteTracking(frame)
    for l in objects:
        x1, y1, x2, y2 = l[0], l[1], l[2], l[3]
        filter_frame = frame[y1:y2, x1:x2].copy()
        # cv2.imwrite(f"C:/Users/ygl/Desktop/projectC/projectC-main/test_data/car_set/test_video{l[4]}.jpg",filter_frame)
        s = filter_frame.shape
        if s[0] == 0 or s[1] == 0:
            continue


        filter_frame = cv2.resize(filter_frame, dsize=(224, 224), interpolation=cv2.INTER_AREA)


        with tf.device('/device:GPU:0'): 
            predict = colorModel.predict(np.array([filter_frame]))
            name = colors3[np.argmax(predict)]
            #colorResult = colorClassifier.predict(image)
            #name = colorResult[0]['color']
            #prob = float(colorResult[0]['prob'])


        cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
        cv2.putText(frame, name+":" + str(l[4]), (x1, y1), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 255, 0), 2)
    cv2.imshow("car_video_test", frame)

video.release()
cv2.destroyAllWindows()