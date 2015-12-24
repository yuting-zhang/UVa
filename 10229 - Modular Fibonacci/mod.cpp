#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

using vvi = vector<vector<long long>>;
vvi matrix_multi(vvi m1, vvi m2){
	return {{m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0],      	      
			 m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1]},
			{m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0],
			 m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1]}};
}

void do_mod(vvi& mat, int mod_num){
	mat[0][0] %= mod_num;
	mat[0][1] %= mod_num;
	mat[1][0] %= mod_num;
	mat[1][1] %= mod_num;
}
vvi matrix_pow(vvi matrix, int power, int mod_num){
	if (power == 0)
		return {{1, 0}, {0, 1}};
	vvi ret;
	if (power % 2 == 0){
		ret = matrix_pow(matrix, power / 2, mod_num);
		do_mod(ret, mod_num);
		ret = matrix_multi(ret, ret);
		do_mod(ret, mod_num);
	}
	else{
		ret = matrix_pow(matrix, power / 2, mod_num);
		do_mod(ret, mod_num);
		ret = matrix_multi(ret, ret);
		do_mod(ret, mod_num);
		ret = matrix_multi(ret, matrix);
		do_mod(ret, mod_num);
	}

	return ret;
}

int main(){
	long long  n, m;
	while (scanf("%lld %lld", &n, &m) == 2){
		int mod_num = pow(2, m);
		if (n == 0){
			printf("0\n");
			continue;
		}
		if (n == 1){
			printf("1\n");
			continue;
		}	

		vvi matrix = {{1, 1}, {1, 0}};
		vvi result = matrix_pow(matrix, n, mod_num);

		printf("%d\n", result[1][0]);
	}
}
