#include <iostream>
#include <string>
#define s second
#define f first

using namespace std;

int main() {
    int N; cin >> N;
    int news; cin >> news;
    pair<string, int>* people = new pair<string, int>[N];
    for (int i = 0; i < N; ++i) {
        cin >> people[i].f >> people[i].s;
    }
    int M; cin >> M;
    int news_pos = 0;
    int next_news_pos = 1;
    int deaths = 0;
    for (int day = 0; day < M; ++day) {
        int i = news_pos + 1;
        while (people[i].s == -1) {
            ++next_news_pos;
            i = (i + 1) % N;
        }
        if (deaths == N - 1) {
            break;
        }
        if (people[news_pos].s == 1 && news == 0) {
            people[news_pos].s = -1;
            ++deaths;
        }
        else if (people[news_pos].s == 0 && news == 0) {
            people[news_pos].s = 1;
            news = 1;
        }
        else if (people[news_pos].s == 0 && news == 1) {
            news = 0;
        }
        news_pos = next_news_pos % N;
        next_news_pos = news_pos + 1;
    }
    for (int i = 0; i < N; ++i) {
        if (people[i].s != -1) {
            cout << people[i].f << ' ' << people[i].s << endl;
        }
    }
    delete[] people;
    return 0;
}
