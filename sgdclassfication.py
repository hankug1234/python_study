# -*- coding: utf-8 -*-
"""SGDClassfication

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1_7Dc64LeR4fMaP7JxFNdy5XN2bQS3E_i
"""

import pandas as pd
fish = pd.read_csv("https://raw.githubusercontent.com/rickiepark/hg-mldl/master/fish.csv")
fish_input = fish.loc[:,'Weight':'Width']
fish_target = fish['Species'].to_numpy()

from sklearn.model_selection import train_test_split
train_input, test_input, train_target, test_target = train_test_split(fish_input, fish_target, random_state = 42)

from sklearn.preprocessing import StandardScaler
ss = StandardScaler()
ss.fit(train_input)
train_scaled = ss.transform(train_input)
test_scaled = ss.transform(test_input)

from sklearn.linear_model import SGDClassifier
sc = SGDClassifier(loss='log', max_iter=10, random_state = 42)
sc.fit(train_scaled, train_target)
print(sc.score(train_scaled, train_target))
print(sc.score(test_scaled, test_target))

sc.partial_fit(train_scaled, train_target)
print(sc.score(train_scaled, train_target))
print(sc.score(test_scaled, test_target))

