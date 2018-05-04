#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		std::cout << "usage: \n";
		std::cout << "\t my_diff src1 src2 \n";
		return 1;
	}

	std::ifstream src1, src2;
	src1.open(argv[1], std::ifstream::in);
	src2.open(argv[2], std::ifstream::in);

	std::string src_file_name_1 = argv[1], src_file_name_2 = argv[2];
	std::string diff_filename = "diff-" +  src_file_name_1 + "-" + src_file_name_2;
	std::ofstream diff;
	diff.open(diff_filename, std::ofstream::out);

	std::string buffer1, buffer2;

	while (src1 >> buffer1 && src2 >> buffer2) {
		if (buffer1 == buffer2)
			diff << buffer1;
	}
	diff << '\n';

	src1.close();
	src2.close();
	diff.close();

	return 0;
}