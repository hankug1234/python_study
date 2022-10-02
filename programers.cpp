#include <string>
#include <vector>
#include <list>
#include <map>
#include<iostream>

using namespace std;

class Data{
    private:
        map<string,int>m; 
        vector<int>v;
        int s;
    public:
        Data(map<string,int>& m,vector<int> v,int s);
        map<string,int> getm();
        vector<int> getv();
        int gets();
};
Data::Data(map<string,int>& im,vector<int> iv,int is){m=im; v=iv;s=is;};
map<string,int> Data::getm(){return m;};
vector<int> Data::getv(){return v;};
int Data::gets(){return s;};

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int max_index = gems.size()-1;
    map<string,int> gems_dict;
    int i = 0;
    for(i=0;i<max_index;i++){
        if(gems_dict.find(gems[i]) != gems_dict.end())
            gems_dict[gems[i]] +=1;
        else
            gems_dict[gems[i]] = 1;
    }
    
    if(gems_dict.size() == 1)
        return {1,1};
    
    Data pd(gems_dict,{0,max_index},1);
    list<Data> queue;
    queue.push_back(pd);
    answer = {1,max_index+1};
    int mean_len = 1000000;
    int state = 0;
    while(queue.size() != 0){
        auto iter = queue.begin();
        Data d = *iter;
        queue.pop_front();
        auto miter = d.getm().begin();
        auto stop = d.getm().end();
        for(miter;miter!=stop;miter++){
            if(miter->second == 0){
                state = 1;
                break;
            }
            
        }
        printf("%p\n",miter);
        if(state ==1 ){
            if(mean_len >(d.getv()[1]-d.getv()[0]+2)){
                mean_len = (d.getv()[1]-d.getv()[0]+2);
                if(d.gets() == 1)
                    answer = {d.getv()[0],d.getv()[1]+1};
                else
                    answer = {d.getv()[0]+1,d.getv()[1]+2};
             state = 0;   
            }
         continue;   
        }
        
        map<string,int> left_gems_dict = d.getm();
        left_gems_dict[gems[d.getv()[1]]] -=1;
        Data ld(left_gems_dict,{d.getv()[0],d.getv()[1]-1},0);
        queue.push_back(ld);
        if(d.gets() == 1){
        map<string,int> right_gems_dict = d.getm();
        right_gems_dict[gems[d.getv()[0]]] -=1; 
        Data rd(right_gems_dict,{d.getv()[0]+1,d.getv()[1]},1);
        queue.push_back(rd);
        }
    
    }
    return answer;
}

int main(void){
	vector<string> gems = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
	vector<string> gems2 = {"AA", "AB", "AC", "AA", "AC"};
	vector<string> gems3 = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
	vector<int> result = solution(gems2);
	printf("%d %d\n",result[0],result[1]);
	return 0;
}
