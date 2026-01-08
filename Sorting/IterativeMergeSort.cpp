#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[l + k] = temp[k];
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int curr = 1; curr < n; curr *= 2) {
        for (int left = 0; left < n - 1; left += 2 * curr) {
            int mid = min(left + curr - 1, n - 1);
            int right = min(left + 2 * curr - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
