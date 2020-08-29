// converts from decimal to any base <= 20

string to_base(int number,int base){
	string bases = "0123456789ABCDEFGHIJK";
	string result = "";

	while(number > 0){
		result = bases[number % base] + result;
		number /= base;
	}
	return result;
}
