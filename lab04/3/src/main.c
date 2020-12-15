/* Дано три  числа k, m, n. Змінити значення змінних таким чинном, 
щоб виконувалася умова k<m<n*/
int main() {
	int  k = 10, m = 2, n =7, i=0;
	if (k<m && k<n) {
		//k залишається
	} else if (k<n && k>m) {
		i = k;
		k=m;
		m=k;
	} else if (k<m && k>n) {
		i = k;
		k=n;
		n=i;
	} else if (k>n && k>m) {
		if (m>n) {
			i = k;
			k=n;
			n=i;
		} else {
			i = k;
			k=m;
			m=i;
		}
	}
	if (m > n){
		i=n;
		n=m;
		m=i;
	}
	else {
		//умова виконується
	}
	return 0;
}
