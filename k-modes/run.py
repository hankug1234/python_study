import pandas as pd
import Kmodes
from sklearn.preprocessing import LabelEncoder


mushroom = pd.read_csv("C:/Users/LG/Desktop/class-7-lab-3 (2)/mushrooms.csv")
label = mushroom['class']
data = mushroom.drop('class',axis=1)
data = pd.DataFrame(data).values
label = pd.Series(label).values
encoder1 = LabelEncoder()
label = encoder1.fit_transform(label)

for n_init in range(1,25):
    for max_iter in range(1,5):
        test = Kmodes.Kmodes(n_clusters=2, max_iter=max_iter, n_init=n_init, random_state=2)
        test.fit(data)
        print("config: n_cluster=2 "+"max_iter="+str(max_iter)+" n_init="+str(n_init))
        print("purity:" + str(test.purity(label)))
        print("accuracy:"+str(test.score(label)))
