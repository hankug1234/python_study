from sklearn.utils import check_random_state
import math

class Kmodes:
    def __init__(self,n_clusters=1,max_iter=10,n_init=3,random_state=0):
        self.n_clusters = n_clusters
        self.max_iter = max_iter
        self.n_init = n_init
        self.random_state = random_state
        self.center = []
        self.cluster_info = []
        self.cluster_size = []
        self.randint = check_random_state(random_state)
        self.labels_ = []

    def purity(self, Y):
        result = self.labels_
        cluster = set(result)
        clusterCount = len(cluster)
        clusterSet = []
        num = 0;
        for n in range(0, clusterCount):
            clusterSet.append(list())

        for n in range(0, len(result)):
            clusterSet[result[n]].append(n)
        for i in range(0, clusterCount):
            subnum = 0;
            for j in range(0, len(clusterSet[i])):
                if (Y[clusterSet[i][j]] == 1):
                    subnum += 1;
            if (subnum >= (len(clusterSet[i]) - subnum)):
                num = num + subnum
            else:
                num = num + len(clusterSet[i]) - subnum
        return (float(num)) / (float(len(result)))

    def __choose_random_sample(self,X):
        i = self.randint.randint(X.shape[0])
        return X[i]

    def __calculate_distance_init(self,center,data):
        distance = 0
        for d in range(0,len(data)):
            if(center[d] != data[d]):
                distance = distance+1
            else:
                distance += 0

        return distance

    def __init(self,n_clusters,n_init,attr_size,X):
         candidate = []
         candidate_cluster_info = []
         candidate_cluster_size = []
         X_size = len(X)
         test_size = math.ceil(X_size/20)
         min = len(X[0])
         index = 0
         for i in range(0,n_clusters):
             for j in range(0,n_init):
                 candidate.append(self.__choose_random_sample(X))
                 candidate_cluster_size.append(1)
                 candidate_cluster_info.append([])
                 for attr in range(0,attr_size):
                     candidate_cluster_info[j].append({})
                     candidate_cluster_info[j][attr][candidate[j][attr]] = 1

             for t in range(0,test_size):
                 test = self.__choose_random_sample(X)
                 for j in range(0,n_init):
                     distance = self.__calculate_distance_init(candidate[j],test)
                     if(min>=distance):
                         min = distance
                         index = j
                 candidate_cluster_size[index]+=1
                 for attr in range(0,attr_size):
                     candidate_keys = candidate_cluster_info[index][attr].keys()
                     if(test[attr] in candidate_keys):
                         candidate_cluster_info[index][attr][test[attr]]+=1
                     else:
                         candidate_cluster_info[index][attr][test[attr]] = 1
                 min = len(X[0])
                 index = 0
             max = 0
             for select in range(1,self.n_init):
                 if(candidate_cluster_size[max]<=candidate_cluster_size[select]):
                     max = select
             self.cluster_info.append(candidate_cluster_info[max])
             self.cluster_size.append(candidate_cluster_size[max])
             self.center.append(candidate[max])
             del candidate_cluster_info[:]
             del candidate_cluster_size[:]
             del candidate[:]


         return self.center

    def __newCenter(self):
        new_center=[]
        for i in range(0,self.n_clusters):
            new_mode = []
            for j in self.cluster_info[i]:
              max_key = max(j, key=lambda k: j[k])
              new_mode.append(max_key)
            new_center.append(new_mode)
        return new_center

    def __changeCenter(self,new_center,attr_size):
        del self.cluster_info[:]
        del self.cluster_size[:]
        del self.center[:]
        self.center = new_center

        for j in range(0, self.n_clusters):
            self.cluster_size.append(1)
            self.cluster_info.append([])
            for attr in range(0, attr_size):
                self.cluster_info[j].append({})
                self.cluster_info[j][attr][self.center[j][attr]] = 1


    def __modeEqule(self,mode1,mode2):
        l = len(mode1)
        for attr in range(0,l):
            if(mode1[attr] == mode2[attr]):
                pass
            else:
                return False
        return True

    def predict(self,X):
        min = len(X[0])
        index = 0
        results = []

        for x in X:
            for c in range(0,self.n_clusters):
                distance = self.__calculate_distance_init(self.center[c],x)
                if(distance<=min):
                    index = c
                    min = distance
            results.append(index)
            min = len(X[0])
            index = 0
        return results

    def score(self,Y):
        size = len(Y)
        results = self.labels_
        score = 0
        for n in range(0,size):
            if(results[n] == Y[n]):
                score+=1
        return (score/size)

    def fit(self,X):
        cmin = len(X[0])
        min = cmin
        index = 0
        state = 0
        self.__init(self.n_clusters,self.n_init,cmin,X)

        for n in range(0,self.max_iter):
            del self.labels_[:]
            for d in X:
                for c in range(0,self.n_clusters):
                    distance = self.__calculate_distance_init(self.center[c],d)
                    if(distance<=min):
                        min = distance
                        index = c
                self.cluster_size[index]+=1
                self.labels_.append(index)
                for attr in range(0, cmin):
                    keys = self.cluster_info[index][attr].keys()
                    if (d[attr] in keys):
                        self.cluster_info[index][attr][d[attr]] += 1
                    else:
                        self.cluster_info[index][attr][d[attr]] = 1
                min = cmin
                index = 0
            new_centers = self.__newCenter()
            for c in range(0,self.n_clusters):
                new_center = new_centers[c]
                if(self.__modeEqule(self.center[c],new_center)):
                    state+=1
                else:
                    pass

            if(state == self.n_clusters):
                break
            else:
                self.__changeCenter(new_centers,cmin)
                state = 0






