#include<vector>
#include<iostream>
#include<chrono>
#include<thread>
#include<memory>
#include<mutex>

using namespace std;

const int maxcount = 150000;
const int threadcount = 4;

bool isprimenumber(int number)
{
	if(number == 1)
		return false;
	if (number ==2 || number == 3)
		return true;
	for(int i=2; i<number-1;i++)
	{
		if((number%i) == 0)
			return false;
	}
	return true;		
}

void primnumbers(const vector<int>& primes)
{
	for(int v : primes)
	{
		cout << v << endl;
	}
}

int main()
{
	int num = 1;
	recursive_mutex num_mutex;
	vector<int> primes;
	recursive_mutex primes_mutex;
	
	auto t0 = chrono::system_clock::now();
	
	vector<shared_ptr<thread>> threads;
	
	for(int i=0;i<threadcount; i++)
	{
		shared_ptr<thread> td(new thread([&]() {
			while(true){
				int n;
				{
					lock_guard<recursive_mutex> num_lock(num_mutex);
					n = num;
					num++;
				}
				if(n>=maxcount)
					break;
				if(isprimenumber(n))
				{
					lock_guard<recursive_mutex> primes_lock(primes_mutex);
					primes.push_back(n);
				}	
			}
		}
		));
		
		threads.push_back(td);
	}
	
	for(auto thread : threads)
	{
		thread->join();
	}
	
	auto t1 = chrono::system_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(t1-t0).count();
	cout << "Took" << duration << "milliseconds." << endl;
return 0;	
}

