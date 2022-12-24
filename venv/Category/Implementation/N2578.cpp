#include <iostream>
#include <map>
using namespace std;

int main(void) {
	map<int, int> a;
	int b[25] = { 0 };
	int c[25];
	int num;
	int count = 0;
	for (int i = 0; i < 25; i++) {
		cin >> num;
		a[num] = i;
	}
	for (int i = 0; i < 25; i++) {
		cin >> num;
		b[a[num]] = 1;
		if (b[(a[num] / 5) * 5] == 1 && b[((a[num] / 5) * 5) + 1] == 1 && b[((a[num] / 5) * 5) + 2] == 1 && b[((a[num] / 5) * 5) + 3] == 1 && b[((a[num] / 5) * 5) + 4] == 1)
			count++;
		if (b[a[num] % 5] == 1 && b[a[num] % 5 + 5] == 1 && b[a[num] % 5 + 10] == 1 && b[a[num] % 5 + 15] == 1 && b[a[num] % 5 + 20] == 1)
			count++;
		if ((a[num] % 4 == 0 && a[num] != 0 && a[num] != 24) && b[4] == 1 && b[8] == 1 && b[12] == 1 && b[16] == 1 && b[20] == 1)
			count++;
		if (a[num] % 6 == 0 && b[0] == 1 && b[6] == 1 && b[12] == 1 && b[18] == 1 && b[24] == 1)
			count++;
		if (count >= 3) {
			num = i;
			break;
		}
	}
	cout << num + 1 << endl;
	return 0;
}