from sklearn.cluster import DBSCAN
import pandas as pd
from sklearn.preprocessing import LabelEncoder, MinMaxScaler, StandardScaler

def humming(x,y):
 re = 0
 if(len(x)!=len(y)):
  return 0
 for n in range(0,len(x)):
  if(x[n] == y[n]):
   re=re
  else:
   re=re+1
 return re

def purity(model,targets):
 result = model.labels_
 cluster = set(result)
 clusterCount = len(cluster)
 clusterSet = []
 num = 0;
 for n in range(0,clusterCount):
  clusterSet.append(list())

 for n in range(0,len(result)):
  clusterSet[result[n]].append(n)
 for i in range(0,clusterCount):
     subnum = 0;
     for j in range(0,len(clusterSet[i])):
         if(targets[clusterSet[i][j]] == 1):
             subnum+=1;
     if(subnum>=(len(clusterSet[i])-subnum)):
         num=num+subnum
     else:
         num=num+len(clusterSet[i])-subnum
 return (float(num))/(float(len(result)))

mushroom = pd.read_csv('C:/Users/LG/Desktop/class-7-lab-3 (2)/mushrooms.csv')
eps = [0.001, 0.002, 0.005, 0.01, 0.02, 0.05, 0.1, 0.2, 0.5]
min_samples =[3, 5, 10, 15, 20, 30, 50, 100]

encoder1 = LabelEncoder()
encoder2 = LabelEncoder()


target = mushroom['class']
data = mushroom.drop('class',axis=1)
col = list(data.columns)
Data = pd.DataFrame(data).values

for x in range(0,len(col)):
 c = pd.Series(data[col[x]]).values
 encoder2.fit(c)
 c = encoder2.transform(c)
 data[col[x]] = c


target = pd.Series(target).values
data = pd.DataFrame(data).values

encoder1.fit(target)
target = encoder1.transform(target)

scale = MinMaxScaler()
data2 = scale.fit_transform(data)

scale2 = StandardScaler()
data3 = scale2.fit_transform(data)

'''
print('------------none------------')
for x in range(0,len(min_samples)):
 Humming = DBSCAN(eps=3,min_samples=min_samples[x],metric=humming)
 Humming.fit(data)
 print('esp=3 '+' min_samples='+str(min_samples[x])+' :',end='')
 print(purity(Humming,target),end='')
 print()
'''

'''
for x in range(0,len(eps)):
 for y in range(0,len(min_samples)):
  Euclidean = DBSCAN(eps=eps[x],min_samples=min_samples[y],p=2)
  Euclidean.fit(Data)
  print('esp='+str(eps[x])+' '+'min_samples='+str(min_samples[y])+" :",end='')
  print(purity(Euclidean,target),end='')
  print()

print('----------euclidean----------')
print('----------labeling-----------')
for x in range(0,len(eps)):
 for y in range(0,len(min_samples)):
  Euclidean = DBSCAN(eps=eps[x],min_samples=min_samples[y],p=2)
  Euclidean.fit(data)
  print('esp='+str(eps[x])+' '+'min_samples='+str(min_samples[y])+" :",end='')
  print(purity(Euclidean,target),end='')
  print()
'''
print('----------labeling+minmaxscaler-----------')
for x in range(0,len(eps)):
 for y in range(0,len(min_samples)):
  Euclidean = DBSCAN(eps=eps[x],min_samples=min_samples[y],p=2)
  Euclidean.fit(data2)
  print('esp='+str(eps[x])+' '+'min_samples='+str(min_samples[y])+" :",end='')
  print(purity(Euclidean,target),end='')
  print()
'''
print('----------labeling+standardscaler-----------')
for x in range(0,len(eps)):
 for y in range(0,len(min_samples)):
  Euclidean = DBSCAN(eps=eps[x],min_samples=min_samples[y],p=2)
  Euclidean.fit(data3)
  print('esp='+str(eps[x])+' '+'min_samples='+str(min_samples[y])+" :",end='')
  print(purity(Euclidean,target),end='')
  print()
'''