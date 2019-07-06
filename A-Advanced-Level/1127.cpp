#include <bits/stdc++.h>
using namespace std;
#define MAXN 30

struct node {
	int data;
	int lchild, rchild;
};

int n = MAXN;
int inorder[MAXN], postorder[MAXN];
node tree[MAXN];
vector<int> ans;
int direction = 0;

int array_find(int a[], int x) {
	for (int i=0; i<n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}

void init() {
	for (int i=0; i<MAXN; i++) {
		tree[i].lchild = -1;
		tree[i].rchild = -1;
	}
}

int find_root(int in_first, int in_end, int post_first, int post_end) {
	return array_find(inorder, postorder[post_end]);
}

void build(int in_first, int in_end, int post_first, int post_end) {
	if (in_first >= in_end || post_first >= post_end || in_first < 0 || post_first < 0 || in_end >= n || post_end >= n) {
		return;
	}
	if (in_first < in_end && post_first < post_end) {
		int temp1 = array_find(inorder, postorder[post_end]);
		int temp2 = array_find(postorder, inorder[temp1 + 1]);
		tree[temp1].rchild = find_root(temp1 + 1, in_end, temp2, post_end - 1);
		tree[temp1].lchild = find_root(in_first, temp1 - 1, post_first, temp2 - 1);
		build(temp1 + 1, in_end, temp2, post_end - 1);
		build(in_first, temp1 - 1, post_first, temp2 - 1);
	}
}

void build() {
	build(0, n - 1, 0, n - 1);
}

void level_order(int root) {
	int cur = 1, next = 0;
	queue<int> q;
	q.push(root);
	vector<int> temp;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		cur--;
		temp.push_back(tree[p].data);
		if (tree[p].lchild != -1) {
			q.push(tree[p].lchild);
			next++;
		}
		if (tree[p].rchild != -1) {
			q.push(tree[p].rchild);
			next++;
		}
		if (cur == 0) {
			cur = next;
			next = 0;
			if (direction == 0) {
				for (int i=0; i<temp.size(); i++) {
					ans.push_back(temp[i]);
				}
				direction = 1;
			}
			else {
				for (int i=temp.size() - 1; i >= 0; i--) {
					ans.push_back(temp[i]);
				}
				direction = 0;
			}
			temp.clear();
		}
	}
}

void ino(int x){
	if(x!=-1){
		ino(tree[x].lchild);
		cout<<tree[x].data<<' ';
		ino(tree[x].rchild);
	}
}

int main() {
	init();
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &inorder[i]);
		tree[i].data = inorder[i];
	}
	for (int i=0; i<n; i++) {
		scanf("%d", &postorder[i]);
	}
	build();
	int root = array_find(inorder, postorder[n - 1]);
	level_order(root);
	for (int i=0; i<ans.size() - 1; i++) {
		printf("%d ", ans[i]);
	}
	printf("%d\n", ans[ans.size() - 1]);
	/* 
	for(int i=0;i<n;i++){
		cout<<tree[i].lchild<<' ';
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<tree[i].rchild<<' ';
	}
	cout<<endl;
	*/ 
	//ino(root);
	return 0;
}
