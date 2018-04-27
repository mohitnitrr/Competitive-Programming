#include "bits_stdc.h"

int getRepeatNumber(const vector<int>& arr) {

	int n = arr.size() - 1;
	int sqrtVal = sqrt(n);
	int bucketSize = sqrtVal;

	if(sqrtVal*sqrtVal < n){
		bucketSize++;
	}
	vector<int> bucket;
	bucket.resize(bucketSize);
	for (int i = 0; i < bucketSize; i++) {
		bucket[i] = 0;
	}

	for (auto &next : arr) {
		int indice = next / sqrtVal - (next % sqrtVal == 0 ? 1 : 0);
		++bucket[indice];
	}

	int bucketToProcess = -1;
	for (int index = 0; index < bucket.size(); index++) {
		if (bucket[index] > sqrtVal) {
			bucketToProcess = index;
			break;
		}
	}
	if (bucketToProcess == -1 && (bucketSize != sqrtVal)) {
		bucketToProcess = bucket.size() - 1;
	}
	
	int duplicate = -1;
	map<int, int> duplicateMap;
	for (auto &next : arr) {
		int indice = next / sqrtVal - (next % sqrtVal == 0 ? 1 : 0);
		if (indice == bucketToProcess) {
			if (duplicateMap.find(next) != duplicateMap.end()) {
				duplicate = next;
				break;
			}
			else {
				duplicateMap[next] = 1;
			}
		}
	}

	return duplicate;
}

int main_intBit9() {
	
	vector<int> input = { 352, 672, 376, 701, 777, 382, 14, 905, 896, 853, 133, 199, 594, 339, 597, 642, 391, 578, 663, 922, 714, 236, 90, 839, 686, 844, 553, 372, 99, 677, 498, 920, 294, 493, 112, 380, 638, 118, 799, 627, 774, 645, 450, 143, 355, 548, 266, 45, 749, 832, 680, 976, 430, 656, 583, 153, 607, 509, 640, 393, 978, 792, 207, 211, 755, 831, 525, 598, 186, 673, 373, 357, 881, 159, 736, 814, 367, 25, 23, 280, 46, 874, 34, 849, 142, 851, 412, 136, 497, 696, 71, 557, 329, 953, 760, 24, 148, 267, 907, 841, 55, 706, 127, 734, 480, 369, 968, 982, 233, 872, 256, 183, 169, 711, 460, 763, 658, 724, 890, 985, 293, 341, 639, 554, 154, 869, 314, 165, 437, 198, 731, 13, 623, 505, 622, 951, 426, 779, 786, 146, 349, 586, 75, 379, 489, 899, 620, 816, 817, 191, 931, 662, 137, 520, 503, 685, 970, 843, 7, 966, 100, 518, 415, 491, 229, 204, 163, 747, 813, 336, 492, 514, 98, 390, 319, 551, 364, 770, 974, 506, 921, 387, 59, 616, 278, 370, 781, 875, 413, 918, 248, 519, 568, 894, 944, 757, 47, 679, 775, 396, 591, 842, 150, 532, 108, 6, 715, 44, 963, 688, 362, 219, 85, 175, 157, 660, 632, 97, 247, 795, 64, 927, 618, 516, 870, 259, 48, 479, 681, 285, 313, 422, 264, 1, 767, 79, 740, 448, 317, 808, 409, 628, 864, 523, 192, 342, 975, 29, 227, 18, 452, 196, 330, 709, 898, 3, 499, 789, 811, 728, 187, 888, 126, 802, 402, 431, 987, 912, 424, 960, 283, 257, 289, 324, 629, 268, 68, 695, 122, 5, 185, 32, 274, 821, 473, 825, 284, 833, 661, 671, 850, 819, 152, 678, 576, 375, 971, 123, 290, 404, 41, 457, 746, 552, 592, 42, 216, 195, 531, 130, 345, 331, 39, 353, 174, 299, 113, 643, 481, 145, 205, 444, 417, 67, 167, 129, 272, 474, 54, 561, 858, 541, 901, 536, 626, 347, 549, 60, 577, 946, 882, 392, 27, 788, 361, 739, 986, 559, 665, 406, 464, 453, 360, 125, 803, 759, 254, 346, 772, 172, 458, 451, 619, 737, 343, 212, 651, 848, 502, 161, 155, 495, 116, 631, 447, 425, 590, 790, 366, 80, 483, 22, 550, 528, 754, 648, 262, 877, 748, 582, 587, 756, 292, 572, 726, 66, 270, 949, 933, 698, 823, 621, 171, 332, 141, 593, 866, 515, 162, 952, 189, 318, 962, 904, 720, 385, 664, 965, 297, 617, 333, 49, 744, 221, 916, 252, 959, 384, 718, 793, 477, 210, 56, 908, 555, 435, 322, 484, 636, 723, 132, 190, 263, 276, 581, 653, 579, 895, 234, 806, 407, 378, 794, 533, 106, 649, 556, 15, 177, 243, 4, 589, 69, 787, 144, 231, 418, 547, 110, 751, 540, 919, 710, 837, 261, 782, 838, 494, 769, 193, 403, 732, 852, 574, 937, 567, 702, 251, 308, 468, 398, 111, 566, 633, 634, 356, 961, 158, 834, 941, 542, 96, 334, 354, 964, 868, 980, 529, 539, 917, 50, 89, 138, 102, 545, 810, 742, 109, 273, 879, 762, 707, 603, 121, 215, 863, 53, 758, 610, 605, 741, 83, 170, 929, 650, 43, 351, 703, 897, 924, 368, 513, 630, 250, 176, 527, 753, 306, 359, 218, 796, 958, 504, 432, 93, 906, 181, 383, 194, 773, 388, 857, 223, 859, 500, 829, 309, 149, 377, 855, 488, 389, 264, 915, 286, 725, 275, 826, 203, 208, 563, 668, 588, 401, 325, 780, 443, 939, 37, 19, 134, 575, 928, 862, 73, 768, 131, 217, 508, 178, 200, 722, 31, 328, 955, 573, 20, 445, 704, 727, 104, 517, 84, 778, 956, 891, 655, 584, 733, 925, 510, 386, 889, 265, 61, 684, 340, 363, 913, 429, 11, 454, 244, 783, 253, 940, 321, 344, 699, 822, 300, 865, 124, 226, 761, 785, 666, 462, 78, 675, 693, 399, 717, 101, 537, 95, 302, 57, 596, 562, 33, 10, 419, 472, 214, 611, 538, 676, 77, 180, 471, 670, 669, 114, 560, 2, 697, 973, 467, 94, 139, 602, 854, 861, 312, 893, 147, 335, 613, 950, 463, 938, 348, 395, 988, 374, 311, 752, 690, 522, 835, 776, 337, 140, 860, 608, 910, 209, 281, 948, 239, 242, 887, 350, 466, 249, 738, 303, 440, 809, 646, 271, 323, 564, 967, 433, 683, 485, 708, 647, 295, 791, 74, 58, 721, 449, 687, 476, 625, 526, 279, 674, 240, 766, 487, 657, 86, 654, 225, 277, 237, 428, 421, 926, 52, 235, 784, 615, 197, 934, 400, 92, 222, 827, 764, 9, 420, 569, 689, 461, 867, 255, 932, 624, 969, 807, 184, 743, 486, 459, 652, 394, 107, 812, 12, 475, 81, 103, 168, 8, 609, 72, 507, 830, 63, 36, 105, 438, 241, 836, 606, 876, 935, 423, 878, 801, 892, 228, 269, 972, 705, 692, 17, 558, 76, 840, 416, 246, 35, 26, 182, 135, 288, 947, 580, 117, 441, 713, 188, 478, 745, 232, 936, 871, 923, 712, 408, 521, 316, 804, 414, 828, 410, 883, 599, 930, 213, 903, 224, 326, 88, 245, 957, 614, 436, 16, 914, 456, 612, 496, 120, 310, 156, 637, 805, 358, 983, 635, 534, 644, 298, 884, 730, 943, 91, 179, 230, 765, 981, 291, 65, 411, 820, 846, 845, 320, 911, 873, 511, 524, 942, 397, 151, 979, 909, 886, 62, 442, 282, 900, 501, 38, 296, 202, 446, 338, 87, 880, 716, 771, 128, 115, 427, 750, 667, 604, 470, 70, 694, 719, 600, 512, 287, 984, 902, 164, 238, 30, 220, 28, 885, 659, 798, 682, 641, 729, 544, 482, 439, 945, 601, 258, 381, 455, 82, 815, 206, 847, 824, 371, 490, 700, 434, 585, 365, 797, 546, 571, 570, 735, 201, 405, 315, 818, 304, 977, 166, 21, 40, 469, 595, 535, 173, 119, 51, 307, 856, 260, 305, 543, 530, 465, 800, 691, 327, 565, 954, 160, 301 };
	cout << getRepeatNumber(input);
	return 0;
}