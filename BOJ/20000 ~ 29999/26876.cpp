# include <cstdio>
# include <queue>

using namespace std;

class time {
public:
	int hour, min;
	
	time(void) {
		scanf("%d:%d", &this->hour, &this->min);
	}
	time(const time &t) {
		this->hour=t.hour;
		this->min=t.min;
	}
	void buttonA(void) {
		this->min++;
		if(min>=60) {
			min=0;
			this->hour++;
		}
		if(this->hour>=24)
			this->hour=0;
	}
	void buttonB(void) {
		this->hour++;
		if(this->hour>=24)
			this->hour=0;
	}
	bool isequal(time t) {
		return this->hour==t.hour&&this->min==t.min;
	}
};

int bfs(time src, time dst) {
	int cou=0;
	bool visited[24][60]={false, };
	queue<time> q;
	visited[src.hour][src.min]=true;
	q.push(src);
	while(!q.empty()) {
		int size=q.size();
		while(size--) {
			time t=q.front();
			q.pop();
			if(t.isequal(dst))
				return cou;
			time a=time(t);
			time b=time(t);
			a.buttonA();
			b.buttonB();
			if(!visited[a.hour][a.min]) {
				visited[a.hour][a.min]=true;
				q.push(a);
			}
			if(!visited[b.hour][b.min]) {
				visited[b.hour][b.min]=true;
				q.push(b);
			}
		}
		cou++;
	}
}

int main(void) {
	time src=time(), dst=time();
	printf("%d", bfs(src, dst));
	return 0;
}