#include "bits_stdc.h"

struct Element {
	int n;
	int c;
};

int repeatedNumber(const vector<int> &A) {
	vector<Element> tmp(2);

	tmp[0].c = 0;
	tmp[1].c = 0;

	int size = A.size();
	int retVal = -1;
	for (int i = 0; i < size; i++) {
		if (tmp[0].n == A[i])
			tmp[0].c += 1;
		else if (tmp[1].n == A[i])
			tmp[1].c += 1;
		else {
			if (tmp[0].c > 0 && tmp[1].c > 0) {
				tmp[0].c -= 1;
				tmp[1].c -= 1;
			}
			else {
				if (tmp[0].c == 0) {
					tmp[0].n = A[i];
					tmp[0].c = 1;
				}
				else {
					tmp[1].n = A[i];
					tmp[1].c = 1;
				}
			}
		}
	}

	int n1 = 0, n2 = 0;
	for (int i = 0; i < size; i++) {
		
		if (A[i] == tmp[0].n)
			n1++;
		else if (A[i] == tmp[1].n)
			n2++;
	}

	if (n1 > size / 3)
		return tmp[0].n;
	else if (n2 > size / 3)
		return tmp[1].n;


	return retVal;
}

/*int main() {

	cout << repeatedNumber({ 1000860, 1000860, 1000348, 1000181, 1000860, 1000470, 1000964, 1000805, 1000890, 1000860, 1000860, 1000989, 1000455, 1000860, 1000675, 1000860, 1000860, 1000822, 1000220, 1000860, 1000860, 1000860, 1000860, 1000860, 1000756, 1000860, 1000940, 1000370, 1000032, 1000860, 1000739, 1000080, 1000188, 1000830, 1000754, 1000834, 1000582, 1000153, 1000270, 1000793, 1000360, 1000727, 1000879, 1000767, 1000016, 1000454, 1000235, 1000409, 1000860, 1000860, 1000567, 1000211, 1000501, 1000283, 1000514, 1000860, 1000044, 1000860, 1000860, 1000384, 1000233, 1000334, 1000813, 1000787, 1000837, 1000395, 1000860, 1000934, 1000918, 1000860, 1000985, 1000895, 1000412, 1000264, 1000544, 1000767, 1000305, 1000678, 1000364, 1000700, 1000446, 1000097, 1000860, 1000860, 1000997, 1000256, 1000860, 1000860, 1000860, 1000850, 1000860, 1000967, 1000207, 1000692, 1000276, 1000417, 1000860, 1000939, 1000211, 1000627, 1000055, 1000992, 1000860, 1000482, 1000573, 1000860, 1000898, 1000025, 1000860, 1000778, 1000549, 1000064, 1000860, 1000809, 1000006, 1000860, 1000456, 1000418, 1000860, 1000653, 1000621, 1000927, 1000339, 1000362, 1000860, 1000899, 1000860, 1000682, 1000179, 1000562, 1000262, 1000860, 1000876, 1000339, 1000860, 1000476, 1000860, 1000860, 1000860, 1000860, 1000168, 1000860, 1000453, 1000414, 1000860, 1000290, 1000677, 1000860, 1000177, 1000860, 1000407, 1000860, 1000480, 1000723, 1000479, 1000612, 1000041, 1000348, 1000606, 1000782, 1000860, 1000860, 1000239, 1000148, 1000120, 1000860, 1000027, 1000736, 1000237, 1000490, 1000792, 1000509, 1000289, 1000860, 1000860, 1000822, 1000964, 1000860, 1000080, 1000770, 1000688, 1000047, 1000671, 1000170, 1000240, 1000860, 1000997, 1000582, 1000860, 1000395, 1000860, 1000253, 1000233, 1000566, 1000951, 1000948, 1000380, 1000077, 1000323, 1000860, 1000860, 1000679, 1000672, 1000673, 1000934, 1000975, 1000860, 1000361, 1000853, 1000463, 1000860, 1000860, 1000860, 1000536, 1000818, 1000526, 1000860, 1000953, 1000264, 1000860, 1000295, 1000604, 1000723, 1000379, 1000860, 1000257, 1000860, 1000175, 1000860, 1000860, 1000860, 1000183, 1000510, 1000860, 1000452, 1000055, 1000568, 1000103, 1000447, 1000860, 1000460, 1000817, 1000412, 1000136, 1000608, 1000480, 1000351, 1000436, 1000860, 1000710, 1000154, 1000439, 1000677, 1000095, 1000186, 1000907, 1000694, 1000038, 1000351, 1000895, 1000860, 1000216, 1000860, 1000860, 1000627, 1000860, 1000278, 1000860, 1000860, 1000860, 1000860, 1000737, 1000761, 1000860, 1000860, 1000860, 1000577, 1000070, 1000445, 1000751, 1000860, 1000625, 1000338, 1000860, 1000860, 1000575, 1000860, 1000949, 1000606, 1000860, 1000772, 1000663, 1000042, 1000081, 1000269, 1000412, 1000860, 1000456, 1000860, 1000860, 1000860, 1000238, 1000032, 1000103, 1000860, 1000696, 1000121, 1000952, 1000227, 1000963, 1000890, 1000760, 1000369, 1000860, 1000860, 1000006, 1000860, 1000095, 1000849, 1000860, 1000860, 1000860, 1000745, 1000860, 1000860, 1000860, 1000860, 1000277, 1000359, 1000860, 1000860, 1000860, 1000093, 1000860, 1000734, 1000223, 1000860, 1000832, 1000860, 1000860, 1000872, 1000555, 1000029, 1000860, 1000428, 1000071, 1000340, 1000944, 1000860, 1000860, 1000774, 1000860, 1000121, 1000915, 1000860, 1000510, 1000860, 1000110, 1000318, 1000362, 1000904, 1000357, 1000860, 1000235, 1000171, 1000533, 1000860, 1000860, 1000472, 1000028, 1000546, 1000394, 1000017, 1000860, 1000129, 1000860, 1000316, 1000860, 1000632, 1000102, 1000008, 1000860, 1000860, 1000403, 1000881, 1000925, 1000566, 1000409, 1000149, 1000860, 1000860, 1000925, 1000860, 1000860, 1000338, 1000292, 1000205, 1000860, 1000295, 1000185, 1000776, 1000471, 1000860, 1000321, 1000860, 1000228, 1000528, 1000860, 1000513, 1000114, 1000664, 1000097, 1000111, 1000587, 1000860, 1000860, 1000891, 1000779, 1000860, 1000860, 1000246, 1000125, 1000860, 1000825, 1000982, 1000913, 1000434, 1000860, 1000860, 1000860, 1000601, 1000532, 1000351, 1000268, 1000277, 1000801, 1000860, 1000355, 1000004, 1000982, 1000879, 1000906, 1000634, 1000005, 1000272, 1000864, 1000526, 1000744, 1000346, 1000860, 1000988, 1000313, 1000780, 1000893, 1000860, 1000741, 1000860, 1000742, 1000206, 1000860, 1000816, 1000860, 1000301, 1000860, 1000452, 1000044, 1000808, 1000860, 1000829, 1000541, 1000788, 1000397, 1000860, 1000860, 1000860, 1000860, 1000399, 1000087, 1000078, 1000860, 1000860, 1000964, 1000784, 1000168, 1000860, 1000830, 1000907, 1000860, 1000860, 1000860, 1000380, 1000587, 1000663, 1000865, 1000725, 1000438, 1000860, 1000910, 1000008, 1000538, 1000370, 1000384, 1000974, 1000849, 1000860, 1000559, 1000860, 1000637, 1000219, 1000045, 1000179, 1000860, 1000860, 1000860, 1000860, 1000236, 1000686, 1000057, 1000817, 1000378, 1000799, 1000313, 1000578, 1000411, 1000223, 1000731, 1000100, 1000801, 1000631, 1000264, 1000860, 1000904, 1000860, 1000245, 1000218, 1000263, 1000911, 1000595, 1000558, 1000860, 1000860, 1000860, 1000860, 1000275, 1000860, 1000214, 1000601, 1000212, 1000860, 1000337, 1000036, 1000079, 1000860, 1000241, 1000003, 1000800, 1000860, 1000104, 1000629, 1000860, 1000860, 1000860, 1000860, 1000860, 1000114, 1000696, 1000860, 1000545, 1000206, 1000205, 1000821, 1000022, 1000047, 1000860, 1000310, 1000860, 1000843, 1000205, 1000860, 1000860, 1000684, 1000860, 1000836, 1000860, 1000860, 1000252, 1000927, 1000860, 1000860, 1000195, 1000860, 1000860, 1000526, 1000860, 1000613, 1000860, 1000912, 1000860, 1000860, 1000860, 1001000, 1000778, 1000835, 1000860, 1000017, 1000860, 1000857, 1000609, 1000733, 1000517, 1000300, 1000860, 1000367, 1000860, 1000394, 1000860, 1000624, 1000860, 1000860, 1000860, 1000933, 1000517, 1000860, 1000860, 1000860, 1000095, 1000695, 1000860, 1000295, 1000765, 1000413, 1000860, 1000860, 1000860, 1000860, 1000982, 1000860, 1000617, 1000860, 1000475, 1000381, 1000815, 1000860, 1000659, 1000548, 1000401, 1000930, 1000860, 1000860, 1000223, 1000618, 1000962, 1000398, 1000839, 1000383, 1000763, 1000171, 1000860, 1000019, 1000994, 1000094, 1000860, 1000860, 1000860, 1000950, 1000190, 1000860, 1000370, 1000215, 1000066, 1000400, 1000860, 1000860, 1000735, 1000860, 1000658, 1000860, 1000183, 1000860, 1000860, 1000342, 1000329, 1000860, 1000432, 1000772, 1000493, 1000730, 1000724, 1000301, 1000860, 1000978, 1000086, 1000440, 1000860, 1000860, 1000492, 1000860, 1000860, 1000627, 1000879, 1000510, 1000214, 1000494, 1000324, 1000701, 1000289, 1000913, 1000860, 1000341, 1000860, 1000873, 1000604, 1000736, 1000217, 1000155, 1000568, 1000860, 1000860, 1000860, 1000860, 1000860, 1000627, 1000217, 1000860, 1000059, 1000544, 1000724, 1000733, 1000860, 1000860, 1000919, 1000860, 1000962, 1000860, 1000848, 1000860, 1000302, 1000417, 1000860, 1000860, 1000914, 1000107, 1000863, 1000001, 1000179, 1000117, 1000860, 1000776, 1000014, 1000468, 1000860, 1000092, 1000849, 1000679, 1000003, 1000860, 1000688, 1000860, 1000392, 1000507, 1000860, 1000712, 1000577, 1000059, 1000860, 1000368, 1000389, 1000942, 1000867, 1000860, 1000381, 1000860, 1000954, 1000077, 1000784, 1000387, 1000860, 1000050, 1000735, 1000860, 1000860, 1000860, 1000860, 1000829, 1000860, 1000347, 1000860, 1000860, 1000860, 1000860, 1000860, 1000549, 1000860, 1000607, 1000860, 1000929, 1000411, 1000860, 1000860, 1000370, 1000589, 1000812, 1000539, 1000169, 1000860, 1000302, 1000079, 1000297, 1000860, 1000404, 1000665, 1000441, 1000628, 1000528, 1000215, 1000991, 1000615, 1000430, 1000424, 1000388, 1000863, 1000893, 1000422, 1000811, 1000125, 1000860, 1000226, 1000860, 1000931, 1000992, 1000228, 1000861, 1000860, 1000647, 1000421, 1000950, 1000721, 1000860, 1000232, 1000860, 1000098, 1000171, 1000860, 1000597, 1000860, 1000771, 1000860, 1000860, 1000860, 1000050, 1000286, 1000860, 1000378, 1000860, 1000860, 1000860, 1000860, 1000860, 1000047, 1000989, 1000406, 1000860, 1000643, 1000860, 1000359, 1000602, 1000913, 1000440, 1000691, 1000860, 1000209, 1000565, 1000860, 1000860, 1000121, 1000130, 1000265, 1000201, 1000074, 1000570, 1000802, 1000299, 1000593, 1000164, 1000442, 1000860, 1000326, 1000582, 1000490, 1000860, 1000536, 1000860, 1000378, 1000860, 1000262, 1000032, 1000860, 1000860, 1000860, 1000312, 1000418, 1000080, 1000577, 1000860, 1000659, 1000168, 1000262, 1000143, 1000069, 1000963, 1000860, 1000860, 1000860, 1000945, 1000786, 1000645, 1000825, 1000517, 1000024, 1000860, 1000889, 1000860, 1000676, 1000295, 1000219, 1000292, 1000714, 1000213, 1000172, 1000794, 1000567, 1000860, 1000860, 1000480, 1000860, 1000965, 1000190, 1000014, 1000445 });
	return 0;
}*/