import solution


def test() -> str:
    s = solution.Solution()

    input1 = [[10, 15, 20], [1, 100, 1, 1, 1, 100, 1, 1, 100, 1], [0, 0, 0, 1], [851, 733, 25, 502, 40, 374, 953, 9, 121, 645, 579, 951, 985, 14, 941, 978, 13, 26, 655, 951, 78, 801, 875, 490, 174, 248, 945, 330, 236, 645, 422, 938, 618, 744, 768, 576, 14, 38, 477, 298, 37, 857, 628, 249, 566, 602, 364, 940, 650, 872, 991, 491, 305, 999, 135, 552, 470, 471, 332, 456, 529, 25, 286, 920, 634, 123, 747, 193, 818, 855, 618, 993, 309, 679, 955, 428, 165, 507, 216, 278, 340, 193, 976, 481, 843, 820, 556, 2, 285, 502, 658, 283, 336, 826, 610, 97, 121, 323, 404, 132, 696, 686, 58, 232, 248, 997, 429, 557, 957, 422, 169, 404, 878, 1, 949, 475, 481, 744, 837, 150, 706, 723, 539, 850, 3, 112, 618, 636, 544, 331, 300, 515, 784, 416, 781, 360, 615, 484, 592, 201, 422, 249, 372, 267, 583, 453, 495, 818, 758, 41, 444, 722, 14, 84, 369, 394, 571, 131, 372, 929, 554, 672, 281, 955, 682, 788, 527, 576, 699, 643, 766, 104, 835, 631, 34, 575, 454, 882, 104, 45, 702, 418, 954, 958, 543, 518, 571, 699, 980, 668, 65, 287, 893, 733, 275, 423, 958, 168, 394, 527, 757, 142, 47, 191, 43, 572, 262, 613, 473, 354, 863, 523, 224, 977, 910, 217, 125, 186, 507, 377, 49, 876, 629, 502, 570, 444, 815, 117, 635, 651, 208, 157, 254, 545, 347, 475, 41, 618, 758, 375, 813, 95, 263, 163, 561, 371, 247, 861, 529, 942, 638, 312, 514, 205, 107, 132, 570, 667, 280, 876, 103, 708, 689, 886, 445, 503, 1, 920, 271, 297, 511, 347, 352, 348, 13, 745, 955, 392, 136, 457, 317, 942, 184, 786, 293, 461, 668, 342, 228, 564, 740, 685, 343, 934, 854, 129, 659, 869, 493, 750, 965, 900, 210, 272, 986, 658, 818, 721, 207, 874, 171, 931, 997, 761, 702, 64, 259, 372, 117, 747, 755, 499, 371, 935, 49, 674, 936, 227, 873, 533, 635, 364, 595, 204, 470, 633, 176, 30, 148, 636, 710, 71, 491, 585, 140, 71, 697, 990, 32, 288, 569, 33, 960, 300, 946, 932, 230, 606, 236, 534, 116, 578, 424, 741, 243, 715, 974, 342, 156, 54, 605, 25, 394, 187, 539, 54, 541, 84, 706, 459, 26, 187, 27, 150, 438, 172, 341, 765, 346, 523, 536, 173, 111, 693, 380, 913, 305, 901, 874, 22, 77, 541, 179, 125, 703, 81, 662, 813, 232, 699, 552, 255, 536, 423, 109, 896, 233, 793, 320, 351, 822, 906, 664, 623, 488, 525, 218, 518, 835, 639, 932, 482, 867, 614, 919, 536, 540, 312, 537, 782, 274, 762, 200, 564, 660, 652, 246, 292, 119, 806, 832, 46, 226, 727, 251, 491, 653, 962, 820, 199, 731, 238, 291, 706, 917, 94, 177, 424, 602, 9, 233, 482, 948, 288, 156, 311, 815, 673, 512, 821, 613, 274, 609, 434, 227, 527, 436, 510, 988, 164, 59, 493, 670, 756,
                                                                                 527, 235, 872, 940, 565, 457, 364, 221, 876, 317, 554, 919, 449, 137, 930, 263, 899, 502, 513, 348, 169, 765, 571, 519, 680, 972, 801, 831, 437, 549, 902, 377, 295, 910, 718, 496, 544, 265, 298, 218, 226, 622, 312, 452, 529, 538, 274, 892, 219, 189, 249, 868, 296, 799, 371, 875, 403, 781, 856, 913, 958, 321, 267, 404, 238, 625, 362, 416, 266, 490, 144, 528, 931, 999, 437, 935, 870, 586, 204, 522, 247, 708, 990, 470, 704, 546, 264, 136, 794, 233, 374, 527, 186, 127, 227, 766, 208, 887, 426, 991, 736, 196, 234, 892, 771, 600, 541, 987, 492, 621, 529, 524, 846, 556, 526, 293, 94, 89, 494, 999, 872, 811, 450, 51, 333, 870, 46, 883, 186, 73, 55, 581, 896, 859, 981, 594, 100, 458, 916, 799, 574, 501, 773, 545, 295, 744, 656, 705, 996, 890, 527, 293, 195, 747, 602, 847, 543, 94, 631, 681, 360, 792, 379, 684, 161, 845, 755, 522, 255, 835, 780, 321, 230, 256, 174, 941, 152, 196, 855, 865, 716, 756, 211, 126, 872, 804, 971, 198, 216, 669, 771, 882, 511, 338, 365, 154, 828, 107, 416, 291, 386, 851, 340, 437, 856, 816, 472, 188, 948, 222, 530, 595, 331, 656, 999, 357, 934, 372, 489, 603, 523, 654, 748, 189, 26, 525, 60, 165, 477, 160, 974, 577, 70, 446, 916, 141, 90, 266, 827, 990, 294, 624, 61, 691, 660, 460, 693, 790, 170, 247, 156, 959, 630, 880, 663, 0, 628, 432, 93, 49, 906, 13, 246, 566, 189, 308, 925, 261, 332, 937, 847, 73, 402, 534, 128, 878, 993, 543, 581, 529, 394, 190, 549, 193, 132, 258, 88, 315, 755, 737, 707, 641, 860, 490, 87, 138, 157, 155, 647, 84, 724, 859, 762, 807, 806, 159, 183, 37, 271, 526, 686, 92, 372, 137, 247, 736, 845, 316, 969, 518, 652, 772, 224, 672, 740, 970, 488, 982, 669, 650, 482, 196, 284, 13, 725, 39, 315, 784, 183, 912, 233, 713, 854, 913, 117, 42, 645, 114, 957, 93, 908, 909, 604, 431, 335, 648, 712, 582, 92, 129, 220, 35, 692, 14, 636, 871, 955, 310, 356, 305, 939, 948, 404, 244, 522, 657, 220, 759, 864, 349, 921, 231, 41, 984, 341, 326, 145, 347, 851, 634, 789, 121, 385, 577, 876, 44, 833, 203, 287, 94, 557, 695, 865, 681, 473, 301, 576, 141, 572, 76, 850, 391, 501, 739, 287, 29, 49, 995, 33, 587, 485, 815, 158, 4, 444, 11, 532, 550, 919, 760, 617, 936, 152, 186, 835, 57, 506, 939, 941, 730, 913, 749, 711, 714, 172, 76, 137, 28, 16, 951, 965, 158, 452, 890, 909, 61, 3, 702, 657, 226, 119, 709, 526, 671, 111, 547, 305, 602, 701, 60, 738, 23, 845, 955, 743, 773, 262, 112, 638, 551, 780, 275, 596, 827, 797, 417, 422, 276, 564, 977, 650, 812, 184, 234, 372, 416, 485, 214, 45, 245, 232, 472, 167, 585, 207, 248]]

    expectations = [15, 6, 0, 209385]

    if (len(input1) != len(expectations)):
        return "test is invalid"

    for i in range(len(expectations)):

        assert (2 <= len(input1[i]) and len(input1[i]) <= 1000)

        for j in range(len(input1[i])):
            assert (0 <= input1[i][j] and input1[i][j] <= 999)

        result = s.minCostClimbingStairs(input1[i])

        failMsg = (f"TEST #{i} FAILED: bad result for {input1[i]}: got {
                   result} expected {expectations[i]}")

        if result != expectations[i]:
            return failMsg

    return "PASS"


if __name__ == '__main__':
    print(test())