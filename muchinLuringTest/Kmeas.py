import pandas as pd
import numpy as np
import math
import plotly.graph_objects as go
from sklearn.cluster import KMeans
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import MinMaxScaler
import seaborn as sns
import matplotlib.pyplot as plt
'''import dataset'''
train_url ="http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/train.csv"
train = pd.read_csv(train_url)
test_url ="http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/test.csv"
test = pd.read_csv(test_url)

def cDistance(a,b):
    value = 0;
    for x in range(0,len(a)):
        value=value+(a[x]-b[x])**2
    return math.sqrt(value)

'''fill missing data'''
train.fillna(train.mean(),inplace=True)
test.fillna(test.mean(),inplace=True)

'''drop useless data colunm'''
train = train.drop(['Name','Ticket','Cabin','Embarked'], axis=1)
test = test.drop(['Name','Ticket','Cabin','Embarked'], axis=1)

'''convet feature to numeric values'''
labelEncoder = LabelEncoder()
labelEncoder.fit(train['Sex'])
labelEncoder.fit(test['Sex'])
train['Sex'] = labelEncoder.transform(train['Sex'])
test['Sex'] = labelEncoder.transform(test['Sex'])

print(train.isna().sum())

X = np.array(train.drop(['Survived'],1)).astype(float)
Y = np.array(train['Survived'])

scaler = MinMaxScaler()
X_scaled = scaler.fit_transform(X)

index = []
num = 0

scatterx = list()
scattery = list()
label = list()
centerx = list()
centery = list()
correct = 0
distance1 = list()
distance2 = list()

kmeans = KMeans(n_clusters=2, max_iter=1, n_init=1, random_state=1)
kmeans.fit(X_scaled)

initial = kmeans.cluster_centers_
print(initial[0])

kmeans = KMeans(n_clusters=2, max_iter=1, n_init=2, random_state=1)
kmeans.fit(X_scaled)

initial = kmeans.cluster_centers_
print(initial[0])

for i in range(1,60):
 kmeans = KMeans(n_clusters=2,max_iter=i,n_init=10,random_state=1)
 kmeans.fit(X_scaled)
 Next = kmeans.cluster_centers_
 print(Next[0])
 distance2.append(cDistance(initial[1], Next[1]))
 for i in range(len(X_scaled)):
   predict_me= np.array(X_scaled[i].astype(float))
   predict_me = predict_me.reshape(-1, len(predict_me))
   prediction = kmeans.predict(predict_me)
   if prediction[0] == Y[i]:
    correct += 1
print(distance1)
plt.plot(distance1,list(range(0,60)),c='red')
plt.plot(distance2,list(range(0,60)),c='green')
plt.show();'''
'''   label.append('green')
  else:
    label.append('blue')
centerx.append(sum(kmeans.cluster_centers_[0][0:4]))
centery.append(sum(kmeans.cluster_centers_[0][5:]))
centerx.append(sum(kmeans.cluster_centers_[1][0:4]))
centery.append(sum(kmeans.cluster_centers_[1][5:]))

plt.scatter(scatterx,scattery,c=label,alpha=0.5)
plt.scatter(centerx,centery,c='red',alpha=0.5)
plt.show()
print(len(scatterx)'''


asixX = range(2,30,1)
c