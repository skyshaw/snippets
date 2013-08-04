int a[100][100];
int (*getArray())[100] {
	return a;
}
int main() {
	int (*pArray)[100] = getArray();
	return 0;
}