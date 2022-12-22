from SORT.sort import Sort
from projectCApp.analysisService.analysisModule.analysis import AnalysisCore
from resource.modelFactory import YoloFactory
import glob
import cv2
import os
import time
import sys

videoList = glob.glob("C:/Users/ygl/Desktop/tempt_projectC-main/carDATAS/data/*")
print(videoList)
yoloFactory = YoloFactory("./resource","yolov5l.pth")
model = yoloFactory.getModel()

readTime = 0
processTime = 0
count = 0

for videoName in videoList:
    video = cv2.VideoCapture(videoName)

    fps, f_count = video.get(cv2.CAP_PROP_FPS), video.get(cv2.CAP_PROP_FRAME_COUNT)
    print("fps:" + str(fps) + "  " + "frame:" + str(f_count))

    analysisCore = AnalysisCore(Sort(),model,2)
    start = time.time()
    while True:
        s = time.time()
        ret,frame = video.read()
        count += 1
        e = time.time()
        readTime += (e - s)
        s = time.time()
        if not ret:
            break
        else:
            analysisCore.excuteTracking(frame)
        e = time.time()
        processTime += (e - s)
        if count == 20000:
            cars = analysisCore.getObjectImage()
            fileName = os.path.basename(videoName)
            split_name = fileName.split(".")
            try:
                if not os.path.exists(f"C:/Users/ygl/Desktop/tempt_projectC-main/carDATAS/{split_name[0]}"):
                    os.makedirs(f"C:/Users/ygl/Desktop/tempt_projectC-main/carDATAS/{split_name[0]}")
            except OSError:
                print(
                    'Error: Creating directory. ' + f"C:/Users/ygl/Desktop/tempt_projectC-main/carDATAS/{split_name[0]}")
                sys.exit()

            for key in cars.keys():
                cv2.imwrite(f"C:/Users/ygl/Desktop/tempt_projectC-main/carDATAS/{split_name[0]}/" + split_name[0] + f"_{key}.jpg", cars[key])
            count = 0
            del analysisCore.objectImage
            analysisCore.objectImage = {}


    print(f"readTime:{readTime} / processTime:{processTime}")
    cars = analysisCore.getObjectImage()
    fileName = os.path.basename(videoName)
    end = time.time()
    print(f"total time:{end - start}")
    print("---------------------------------------------------")
    split_name = fileName.split(".")
    try:
        if not os.path.exists(f"C:/Users/ygl/Desktop/tempt_projectC-main/carDATAS/{split_name[0]}"):
            os.makedirs(f"C:/Users/ygl/Desktop/tempt_projectC-main/carDATAS/{split_name[0]}")
    except OSError:
        print('Error: Creating directory. ' + f"C:/Users/ygl/Desktop/tempt_projectC-main/carDATAS/{split_name[0]}")
        sys.exit()

    for key in cars.keys():
        cv2.imwrite(f"C:/Users/ygl/Desktop/tempt_projectC-main/carDATAS/{split_name[0]}/"+split_name[0]+f"_{key}.jpg",cars[key])


"""
label_num = 2

yoloFactory = YoloFactory("./resource","yolov5l.pth") # make yolov5 model factory class input: (directory path, model name)
model = yoloFactory.getModel() # get yolov5 model object
tracker = Sort() # tracker object use SORT

videoList = glob.glob("C:/Users/ygl/Desktop/tempt_projectC-main/carDATAS/data/*")

analysisCore = AnalysisCore(tracker,model,label_num)
"""

