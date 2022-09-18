import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.naive_bayes import GaussianNB
from sklearn.model_selection import train_test_split
import numpy as np

golf = pd.read_csv('C:/Users/LG/Desktop/ML-lab-4 (1)/play_golf.csv')
university = pd.read_csv('C:/Users/LG/Desktop/ML-lab-4 (1)/go_university.csv')

col = list(golf.columns)
col2 = list(university.columns)

encoder = LabelEncoder()


for x in range(0,len(col)):#labelEncoding golf dataset
 c = pd.Series(golf[col[x]]).values
 encoder.fit(c)
 c = encoder.transform(c)
 golf[col[x]] = c

for x in range(0,len(col2)):#labelEncoding university dataset
 c = pd.Series(university[col2[x]]).values
 encoder.fit(c)
 c = encoder.transform(c)
 university[col2[x]] = c

golf_predic = golf['play Golf']
golf = golf.drop('play Golf',axis=1)

university_predic = university['university']
university = university.drop('university',axis = 1)

x_train = golf[0:15]
y_train  = golf_predic[0:15]

x_test = golf[15:]
y_test = golf_predic[15:]

data_golftrx = pd.DataFrame(x_train).values
data_golftex = pd.DataFrame(x_test).values

data_predictry = pd.Series(y_train).values
data_predictey = pd.Series(y_test).values

naive = GaussianNB()
naive.fit(data_golftrx,data_predictry)


predict = naive.predict(data_golftex)
y_test = pd.Series(y_test).values

count = 0
for k in range(0,len(predict)):
    if(predict[k] == y_test[k]):
        count+=1;

print('----------golf-------------------')
print('accuracy:'+str(count/len(predict)))
print("real reslut:"+str(y_test))
print("predict result:"+str(predict))
print("predict_new_data[2,0,0,0]:"+str(naive.predict(np.array([[2,0,0,0]]))))

x_train = university[0:15]
y_train  = university_predic[0:15]

x_test = university[15:]
y_test = university_predic[15:]

data_unitrx = pd.DataFrame(x_train).values
data_unitex = pd.DataFrame(x_test).values

data_predictry = pd.Series(y_train).values
data_predictey = pd.Series(y_test).values

naive = GaussianNB()
naive.fit(data_unitrx,data_predictry)

predict = naive.predict(data_unitex)
y_test = pd.Series(y_test).values

count = 0
for k in range(0,len(predict)):
    if(predict[k] == y_test[k]):
        count+=1;


print('----------go on to university-------------------')
print('accuracy:'+str(count/len(predict)))
print("real reslut:"+str(y_test))
print("predict result:"+str(predict))
print("predict_new_data[1,1,1]:"+str(naive.predict(np.array([[1,1,1]]))))


print('------------------markov----------------------')
StockProbabilityMetrix=np.array([[0.9,0.07,0.03],[0.15,0.8,0.05],[0.35,0.15,0.5]])
PeopleProbabilityMetrix=np.array([[0.6,0.15,0.05,0.2],[0.05,0.8,0.1,0.05],[0.05,0.15,0.5,0.3],[0.2,0.15,0.15,0.5]])
StockInitial = np.array([1,2,3,1,3,2,2,1])
PeopleInitial = np.array([2,4,1,1,3,2])


def Markov(metrix,init):
    pro = 1
    for i in range(0,len(init)-1):
        pro*=metrix[init[i]-1][init[i+1]-1]
    return pro
print("stock market result:"+str(Markov(StockProbabilityMetrix,StockInitial)))
print("people behavior result:"+str(Markov(PeopleProbabilityMetrix,PeopleInitial)))




