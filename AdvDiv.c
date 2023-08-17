#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char* advdiv(char* n1, char* n2, char minch, char decch, char rch1, char rch2) {
  bool neg = false;
	size_t n1l, n2l, n1d, n1nz = 0, n2d, n1r, n1size, n2r, n2nz = 0, r1l, r2l, resl = 0, ressize, x, y, z;
	unsigned long int n1i, n2i, n2i2, n2i3, n2i4, n2i5, n2i6, n2i7, n2i8, n2i9, carry = 0, n1xi;
	unsigned long int* carries;
	char sign[2] = "";
	char* r1;
	char* r2;
	char* m1;
	char* m2;
	char* res;
	char* result;
	char* tmp;

	if(n1[0]=='\0' || n2[0]=='\0' || minch=='\0' || decch=='\0' || rch1=='\0' || minch=='0' || decch=='0' || rch1=='0' || rch2=='0' || minch=='1' || decch=='1' || rch1=='1' || rch2=='1' || minch=='2' || decch=='2' || rch1=='2' || rch2=='2' || minch=='3' || decch=='3' || rch1=='3' || rch2=='3' || minch=='4' || decch=='4' || rch1=='4' || rch2=='4' || minch=='5' || decch=='5' || rch1=='5' || rch2=='5' || minch=='6' || decch=='6' || rch1=='6' || rch2=='6' || minch=='7' || decch=='7' || rch1=='7' || rch2=='7' || minch=='8' || decch=='8' || rch1=='8' || rch2=='8' || minch=='9' || decch=='9' || rch1=='9' || rch2=='9')
		return "";

	if(n1[0]==minch) {
		n1 = (char*) n1 + 1;
		neg = true;
	};

	if(n2[0]==minch) {
		n2 = (char*) n2 + 1;
		neg = !neg;
	};

	if(neg)
		strncat(sign, &minch, 1);

	n1r = n1d = n1l = strlen(n1);

	for(x = 0; x <= n1l; x++) {
		if(n1[x]==decch) {
			if(n1d!=n1l)
				return "";
			n1nz = n1d = x;
			continue;
		};
		if(n1[x]==rch1) {
			if(n1r!=n1l || n1d==n1l)
				return "";
			n1r = x;
			continue;
		};
		if(n1[x]==rch2) {
			if(n1r==n1l || n1l > x + 1)
				return "";
			continue;
		};
		switch(n1[x]) {
			case '\0':
				if(n1r!=n1l && n1[x - 1]!=rch2)
					return "";
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				n1nz = x;
			case '0':
				break;
			default:
				return "";
		};
	};

	n2r = n2d = n2l = strlen(n2);

	for(x = 0; x <= n2l; x++) {
		if(n2[x]==decch) {
			if(n2d!=n2l)
				return "";
			n2nz = n2d = x;
			continue;
		};
		if(n2[x]==rch1) {
			if(n2r!=n2l || n2d==n2l)
				return "";
			n2r = x;
			continue;
		};
		if(n2[x]==rch2) {
			if(n2r==n2l || n2l > x + 1)
				return "";
			continue;
		};
		switch(n2[x]) {
			case '\0':
				if(n2r!=n2l && n2[x - 1]!=rch2)
					return "";
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				n2nz = x;
			case '0':
				break;
			default:
				return "";
		};
	};

	tmp = n1;
	n1 = (char*) malloc((n1r + 2) * sizeof(char));
	r1 = (char*) malloc((n1l - n1r + 2) * sizeof(char));
	while(tmp[0]=='0') {
		tmp = (char*) tmp + 1;
		n1l--;
		n1d--;
		n1r--;
		if(n1nz!=0)
			n1nz--;
	};
	strcpy(n1, tmp[0]==decch ? "0" : "");
	strncat(n1, tmp, n1r);
	if(n1d + 1==n1r)
		n1[n1d + (tmp[0]==decch ? 1 : 0)] = '\0';
	if(n1r==n1l) {
		if(n1nz >= n1d)
			n1[n1nz + (n1nz==n1d ? 0 : 1) + (tmp[0]==decch ? 1 : 0)] = '\0';
		strcpy(r1, "0");
	}
	else {
		strcpy(r1, (char*) tmp + n1r + 1);
		if(rch2!='\0')
			r1[n1l - n1r - 2] = '\0';
	};
	if(n1[0]=='\0') {
    n1[0] = '0';
		n1[1] = '\0';
	};

	tmp = n2;
	n2 = (char*) malloc((n2r + 2) * sizeof(char));
	r2 = (char*) malloc((n2l - n2r + 2) * sizeof(char));
	while(tmp[0]=='0') {
		tmp = (char*) tmp + 1;
		n2l--;
		n2d--;
		n2r--;
		if(n2nz!=0)
			n2nz--;
	};
	strcpy(n2, tmp[0]==decch ? "0" : "");
	strncat(n2, tmp, n2r);
	if(n2d + 1==n2r)
		n2[n2d + (tmp[0]==decch ? 1 : 0)] = '\0';
	if(n2r==n2l) {
		if(n2nz >= n2d)
			n2[n2nz + (n2nz==n2d ? 0 : 1) + (tmp[0]==decch ? 1 : 0)] = '\0';
		strcpy(r2, "0");
	}
	else {
		strcpy(r2, (char*) tmp + n2r + 1);
		if(rch2!='\0')
			r2[n2l - n2r - 2] = '\0';
	};
	if(n2[0]=='\0') {
    n2[0] = '0';
		n2[1] = '\0';
	};


	if(n2[0]=='0' && n2[1]=='\0' && r2[0]=='0' && r2[1]=='\0')
		return "";

	if(n1[0]=='0' && n1[1]=='\0' && r1[0]=='0' && r1[1]=='\0')
		return "0";
	
	n1l = strlen(n1);
	r1l = strlen(r1);
	n2l = strlen(n2);

	n2d = n2l;
	for(x = 0; x < n2l; x++) {
		if(n2[x]==decch) {
			n2d = x;
			n2[x] = n2[x + 1];
			for(x++; x < n2l; x++)
				n2[x] = n2[x + 1];
			break;
		};
	};

	if(r2[0]!='0' || r2[1]!='\0') {
		r2l = strlen(r2);

		n1d = n1l;
		for(x = 0; x < n1l; x++) {
      if(n1[x]==decch) {
				n1d = x;
				do
					n1[x] = n1[x + 1];
				while(++x < n1l);
				break;
			};
		};
		n1i = atoi(n1);
		n1 = realloc(n1, (n1l + r1l + 1) * sizeof(char));
    strcat(n1, r1);
		n1i = atoi(n1) - n1i;

		free(n1);
		free(r1);

		n2i = atoi(n2);
		n2 = realloc(n2, (n2l + r2l + 1) * sizeof(char));
		strcat(n2, r2);
		n2i = atoi(n2) - n2i;

		free(n2);
		free(r2);

		if(n1d==n1l) {
    	m1 = (char*) malloc((r1l + 1) * sizeof(char));
			for(x = 0; x < r1l; x++)
				m1[x] = '9';
			m1[r1l] = '\0';
		}
		else {
			n1r = n1l - n1d - 1 + r1l;
      m1 = (char*) malloc((n1r + 1) * sizeof(char));
			for(x = 0; x < r1l; x++)
				m1[x] = '9';
			for(; x < n1r; x++)
				m1[x] = '0';
			m1[n1r] = '\0';
		};

		if(n2d==n2l) {
    	m2 = (char*) malloc((r2l + 1) * sizeof(char));
			for(x = 0; x < r2l; x++)
				m2[x] = '9';
			m2[r2l] = '\0';
		}
		else {
			n2r = n2l - n2d - 1 + r2l;
      m2 = (char*) malloc((n2r + 1) * sizeof(char));
			for(x = 0; x < r2l; x++)
				m2[x] = '9';
			for(; x < n2r; x++)
				m2[x] = '0';
			m2[n2r] = '\0';
		};

		n1i*= atoi(m2);
		n2i*= atoi(m1);

		free(m1);
		free(m2);

		n1l+= r1l;
		n2l+= r2l;

		n1 = (char*) malloc((n1l + n2r) * sizeof(char));
		tmp = (char*) malloc((n1l + n2r) * sizeof(char));
		n2 = (char*) malloc((n2l + n1r) * sizeof(char));

		strcpy(n1, sign);
		sprintf(tmp, "%lu", n1i);
		strcat(n1, tmp);
		sprintf(n2, "%lu", n2i);

		free(tmp);

		res = advdiv(n1, n2, minch, decch, rch1, rch2);

    free(n1);
		free(n2);

		return res;
	};

	free(r2);

	n1r = 0;
  if(n2d!=n2l) {
    for(x = 0; x <= n1l; x++) {
      if(n1[x]==decch || x==n1l) {
				n1size = n1l + 1;
				n1d = x + n2l - n2d - 1;
				for(; x < n1d; x++) {
					if(x==n1size) {
						n1size+= 4;
						n1 = realloc(n1, n1size * sizeof(char));
					};
					if(x >= n1l - 1) {
						n1[x] = r1[n1r];
						n1r = (n1r + 1) % r1l;
					}
					else
						n1[x] = n1[x + 1];
				};
				break;
			};
		};
    if(x >= n1l) {
			n1[x] = '\0';
			n1l = n1d;
		}
		else
			n1[x] = decch;
	};

	n2i = atoi(n2);

  free(n2);

	n2i2 = n2i * 2;
	n2i3 = n2i * 3;
	n2i4 = n2i * 4;
	n2i5 = n2i * 5;
	n2i6 = n2i * 6;
	n2i7 = n2i * 7;
	n2i8 = n2i * 8;
	n2i9 = n2i * 9;

	ressize = n1l + 1;
	res = (char*) malloc(ressize * sizeof(char));

	if(neg) {
		res[0] = minch;
		resl = 1;
	};

	for(x = 0; ; x++) {
		if(x==n1l || n1[x]==decch)
			break;
		n1xi = n1[x] - 48 + carry * 10;
		if(n1xi < n2i) {
      carry = n1xi;
			if(resl==neg)
				continue;
			res[resl] = '0';
			resl++;
			continue;
		};
		if(n1xi < n2i2) {
			carry = n1xi - n2i;
			res[resl] = '1';
			resl++;
			continue;
		};
		if(n1xi < n2i3) {
			carry = n1xi - n2i2;
			res[resl] = '2';
			resl++;
			continue;
		};
		if(n1xi < n2i4) {
			carry = n1xi - n2i3;
			res[resl] = '3';
			resl++;
			continue;
		};
		if(n1xi < n2i5) {
			carry = n1xi - n2i4;
			res[resl] = '4';
			resl++;
			continue;
		};
		if(n1xi < n2i6) {
			carry = n1xi - n2i5;
			res[resl] = '5';
			resl++;
			continue;
		};
		if(n1xi < n2i7) {
			carry = n1xi - n2i6;
			res[resl] = '6';
			resl++;
			continue;
		};
		if(n1xi < n2i8) {
			carry = n1xi - n2i7;
			res[resl] = '7';
			resl++;
			continue;
		};
		if(n1xi < n2i9) {
			carry = n1xi - n2i8;
			res[resl] = '8';
			resl++;
			continue;
		};
		carry = n1xi - n2i9;
		res[resl] = '9';
		resl++;
	};

  if(x==n1l && carry==0) {
		free(n1);
		free(r1);
    res[resl] = '\0';
		return res;
	};

  if(resl==neg) {
    res[neg] = '0';
		resl++;
	};

  n1d = x;

	ressize+= 16;

	res = realloc(res, ressize * sizeof(char));

	res[resl++] = decch;

	for(x++; ; x++) {
		if(x >= n1l) {
			free(n1);
			carries = (unsigned long int*) malloc(r1l * n2i * sizeof(unsigned long int));
			for(y = 0; ; y++) {
				carries[y] = carry;
      	n1xi = r1[n1r] - 48 + carry * 10;
				n1r = (n1r + 1) % r1l;
				if(n1xi < n2i) {
					carry = n1xi;
					res[resl] = '0';
				}
				else if(n1xi < n2i2) {
					carry = n1xi - n2i;
					res[resl] = '1';
				}
				else if(n1xi < n2i3) {
					carry = n1xi - n2i2;
					res[resl] = '2';
				}
				else if(n1xi < n2i4) {
					carry = n1xi - n2i3;
					res[resl] = '3';
				}
				else if(n1xi < n2i5) {
					carry = n1xi - n2i4;
					res[resl] = '4';
				}
				else if(n1xi < n2i6) {
					carry = n1xi - n2i5;
					res[resl] = '5';
				}
				else if(n1xi < n2i7) {
					carry = n1xi - n2i6;
					res[resl] = '6';
				}
				else if(n1xi < n2i8) {
					carry = n1xi - n2i7;
					res[resl] = '7';
				}
				else if(n1xi < n2i9) {
					carry = n1xi - n2i8;
					res[resl] = '8';
				}
				else {
					carry = n1xi - n2i9;
					res[resl] = '9';
				};
				resl++;
				if(carry==0 && r1l==1 && r1[0]=='0') {
					free(r1);
					n1nz = 0;
          res[resl] = '\0';
					return res;
				};
				for(z = 0; z < y; z++) {
        	if(carries[z]==carry && (z % r1l)==((y + 1) % r1l)) {
						free(r1);
						free(carries);
						res[resl] = '\0';
						result = (char*) malloc((resl + 3) * sizeof(char));
						n1r = resl - y + z - 1;
						if(res[n1r - 1]==res[resl - 1]) {
              strncpy(result, res, --n1r);
							result[n1r] = rch1;
							result[n1r + 1] = res[resl - 1];
              result[n1r + 2] = '\0';
							res[--resl] = '\0';
						}
						else {
							strncpy(result, res, n1r);
							result[n1r] = rch1;
							result[n1r + 1] = '\0';
						};
						if(n1r + 2==resl && res[n1r]==res[n1r + 1])
							res[--resl] = '\0';
						strcat(result, res + n1r);
						free(res);
						result[resl + 1] = rch2;
						result[resl + 2] = '\0';
						return result;
					};
				};
				if(resl==ressize) {
					ressize+= 16;

					res = realloc(res, ressize * sizeof(char));
				};
				x++;
			};
		};
		n1xi = n1[x] - 48 + carry * 10;
		if(n1xi < n2i) {
			carry = n1xi;
			res[resl] = '0';
		}
		else if(n1xi < n2i2) {
			carry = n1xi - n2i;
			res[resl] = '1';
		}
		else if(n1xi < n2i3) {
			carry = n1xi - n2i2;
			res[resl] = '2';
		}
		else if(n1xi < n2i4) {
			carry = n1xi - n2i3;
			res[resl] = '3';
		}
		else if(n1xi < n2i5) {
			carry = n1xi - n2i4;
			res[resl] = '4';
		}
		else if(n1xi < n2i6) {
			carry = n1xi - n2i5;
			res[resl] = '5';
		}
		else if(n1xi < n2i7) {
			carry = n1xi - n2i6;
			res[resl] = '6';
		}
		else if(n1xi < n2i8) {
			carry = n1xi - n2i7;
			res[resl] = '7';
		}
		else if(n1xi < n2i9) {
			carry = n1xi - n2i8;
			res[resl] = '8';
		}
		else {
			carry = n1xi - n2i9;
			res[resl] = '9';
		};
		resl++;
		if(resl==ressize) {
			ressize+= 16;

			res = realloc(res, ressize * sizeof(char));
		};
	};
};

int main(int argc, char* argv[]) {
	char* r;

	if(argc < 3)
		return 0;
	r = advdiv(argv[1], argv[2], '-', '.', '[', ']');
	if(r[0]=='\0')
		return 0;
	printf("%s\n", r);
	free(r);
	return 1;
};
