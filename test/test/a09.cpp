#include"a09.h"
int random_select(vector<int>& A, const int p, const int r, int i) {
	if (p == r)
		return A[p];
	int q = random_partion(A, p, r);
	int k = q - p + 1;
	if (i == k)
		return A[q];
	else
	{
		if (i < k)
			return random_select(A, p, q - 1, i);
		else
		{
			return random_select(A, q + 1, r, i - k);
		}
	}
}

int random_partion(vector<int>& A, const int p, const int r) {
	int q = random(p, r),i=p-1,temp;
	temp = A[q];
	A[q] = A[r];
	A[r] = temp;
	for (int j = p; j != r; j++) {
		if (A[j] < A[r]) {
			i += 1;
			int tempt = A[i];
			A[i] = A[j];
			A[j] = tempt;
		}
	}
	int tempt = A[i+1];
	A[i+1] = A[r];
	A[r] = tempt;
	return i + 1;
}