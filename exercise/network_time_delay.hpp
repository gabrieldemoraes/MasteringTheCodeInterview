#ifndef NETWORK_TIME_DELAY_HPP
#define NETWORK_TIME_DELAY_HPP

#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <limits>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap;
    function<bool(int, int)> comparator;

    int parent(int idx) {
        return (idx - 1) / 2;
    }

    int leftChild(int idx) {
        return idx * 2 + 1;
    }

    int rightChild(int idx) {
        return idx * 2 + 2;
    }

    void swap(int i, int j) {
        std::swap(heap[i], heap[j]);
    }

    bool compare(int i, int j) {
        return comparator(heap[i], heap[j]);
    }

    void siftUp() {
        int idx = heap.size() - 1;
        while (idx > 0 && compare(idx, parent(idx))) {
            swap(idx, parent(idx));
            idx = parent(idx);
        }
    }

    void siftDown() {
        int idx = 0;
        while (true) {
            int left = leftChild(idx);
            int right = rightChild(idx);
            int smallest = idx;

            if (left < heap.size() && compare(left, smallest)) {
                smallest = left;
            }

            if (right < heap.size() && compare(right, smallest)) {
                smallest = right;
            }

            if (smallest == idx) {
                break;
            }

            swap(idx, smallest);
            idx = smallest;
        }
    }

public:
    PriorityQueue(function<bool(int, int)> comparator) : comparator(comparator) {}

    void push(int value) {
        heap.push_back(value);
        siftUp();
    }

    int pop() {
        int top = heap[0];
        swap(0, heap.size() - 1);
        heap.pop_back();
        siftDown();
        return top;
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int network_delay_time(vector<vector<int>>& times, int N, int k) {
    vector<int> distances(N, numeric_limits<int>::max());
    vector<vector<pair<int, int>>> adjList(N);
    distances[k - 1] = 0;

    PriorityQueue heap([&](int a, int b) { return distances[a] < distances[b]; });
    heap.push(k - 1);

    for (const auto& time : times) {
        int source = time[0] - 1;
        int target = time[1] - 1;
        int weight = time[2];
        adjList[source].emplace_back(target, weight);
    }

    while (!heap.isEmpty()) {
        int current = heap.pop();

        for (const auto& neighbor : adjList[current]) {
            int target = neighbor.first;
            int weight = neighbor.second;
            if (distances[current] + weight < distances[target]) {
                distances[target] = distances[current] + weight;
                heap.push(target);
            }
        }
    }

    int ans = *max_element(distances.begin(), distances.end());
    return ans == numeric_limits<int>::max() ? -1 : ans;
}

int network_delay_time_bellman_ford(vector<vector<int>>& times, int N, int k) {
    vector<int> distances(N, numeric_limits<int>::max());
    distances[k - 1] = 0;

    for(auto i = 0; i < N -1; ++i)
    {
        int count = 0;
        for (const auto& time : times) 
        {
            int source = time[0] - 1;
            int target = time[1] - 1;
            int weight = time[2];
            
            if(distances[source] != numeric_limits<int>::max() && distances[source] + weight < distances[target])
            {
                distances[target] = distances[source ] + weight;
                ++count;
            }
        }
        if(count == 0) break;
    }

    int ans = *max_element(distances.begin(), distances.end());
    return ans == numeric_limits<int>::max() ? -1 : ans;
}

#endif