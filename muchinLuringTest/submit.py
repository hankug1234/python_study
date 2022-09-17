import pandas as pd
'''import csv data'''
df = pd.read_csv("C:\Downloads/knn_data.csv")
'''print data content'''
print(df.head())
print(df.shape)

'''except tartget data colunm'''
x = df.drop(columns=['lang'])

print(x.head())
'''separte tartget value'''
y = df['lang'].values

print(y[0:15])
'''import split module '''
from sklearn.model_selection import train_test_split

'''make split object variable'''
x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.2,random_state=5,stratify = y)

'''import classification module'''
from sklearn.neighbors import KNeighborsClassifier

'''make classification object variable and set object number'''
knn = KNeighborsClassifier(n_neighbors = 3)
'''classification data set'''
knn.fit(x_train,y_train)

print(knn.predict(x_train[0:15]))
print(knn.score(x_test,y_test))

'''import k-fold cross validation module'''
from sklearn.model_selection import cross_val_score
import numpy as np

'''make k-fold cross validation object variable'''
knn_cv = KNeighborsClassifier(n_neighbors=3)
'''start k-ford cross validation process'''
cv_scores = cross_val_score(knn_cv,x,y,cv=5)

print(cv_scores)
print('cv_scores mean:{}'.format(np.mean(cv_scores)))